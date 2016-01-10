/**
 * @file   macros.hpp
 * @author  fqguozhou@gmail.com
 * @date   Mon Mar 30 11:23:47 2015
 *
 * @brief
 *
 *
 */
#ifndef __MACROS_HPP__
#define __MACROS_HPP__

#ifdef MPP_WIN32
#define MPP_EXPORT _declspec(dllexport)
#else
#define MPP_EXPORT
#endif  // MPP_WIN32

#define DATA_MEMBER_ACCESS(VAR, TYPE)                           \
 public:                                                        \
  const TYPE& get_##VAR() const { return this->VAR##_; }        \
 public:                                                        \
  void set_##VAR(TYPE&& VAR) { this->VAR##_ = std::move(VAR); } \
  void set_##VAR(const TYPE& VAR) { this->VAR##_ = VAR; }

#define MPP_COPY_ASSIGN_REF(TYPE) const TYPE &
#define MPP_MOVE_ASSIGN_REF(TYPE) TYPE &&
#define MPP_RV_REF(VAR) (std::move(VAR))
#define MPP_FORWARD(VAR, TYPE) (std::forward<TYPE>(VAR))
#endif  // __MACROS_HPP__
