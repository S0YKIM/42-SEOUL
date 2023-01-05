/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:55:02 by sokim             #+#    #+#             */
/*   Updated: 2023/01/05 12:34:21 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

template <bool B, class T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
  typedef T type
};

template <typename T, T v>
struct _integral_constant {
  typedef _integral_constant<T, v> type;
  typedef T value_type;
  static const T value = v;
  operator value_type() const throw() { return value; }
};

typedef _integral_constant<bool, true> true_type;
typedef _integral_constant<bool, false> false_type;

/**
 * @brief Membergeneric definition of is_integral
 *
 * @tparam T The type to be checked whether it is integral or not
 */
template <typename T>
struct _is_integral : public false_type {};

/**
 * @brief Template specialization for every integral type
 *
 * If is_integral<X>::value is true, than X is integral.
 */
template <>
struct _is_integral<bool> : public true_type {};

template <>
struct _is_integral<char> : public true_type {};

template <>
struct _is_integral<wchar_t> : public true_type {};

template <>
struct _is_integral<signed char> : public true_type {};

template <>
struct _is_integral<short int> : public true_type {};

template <>
struct _is_integral<int> : public true_type {};

template <>
struct _is_integral<long int> : public true_type {};

template <>
struct _is_integral<long long int> : public true_type {};

template <>
struct _is_integral<unsigned char> : public true_type {};

template <>
struct _is_integral<unsigned short int> : public true_type {};

template <>
struct _is_integral<unsigned int> : public true_type {};

template <>
struct _is_integral<unsigned long int> : public true_type {};

template <>
struct _is_integral<unsigned long long int> : public true_type {};

/**
 * @brief Remove const and volatile keyword from the given type
 *
 * Since is_integral needs to consider cv-qualified integral types as integral,
 * it provides typedef for the pure type without const and volatile keyword.
 */
template <typename T>
struct _remove_const_volatile {
  typedef T type;
};

template <typename T>
struct _remove_const_volatile<const T> {
  typedef T type;
};

template <typename T>
struct _remove_const_volatile<volatile T> {
  typedef T type;
};

template <typename T>
struct _remove_const_volatile<const volatile T> {
  typedef T type;
};

/**
 * @brief Tell if the given type is integral or not
 *
 * Inherits _is_integral struct to remove const and volatile keyword.
 */
template <typename T>
struct is_integral
    : public _is_integral<typename _remove_const_volatile<T>::type> {};

#endif
