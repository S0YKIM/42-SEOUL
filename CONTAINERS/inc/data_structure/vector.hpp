/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:01 by sokim             #+#    #+#             */
/*   Updated: 2023/01/03 13:58:30 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"

namespace ft {
template <typename T, typename Allocator>
class vector_base {
 protected:
  typedef typename Allocator::pointer pointer;

  Allocator alloc_;
  pointer start_;
  pointer end_;
  pointer end_of_capacity_;

  vector_base(const Allocator &a)
      : alloc_(a), start_(0), end_(0), end_of_capacity_(0) {}

  vector_base(const Allocator &a, size_t n)
      : alloc_(a),
        start_(alloc_.allocate(n)),
        end_(start_),
        end_of_capacity_(start_ + n) {}

  ~vector_base() {
    if (start_) alloc.deallocate(start_, end_of_capacity_ - start_);
  }
};

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  typedef Allocator<T> allocator_type;

  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef vector_iterator<pointer> iterator;
  typedef vector_iterator<const_pointer> const_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;
  typedef reverse_iterator<const_iterator> const_reverse_iterator;

  typedef ptrdiff_t difference_type;
  typedef size_t size_type;
};
}  // namespace ft

#endif
