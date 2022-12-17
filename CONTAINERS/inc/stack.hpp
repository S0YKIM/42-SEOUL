/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:49:23 by sokim             #+#    #+#             */
/*   Updated: 2022/12/17 19:57:51 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <vector>
# include <vector.hpp>
# include <stack>

namespace ft {
template <typename T, typename Container = std::vector<T> >
class stack;

template <typename T, typename Container>
inline bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs);

template <typename T, typename Container>
inline bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs);

template <typename T, typename Container>
class stack {
public:
	template <typename T1, typename C1>
	friend bool operator==(const ft::stack<T1, C1>& lhs, const ft::stack<T1, C1>& rhs);

	template <typename T1, typename C1>
	friend bool operator< (const ft::stack<T1, C1>& lhs, const ft::stack<T1, C1>& rhs);

	typedef Container							container_type;
	typedef typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;

protected:
	Container	c_;

public:
	/* Default constructor or copy constructor */
	explicit stack(const container_type& c = container_type()) : c_(c) {}

	/* Returns a read/write reference to the data at the first element of the stack */
	reference top() { return c_.back(); }

	/* Returns a read-only constant reference to the data at the first element of the stack */
	const_reference top() const { return c_.back(); }

	/* Returns true if the stack is empty */
	bool empty() const { return c_.empty(); }

	/* Returns the number of elements in the stack */
	size_type size() const { return c_.size(); }

	/* Creates an element at the top of the stack and assigns the given data to it */
	void push(const value_type& value) { c_.push_back(value); }

	/* Removes the top element from the stack */
	void pop() { c_.pop_back(); }
};

template <typename T, typename Container>
inline bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return lhs.c_ == rhs.c_; }

template <typename T, typename Container>
inline bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return lhs.c_ < rhs.c_; }

template <typename T, typename Container>
inline bool operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return !(lhs == rhs); }

template <typename T, typename Container>
inline bool operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return !(rhs < lhs); }

template <typename T, typename Container>
inline bool operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return rhs < lhs; }

template <typename T, typename Container>
inline bool operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return !(lhs < rhs); }
} // namespace ft

#endif
