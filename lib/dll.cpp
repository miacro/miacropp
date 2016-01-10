/**
 * @file   dll.cpp
 * @author  fqguozhou@gmail.com
 * @date   Thu Nov  5 18:02:25 2015
 *
 * @brief
 *
 *
 */

#include "dll.hpp"
#include "utils.hpp"
using namespace miacropp;
dll::dll() : handle_(nullptr) {}
dll::dll(dll&& other)
    : handle_(std::move(other).handle_), error_(std::move(other).error_)
{
  other.handle_ = nullptr;
  other.error_.clear();
}

dll& dll::operator=(dll&& other)
{
  this->close();
  this->handle_ = std::move(other).handle_;
  this->error_ = std::move(other).error_;
  other.handle_ = nullptr;
  other.error_.clear();
  return (*this);
}

dll::~dll() { this->close(); }


int
dll::open(const string& dll_location)
{
  this->close();
  string full_location = dll::get_full_dll_location(dll_location);
#ifdef MPP_LINUX
  this->handle_ = dlopen(full_location.c_str(), RTLD_NOW);
  if (this->handle_ != nullptr)
    return 0;
#endif  // MPP_LINUX
#ifdef MPP_WIN32
  this->handle_ = LoadLibrary(full_location.c_str());
  if (this->handle_ != nullptr)
    return 0;
#endif  // MPP_WIN32
  this->get_last_error();
  return -1;
}

int
dll::close()
{
  if (this->handle_ == nullptr)
    return 0;
#ifdef MPP_LINUX
  if (dlclose(this->handle_) != 0)
  {
    this->get_last_error();
    return -1;
  }
#endif  // MPP_LINUX
#ifdef MPP_WIN32
  if (FreeLibrary(this->handle_) == false)
  {
    this->get_last_error();
    return -1;
  }
#endif  // MPP_WIN32
  this->handle_ = nullptr;
  return 0;
}

void*
dll::symbol(const string& symbol_name)
{
  if (this->handle_ == nullptr)
  {
    this->error_ = "shared object not opened";
    return nullptr;
  }
  void* symbol_ptr;
#ifdef MPP_LINUX
  symbol_ptr = dlsym(this->handle_, symbol_name.c_str());
  if (symbol_ptr == nullptr)
  {
    this->get_last_error();
    return nullptr;
  }
#endif  // MPP_LINUX
#ifdef MPP_WIN32
  symbol_ptr = GetProcAddress(this->handle_, symbol_name.c_str());
  if (symbol_ptr == nullptr)
  {
    this->get_last_error();
    return nullptr;
  }
#endif  // MPP_WIN32
  return symbol_ptr;
  ;
}

const string&
dll::get_error() const
{
  return this->error_;
}

string
dll::get_full_dll_location(const string& dll_location)
{
  string full_dll_location = dll_location;
#ifdef MPP_LINUX
  if (dll_location.find("lib") != 0)
    full_dll_location = "lib" + full_dll_location;
  if (dll_location.rfind(".so") != dll_location.length() - 3)
    full_dll_location = full_dll_location + ".so";
#endif
#ifdef MPP_WIN32
  string temp_string = dll_location.to_lower();
  if (temp_string.rfind(".dll") != dll_location.length() - 4)
    full_dll_location = full_dll_location + ".dll";
#endif
  return full_dll_location;
}

void
dll::get_last_error()
{
#ifdef MPP_LINUX
  this->error_ = dlerror();
#endif  // MPP_LINUX
#ifdef MPP_WIN32
  char* buffer;
  FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM
                    | FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                (LPTSTR)&buffer, 0, NULL);
  this->error_ = buffer;
#endif
}
