/**
 * @file   string.cpp
 * @author  fqguozhou@gmail.com
 * @date   Wed Apr  8 10:05:17 2015
 *
 * @brief
 *
 *
 */

#include "string.hpp"
#include "boost/regex.hpp"
#include "boost/locale/encoding_utf.hpp"
using namespace miacropp;
string::string() noexcept {}
string::string(const char *str, size_type length) : std::string(str, length) {}
string::~string() noexcept {}
std::vector<string>
string::split(char ch) const noexcept
{
  size_type index_end = 0;
  size_type index_start = 0;
  std::vector<string> string_vector;
  try
  {
    while (index_end = this->find(ch, index_start), index_end != this->npos)
    {
      string limit = this->substr(index_start, index_end - index_start);
      if (!(limit.empty()))
        string_vector.push_back(limit);
      index_start = index_end + 1;
    }
    if (index_start < this->length())
    {
      string limit = this->substr(index_start, this->length() - index_start);
      if (!(limit.empty()))
        string_vector.push_back(limit);
    }
  }
  catch (...)
  {
  }
  return string_vector;
}

string
string::pop_last_field(char ch) noexcept
{
  string last_field;
  while ((this->size() > 0) && ((*this)[this->size() - 1] != ch))
  {
    last_field.insert(last_field.begin(), this->back());
    this->pop_back();
  }
  if ((this->size() > 0) && ((*this)[this->size() - 1] == ch))
    this->pop_back();
  return last_field;
}
string
string::pop_first_field(char ch) noexcept
{
  size_t i = 0;
  string first_field;
  for (i = 0; i < this->size(); ++i)
  {
    if (this->operator[](i) == ch)
    {
      ++i;
      break;
    }
    else
      first_field.push_back(this->operator[](i));
  }
  if (i < this->size())
    this->operator=(this->substr(i));
  else
    this->clear();
  return first_field;
}

void
string::clear_end_blank() noexcept
{
  try
  {
    std::string::size_type index_end = this->length() - 1;
    while ((index_end > 0)
           && (((*this)[index_end] == ' ') || (*this)[index_end] == '\t'
               || (*this)[index_end] == '\r' || (*this)[index_end] == '\n'))
      --index_end;
    this->erase(index_end + 1, this->length() - 1 - index_end);
  }
  catch (...)
  {
  }
  return;
}
void
string::clear_head_blank() noexcept
{
  try
  {
    std::string::size_type index_begin = 0;
    while ((index_begin < this->length())
           && (((*this)[index_begin] == ' ') || (*this)[index_begin] == '\t'
               || (*this)[index_begin] == '\r' || (*this)[index_begin] == '\n'))
      ++index_begin;
    this->erase(0, index_begin);
  }
  catch (...)
  {
  }
  return;
}

void
string::clear_extra_blank() noexcept
{
  this->clear_head_blank();
  this->clear_end_blank();
}
/**
 * get word separated by tab or white space in string
 *
 * @param index
 * @param word
 *
 * @return index of the end of the word, not the last character
 */
std::string::size_type
string::get_word(size_type index, string &word)
{
  size_type index_begin = index;
  while ((index_begin < this->length())
         && ((*this)[index_begin] == ' ' || (*this)[index_begin] == '\t'))
    ++index_begin;
  size_type index_end = index_begin;
  while ((index_end < this->length())
         && ((*this)[index_end] != ' ' && (*this)[index_end] != '\t'))
    ++index_end;
  word = this->substr(index_begin, index_end - index_begin);
  return index_end;
}

string
string::to_lower() const
{
  string lower_string = (*this);
  for (auto iter = lower_string.begin(); iter != lower_string.end(); ++iter)
    if (((*iter) >= 'A') && ((*iter) <= 'Z'))
      (*iter) = (*iter) + 'a' - 'A';
  return lower_string;
}

string
string::to_upper() const
{
  string upper_string = (*this);
  for (auto iter = upper_string.begin(); iter != upper_string.end(); ++iter)
    if (((*iter) >= 'a') && ((*iter) <= 'z'))
      (*iter) = (*iter) + 'A' - 'a';
  return upper_string;
}

