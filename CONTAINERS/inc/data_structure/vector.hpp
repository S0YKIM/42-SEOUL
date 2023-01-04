/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:01 by sokim             #+#    #+#             */
/*   Updated: 2023/01/04 15:32:07 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "vector_iterator.hpp"

namespace ft {
template <typename T, typename Allocator>
class vector_base {
 public:
  typedef Allocator allocator_type;
  typedef typename allocator_type::pointer pointer;

 protected:
  allocator_type _alloc;
  pointer _begin;
  pointer _end;
  pointer _end_of_capacity_;

  /**
   * @brief Default constructor allocates no storage
   */
  vector_base(const Allocator &a)
      : _alloc(a), _begin(nullptr), _end(nullptr), _end_of_capacity_(nullptr) {}

  /**
   * @brief Allocate storage of n size
   *
   * @param n The size of storage to allocate
   */
  vector_base(const Allocator &a, size_t n)
      : _alloc(a),
        _begin(_alloc.allocate(n)),
        _end(_begin),
        _end_of_capacity_(_begin + n) {}

  /**
   * @brief Deallocate the storage of vector
   */
  ~vector_base() {
    if (_begin) alloc.deallocate(_begin, _end_of_capacity_ - _begin);
  }
};

template <typename T, typename Allocator = std::allocator<T> >
class vector : private vector_base<T, Allocator> {
 private:
  vector_base<T, Allocator> _base;
  vector<T, Allocator> _self;

 public:
  typedef T value_type;
  typedef Allocator allocator_type;

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

 public:
  /**
   * @brief Default constructor creates no elements
   */
  explicit vector(const allocator_type &a = allocator_type()) : _base(a) {}

  /**
   * @brief Create a vector with copies of an exemplar element
   *
   * @param n The number of elements to initially create
   * @param value An element to copy
   */
  explicit vector(size_type n, const value_type &value = value_type(),
                  const allocator_type &a = allocator_type())
      : _base(a, n) {
    this->_end = std::uninitialized_fill_n(this->_begin, n, value);
  }

  // TODO: getAlloc(), size() 구현
  /**
   * @brief Copy constructor of vector
   *
   * The size of storage will be the size of the source vector, not the capacity
   * of it. Therefore any extra memory in the source vector will not be copied.
   */
  vector(const vector &other) : _base(other.getAlloc(), other.size()) {
    this->_end =
        std::uninitialzied_copy(other.begin(), other.end(), this->_begin);
  }

  // TODO: is_integral, enable_if 클래스 구현
  // TODO: range constructor 마저 구현
  template <typename InputIterator>
  vector(typename enable_if<!is_integral<InputIterator>::value,
                            InputIterator>::type first,
         InputIterator last, const allocator type &a = allocator_type())
      : _base(a) {
    typedef typename iterator_traits<InputIterator>::iterator_category
        iterator_category;
    _range_initialize(first, last, iterator_category);
  }

  ~vector() { std::destroy(this->_begin, this->_end); }

 private:
  // TODO: InputIterator 범위 생성자 구현
  template <typename InputIerator>
  void _range_initialize(InputIterator first, InputIterator last,
                         input_iterator_tag) {}

  // TODO: ForwardIterator 범위 생성자 구현
  template <typename ForwardIterator>
  void _range_initialize(ForwardIterator first, ForwardIterator last,
                         forward_iterator_tag) {}
};
}  // namespace ft

#endif
