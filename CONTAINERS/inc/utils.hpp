/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:18:05 by sokim             #+#    #+#             */
/*   Updated: 2022/12/15 16:45:47 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

/* 
	Membergeneric definition
*/
template <class Iter>
struct iterator_traits {
	typedef typename Iter::iterator_category iterator_category;
	typedef typename Iter::value_type value_type;
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
};

/*
	T* specialization
*/
template <class T>
struct iterator_traits<T *> {
	typedef typename random_access_iterator_tag iterator_catogory;
	typedef typename T value_type;
	typedef typename ptrdiff_t difference_type;
	typedef typename T* pointer;
	typedef typename T& reference;
};

/*
	const T* specialization
*/
template <class T>
struct iterator_traits<const T *> {
	typedef typename random_access_iterator_tag iterator_catogory;
	typedef typename T value_type;
	typedef typename ptrdiff_t difference_type;
	typedef typename const T* pointer;
	typedef typename const T& reference;
};

#endif
