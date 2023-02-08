/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:10:18 by sokim             #+#    #+#             */
/*   Updated: 2023/02/08 21:54:21 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <cstddef>     // std::ptrdiff_t
#include <exception>   // std::out_of_range
#include <functional>  // std::less
#include <memory>      // std::allocator

#include "_rb_tree.hpp"

namespace ft {
template <typename value_type>
struct identity {
  T& operator()(value_type& x) const { return x; }
  const T& operator()(const value_type& x) const { return x; }
};

template <typename Key, typename Compare = std::less<Key>,
          typename Alloc = std::allocator<Key> >
class set {
 public:
  typedef Key key_type;
  typedef Key value_type;
  typedef Compare key_compare;
  typedef Compare value_compare;
  typedef Alloc allocator_type;

  typedef size_t size_type;
  typedef std::ptrdiff_t difference_type;

  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

 private:
  typedef _rb_tree<key_type, value_type, ft::identity<value_type>, key_compare,
                   allocator_type>
      base_structure;
  base_structure _base;

 public:
  typedef typename base_structure::iterator iterator;
  typedef typename base_structure::const_iterator const_iterator;
  typedef typename base_structure::reverse_iterator reverse_iterator;
  typedef
      typename base_structure::const_reverse_iterator const_reverse_iterator;

  // STRONG
  // Undefined behavior if allocator_traits::construct is not supported with the
  // appropriate arguments for the element constructions, or if the range
  // specified by [first,last) is not valid.
  /**
   * @brief Empty container constructor(default constructor).
   */
  set() : _base() {}
  explicit set(const Compare& comp, const Alloc& a = Alloc())
      : _base(comp, a) {}

  /**
   * @brief Range constructor.
   *
   * @tparam InputIterator
   * @param first
   * @param last
   * @param comp
   * @param a
   */
  template <typename InputIterator>
  set(InputIterator first, InputIterator last, const Compare& comp = Compare(),
      const Alloc& a = Alloc())
      : _base(comp, a) {
    _base.insert(first, last);
  }

  /**
   * @brief Copy constructor.
   *
   * @param other
   */
  set(const set& other) : _base(other._base) {}

  /**
   * @brief Assignment operator.
   *
   * @param other
   * @return set&
   */
  set& operator=(const set& other) {
    _base = other._base;
    return *this;
  }

  /**
   * @brief Get the copy of allocator object.
   *
   * @return allocator_type
   */
  allocator_type get_allocator() const { return _base.get_allocator(); }

  // SECTION: Iterators
  // NOTHROW
  /**
   * @brief Returns iterator to the first element.
   */
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
   * @brief Returns reverse iterator pointing to the last element in the set.
   *
   * @return reverse_iterator
   */
  reverse_iterator rbegin() { return _base.rbegin(); }
  const_reverse_iterator rbegin() const { return _base.rbegin(); }

  // NOTHROW
  /**
   * @brief Returns reverse iterator pointing to the element right before the
   * first element in the set.
   *
   * @return reverse_iterator
   */
  reverse_iterator rend() { return _base.rend(); }
  const_reverse_iterator rend() const { return _base.rend(); }
  // !SECTION

  // SECTION: Size and capacity
  // NOTHROW
  /**
   * @brief Checks if the set is empty.
   */
  bool empty() const { return _base.empty(); }

  // NOTHROW
  /**
   * @brief Returns the number of elements in the set.
   *
   * @return size_type
   */
  size_type size() const { return _base.size(); }

  // NOTHROW
  /**
   * @brief Returns the maximum number of elements the set is able to hold.
   *
   * @return size_type
   */
  size_type max_size() const { return _base.max_size(); }
  // !SECTION

  // SECTION: Modifiers
  // NOTHROW
  /**
   * @brief Erases all elements from the set.
   *
   * After this call, size() returns 0.
   */
  void clear() { _base.clear(); }

  // STRONG
  // Undefined behavior if allocator_traits::construct is not supported with the
  // appropriate arguments for the element constructions, or if an invalid
  // position is specified.
  /**
   * @brief Inserts a pair into set.
   *
   * @param value The pair to be copied to the inserted element
   * @return pair<iterator, bool>
   *
   * Returns a pair, with its member 'first' is set to an iterator pointing to
   * either the newly inserted element or to the element with an equivalent key
   * in the set. Another member 'second' is set to true if a new element was
   * inserted or false if an equivalent key already existed.
   */
  pair<iterator, bool> insert(const value_type& value) {
    return _base.insert(value);
  }

  // STRONG
  /**
   * @brief Inserts a value into set using a hint position.
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

  // NOTHROW If the allocators in both containers compare equal.
  // Otherwise, undefined behavior.
  /**
   * @brief Exchange the contents of the sets.
   *
   * @param other
   */
  void swap(set& other) { _base.swap(other._base); }
  // !SECTION

  // SECTION: Lookup
  // STRONG
  /**
   * @brief Returns the number of elements with key equivalent to the given key.
   * (1 or 0)
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
  iterator find(const Key& key) const { return _base.find(key); }

  // STRONG
  /**
   * @brief Returns a range containing all elements with the given key in the
   * container.
   *
   * @param key
   * @return pair<iterator, iterator>
   *
   * Since set guarantees that every key is unique, the length of the range is
   * always 0 or 1.
   */
  pair<iterator, iterator> equal_range(const Key& key) const {
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
  iterator lower_bound(const Key& key) const { return _base.lower_bound(key); }

  // STRONG
  /**
   * @brief Returns an iterator pointing to the first element that is greater
   * than the given key.
   *
   * @param key
   * @return iterator
   */
  iterator upper_bound(const Key& key) const { return _base.upper_bound(key); }
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
   * set::value_type (key) by using key_comp to compare the keys.
   *
   * @return value_compare Nested class of set class
   */
  value_compare value_comp() const { return value_compare(_base.key_comp()); }
  // !SECTION

  template <typename K1, typename C1, typename A1>
  friend bool operator==(const set<K1, C1, A1>& lhs,
                         const set<K1, C1, A1>& rhs);

  template <typename K1, typename C1, typename A1>
  friend bool operator<(const set<K1, T1, C1, A1>& lhs,
                        const set<K1, T1, C1, A1>& rhs);
};

