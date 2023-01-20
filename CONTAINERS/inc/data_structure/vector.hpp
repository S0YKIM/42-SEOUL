/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:01 by sokim             #+#    #+#             */
/*   Updated: 2023/01/20 15:41:41 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
// std::allocator<T>::construct, destroy
// std::uninitialized_fill, std::uninitialized_fill_n
// std::uninitialized_copy, std::uninitialized_copy_n
#include <algorithm>
// std::fill, std::fill_n
// std::copy, std::copy_backward
// std::lexicographical_compare
#include "algorithm.hpp"         // ft::equal
#include "reverse_iterator.hpp"  // reverse_iterator
#include "type_traits.hpp"       // is_integral, enable_if
#include "vector_iterator.hpp"   // vector_iterator

namespace ft {
template <typename T, typename Allocator>
class _vector_base {
 public:
  typedef Allocator allocator_type;
  typedef typename allocator_type::pointer pointer;

 protected:
  allocator_type _alloc;
  pointer _begin;
  pointer _end;
  pointer _end_of_capacity;

  /**
   * @brief Default constructor allocates no storage
   */
  _vector_base(const Allocator &a)
      : _alloc(a), _begin(0), _end(0), _end_of_capacity(0) {}

  /**
   * @brief Allocate storage of n size
   *
   * @param n The size of storage to allocate
   */
  _vector_base(const Allocator &a, size_t n)
      : _alloc(a),
        _begin(_alloc.allocate(n)),
        _end(_begin),
        _end_of_capacity(_begin + n) {}

  /**
   * @brief Deallocate the storage of vector
   */
  ~_vector_base() {
    if (_begin) _alloc.deallocate(_begin, _end_of_capacity - _begin);
  }
};  // class _vector_base

template <typename T, typename Allocator = std::allocator<T> >
class vector : private _vector_base<T, Allocator> {
 private:
  typedef _vector_base<T, Allocator> _base;
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
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

 public:
  // STRONG
  // Undefined behavior if allocator_traits::construct is not supported with the
  // apporpriate arguments for the element constructions.
  /**
   * @brief Default constructor creates no elements
   */
  explicit vector(const allocator_type &a = allocator_type()) : _base(a) {}

  // STRONG
  /**
   * @brief Creates a vector with copies of an exemplar element.
   *
   * @param n The number of elements to initially create
   * @param value An element to copy
   */
  explicit vector(size_type n, const value_type &value = value_type(),
                  const allocator_type &a = allocator_type())
      : _base(a, n) {
    this->_end = std::uninitialized_fill_n(this->_begin, n, value);
  }

  // STRONG
  /**
   * @brief Copy constructor of vector
   *
   * The size of storage will be the size of the source vector, not the capacity
   * of it. Therefore any extra memory in the source vector will not be copied.
   */
  vector(const vector &other) : _base(other.get_allocator(), other.size()) {
    this->_end =
        std::uninitialized_copy(other.begin(), other.end(), this->_begin);
  }

  // STRONG
  // Undefined behavior if the range specifed by [first, last) is not valid.
  template <typename InputIterator>
  vector(typename enable_if<!is_integral<InputIterator>::value,
                            InputIterator>::type first,
         InputIterator last, const allocator_type &a = allocator_type())
      : _base(a) {
    typedef typename iterator_traits<InputIterator>::iterator_category
        iterator_category;
    _range_initialize(first, last, iterator_category());
  }

  // NOTHROW
  /**
   * @brief Destructor of vector
   */
  ~vector() { _range_destroy(begin(), end()); }

  // BASIC
  // Undefined behavior if value_type is not copy assignable.
  vector &operator=(const vector &other) {
    if (this != &other) assign(other.begin(), other.end());
    return *this;
  }

  // BASIC
  // Undefined behavior if allocator_traits::construct is not supported.
  /**
   * @brief Assigns new contents to the vector.
   *
   * @param n Number of elements to be assigned
   * @param value Value to be assigned
   *
   * Replaces its current contents with new contents, and modifies its size
   * accordingly.
   */
  void assign(size_type n, const T &value) {
    if (n > capacity()) {
      vector tmp(n, value);

      swap(tmp);
    } else if (n > size()) {
      std::fill(begin(), end(), value);
      this->_end = std::uninitialized_fill_n(this->_end, n - size(), value);
    } else {
      std::fill_n(this->_begin, n, value);
      erase(begin() + n, end());
    }
  }

  // BASIC
  template <class InputIterator>
  void assign(typename enable_if<!is_integral<InputIterator>::value,
                                 InputIterator>::type first,
              InputIterator last) {
    typedef typename iterator_traits<InputIterator>::iterator_category
        iterator_category;

    _range_assign(first, last, iterator_category());
  }

