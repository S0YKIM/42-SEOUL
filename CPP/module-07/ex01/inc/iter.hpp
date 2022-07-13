/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:01:30 by sokim             #+#    #+#             */
/*   Updated: 2022/07/13 11:18:15 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, size_t len, void (*f)(T)) {
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void	iter(T *array, size_t len, void (*f)(T &)) {
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void	iter(T *array, size_t len, void (*f)(const T &)) {
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif
