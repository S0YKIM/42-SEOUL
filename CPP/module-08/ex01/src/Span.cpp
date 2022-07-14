/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:56:54 by sokim             #+#    #+#             */
/*   Updated: 2022/07/14 14:38:16 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : container_(0, 0), maxsize_(0) {}

Span::Span(unsigned int n) : container_(0, 0), maxsize_(n) {}

Span::Span(const Span &origin) {
	*this = origin;
}

Span &Span::operator=(const Span &origin) {
	container_ = origin.getContainer();
	maxsize_ = origin.getMaxsize();
	return (*this);
}

Span::~Span() {}

const std::vector<int>	&Span::getContainer() const {
	return (container_);
}

const unsigned int	&Span::getMaxsize() const {
	return (maxsize_);
}

void	Span::addNumber(int num) {
	if (container_.size() == maxsize_)
		throw	FullException();
	container_.push_back(num);
}

void	Span::addNumbers(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end) {
	for (std::vector<int>::iterator it = begin; it != end; it++) {
		if (container_.size() == maxsize_)
			throw	FullException();
		container_.push_back(*it);
	}
}

// 간격의 차이가 가장 작은 숫자들 간의 간격
unsigned int	Span::shortestSpan() const {
	if (container_.size() < 2)
		throw NotFoundException();
	
	int							result = INT_MAX;
	std::vector<int>			tmp = container_;
	std::vector<int>::iterator	it = tmp.begin();

	std::sort(tmp.begin(), tmp.end());
	while (it != tmp.end() - 1) {
		result = std::min(result, *(it + 1) - *it);
		it++;
	}
	return (result);
}

// 간격의 차이가 가장 큰 숫자들 간의 간격
unsigned int	Span::longestSpan() const {
	if (container_.size() < 2)
		throw NotFoundException();

	std::vector<int>	tmp = container_;
	int					result;

	std::sort(tmp.begin(), tmp.end());
	result = tmp.back() - tmp.front();
	return (result);
}

const char	*Span::NotFoundException::what() const throw() {
	return ("Couldn't find the span.");
}

const char	*Span::FullException::what() const throw() {
	return ("The container is already full.");
}
