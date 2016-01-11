/**
 * @file   dll.hpp
 * @author  fqguozhou@gmail.com
 * @date   Fri May 22 11:28:45 2015
 *
 * @brief
 *
 *
 */

#ifndef __DLL_HPP__
#define __DLL_HPP__
#include "miacropp/config.hpp"
#include "lib/string.hpp"

#ifdef MPP_LINUX
#include <dlfcn.h>
#endif  // MPP_LINUX

#ifdef MPP_WIN32
#endif  // MPP_WIN3_

namespace miacropp
{
#ifdef MPP_LINUX
  typedef void* Dll_Handle;
#endif  // MPP_LINUX

#ifdef MPP_WIN32
  typedef HMODULE Dll_Handle;
#endif  // MPP_WIN32
  class MPP_EXPORT dll
  {
   public:
    dll();
    dll(const dll&) = delete;
    dll(dll&&);
    dll& operator=(const dll&) = delete;
    dll& operator=(dll&&);
    ~dll();

   public:
    int open(const string& dll_location);
    int close();
    void* symbol(const string& symbol_name);
    const string& get_error() const;
    static string get_full_dll_location(const string& dll_location);

   protected:
    void get_last_error();

   protected:
    Dll_Handle handle_;
    string error_;
  };
};
#endif  // __DLL_HPP__
