/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:49:23 by sokim             #+#    #+#             */
/*   Updated: 2022/12/17 14:09:19 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <vector.hpp>
# include <stack>

namespace ft {
template <typename T, typename Container = ft::vector<T>>
class stack {
public:
	typedef typename Container					container_type;
	typedef typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;

protected:
	Container	c_;

public:
	/* Default constructor or copy constructor */
	explicit stack(const Container& c = Container()) : c_(c) {};

	/* Returns a read/write reference to the data at the first element of the stack */
	reference	top() { return c.back(); };

	/* Returns a read-only constant reference to the data at the first element of the stack */
	const_reference	top() const { return c.back(); };
};
}

#endif
