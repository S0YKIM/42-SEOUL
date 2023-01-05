/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:01 by sokim             #+#    #+#             */
/*   Updated: 2023/01/05 16:03:24 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

#include "reverse_iterator.hpp"  // reverse_iterator
#include "type_traits.hpp"       // is_integral, enable_if
#include "vector_iterator.hpp"   // vector_iterator

namespace ft {
template <typename T, typename Allocator>
class vector_base {
 public:
  typedef Allocator allocator_type;
  typedef typename allocator_type::pointer pointer;

 protected:
  allocator_type alloc_;
  pointer begin_;
  pointer end_;
  pointer end_of_capacity_;

  /**
   * @brief Default constructor allocates no storage
   */
  vector_base(const Allocator &a)
      : alloc_(a), begin_(0), end_(0), end_of_capacity_(0) {}

  /**
   * @brief Allocate storage of n size
   *
   * @param n The size of storage to allocate
   */
  vector_base(const Allocator &a, size_t n)
      : alloc_(a),
        begin_(alloc_.allocate(n)),
        end_(begin_),
        end_of_capacity_(begin_ + n) {}

  /**
   * @brief Deallocate the storage of vector
   */
  ~vector_base() {
    if (begin_) alloc.deallocate(begin_, end_of_capacity_ - begin_);
  }
};

template <typename T, typename Allocator = std::allocator<T> >
class vector : private vector_base<T, Allocator> {
 private:
  typedef vector_base<T, Allocator> _base;
  typedef vector<T, Allocator> _self;

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
    this->end_ = std::uninitialized_fill_n(this->begin_, n, value);
  }

  // TODO: getAlloc(), size() 구현
  /**
   * @brief Copy constructor of vector
   *
   * The size of storage will be the size of the source vector, not the capacity
   * of it. Therefore any extra memory in the source vector will not be copied.
   */
  vector(const vector &other) : _base(other.getAlloc(), other.size()) {
    this->end_ =
        std::uninitialzied_copy(other.begin(), other.end(), this->begin_);
  }

  // TODO: range constructor 마저 구현
  template <typename InputIterator>
  vector(typename enable_if<!is_integral<InputIterator>::value,
                            InputIterator>::type first,
         InputIterator last, const allocator type &a = allocator_type())
      : _base(a) {
    typedef typename iterator_traits<InputIterator>::iterator_category
        iterator_category;
    _range_initialize(first, last, iterator_category());
  }

  ~vector() { std::destroy(this->begin_, this->end_); }

  // SECTION: Getter functions
  allocator_type get_allocator() const { return this->alloc_; }

  iterator begin() { return iterator(this->begin_); }

  const_iterator begin() const { return const_iterator(this->begin_); }

  iterator end() { return ierator(this->end_); }
  // TODO: operator = 구현
  vector &operator=(const vector &other);

 private:
  // TODO: push_back() 구현
  /**
   * @brief Initialize values of elements in range constructor
   *
   * @tparam InputIterator Only input iterator can call this function
   * @param first
   * @param last
   */
  template <typename InputIterator>
  void _range_initialize(InputIterator first, InputIterator last,
                         input_iterator_tag) {
    for (; first != last; ++first) push_back(*first);
  }

  /**
   * @brief Initialize values of elements in range constructor
   *
   * @tparam ForwardIterator Forward iterator or its derived classes
   * @param first
   * @param last
   */
  template <typename ForwardIterator>
  void _range_initialize(ForwardIterator first, ForwardIterator last,
                         forward_iterator_tag) {
    size_type n = std::distance(first, last);
    this->begin_ = alloc_.allocate(n);
    this->end_of_capacity_ = this->begin_ + n;
    this->end_ = std::uninitialized_copy(first, last, this->_begin);
  }
};
}  // namespace ft

#endif
