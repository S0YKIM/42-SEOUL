/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:14:01 by sokim             #+#    #+#             */
/*   Updated: 2022/07/13 10:56:23 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T &a, T &b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	max(T &a, T &b) {
	if (a > b)
		return (a);
	return (b);
}

#endif
