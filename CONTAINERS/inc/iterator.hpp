/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itertator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:50:36 by sokim             #+#    #+#             */
/*   Updated: 2022/12/22 15:49:04 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {
/*
	Common iterator class. Iterator classes can inherit from this class.
*/
template <typename Category, typename T, typename Distance = std::ptrdiff_t, \
	typename Pointer = T*, typename Reference = T&>
struct iterator {
	/* One of Iterator tags */
	typedef Category	iterator_category;
	/* The type pointed to by the iterator */
	typedef T			value_type;
	/* The signed integer type of the result of subtracting two pointers */
	typedef Distance	difference_type;
	/* Pointer-to-value type */
	typedef Pointer		pointer;
	/* Reference-to-value type */
	typedef Reference	reference;
};
}

#endif