template <typename Key, typename Compare, typename Alloc>
inline bool operator==(const set<Key, Compare, Alloc>& lhs,
                       const set<Key, Compare, Alloc>& rhs) {
  return lhs._base == rhs._base;
}

template <typename Key, typename Compare, typename Alloc>
inline bool operator<(const set<Key, Compare, Alloc>& lhs,
                      const set<Key, Compare, Alloc>& rhs) {
  return lhs._base < rhs._base;
}

template <typename Key, typename Compare, typename Alloc>
inline bool operator!=(const set<Key, Compare, Alloc>& lhs,
                       const set<Key, Compare, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <typename Key, typename Compare, typename Alloc>
inline bool operator>(const set<Key, Compare, Alloc>& lhs,
                      const set<Key, Compare, Alloc>& rhs) {
  return rhs < lhs;
}

template <typename Key, typename Compare, typename Alloc>
inline bool operator<=(const set<Key, Compare, Alloc>& lhs,
                       const set<Key, Compare, Alloc>& rhs) {
  return !(rhs < lhs);
}

template <typename Key, typename Compare, typename Alloc>
inline bool operator>=(const set<Key, Compare, Alloc>& lhs,
                       const set<Key, Compare, Alloc>& rhs) {
  return !(lhs < rhs);
}

template <typename Key, typename Compare, typename Alloc>
inline void swap(set<Key, Compare, Alloc>& lhs, set<Key, Compare, Alloc>& rhs) {
  lhs.swap(rhs);
}
}  // namespace ft

#endif
