/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:11:36 by sokim             #+#    #+#             */
/*   Updated: 2022/12/26 13:47:09 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_base_types.hpp"

namespace ft {
/* std::allocator::pointer (ex. int *) */
template <typename Iter>
class vector_iterator {
public:
	typedef typename iterator_traits<Iter>		traits;

	typedef typename traits::iterator_category	itertator_category;
	typedef typename traits::value_type			value_type;
	typedef typename traits::difference_type	difference_type;
	typedef typename traits::pointer			pointer;
	typedef typename traits::reference			reference;

private:
	Iter	current_;

public:
	/* Default constructor */
	vector_iterator() {}

	explicit vector_iterator(const Iter &current) : current_(current) {}

	/* Copy constructor */
	template <typename I1>
	inline vector_iterator(const vector_iterator<I1> &other) : current_(other.base()) {}

	/* Getter function for current */
	const Iter &base() const { return current_; }

	/* Forward iterator requirements */
	reference operator *() const { return *current_; }
	pointer operator->() const { return current_; }
	vector_iterator &operator++() {
		++current_;
		return *this;
	}
	vector_iterator operator++(int) {
		vector_iterator	tmp;

		tmp(current_++);
		return tmp;
	}

	/* Bidirectional iterator requirements */
	vector_iterator &operator--() {
		--current_;
		return *this;
	}
	vector_iterator oprator--(int) {
		vector_iterator	tmp;

		tmp(current_--);
		return tmp;
	}
	
};
}
#endif
