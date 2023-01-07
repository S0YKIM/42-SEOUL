/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:01 by sokim             #+#    #+#             */
/*   Updated: 2023/01/07 16:40:40 by sokim            ###   ########.fr       */
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
  // STRONG GUARANTEE
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
  ~vector() { std::destroy(this->begin_, this->end_); }

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

  // STRONG GUARANTEE
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
  // TODO: clear() 구현
  void clear();

  /**
   * @brief Inserts the given value into the vector.
   *
   * @param position The position where the value will be inserted.
   * @param value Data to be inserted.
   * @return iterator An iterator that points to the inserted data.
   */
  iterator insert(iterator position, const value_type &value) {
    size_type n = position - begin();

    // STRONG GUARANTEE
    // CASE 1: Insert a single element at the end, and no reallocations happen.
    if (this->end_ != this->end_of_capacity_ && position == end()) {
      alloc_.construct(this->end_, value);
      ++this->end_;
    }

    // BASIC GUARANTEE
    // CASE 2: Insert a single element at the beginning or in the middle of the
    // vector, and no reallocations happen.
    else if (this->end_ != this->end_of_capacity_) {
      alloc_.construct(this->end_, *(this->end_ - 1));
      ++this->end_;
      std::copy_backward(position, iterator(this->end_ - 2),
                         iterator(this->end_ - 1));
      // TEST: value_type tmp 와 같은 복사본이 필요한가?
      *position = value;
    }

    // STRONG GUARANTEE
    // CASE 3: Insert a single element when reallocations needed.
    else {
      const size_type old_capacity = capacity();
      const size_type new_capacity = old_capacity ? old_capacity * 2 : 1;
      iterator new_begin(alloc_.allocate(new_capacity));
      iterator new_end(new_begin);

      try {
        new_end = std::uninitialized_copy(begin(), position, new_begin);
        alloc_.construct(new_end.base(), value);
        ++new_end;
        new_end = std::uninitialized_copy(position, end(), new_end);
      } catch (...) {
        std::destroy(new_begin, new_end);
        alloc_.deallocate(new_begin.base(), new_capacity);
        throw std::exception("ft::vector::insert() exception occured.");
      }
      std::destroy(begin(), end());
      alloc_.deallocate(this->begin_, old_capacity);
      this->begin_ = new_begin.base();
      this->end_ = new_end().base();
      this->end_of_capacity_ = new_begin.base() + new_capacity;
    }

    return begin() + n;
  }

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
      // STRONG GUARANTEE
      // CASE 1-1: Insert new elements at the end of the vector.
      if (position == end())
        this->end_ = std::uninitialized_fill_n(position, n, value);

      // BASIC GUARANTEE
      // CASE 1-2: Insert new elements at the beginning or in the middle.
      else {
        this->end_ = std::uninitialized_copy(end() - n, end(), end());
        std::copy_backward(position, iterator(this->end_ - n * 2),
                           iterator(this->end_ - n));
        std::fill(position, position + n, value);
      }
    }

    // STRONG GUARANTEE
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
        std::destroy(new_begin, new_end);
        alloc_.deallocate(new_begin.base(), new_capacity);
        throw std::exception("ft::vector::insert() exception occured.");
      }
      std::destroy(begin(), end());
      alloc_.deallocate(this->begin_, old_capacity);
      this->begin_ = new_begin.base();
      this->end_ = new_end().base();
      this->end_of_capacity_ = new_begin.base() + new_capacity;
    }
  }

  template <typename InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last);

  // TODO: erase() 구현
  iterator erase(iterator position);
  iterator erase(iterator first, iterator last);

  // STRONG GUARANTEE
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

  // TODO: pop_back() 구현
  void pop_back();

  // TODO: resize() 구현
  void resize(size_type n, value_type value = value_type());

  // TODO: swap() 구현
  void swap(vector &other);
  // !SECTION

 private:
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
