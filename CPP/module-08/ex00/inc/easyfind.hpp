/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:46:28 by sokim             #+#    #+#             */
/*   Updated: 2022/07/14 10:53:48 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception {
public:
	const char	*what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &container, int target) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif
