/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:18:05 by sokim             #+#    #+#             */
/*   Updated: 2022/12/22 15:48:58 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef> // std::ptrdiff_t

namespace ft {
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
