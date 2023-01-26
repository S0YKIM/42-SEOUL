/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:49:41 by sokim             #+#    #+#             */
/*   Updated: 2023/01/26 21:57:30 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef>     // std::ptrdiff_t
#include <functional>  // std::less
#include <memory>      // std::allocator

#include "_rb_tree.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<pair<const Key, T>>>
class map {
 public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef pair<const Key, T> value_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;

  typedef size_t size_type;
  typedef std::ptrdiff_t difference_type;

  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

 private:
  typedef _rb_tree<key_type, value_type, ft::select_first<value_type>,
                   key_compare, allocator_type>
      base_structure;
  base_structure _base;

 public:
  typedef typename base::iterator iterator;
  typedef typename base::const_iterator const_iterator;
  typedef typename base::reverse_iterator reverse_iterator;
  typedef typename base::const_reverse_iterator const_reverse_iterator;

  class value_compare {
    friend class map<Key, T, Compare, Alloc>;

   protected:
    key_compare comp;
    value_compare(key_compare c) : comp(c) {}

   public:
    bool operator()(const value_type& x, const value_type& y) const {
      return comp(x.first, y.first);
    }
  };

  // STRONG
  // Undefined behavior if allocator_traits::construct is not supported with the
  // appropriate arguments for the element constructions, or if the range
  // specified by [first,last) is not valid,
  /**
   * @brief Empty container constructor(default constructor).
   */
  map() : _base() {}
  explicit map(const Compare& comp, const Alloc a = Alloc()) : _base(comp, a) {}

  // TODO: _rb_tree::insert() 구현
  /**
   * @brief Range constructor from range [first, last).
   *
   * @tparam InputIterator
   * @param first
   * @param last
   * @param comp
   * @param a
   */
  template <typename InputIterator>
  map(InputIterator first, InputIterator last, const Compare& comp = Compare(),
      const Alloc& a = Alloc())
      : _base(comp, a) {
    _base.insert(first, last);
  }

  /**
   * @brief Copy constructor.
   *
   * @param other
   */
  map(const map& other) : _base(other._base) {}

  /**
   * @brief Assignment operator.
   *
   * @param other
   * @return map&
   */
  map& operator=(const map& other) {
    _base = other._base;
    return *this;
  }

  /**
   * @brief Get the copy of allocator object
   *
   * @return allocator_type
   */
  allocator_type get_allocator() const { return _base.get_allocator(); }

  // SECTION: Element access
  T& at(const Key& key) {}
  T& operator[](const Key& key) {}
  // !SECTION

  // NOTHROW
  /**
   * @brief Returns iterator to the first element.
   */
  // SECTION: Iterators
  iterator begin() { return _base.begin(); }
  const_iterator begin() const { return _base.begin(); }

  // NOTHROW
  /**
   * @brief Returns iterator to the element following the last element.
   *
   * @return iterator
   */
  iterator end() { return _base.end(); }
  const_iterator end() const { return _base.end(); }

  // NOTHROW
  /**
   * @brief Returns reverse iterator pointing to the last element in the map.
   *
   * @return reverse_iterator
   */
  reverse_iterator rbegin() { return _base.rbegin(); }
  const_reverse_iterator rbegin() const { return _base.rbegin(); }

  // NOTHROW
  /**
   * @brief Returns reverse iterator pointing to the element right before the
   * first element in the map.
   *
   * @return reverse_iterator
   */
  reverse_iterator rend() { return _base.rend(); }
  const_reverse_iterator rend() const { return _base.rend(); }
  // !SECTION

  // SECTION: Size and capacity
  // NOTHROW
  /**
   * @brief Checks if the map is empty.
   */
  bool empty() const { return _base.empty(); }

  // NOTHROW
  /**
   * @brief Returns the number of elements in the map.
   *
   * @return size_type
   */
  size_type size() const { return _base.size(); }

  // NOTHROW
  /**
   * @brief Returns the maximum number of elements the map is able to hold.
   *
   * @return size_type
   */
  / size_type max_size() const { return _base.max_size(); }
  // !SECTION

  // SECTION: Modifiers
  // NOTHROW
  /**
   * @brief Erases all elements from the map.
   *
   * After this call, size() returns 0.
   */
  void clear() { _base.clear(); }

  // STRONG
  // Undefined behavior if allocator_traits::construct is not supported with the
  // appropriate arguments for the element constructions, or if an invalid
  // position is specified.
  /**
   * @brief Inserts a pair into map.
   *
   * @param value The pair to be copied to the inserted element
   * @return pair<iterator, bool>
   *
   * Returns a pair, with its member 'first' is set to an iterator pointing to
   * either the newly inserted element or to the element with an equivalent key
   * in the map. Another member 'second' is set to true if a new element was
   * inserted or false if an equivalent key already existed.
   */
  pair<iterator, bool> insert(const value_type& value) {
    return _base.insert(value);
  }

  // STRONG
  /**
   * @brief Inserts a pair into map using a hint position.
   *
   * @param pos A hint for the position where the element can be inserted
   * @param value The pair to be copied to the inserted element
   * @return iterator
   *
   * Inserts value in the position as close as possible to the position just
   * prior to pos.
   */
  iterator insert(iterator pos, const value_type& value) {
    return _base.insert(pos, value);
  }

  // BASIC
  /**
   * @brief Inserts elements from range [first, last).
   *
   * @tparam InputIterator
   * @param first
   * @param last
   *
   * If multiple elements in the range have keys that compare equivalent, it is
   * unspecified which element is inserted.
   */
  template <typename InputIterator>
  void insert(InputIterator first, InputIterator last) {
    _base.insert(first, last);
  }

  void erase(iterator pos);
  void erase(iterator first, iterator last);
  void swap(map& other);
  // !SECTION

  // SECTION: Lookup
  size_type count(const Key& key) const;
  iterator find(const Key& key);
  const_iterator find(const Key& key) const;
  pair<iterator, iterator> equal_range(const Key& key);
  pair<const_iterator, const_iterator> equal_range(const Key& key) const;
  iterator lower_bound(const Key& key);
  const_iterator lower_bound(const Key& key) const;
  iterator upper_bound(const Key& key);
  const_iterator upper_bound(const Key& key) const;
  // !SECTION

  // SECTION: Observers
  key_compare key_comp() const;
  map::value_compare value_comp() const;
  // !SECTION
};
}  // namespace ft

#endif
