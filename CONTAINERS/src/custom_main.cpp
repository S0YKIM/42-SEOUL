/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:30:21 by sokim             #+#    #+#             */
/*   Updated: 2022/12/17 16:17:36 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>

#include <stdlib.h>

#include <stack.hpp>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
#define COUNT 10

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c_ = rhs.c_;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c_.begin(); }
	iterator end() { return this->c_.end(); }
};

int main() {
	ft::stack<int>							stack_int;
	ft::stack<Buffer, std::deque<Buffer> >	stack_deq_buffer;
	MutantStack<char>						iterable_stack;
	Buffer									buf;

	std::cout << "********** Int stack **********" << std::endl;
	for (int i = 1; i <= 10; i++)
		stack_int.push(i);
	for (int idx = 0; idx < 10; idx++)
	{
		std::cout << stack_int.top() << std::endl;
		stack_int.pop();
	}
	std::cout << std::endl;

	std::cout << "********** User defined buffer stack **********" << std::endl;
	for (int idx = 0; idx < 10; idx++) {
		int	i;
		for (i = 0; i < idx; i++)
			buf.buff[i] = i + 'a';
		buf.buff[i] = '\0';
		buf.idx = idx;
		stack_deq_buffer.push(buf);
	}
	for (int idx = 0; idx < 10; idx++)
	{
		std::cout << stack_deq_buffer.top().buff << std::endl;
		stack_deq_buffer.pop();
	}
	std::cout << std::endl;

	std::cout << "********** Iterable char stack **********" << std::endl;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}