  // SECTION: Get allocator
  // NOTHROW
  /**
   * @brief Get a copy of the memory allocator object
   */
  allocator_type get_allocator() const { return this->_alloc; }
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
  iterator begin() { return iterator(this->_begin); }

  const_iterator begin() const { return const_iterator(this->_begin); }

  // NOTHROW
  /**
   * @brief Returns a iterator that points to the one past the last element in
   * the vector. Iteration is done in ordinary element order.
   *
   * @return Read/write iterator
   * @return Read-only (const) iterator
   */
  iterator end() { return iterator(this->_end); }

  const_iterator end() const { return const_iterator(this->_end); }

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
  size_type max_size() const { return this->_alloc.max_size(); }

  // NOTHROW
  /**
   * @brief The capacity including the extra space where memory is allocated but
   * no elements constructed yet.
   *
   * @return size_type The total number of elements that the vector can hold
   * before needing to allocate more memory.
   */
  size_type capacity() const {
    return size_type(const_iterator(this->_end_of_capacity) - begin());
  }

  // NOTHROW
  /**
   * @brief Returns true if the vector is empty.
   */
  bool empty() const { return begin() == end(); }

  // STRONG: If no reallocations happen or if the type of the elements has
  // either a non-thrwoing move constructor or a copy constructor.
  // BASIC: Otherwise, the vector is guaranteed to end in a valid state.
  /**
   * @brief Preallocate enough memory for specifed number of elements.
   *
   * @param n Number of elements required.
   */
  void reserve(size_type n) {
    if (n > max_size())
      throw std::length_error(
          "ft::vector::reserve() Cannot reserve more than max size.");
    if (n > capacity()) {
      vector tmp;

      tmp._begin = tmp._alloc.allocate(n);
      tmp._end_of_capacity = tmp._begin + n;
      tmp._end = std::uninitialized_copy(this->_begin, this->_end, tmp._begin);
      swap(tmp);
    }
  }
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

  const_reference operator[](size_type n) const { return *(begin() + n); }

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
  value_type *data() { return this->_begin; }

  const value_type *data() const { return this->_begin; }
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

    // typename iterator_traits<iterator>::value_type v;

    // CASE 1: No reallocations needed to insert new elements.
    if (new_size <= capacity()) {
      // STRONG
      // CASE 1-1: Insert new elements at the end of the vector.
      if (position == end()) {
        std::uninitialized_fill_n(position, n, value);
        this->_end += n;
      }

      // BASIC
      // CASE 1-2: Insert new elements at the beginning or in the middle.
      else {
        std::uninitialized_copy(end() - n, end(), end());
        this->_end += n;
        std::copy_backward(position, iterator(this->_end - n * 2),
                           iterator(this->_end - n));
        std::fill_n(position, n, value);
      }
    }

    // STRONG
    // CASE 2: Reallocations needed to insert new elements.
    else {
      const size_type old_capacity = capacity();
      size_type new_capacity = old_capacity ? old_capacity * 2 : 1;
      if (new_capacity < new_size) new_capacity = new_size;
      vector tmp;

      tmp._begin = tmp._alloc.allocate(new_capacity);
      tmp._end_of_capacity = tmp._begin + new_capacity;
      tmp._end = std::uninitialized_copy(begin(), position, tmp._begin);
      tmp._end = std::uninitialized_fill_n(tmp._end, n, value);
      tmp._end = std::uninitialized_copy(position, end(), tmp._end);
      swap(tmp);
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
              typename enable_if<!is_integral<InputIterator>::value,
                                 InputIterator>::type first,
              InputIterator last) {
    typedef typename iterator_traits<InputIterator>::iterator_category
        iterator_category;
    if (first == last) return;
    _range_insert(position, first, last, iterator_category());
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
    if (position + 1 != end()) std::copy(position + 1, end(), position);
    --this->_end;
    this->_alloc.destroy(this->_end);
    return position;
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
    this->_end -= n;
    return first;
  }

  // NOTHROW
  /**
   * @brief Removes all the elements.
   */
  void clear() { erase(begin(), end()); }

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
  void pop_back() { erase(end() - 1); }

  // NOTHROW: If new_size is less than or equal to the size of the vector.
  // STRONG: If new_size is greater than the size of the vector and the type of
  // the elements is either copyable or no-throw moveable.
  // BASIC: Otherwise, the vector is left with a valid state.
  /**
   * @brief Resizes the vector to the specified number of elements.
   *
   * @param new_size Number of elements the vector should contain.
   * @param value Data with which new elements should be populated.
   */
  void resize(size_type new_size, value_type value = value_type()) {
    if (new_size < size())
      erase(begin() + new_size, end());
    else
      insert(end(), new_size - size(), value);
  }

