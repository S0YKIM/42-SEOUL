/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:55:02 by sokim             #+#    #+#             */
/*   Updated: 2023/01/04 15:27:17 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

template <typename T, T v>
struct integral_constant {
  typedef integral_constant<T, v> type;
  typedef T value_type;
  static const T value = v;
  operator value_type() const throw() { return value; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

/**
 * @brief Membergeneric definition of is_integral
 *
 * @tparam T The type to be checked whether it is integral or not
 */
template <typename T>
struct is_integral : public false_type {};

#endif
