/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:56:59 by sokim             #+#    #+#             */
/*   Updated: 2022/07/14 14:34:46 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

class Span {
private:
	std::vector<int>	container_;
	unsigned int		maxsize_;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &origin);
	Span &operator=(const Span &origin);
	~Span();

	const std::vector<int>	&getContainer() const;
	const unsigned int		&getMaxsize() const;

	void					addNumber(int num);
	void					addNumbers(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end);
	
	unsigned int			shortestSpan() const;
	unsigned int			longestSpan() const;

	class NotFoundException : public std::exception {
	public:
		const char	*what() const throw();
	};

	class FullException : public std::exception {
	public:
		const char	*what() const throw();
	};
};

#endif