  // NOTHROW if the allocators in both vectors compare equal.
  // Otherwise, it causes undefined behavior.
  /**
   * @brief Swaps data with another vector.
   */
  void swap(vector &other) {
    std::swap(this->_begin, other._begin);
    std::swap(this->_end, other._end);
    std::swap(this->_end_of_capacity, other._end_of_capacity);
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
    for (; first != last; ++first) this->_alloc.destroy(first.base());
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
                         std::input_iterator_tag) {
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
                         std::forward_iterator_tag) {
    size_type n = std::distance(first, last);
    this->_begin = this->_alloc.allocate(n);
    this->_end_of_capacity = this->_begin + n;
    this->_end = std::uninitialized_copy(first, last, this->_begin);
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
                     std::input_iterator_tag) {
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
                     ForwardIterator last, std::forward_iterator_tag) {
    difference_type n = std::distance(first, last);
    size_type new_size = size() + n;
    pointer pos = this->_begin + (position - begin());

    // CASE 1: No reallocations needed to insert new elements.
    if (new_size <= capacity()) {
      // STRONG
      // CASE 1-1: Insert new elements at the end of the vector.
      if (position == end())
        this->_end = std::uninitialized_copy(first, last, pos);

      // BASIC
      // CASE 1-2: Insert new elements at the beginning or in the middle.
      else {
        this->_end = std::uninitialized_copy(end() - n, end(), this->_end);
        std::copy_backward(position, iterator(this->_end - n * 2),
                           iterator(this->_end - n));
        std::copy(first, last, position);
      }
    }

    // STRONG
    // CASE 2: Reallocations needed to insert new elements.
    else {
      const size_type old_capacity = capacity();
      size_type new_capacity = old_capacity ? old_capacity * 2 : 1;
      if (new_capacity < new_size) new_capacity = new_size;
      vector tmp;

      tmp._begin = tmp._alloc.allocate(new_capacity);
      tmp._end_of_capacity = tmp._begin + new_capacity;
      tmp._end = std::uninitialized_copy(begin(), position, tmp._begin);
      tmp._end = std::uninitialized_copy(first, last, tmp._end);
      tmp._end = std::uninitialized_copy(position, end(), tmp._end);
      swap(tmp);
    }
  }

  template <typename InputIterator>
  void _range_assign(InputIterator first, InputIterator last,
                     std::input_iterator_tag) {
    iterator tmp(begin());

    while (first != last && tmp != end()) {
      *tmp = *first;
      ++tmp;
      ++first;
    }
    if (first == last)
      erase(tmp, end());
    else
      insert(end(), first, last);
  }

  template <typename ForwardIterator>
  void _range_assign(ForwardIterator first, ForwardIterator last,
                     std::forward_iterator_tag) {
    size_t new_size = std::distance(first, last);

    if (new_size > capacity()) {
      vector tmp(first, last);

      swap(tmp);
    } else if (new_size > size()) {
      ForwardIterator mid = first;

      std::advance(mid, size());
      std::copy(first, mid, this->_begin);
      this->_end = std::uninitialized_copy(mid, last, this->_end);
    } else {
      iterator copy_end;

      std::copy(first, last, this->_begin);
      erase(begin() + new_size, end());
    }
  }
};  // class vector

// NOTE: Non-member functions
// NOTE: Relational operators
/**
 * @brief Vector equality comparison.
 *
 * Vectors are considered equivalent if their sizes are qual, and if
 * corresponding elements compare equal.
 */
template <typename T, typename Allocator>
inline bool operator==(const vector<T, Allocator> &lhs,
                       const vector<T, Allocator> &rhs) {
  return lhs.size() == rhs.size() &&
         ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

/**
 * @brief Vector ordering relation.
 *
 * It returns true if the range on the left-hand side is lexicographically less
 * than the range on the right-hand side.
 */
template <typename T, typename Allocator>
inline bool operator<(const vector<T, Allocator> &lhs,
                      const vector<T, Allocator> &rhs) {
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                      rhs.end());
}

template <typename T, typename Allocator>
inline bool operator!=(const vector<T, Allocator> &lhs,
                       const vector<T, Allocator> &rhs) {
  return !(lhs == rhs);
}

template <typename T, typename Allocator>
inline bool operator>(const vector<T, Allocator> &lhs,
                      const vector<T, Allocator> &rhs) {
  return rhs < lhs;
}

template <typename T, typename Allocator>
inline bool operator<=(const vector<T, Allocator> &lhs,
                       const vector<T, Allocator> &rhs) {
  return !(rhs < lhs);
}

template <typename T, typename Allocator>
inline bool operator>=(const vector<T, Allocator> &lhs,
                       const vector<T, Allocator> &rhs) {
  return !(lhs < rhs);
}

template <typename T, typename Allocator>
inline void swap(vector<T, Allocator> &lhs, vector<T, Allocator> &rhs) {
  lhs.swap(rhs);
}
}  // namespace ft

#endif
