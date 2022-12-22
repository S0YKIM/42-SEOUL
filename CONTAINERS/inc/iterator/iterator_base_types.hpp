/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_base_types.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:18:05 by sokim             #+#    #+#             */
/*   Updated: 2022/12/22 21:18:08 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_BASE_TYPES_HPP
# define ITERATOR_BASE_TYPES_HPP

# include <cstddef> // std::ptrdiff_t

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

/*
	Tags for iterator_traits
*/
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

/*
	Membergeneric definition
*/
template <typename Iter>
struct iterator_traits {
	typedef typename Iter::iterator_category	iterator_category;
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::pointer				pointer;
	typedef typename Iter::reference			reference;
};

/*
	T* specialization
*/
template <typename T>
struct iterator_traits<T *> {
	typedef typename random_access_iterator_tag	iterator_catogory;
	typedef typename T							value_type;
	typedef typename std::ptrdiff_t				difference_type;
	typedef typename T*							pointer;
	typedef typename T&							reference;
};

/*
	const T* specialization
*/
template <typename T>
struct iterator_traits<const T *> {
	typedef typename random_access_iterator_tag	iterator_catogory;
	typedef typename T							value_type;
	typedef typename std::ptrdiff_t				difference_type;
	typedef typename const T*					pointer;
	typedef typename const T&					reference;
};
}

#endif
