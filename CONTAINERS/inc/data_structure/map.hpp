/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:49:41 by sokim             #+#    #+#             */
/*   Updated: 2023/02/07 12:32:21 by sokim            ###   ########.fr       */
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
  /**
   * @brief Returns a reference to its mapped value.
   *
   * @param key
   * @return T&
   *
   * If k matches the key of an element in the container, the function returns a
   * reference to its mapped value. If k does not match the key of any element
   * in the container, the function inserts a new element with that key and
   * returns a reference to its mapped value.
   */
  T& operator[](const Key& key) {
    iterator it = find(key);
    if (it == end()) it = insert(it, make_pair(key, T()));
    return it->second;
  }

  T& at(const Key& key) {}
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

  // STRONG
  // Undefined behavior if an invalid position or range is specified.
  /**
   * @brief Removes the element at pos.
   *
   * @param pos
   */
  void erase(iterator pos) { _base.erase(pos); }

  // BASIC
  /**
   * @brief Removes the elements in the range [first, last).
   *
   * @param first
   * @param last
   */
  void erase(iterator first, iterator last) {
    while (first != last) _base.erase(first++);
  }

  // STRONG
  /**
   * @brief Removes the element (if one exists) with the key equivalent to key.
   *
   * @param key
   * @return size_type
   */
  size_type erase(const key_type& key) { return _base.erase(key); }

  // TODO: _rb_tree::swap() 구현
  // NOTHROW If the allocators in both containers compare equal.
  // Otherwise, undefined behavior.
  /**
   * @brief Exchange the contents of the maps.
   *
   * @param other
   */
  void swap(map& other) { _base.swap(other._base); }
  // !SECTION

  // SECTION: Lookup
  // STRONG
  /**
   * @brief Returns the number of elements with key equivalent to the given key.
   *
   * @param key
   * @return size_type
   */
  size_type count(const Key& key) const { return _base.count(key); }

  // STRONG
  /**
   * @brief Tries to locate an element with which the key matches.
   *
   * @param key
   * @return iterator
   *
   * If successful, it returns an iterator pointing to the element.
   * Otherwise, it returns the past-the-end iterator.
   */
  iterator find(const Key& key) { return _base.find(key); }
  const_iterator find(const Key& key) const { return _base.find(key); }

  // STRONG
  /**
   * @brief Returns a range containing all elements with the given key in the
   * container.
   *
   * @param key
   * @return pair<iterator, iterator>
   *
   * Since map guarantees that every key is unique, the length of the range is
   * always 0 or 1.
   */
  pair<iterator, iterator> equal_range(const Key& key) {
    return _base.equal_range(key);
  }

  pair<const_iterator, const_iterator> equal_range(const Key& key) const {
    return _base.equal_range(key);
  }

  // STRONG
  /**
   * @brief Returns an iterator pointing to the first element that is not less
   * than (i.e. greater or equal to) the given key.
   *
   * @param key
   * @return iterator
   */
  iterator lower_bound(const Key& key) { return _base.lower_bound(key); }

  const_iterator lower_bound(const Key& key) const {
    return _base.lower_bound(key);
  }

  // STRONG
  /**
   * @brief Returns an iterator pointing to the first element that is greater
   * than the given key.
   *
   * @param key
   * @return iterator
   */
  iterator upper_bound(const Key& key) { return _base.upper_bound(key); }

  const_iterator upper_bound(const Key& key) const {
    return _base.upper_bound(key);
  }
  // !SECTION

  // SECTION: Observers
  // STRONG
  /**
   * @brief Returns the function object that compares the keys.
   *
   * @return key_compare
   */
  key_compare key_comp() const { return _base.key_comp(); }

  // STRONG
  /**
   * @brief Returns a function object that compares objects of type
   * map::value_type (key-value pairs) by using key_comp to compare the
   * first components of the pairs.
   *
   * @return value_compare Nested class of map class
   */
  value_compare value_comp() const { return value_compare(_base.key_comp()); }
  // !SECTION
};
}  // namespace ft

#endif
