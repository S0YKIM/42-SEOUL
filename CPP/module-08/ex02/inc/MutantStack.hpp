/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:00:24 by sokim             #+#    #+#             */
/*   Updated: 2022/07/14 14:22:18 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}
	MutantStack(const MutantStack &origin) { *this = origin; }
	MutantStack &operator=(const MutantStack &origin) {
		if (this != &origin)
			std::stack<T>::opertator=(origin);
		return (*this);
	}
	~MutantStack() {}
	
	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	iterator	begin() { return this->c.begin(); }
	iterator	end() { return this->c.end(); }

	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	const_iterator	cbegin() const { return this->c.begin(); }
	const_iterator	cend() const { return this->c.begin(); }

	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	reverse_iterator	rbegin() { return this->c.rbegin(); }
	reverse_iterator	rend() { return this->c.rend(); }

	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator	crbegin() const { return this->c.rbegin(); }
	const_reverse_iterator	crend() const { return this->c.crend(); }
};

#endif
