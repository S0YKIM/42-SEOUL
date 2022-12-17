/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:49:23 by sokim             #+#    #+#             */
/*   Updated: 2022/12/17 13:48:00 by sokim            ###   ########.fr       */
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

public:
	/* Default constructor or copy constructor */
	explicit stack(const Container& cont = Container()) {};

	/* Copy constructor */
	stack(const stack& other) {};

	/* Copy assignment operator overloading */
	stack& operator=(const stack& other) {};

	/* Destructor */
	~stack() {};
};
}

#endif
