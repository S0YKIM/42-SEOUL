/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:11:36 by sokim             #+#    #+#             */
/*   Updated: 2022/12/22 22:00:53 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_base_types.hpp"

namespace ft {
template <typename Iter>
class vector_iterator {
public:
	/* std::allocator::pointer (ex. int *) */
	typedef Iter														iterator_type;
	typedef typename iterator_traits<iterator_type>::iterator_category	itertator_category;
	typedef typename iterator_traits<iterator_type>::value_type			value_type;
	typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
	typedef typename iterator_traits<iterator_type>::pointer			pointer;
	typedef typename iterator_traits<iterator_type>::reference			reference;

private:
	iterator_type	it_;

public:
	/* Default constructor */
	vector_iterator() {}
	
};
}

#endif
