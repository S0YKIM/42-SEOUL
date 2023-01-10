/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:01 by sokim             #+#    #+#             */
/*   Updated: 2023/01/10 13:51:14 by sokim            ###   ########.fr       */
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
  // STRONG
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

  template <typename InputIterator>
  vector(typename enable_if<!is_integral<InputIterator>::value,
                            InputIterator>::type first,
         InputIterator last, const allocator type &a = allocator_type())
      : _base(a) {
    typedef typename iterator_traits<InputIterator>::iterator_category
        iterator_category;
    _range_initialize(first, last, iterator_category());
  }

  // NOTHROW
  /**
   * @brief Destructor of vector
   */
  ~vector() { _range_destroy(this->begin_, this->end_); }

  // TODO: operator = 구현
  vector &operator=(const vector &other);

  // TODO: assign() 구현
  void assign(size_type n, const T &value);

  // SECTION: Get allocator
  // NOTHROW
  /**
   * @brief Get a copy of the memory allocator object
   */
  allocator_type get_allocator() const { return this->alloc_; }
  // !SECTION

  // SECTION: Iterators
  // NOTHROW
  /**
   * @brief Returns a iterator that points to the first element in the vector.
   * Iteration is done in ordinary element order.
   *
   * @return Read/write iterator
   * @return Read-only (const) iterator
   */
  iterator begin() { return iterator(this->begin_); }

  const_iterator begin() const { return const_iterator(this->begin_); }

  // NOTHROW
  /**
   * @brief Returns a iterator that points to the one past the last element in
   * the vector. Iteration is done in ordinary element order.
   *
   * @return Read/write iterator
   * @return Read-only (const) iterator
   */
  iterator end() { return iterator(this->end_); }

  const_iterator end() const { return const_iterator(this->end_); }

  // NOTHROW
  /**
   * @brief Returns a reverse iterator that points to the last element in the
   * vector. Iteration is done in reverse element order.
   *
   * @return Read/write reverse iterator
   * @return Read-only (const) reverse iterator
   */
  reverse_iterator rbegin() { return reverse_iterator(end()); }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  // NOTHROW
  /**
   * @brief Returns reverse iterator that points to the one before the first
   * element in the vector. Iteration is done in reverse element order.
   *
   * @return Read/write reverse iterator
   * @return Read-only (const) reverse iterator
   */
  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }
  // !SECTION

  // SECTION: Size and capacity
  // NOTHROW
  /**
   * @brief Returns the number of elements in the vector.
   */
  size_type size() const { return size_type(end() - begin()); }

  // NOTHROW
  /**
   * @brief Returns the size of the largest possible vector.
   */
  size_type max_size() const { return this->alloc_.max_size(); }

  // TODO: resize() 구현
  void resize(size_type n, value_type value = value_type()) {}

  // NOTHROW
  /**
   * @brief The capacity including the extra space where memory is allocated but
   * no elements constructed yet.
   *
   * @return size_type The total number of elements that the vector can hold
   * before needing to allocate more memory.
   */
  size_type capacity() const {
    return size_type(const_iterator(this->end_of_capacity_) - begin());
  }

  // NOTHROW
  /**
   * @brief Returns true if the vector is empty.
   */
  bool empty() const { return begin() == end(); }

  // TODO: reserve() 구현
  void reserve(size_type n) {}
  // !SECTION

  // SECTION: Element access
  // NOTHROW: If n < size(). Otherwise, undefined behavior.
  /**
   * @brief Subscript access to the data contained in the vector.
   *
   * @return Read/write reference to data.
   * @return Read-only (constant) reference to data.
   *
   * It doens't check if the index is out of range or not. However, member
   * function at() provides range check.
   */
  reference operator[](size_type n) { return *(begin() + n); }

  const reference operator[](size_type n) const { return *(begin() + n); }

  // STRONG
  /**
   * @brief Provides access to the data contained in the vector.
   *
   * @return Read/write reference to data.
   * @return Read-only (constant) reference to data.
   *
   * Provides safer data access than operator [].
   */
  reference at(size_type n) {
    if (n >= size())
      throw std::out_of_range("ft::vector::at() n is out of range.");
    return (*this)[n];
  }

  const_reference at(size_type n) const {
    if (n >= size())
      throw std::out_of_range("ft::vector::at() n is out of range.");
    return (*this)[n];
  }

  // NOTHROW: If container is not empty. Otherwise, undefined behavior.
  /**
   * @brief Returns reference to the data at the first element of the vector.
   *
   * @return Read/write reference
   * @return Read-only reference
   */
  reference front() { return *begin(); }

  const_reference front() const { return *begin(); }

  // NOTHROW: If container is not empty. Otherwise, undefined behavior.
  /**
   * @brief Returns reference to the data at the last element of the vector.
   *
   * @return Read/write reference
   * @return Read-only reference
   */
  reference back() { return *(end() - 1); }

  const_reference back() const { return *(end() - 1); }

  // NOTHROW
  /**
   * @brief Returns a direct pointer to the memory array used interanally by the
   * vector to store its owned elements.
   *
   * @return Read/write pointer
   * @return Read-only (constant) pointer
   */
  value_type *data() { return begin_; }

  const value_type *data() const { return begin_; }
  // !SECTION

  // SECTION: Modifiers
  /**
   * @brief Inserts a number of copies of the given data into the vector.
   *
   * @param position The position where the elements will be inserted.
   * @param n Number of elements to be inserted.
   * @param value Data to be inserted.
   */
  void insert(iterator position, size_type n, const value_type &value) {
    // NOTHROW
    if (n == 0) return;

    size_type new_size = size() + n;

    // CASE 1: No reallocations needed to insert new elements.
    if (new_size <= capacity()) {
      // STRONG
      // CASE 1-1: Insert new elements at the end of the vector.
      if (position == end())
        this->end_ = std::uninitialized_fill_n(position, n, value);

      // BASIC
      // CASE 1-2: Insert new elements at the beginning or in the middle.
      else {
        this->end_ = std::uninitialized_copy(end() - n, end(), end());
        std::copy_backward(position, iterator(this->end_ - n * 2),
                           iterator(this->end_ - n));
        std::fill(position, position + n, value);
      }
    }

    // STRONG
    // CASE 2: Reallocations needed to insert new elements.
    else {
      const size_type old_capacity = capacity();
      const size_type new_capacity = old_capacity ? old_capacity * 2 : 1;
      if (new_capacity < new_size) new_capacity = new_size;
      iterator new_begin(alloc_.allocate(new_capacity));
      iterator new_end(new_begin);

      try {
        new_end = std::uninitialized_copy(begin(), position, new_begin);
        new_end = std::uninitialized_fill_n(new_end, n, value);
        new_end = std::uninitialized_copy(position, end(), new_end);
      } catch (...) {
        _range_destroy(new_begin, new_end);
        alloc_.deallocate(new_begin.base(), new_capacity);
        throw std::exception("ft::vector::insert() exception occured.");
      }
      _range_destroy(begin(), end());
      alloc_.deallocate(this->begin_, old_capacity);
      this->begin_ = new_begin.base();
      this->end_ = new_end().base();
      this->end_of_capacity_ = new_begin.base() + new_capacity;
    }
  }

  /**
   * @brief Inserts the given value into the vector.
   *
   * @param position The position where the value will be inserted.
   * @param value Data to be inserted.
   * @return iterator An iterator that points to the inserted data. It can be
   * changed from the original position if reallocation happened.
   */
  iterator insert(iterator position, const value_type &value) {
    difference_type n = position - begin();

    insert(position, 1, value);
    return begin() + n;
  }

  template <typename InputIterator>
  void insert(iterator position,
              typename enable_if<!is_integral<InputIterator>,
                                 InputIterator::value>::type first,
              InputIterator last) {
    typedef typename iterator_traits<InputIterator>::iterator_category
        iterator_category;
    if (first == last) return;
    _range_insert(position, first, last, iterator_category);
  }

  // NOTHROW: If the removed element is the last element.
  // BASIC: Otherwise, the vector is guaranteed to end in a valid state.
  // Undefined behavior if the position or range is invalid.
  /**
   * @brief Remove element at the given position.

   *
   * @param position Iterator pointing to the element to be erased.
   * @return iterator An iterator pointing to the next element.
   */
  iterator erase(iterator position) {
    if (position + 1 != end_) std::copy(position + 1, end(), position);
    --this->end_;
    alloc_.destroy(this->end_);
  }

  // NOTHROW: If the removed elements include the last element.
  // BASIC: Otherwise, the vector is guaranteed to end in a valid state.
  // Undefined behavior if the position or range is invalid.
  /**
   * @brief Remove a range of elements.
   *
   * @param first
   * @param last
   * @return iterator
   */
  iterator erase(iterator first, iterator last) {
    difference_type n = last - first;
    iterator end_of_copy = std::copy(last, end(), first);

    _range_destroy(end_of_copy, end());
    this->end_ = this->end - n;
    return first;
  }

  // NOTHROW
  /**
   * @brief Removes all the elements.
   */
  void clear() { erase(begin_, end_); }

  // STRONG
  /**
   * @brief Add a single element to the end of the vector.
   *
   * @param value Data to be added.
   */
  void push_back(const value_type &value) {
    // Case 1: There is enough capacity left to add the data.
    // Case 2: Reallocation is needed to add the data.
    insert(end(), value);
  }

  // NOTHROW: If the vector is not empty. Otherwise, undefined behavior.
  /**
   * @brief Removes the last element.
   */
  void pop_back() { erase(this->end_ - 1); }

  /**
   * @brief Resizes the vector to the specified number of elements.
   *
   * @param new_size Number of elements the vector should contain.
   * @param value Data with which new elements should be populated.
   */
  void resize(size_type new_size, value_type value = value_type()) {
    if (new_size < size())
      erase(this->begin_ + new_size, this->end_);
    else
      insert(this->end_, new_size - size(), value);
  }

  // NOTHROW if the allocators in both vectors compare equal.
  // Otherwise, it causes undefined behavior.
  /**
   * @brief Swaps data with another vector.
   */
  void swap(vector &other) {
    this->begin_ = other.begin_;
    this->end_ = other.end_;
    this->end_of_capacity_ = other.end_of_capacity_;
  }
  // !SECTION

 private:
  /**
   * @brief Destroy the objects in the range of [first, last).
   *
   * @tparam ForwardIterator
   * @param first
   * @param last
   */
  template <typename ForwardIterator>
  void _range_destroy(ForwardIterator first, ForwardIterator last) {
    for (; first != last; ++first) alloc_.destroy(first);
  }

  /**
   * @brief Initialize values of elements in range constructor.
   *
   * @tparam InputIterator Only input iterator calls this function
   * @param first
   * @param last
   */
  template <typename InputIterator>
  void _range_initialize(InputIterator first, InputIterator last,
                         input_iterator_tag) {
    for (; first != last; ++first) push_back(*first);
  }

  /**
   * @brief Initialize values of elements in range constructor.
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

  /**
   * @brief Insert elements from first to last in the vector.
   *
   * @tparam InputIterator Only input iterator calls this function
   * @param position The position where the elements are inserted
   * @param first
   * @param last
   */
  template <typename InputIterator>
  void _range_insert(iterator position, InputIterator first, InputIterator last,
                     input_iterator_tag) {
    for (; first != last; ++first) {
      position = insert(position, *first);
      ++position;
    }
  }

  /**
   * @brief Insert elements from first to last in the vector.
   *
   * @tparam ForwardIterator Forward iterator or its derived classes
   * @param position The position where the elements are inserted
   * @param first
   * @param last
   */
  template <typename ForwardIterator>
  void _range_insert(iterator position, ForwardIterator first,
                     ForwardIterator last, forward_iterator_tag) {
    difference_type n = std::distance(first, last);
    size_type new_size = size() + n;

    // CASE 1: No reallocations needed to insert new elements.
    if (new_size <= capacity()) {
      // STRONG
      // CASE 1-1: Insert new elements at the end of the vector.
      if (position == end())
        this->end_ = std::uninitialized_copy(first, last, position);

      // BASIC
      // CASE 1-2: Insert new elements at the beginning or in the middle.
      else {
        this->end_ = std::uninitialized_copy(end() - n, end(), end());
        std::copy_backward(position, iterator(this->end_ - n * 2),
                           iterator(this->end_ - n));
        std::copy(first, last, position);
      }
    }

    // STRONG
    // CASE 2: Reallocations needed to insert new elements.
    else {
      const size_type old_capacity = capacity();
      const size_type new_capacity = old_capacity ? old_capacity * 2 : 1;
      if (new_capacity < new_size) new_capacity = new_size;
      iterator new_begin(alloc_.allocate(new_capacity));
      iterator new_end(new_begin);

      try {
        new_end = std::uninitialized_copy(begin(), position, new_begin);
        new_end = std::uninitialized_copy(first, last, new_end);
        new_end = std::uninitialized_copy(position, end(), new_end);
      } catch (...) {
        _range_destroy(new_begin, new_end);
        alloc_.deallocate(new_begin.base(), new_capacity);
        throw std::exception("ft::vector::insert() exception occured.");
      }
      _range_destroy(begin(), end());
      alloc_.deallocate(this->begin_, old_capacity);
      this->begin_ = new_begin.base();
      this->end_ = new_end().base();
      this->end_of_capacity_ = new_begin.base() + new_capacity;
    }
  }
};
}  // namespace ft

#endif