string
string::replace_char(size_type pos, size_type count, char origin_char,
                     char modify_char) const
{
  string modified_string = (*this);
  if (pos > modified_string.length())
    pos = 0;
  size_type end = pos + count;
  if (end > modified_string.length())
    end = modified_string.length();
  for (size_type i = pos; i < end; ++i)
    if (modified_string[i] == origin_char)
      modified_string[i] = modify_char;
  return modified_string;
}


std::string::size_type
string::find_case_insensitive(string str, size_type index) const
{
  string lower_case_this = (*this).to_lower();
  return lower_case_this.find(str.to_lower(), index);
}

bool
string::is_uint(size_type index) const
{
  for (size_type i = index; i < this->length(); ++i)
    if ((*this)[i] < '0' || (*this)[i] > '9')
      return false;
  return true;
}

bool
string::is_int(size_type index) const
{
  if ((*this)[index] == '-' || (*this)[index] == '+')
    ++index;
  return this->is_uint(index);
}

bool
string::is_float(size_type index) const
{
  if ((*this)[index] == '-' || (*this)[index] == '+')
    ++index;
  return this->is_ufloat(index);
}

bool
string::is_ufloat(size_type index) const
{
  size_type dot_ind = this->find('.', index);
  if (dot_ind == npos)
    dot_ind = this->length();
  for (size_type i = index; i < dot_ind; ++i)
    if ((*this)[i] < '0' || (*this)[i] > '9')
      return false;
  for (size_type i = dot_ind + 1; i < this->length(); ++i)
    if ((*this)[i] < '0' || (*this)[i] > '9')
      return false;
  return true;
}

string
string::to_hex() const
{
  string hex_format;
  hex_format.resize(this->length() * 2);
  for (size_t i = 0; i < this->length(); ++i)
    std::sprintf(const_cast<char *>(hex_format.c_str() + i * 2), "%2.2x",
                 (*this)[i] & 0x0ff);
  return hex_format;
}

void
string::from_int(int64_t number)
{
  this->operator=(std::to_string(number));
}

string
string::substr(size_type &pos, char start_char, char end_char)
{
  if (pos >= this->length())
    return string();
  size_type begin = this->find(start_char, pos);
  if (begin == npos)
    return string();
  size_type end = this->find(end_char, begin + 1);
  if (end == npos)
    return string();
  pos = end + 1;
  size_type count = pos - begin;
  string sub_str = this->substr(begin, count);
  return sub_str;
}

int
string::to_int() const
{
  int result;
  try
  {
    result = std::stoi((*this));
  }
  catch (...)
  {
    result = 0;
  }
  return result;
}

string
string::to_utf8() const
{
#ifdef WIN32
  int n = ::MultiByteToWideChar(936, 0, this->c_str(), -1, NULL, 0);
  wchar_t *wb = new wchar_t[n];
  ::MultiByteToWideChar(936, 0, this->c_str(), -1, wb, n);
  n = ::WideCharToMultiByte(CP_UTF8, 0, wb, -1, NULL, 0, 0, 0);
  char *cb = new char[n];
  ::WideCharToMultiByte(CP_UTF8, 0, wb, -1, cb, n, 0, 0);
  delete wb;
  string utf8Str = string(cb, strlen(cb));
  delete cb;
  return utf8Str;
#else
  int n = strlen(this->c_str());
  char *cb = new char[n + 1];
  std::memcpy(cb, this->c_str(), n + 1);
  string utf8Str = string(cb, strlen(cb));
  delete[] cb;
  return utf8Str;
#endif
}

void
string::from_wstring(const std::wstring &wstr)
{
  (*this) = boost::locale::conv::utf_to_utf<char>(wstr.c_str(),
                                                  wstr.c_str() + wstr.size());
}

std::wstring
string::to_wstring() const
{
  auto wstr = boost::locale::conv::utf_to_utf<wchar_t>(
      this->c_str(), this->c_str() + this->size());
  return wstr;
}
