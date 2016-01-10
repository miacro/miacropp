/**
 * @file   string.hpp
 * @author  fqguozhou@gmail.com
 * @date   Wed Apr  8 10:04:57 2015
 *
 * @brief
 *
 *
 */

#ifndef __EHR_STRING_HPP__
#define __EHR_STRING_HPP__
#include "miacropp/config.hpp"
#include <string>
#include <vector>
namespace miacropp
{
  class MPP_EXPORT string : public std::string
  {
    typedef std::string INHERITED_TYPE;

   public:
    // using INHERITED_TYPE::INHERITED_TYPE;
    using INHERITED_TYPE::substr;
    using INHERITED_TYPE::replace;

    string() noexcept;
    string(const char *, size_type const);

    template <class T>
    string(T &&str) noexcept : INHERITED_TYPE(std::forward<T>(str))
    {
    }

    template <class T>
    string &operator=(T &&other) noexcept
    {
      this->clear();
      INHERITED_TYPE::operator=(std::forward<T>(other));
      return (*this);
    }
    ~string() noexcept;

   public:
    std::vector<string> split(char ch) const noexcept;
    string pop_last_field(char ch) noexcept;
    string pop_first_field(char ch) noexcept;
    void clear_head_blank() noexcept;
    void clear_end_blank() noexcept;
    void clear_extra_blank() noexcept;
    size_type get_word(size_type index, string &word);
    size_type find_case_insensitive(string, size_type index) const;
    string to_lower() const;
    string to_upper() const;
    string replace_char(size_type pos, size_type count, char origin_char,
                        char modify_char) const;
    bool is_int(size_type index = 0) const;
    bool is_uint(size_type index = 0) const;
    bool is_float(size_type index = 0) const;
    bool is_ufloat(size_type index = 0) const;
    string to_hex() const;
    void from_int(int64_t);
    int to_int() const;
    string substr(size_type &pos, char start_char, char end_char);
    string to_utf8() const;
    void from_wstring(const std::wstring &wstr);
    std::wstring to_wstring() const;
  };
};

namespace std
{
  template <>
  struct hash<miacropp::string>
  {
    size_t operator()(miacropp::string const &str) const
    {
      std::hash<std::string> hash_fun;
      return hash_fun(str);
    }
    bool operator()(const miacropp::string &lhs,
                    const miacropp::string &rhs) const
    {
      return lhs == rhs;
    }
  };
};
#endif  // __EHR_STRING_HPP__
