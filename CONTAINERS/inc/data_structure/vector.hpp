/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:01 by sokim             #+#    #+#             */
/*   Updated: 2023/01/06 12:10:05 by sokim            ###   ########.fr       */
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
  /**
   * @brief Get a copy of the memory allocator object
   */
  allocator_type get_allocator() const { return this->alloc_; }

  /**
   * @brief Returns a read/write iterator that points to the first element in
   * the vector. Iteration is done in ordinary element order.
   */
  iterator begin() { return iterator(this->begin_); }

  /**
   * @brief Returns a read-only (constant) iterator that points to the first
   * element in the vector. Iteration is done in ordinary element order.
   */
  const_iterator begin() const { return const_iterator(this->begin_); }

  /**
   * @brief Returns a read/write iterator that points to the one past the last
   * element in the vector. Iteration is done in ordinary element order.
   */
  iterator end() { return iterator(this->end_); }

  /**
   * @brief Returns a read-only iterator that points to the one past the last
   * element in the vector. Iteration is done in ordinary element order.
   */
  const_iterator end() const { return const_iterator(this->end_); }

  /**
   * @brief Returns a read/write reverse iterator that points to the last
   * element in the vector. Iteration is done in reverse element order.
   */
  reverse_iterator rbegin() { return reverse_iterator(end()); }

  /**
   * @brief Returns a read-only reverse iterator that points to the last
   * element in the vector. Iteration is done in reverse element order.
   */
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  /**
   * @brief Returns a read/write reverse iterator that points to one before the
   * first element in the vector. Iteration is done in reverse element order.
   */
  reverse_iterator rend() { return reverse_iterator(begin()); }

  /**
   * @brief Returns a read-only (const) reverse iterator that points to one
   * before the first element in the vector. Iteration is done in reverse
   * element order.
   */
  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }
  // !SECTION

  // SECTION: Size and capacity
  /**
   * @brief Returns the number of elements in the vector.
   */
  size_type size() const { return size_type(end() - begin()); }

  /**
   * @brief Returns the size of the largest possible vector.
   */
  size_type max_size() const { return this->alloc_.max_size(); }

  /**
   * @brief Returns the total number of elements that the vector can hold before
   * needing to allocate more memory. The extra space where memory is allocated
   * but no elements constructed yet.
   */
  size_type capacity() const {
    return size_type(const_iterator(this->end_of_capacity_) - begin());
  }

  /**
   * @brief Returns true if the vector is empty.
   */
  bool empty() const { return begin() == end(); }
  // !SECTION

  // SECTION: Access to element
  /**
   * @brief Subscript access to the data contained in the vector.
   *
   * @return Read/write reference to data.
   *
   * It doens't check if the index is out of range or not. However, member
   * function at() provides range check.
   */
  reference operator[](size_type n) { return *(begin() + n); }

  /**
   * @brief Subscript access to the data contained in the vector.
   *
   * @return Read-only (constant) reference to data.
   *
   * It doens't check if the index is out of range or not. However, member
   * function at() provides range check.
   */
  const reference operator[](size_type n) const { return *(begin() + n); }

  /**
   * @brief Provides access to the data contained in the vector.
   *
   * @return Read/write reference to data.
   *
   * Provides safer data access than operator [].
   */
  reference at(size_type n) {
    if (n >= size())
      throw std::out_of_range("ft::vector::at() n is out of range.");
    return (*this)[n];
  }

  /**
   * @brief Provides access to the data contained in the vector.
   *
   * @return Read-only (constant) reference to data.
   *
   * Provides safer data access than operator [].
   */
  const_reference at(size_type n) const {
    if (n >= size())
      throw std::out_of_range("ft::vector::at() n is out of range.");
    return (*this)[n];
  }

  /**
   * @brief Returns a read/write reference to the data at the first element of
   * the vector.
   */
  reference front() { return *begin(); }

  /**
   * @brief Returns a read-only (constant) reference to the data at the first
   * element of the vector.
   */
  const_reference front() const { return *begin(); }

  /**
   * @brief Returns a read/write reference to the data at the last element of
   * the vector.
   */
  reference back() { return *(end() - 1); }

  /**
   * @brief Returns a read-only (constant) reference to the data at the last
   * element of the vector.
   */
  const_reference back() const { return *(end() - 1); }

  // NOTHROW
  /**
   * @brief Returns a direct pointer(read/write) to the memory array used
   * interanally by the vector to store its owned elements.
   */
  value_type *data() { return begin_; }

  // NOTHROW
  /**
   * @brief Returns a direct pointer(read-only) to the memory array used
   * interanally by the vector to store its owned elements.
   */
  const value_type *data() const { return begin_; }
  // !SECTION

  // !SECTION
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
