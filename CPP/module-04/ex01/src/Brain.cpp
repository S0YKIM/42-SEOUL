/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:27:56 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 14:37:40 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &origin) {
	std::cout << "Brain copy constructor called." << std::endl;
	*this = origin;
}

Brain &Brain::operator=(const Brain &origin) {
	std::cout << "Brain assignment operator called." << std::endl;
	if (this == &origin)
		return (*this);
	for (int i = 0; i < 100; i++) {
		setIdea(i, origin.getIdea(i));
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

std::string	Brain::getIdea(int idx) const {
	return (ideas[idx]);
}

void	Brain::setIdea(int idx, std::string idea) {
	ideas[idx] = idea;
}
