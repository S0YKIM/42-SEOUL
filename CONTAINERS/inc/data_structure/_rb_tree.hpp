/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:10:51 by sokim             #+#    #+#             */
/*   Updated: 2023/02/08 20:45:25 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <algorithm>  // std::lexicographical_compare
#include <exception>  // std::exception

#include "algorithm.hpp"         // ft::equal
#include "pair.hpp"              // ft::pair
#include "rb_tree_iterator.hpp"  // ft::rb_tree_iterator
#include "reverse_iterator.hpp"  // ft::reverse_iterator

namespace ft {
inline void _rb_tree_rotate_left(_rb_tree_node_base* node,
                                 _rb_tree_node_base*& root);

inline void _rb_tree_rotate_right(_rb_tree_node_base* node,
                                  _rb_tree_node_base*& root);

void _rb_tree_rebalance_after_insertion(_rb_tree_node_base* node,
                                        _rb_tree_node_base*& root);

_rb_tree_node_base* _rb_tree_rebalance_for_erase(
    _rb_tree_node_base* z, _rb_tree_node_base*& root,
    _rb_tree_node_base*& leftmost, _rb_tree_node_base*& rightmost);

template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc = std::allocator<Val> >
class _rb_tree {
 private:
  typedef typename Alloc::template rebind<_rb_tree_node<Val> >::other
      node_allocator;

 protected:
  typedef _rb_tree_node_base* _base_ptr;
  typedef const _rb_tree_node_base* _const_base_ptr;
  typedef _rb_tree_node<Val> _rb_tree_node;
  typedef _rb_tree_node* link_type;
  typedef const _rb_tree_node* const_link_type;

 public:
  typedef Key key_type;
  typedef Val value_type;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef Alloc allocator_type;

  typedef _rb_tree<Key, Val, KeyOfValue, Compare, Alloc> self;

 protected:
  // NOTE: Structure _rb_tree_impl
  /**
   * @brief Contains the actual data(key_compare, header)
   *
   * @tparam Compare Functor to compare keys
   */
  template <typename KeyCompare>
  struct _rb_tree_impl {
    KeyCompare _key_compare;
    _rb_tree_node_base _header;
    size_type _node_count;

    _rb_tree_impl(const KeyCompare& comp = KeyCompare())
        : _key_compare(comp), _header(), _node_count(0) {
      _header._color = RED;
      _header._parent = 0;
      _header._left_child = &_header;
      _header._right_child = &_header;
    }
  };

  _rb_tree_impl<Compare> _impl;
  node_allocator _alloc;

  // NOTE: Member functions
  node_allocator& get_node_allocator() { return _alloc; }

  const node_allocator& get_node_allocator() const { return _alloc; }

 public:
  _rb_tree() : _impl(), _alloc() {}

  _rb_tree(const Compare& comp, const node_allocator& a = node_allocator())
      : _impl(comp), _alloc(a) {}

  _rb_tree(const self& other) : _impl(other._impl), _alloc(other._alloc) {
    if (other._root()) {
      _root() = _copy(other._root(), _end());
      _leftmost() = _rb_tree_node_base::_minimum(_root());
      _rightmost() = _rb_tree_node_base::_maximum(_root());
      _impl._node_count = other._impl._node_count;
    }
  }

  ~_rb_tree() { _erase(_begin()); }

  self& operator=(const self& other) {
    if (this != &other) {
      clear();
      _impl._node_count = 0;
      _impl._key_compare = other._impl._key_compare;
      if (other._root() == 0) {
        _root() = 0;
        _leftmost() = _end();
        _rightmost() = _end();
      } else {
        _root() = _copy(other._root(), _end());
        _leftmost() = _rb_tree_node_base::_minimum(_root());
        _rightmost() = _rb_tree_node_base::_maximum(_root());
        _impl._node_count = other._impl._node_count;
      }
    }
    return *this;
  }

 protected:
  // SECTION: Node management
  /**
   * @brief Allocate a node.
   *
   * @return _rb_tree_node* The address of the node allocated
   */
  _rb_tree_node* _get_node() { return _alloc.allocate(1); }

  /**
   * @brief Deallocate the given node.
   *
   * @param node The node to be deallocated
   */
  void _put_node(_rb_tree_node* node) { _alloc.deallocate(node, 1); }

  /**
   * @brief Create a node with the given value.
   *
   * @param value The given value
   * @return link_type The address of the created node
   */
  link_type _create_node(const value_type& value) {
    link_type tmp = _get_node();
    try {
      _alloc.construct(tmp, value);
    } catch (const std::exception& e) {
      _put_node(tmp);
      throw e;
    }
    return tmp;
  }

  /**
   * @brief Clone the given node.
   *
   * @param other The node to be cloned
   * @return link_type The address of the clone node
   */
  link_type _clone_node(const_link_type other) {
    link_type tmp = _create_node(other->_value);
    tmp->_color = other->_color;
    tmp->_left_child = 0;
    tmp->_right_child = 0;
    return tmp;
  }

  /**
   * @brief Destroy the node.
   *
   * @param node
   */
  void _destroy_node(link_type node) {
    _alloc.destroy(node);
    _put_node(node);
  }  // !SECTION

  // SECTION: Protected functions to access
  /**
   * @brief Get the reference of the root node base.
   */
  _base_ptr& _root() { return _impl._header._parent; }
  _const_base_ptr _root() const { return _impl._header._parent; }

  /**
   * @brief Get the reference of the leftmost node base.
   */
  _base_ptr& _leftmost() { return _impl._header._left_child; }
  _const_base_ptr _leftmost() const { return _impl._header._left_child; }

  /**
   * @brief Get the reference of the rightmost node base.
   */
  _base_ptr& _rightmost() { return _impl._header._right_child; }
  _const_base_ptr _rightmost() const { return _impl._header._right_child; }

  /**
   * @brief Get the address of the root node.
   *
   * @return link_type _rb_tree_node*
   */
  link_type _begin() { return static_cast<link_type>(_impl._header._parent); }
  const_link_type _begin() const {
    return static_cast<const_link_type>(_impl._header._parent);
  }

  /**
   * @brief Get the address of the nil node(==header node).
   *
   * @return link_type _rb_tree_node*
   */
  link_type _end() { return static_cast<link_type>(&_impl._header); }
  const_link_type _end() const {
    return static_cast<const_link_type>(&_impl._header);
  }

  /**
   * @brief Get the value of the given node.
   *
   * @param node
   * @return const_reference
   */
  static const_reference _value(const_link_type node) { return node->_value; }

  static const_reference _value(_const_base_ptr node) {
    return static_cast<const_link_type>(node)->_value;
  }

  /**
   * @brief Get the key of the given node.
   *
   * @param node
   * @return const key_type
   *
   * First, get the value of the given node by _value().
   * Second, get the key of the given node by the functor KeyOfValue().
   */
  static const key_type& _key(const_link_type node) {
    return KeyOfValue()(_value(node));
  }

  static const key_type& _key(_const_base_ptr node) {
    return KeyOfValue()(_value(node));
  }

  static link_type& _parent(link_type node) {
    return static_cast<link_type&>(node->_parent);
  }

  static link_type& _parent(_base_ptr node) {
    return static_cast<link_type&>(node->_parent);
  }

  /**
   * @brief Get the left child of the given node.
   *
   * @param node
   * @return link_type
   */
  static link_type _left(_base_ptr node) {
    return static_cast<link_type>(node->_left_child);
  }

  static const_link_type _left(_const_base_ptr node) {
    return static_cast<const_link_type>(node->_left_child);
  }

  static link_type _left(link_type node) {
    return static_cast<link_type>(node->_left_child);
  }

  static const_link_type _left(const_link_type node) {
    return static_cast<const_link_type>(node->_left_child);
  }

  /**
   * @brief Get the right child of the given node.
   *
   * @param node
   * @return link_type
   */
  static link_type _right(_base_ptr node) {
    return static_cast<link_type>(node->_right_child);
  }

  static const_link_type _right(_const_base_ptr node) {
    return static_cast<const_link_type>(node->_right_child);
  }

  static link_type _right(link_type node) {
    return static_cast<link_type>(node->_right_child);
  }

  static const_link_type _right(const_link_type node) {
    return static_cast<const_link_type>(node->_right_child);
  }

  /**
   * @brief Get the node which has the smallest key below the given node.
   *
   * @param node
   * @return _base_ptr
   */
  static link_type minimum(_base_ptr node) {
    return static_cast<link_type>(_rb_tree_node_base::_minimum(node));
  }

  static const_link_type minimum(_const_base_ptr node) {
    return static_cast<const_link_type>(_rb_tree_node_base::_minimum(node));
  }

  /**
   * @brief Get the node which has the biggest key below the given node.
   *
   * @param node
   * @return _base_ptr
   */
  static link_type maximum(_base_ptr node) {
    return static_cast<link_type>(_rb_tree_node_base::_maximum(node));
  }

  static const_link_type maximum(_const_base_ptr node) {
    return static_cast<const_link_type>(_rb_tree_node_base::_maximum(node));
  }  // !SECTION

 public:
  typedef _rb_tree_iterator<value_type> iterator;
  typedef _rb_tree_const_iterator<value_type> const_iterator;

  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  /**
   * @brief Insert a new node with the given value to the tree.
   *
   * @param x Usually 0, sometimes leftmost or rightmost node.
   * @param y Address of a node which is going to be the parent of the new node.
   * @param value The value which the new node will have.
   * @return iterator
   */
  iterator _insert(_base_ptr x, _base_ptr y, const value_type& value) {
    link_type node;

    // Case 1: Add the new node as the left child of y.
    if (y == &_impl._header || x || key_comp()(KeyOfValue()(value), _key(y))) {
      node = _create_node(value);
      y->_left_child = node;
      if (y == &_impl._header) {
        _root() = node;
        _rightmost() = node;
      } else if (y == _leftmost())
        _leftmost() = node;
    }
    // Case 2: Add the new node as the right child of y.
    else {
      node = _create_node(value);
      y->_right_child = node;
      if (y == _rightmost()) _rightmost() = node;
    }
    node->_parent = y;
    node->_left_child = 0;
    node->_right_child = 0;
    // Check if it still satisfies the properties of rbtree after insertion.
    _rb_tree_rebalance_after_insertion(node, _impl._header._parent);
    // Update the size of the rbtree.
    ++_impl._node_count;
    return iterator(node);
  }

  const_iterator _insert(_const_base_ptr x, _const_base_ptr y,
                         const value_type& value) {
    link_type node;

    // Case 1: Add the new node as the left child of y.
    if (y == &_impl._header || x ||
        _key_compare(KeyOfValue()(value), _key(y))) {
      node = _create_node(value);
      y->_left_child = node;
      if (y == &_impl._header) {
        _root() = node;
        _rightmost() = node;
      } else if (y == _leftmost())
        _leftmost() = node;
    }
    // Case 2: Add the new node as the right child of y.
    else {
      node = _create_node(value);
      y->_right_child = node;
      if (y == _rightmost()) _rightmost() = node;
    }
    node->_parent = y;
    node->_left_child = 0;
    node->_right_child = 0;
    // Check if it still satisfies the properties of rbtree after insertion.
    _rb_tree_rebalance_after_insertion(node, _impl._header._parent);
    // Update the size of the rbtree.
    ++_impl._node_count;
    return const_iterator(node);
  }

  /**
   * @brief Clone the given node including its sub-tree.
   *
   * @param x The node to be copied
   * @param p The node which will be the parent of a new node
   * @return _base_ptr
   */
  _base_ptr _copy(_const_base_ptr x, _base_ptr p) {
    link_type top = _clone_node(static_cast<const_link_type>(x));
    top->_parent = p;

    try {
      // Recur until it copies all the nodes
      if (x->_right_child) top->_right_child = _copy(_right(x), top);
      p = top;
      x = _left(x);

      while (x) {
        link_type y = _clone_node(static_cast<const_link_type>(x));
        p->_left_child = y;
        y->_parent = p;
        if (x->_right_child) y->_right_child = _copy(_right(x), y);
        p = y;
        x = _left(x);
      }
    } catch (const std::exception& e) {
      _erase(top);
      throw e;
    }
    return top;
  }

  /**
   * @brief Erase the given node from the tree including its child nodes.
   *
   * @param x Pointer to a node to be erased
   */
  void _erase(link_type x) {
    while (x) {
      _erase(_right(x));
      link_type y = _left(x);
      _destroy_node(x);
      x = y;
    }
  }

 public:
  // SECTION: Accessors
  Compare key_comp() const { return _impl._key_compare; }

  iterator begin() { return iterator(static_cast<link_type>(_leftmost())); }

  const_iterator begin() const {
    return const_iterator(static_cast<const_link_type>(_leftmost()));
  }

  iterator end() { return iterator(static_cast<link_type>(&_impl._header)); }

  const_iterator end() const {
    return const_iterator(static_cast<const_link_type>(&_impl._header));
  }

  reverse_iterator rbegin() { return reverse_iterator(end()); }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }

  bool empty() const { return _impl._node_count == 0; }

  size_type size() const { return _impl._node_count; }

  size_type max_size() const { return _alloc.max_size(); }
  // !SECTION

  // SECTION: Modifiers
  /**
   * @brief Swap two rbtrees. For example, A.swap(B)
   *
   * @param other
   */
  void swap(_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& other) {
    // A is empty.
    if (_root() == 0) {
      // B is not empty.
      if (other._root() != 0) {
        _root() = other._root();
        _leftmost() = other._leftmost();
        _rightmost() = other._rightmost();
        _root()->_parent = _end();

        other._root() = 0;
        other._leftmost() = other._end();
        other._rightmost() = other._end();
      }
    }
    // A is not empty but B is empty.
    else if (other._root() == 0) {
      other._root() = _root();
      other._leftmost() = _leftmost();
      other._rightmost() = _rightmost();
      other._root()->_parent = other._end();

      _root() = 0;
      _leftmost() = _end();
      _rightmost() = _end();
    }
    // Both A and B are not empty.
    else {
      std::swap(_root(), other._root());
      std::swap(_leftmost(), other._leftmost());
      std::swap(_rightmost(), other._rightmost());

      _root()->_parent = _end();
      other._root()->_parent = other._end();
    }
    std::swap(_impl._node_count, other._impl._node_count);
    std::swap(_impl._key_compare, other._impl._key_compare);
  }

  /**
   * @brief Insert a new pair to the tree.
   *
   * @param value pair(key, value) type
   * @return pair<iterator, bool>
   *
   * If there was the same key in the tree already, it doesn't insert a new
   * node. Instead, it returns a pair that is consist of (iterator to already
   * existing node, false). Otherwise, it inserts a new node and returns a pair
   * that is consist of (iterator to a new node, true).
   */
  pair<iterator, bool> insert(const value_type& value) {
    link_type y = _end();
    link_type x = _begin();
    bool comp = true;
    while (x) {
      y = x;
      // default: std::less<Key>
      comp = key_comp()(KeyOfValue()(value), _key(x));
      x = comp ? _left(x) : _right(x);
    }
    iterator it = iterator(y);
    if (comp) {
      if (it == begin())
        return ft::make_pair(_insert(x, y, value), true);
      else
        --it;
    }
    if (key_comp()(_key(it._node), KeyOfValue()(value)))
      return ft::make_pair(_insert(x, y, value), true);
    return ft::make_pair(it, false);
  }

  /**
   * @brief Insert a new pair to the tree with hint position given.
   *
   * @param pos Hint position to help insertion to be more efficient
   * @param value pair<iterator, bool>
   * @return iterator
   */
  iterator insert(iterator pos, const value_type& value) {
    if (pos._node == _impl._header._left_child) {
      // begin()
      if (size() > 0 && key_comp()(KeyOfValue()(value), _key(pos._node)))
        return _insert(pos._node, pos._node, value);
      // (1) The tree is empty or (2) The given key is bigger than leftmost
      // In this case, the hint position is no use.
      else
        return insert(value).first;
    } else if (pos._node == &_impl._header) {
      // end()
      if (key_comp()(_key(_rightmost()), KeyOfValue()(value)))
        return _insert(0, _rightmost(), value);
      // In this case, the hint position is no use.
      else
        return insert(value).first;
    } else {
      iterator before = pos;
      --before;
      // before < value < pos
      if (key_comp()(_key(before._node), KeyOfValue()(value)) &&
          key_comp()(KeyOfValue()(value), _key(pos._node))) {
        if (_right(before._node) == 0)
          return _insert(0, before._node, value);
        else
          return _insert(pos._node, pos._node, value);
      }
      // In this case, the hint position is no use.
      else
        return insert(value).first;
    }
  }

  /**
   * @brief Range insertion from range of [first, last).
   *
   * @param first
   * @param last
   */
  template <typename InputIterator>
  void insert(InputIterator first, InputIterator last) {
    for (; first != last; ++first) insert(*first);
  }

  /**
   * @brief Erase one node.
   *
   * @param pos Iterator to the node to be erased
   */
  void erase(iterator pos) {
    link_type y = static_cast<link_type>(_rb_tree_rebalance_for_erase(
        pos._node, _impl._header._parent, _impl._header._left_child,
        _impl._header._right_child));
    _destroy_node(y);
    --_impl._node_count;
  }

  /**
   * @brief Erase every node which has the same key as the given key.
   *
   * @param k Key
   * @return size_type The number of nodes erased (0 or 1)
   *
   * Since this is not a multimap but a map, there might be only one or no node
   * to be erased.
   */
  size_type erase(const Key& k) {
    pair<iterator, iterator> range = equal_range(k);
    size_type n = std::distance(range.first, range.second);
    erase(range.first, range.second);
    return n;
  }

  /**
   * @brief Erase in the range of [first, last).
   *
   * @param first
   * @param last
   */
  void erase(iterator first, iterator last) {
    if (first == begin() && last == end())
      clear();
    else
      while (first != last) erase(first++);
  }

  /**
   * @brief Erase in the range of [first, last) by key.
   *
   * @param first
   * @param last
   */
  void erase(const Key* first, const Key* last) {
    while (first != last) erase(*first++);
  }

  void clear() {
    if (_impl._node_count != 0) {
      _erase(static_cast<link_type>(_root()));
      _root() = 0;
      _leftmost() = _end();
      _rightmost() = _end();
      _impl._node_count = 0;
    }
  }
  // !SECTION
  // SECTION: Search
  /**
   * @brief Find the node of which key is same as k.
   *
   * @param k Key to be searched
   * @return iterator
   */
  iterator find(const Key& k) {
    link_type y = const_cast<link_type>(_end());
    link_type x = const_cast<link_type>(static_cast<const_link_type>(_root()));

    while (x) {
      // k <= x
      if (!key_comp()(_key(x), k)) {
        y = x;
        x = _left(x);
      }
      // k > x
      else
        x = _right(x);
    }

    iterator it = iterator(y);
    // There is no node that has the same key.
    if (it == end() || key_comp()(k, _key(it._node))) return end();
    // Found the node we were looking for.
    else
      return it;
  }

  const_iterator find(const Key& k) const {
    link_type y = const_cast<link_type>(_end());
    link_type x = const_cast<link_type>(static_cast<const_link_type>(_root()));

    while (x) {
      // k <= x
      if (!key_comp()(_key(x), k)) {
        y = x;
        x = _left(x);
      }
      // k > x
      else
        x = _right(x);
    }

    const_iterator it = const_iterator(y);
    // There is no node that has the same key.
    if (it == end() || key_comp()(k, _key(it._node))) return end();
    // Found the node we were looking for.
    else
      return it;
  }

  /**
   * @brief Count the number of nodes that have the same key as k.
   *
   * @param k Key to be searched
   * @return size_type The number of nodes found (0 or 1)
   */
  size_type count(const Key& k) const {
    pair<const_iterator, const_iterator> range = equal_range(k);
    size_type n = std::distance(range.first, range.second);
    return n;
  }

  /**
   * @brief Find node which is smallest among the nodes that are bigger than k.
   * (Including k)
   *
   * @param k Key to be searched
   * @return iterator
   *
   * The returned iterator could be exactly same as k. If not, it should be the
   * smallest node among the nodes that are bigger than k.
   */
  iterator lower_bound(const Key& k) {
    link_type y = const_cast<link_type>(_end());
    link_type x = const_cast<link_type>(static_cast<const_link_type>(_root()));

    while (x) {
      // k <= x
      if (!key_comp()(_key(x), k)) {
        y = x;
        x = _left(x);
      }
      // k > x
      else
        x = _right(x);
    }

    // It can be exactly same as k or bigger than k.
    return iterator(y);
  }

  const_iterator lower_bound(const Key& k) const {
    link_type y = const_cast<link_type>(_end());
    link_type x = const_cast<link_type>(static_cast<const_link_type>(_root()));

    while (x) {
      // k <= x
      if (!key_comp()(_key(x), k)) {
        y = x;
        x = _left(x);
      }
      // k > x
      else
        x = _right(x);
    }

    // It can be exactly same as k or bigger than k.
    return const_iterator(y);
  }

  /**
   * @brief Find node which is smallest among the nodes that are bigger than k.
   * (Not including k)
   *
   * @param k Key to be searched
   * @return iterator
   */
  iterator upper_bound(const Key& k) {
    link_type y = const_cast<link_type>(_end());
    link_type x = const_cast<link_type>(static_cast<const_link_type>(_root()));

    while (x) {
      // k < x
      if (key_comp()(k, _key(x))) {
        y = x;
        x = _left(x);
      }
      // k >= x
      else
        x = _right(x);
    }

    return iterator(y);
  }

  const_iterator upper_bound(const Key& k) const {
    link_type y = const_cast<link_type>(_end());
    link_type x = const_cast<link_type>(static_cast<const_link_type>(_root()));

    while (x) {
      // k < x
      if (key_comp()(k, _key(x))) {
        y = x;
        x = _left(x);
      }
      // k >= x
      else
        x = _right(x);
    }

    return const_iterator(y);
  }

  /**
   * @brief Find the range of nodes which have the same key as k.
   *
   * @param k Key to be searched
   * @return pair<iterator, iterator>
   */
  pair<iterator, iterator> equal_range(const Key& k) {
    return ft::make_pair(lower_bound(k), upper_bound(k));
  }

  pair<const_iterator, const_iterator> equal_range(const Key& k) const {
    return ft::make_pair(lower_bound(k), upper_bound(k));
  }
  // !SECTION
};

template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc>
inline bool operator==(
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& lhs,
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& rhs) {
  return lhs.size() == rhs.size() &&
         ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc>
inline bool operator<(
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& lhs,
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& rhs) {
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                      rhs.end());
}

template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc>
inline bool operator!=(
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& lhs,
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc>
inline bool operator>(
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& lhs,
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& rhs) {
  return rhs < lhs;
}

template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc>
inline bool operator<=(
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& lhs,
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& rhs) {
  return !(rhs < lhs);
}

template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc>
inline bool operator>=(
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& lhs,
    const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& rhs) {
  return !(lhs < rhs);
}

template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc>
inline void swap(_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& lhs,
                 _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& rhs) {
  lhs.swap(rhs);
}

/**
 * @brief Left rotation.
 *
 * @param node The node to be pulled down
 * @param root The root node of the tree
 */
inline void _rb_tree_rotate_left(_rb_tree_node_base* node,
                                 _rb_tree_node_base*& root) {
  _rb_tree_node_base* tmp = node->_right_child;
  node->_right_child = tmp->_left_child;
  if (tmp->_left_child) tmp->_left_child->_parent = node;
  tmp->_parent = node->_parent;

  if (node == root)
    root = tmp;
  else if (node == node->_parent->_left_child)
    node->_parent->_left_child = tmp;
  else
    node->_parent->_right_child = tmp;

  tmp->_left_child = node;
  node->_parent = tmp;
}

/**
 * @brief Right rotation.
 *
 * @param node The node to be pulled down
 * @param root The root node of the tree
 */
inline void _rb_tree_rotate_right(_rb_tree_node_base* node,
                                  _rb_tree_node_base*& root) {
  _rb_tree_node_base* tmp = node->_left_child;
  node->_left_child = tmp->_right_child;
  if (tmp->_right_child) tmp->_right_child->_parent = node;
  tmp->_parent = node->_parent;

  if (node == root)
    root = tmp;
  else if (node == node->_parent->_right_child)
    node->_parent->_right_child = tmp;
  else
    node->_parent->_left_child = tmp;

  tmp->_right_child = node;
  node->_parent = tmp;
}

/**
 * @brief Check if the tree follows the rb tree rule after an insertion.
 *
 * @param node The node which was inserted
 * @param root The root node
 */
void _rb_tree_rebalance_after_insertion(_rb_tree_node_base* node,
                                        _rb_tree_node_base*& root) {
  node->_color = RED;
  while (node != root && node->_parent->_color == RED) {
    if (node->_parent == node->_parent->_parent->_left_child) {
      _rb_tree_node_base* tmp = node->_parent->_parent->_right_child;
      if (tmp && tmp->_color == RED) {
        node->_parent->_color = BLACK;
        tmp->_color = BLACK;
        node->_parent->_parent->_color = RED;
        node = node->_parent->_parent;
      }
      // Case 1 or 2
      else {
        // Case 2: < shape
        // Change into Case 1 by left rotation
        if (node == node->_parent->_right_child) {
          node = node->_parent;
          _rb_tree_rotate_left(node, root);
        }
        // Case 1: / shape
        node->_parent->_color = BLACK;
        node->_parent->_parent->_color = RED;
        _rb_tree_rotate_right(node->_parent->_parent, root);
      }
    } else {
      _rb_tree_node_base* tmp = node->_parent->_parent->_left_child;
      if (tmp && tmp->_color == RED) {
        node->_parent->_color = BLACK;
        tmp->_color = BLACK;
        node->_parent->_parent->_color = RED;
        node = node->_parent->_parent;
      } else {
        // Case 2: > shape
        // Change into Case 1 by right rotation
        if (node == node->_parent->_left_child) {
          node = node->_parent;
          _rb_tree_rotate_right(node, root);
        }
        // Case 1: \ shape
        node->_parent->_color = BLACK;
        node->_parent->_parent->_color = RED;
        _rb_tree_rotate_left(node->_parent->_parent, root);
      }
    }
  }
  root->_color = BLACK;
}

/**
 * @brief Detach the node to be erased from the tree and rebalance.
 *
 * @param z Node to be erased
 * @param root Root node
 * @param leftmost Node which has the smallest data
 * @param rightmost Node which has the biggest data
 * @return _rb_tree_node_base* Type of the node to be erased
 *
 * (Case A) The node to be erased has both child nodes.
 * (Case B) The node to be erased has one or no child node.
 */
_rb_tree_node_base* _rb_tree_rebalance_for_erase(
    _rb_tree_node_base* z, _rb_tree_node_base*& root,
    _rb_tree_node_base*& leftmost, _rb_tree_node_base*& rightmost) {
  // y: (Case A) Successor of the node to be erased (Case B) Note to be erased
  _rb_tree_node_base* y = z;
  // x: (Case A) Child node of successor (Case B) successor
  // Substitute the place of the successor
  _rb_tree_node_base* x = 0;
  _rb_tree_node_base* x_parent = 0;
  // SECTION: Decide successor
  // (Case B) One or no child node exists
  if (y->_left_child == 0)
    x = y->_right_child;
  else {
    // (Case B) Only left child node exists
    if (y->_right_child == 0) x = y->_left_child;
    // (Case A) Both child nodes exist
    else {
      y = y->_right_child;
      while (y->_left_child) y = y->_left_child;
      x = y->_right_child;
    }
  }  // !SECTION
  // SECTION: (Case A) Both child nodes exist
  if (y != z) {
    z->_left_child->_parent = y;
    y->_left_child = z->_left_child;
    // If the successor was not the right child of the node to be erased, the
    // child node of the successor will lose its parent.
    // So its parent also has to be appropriately modified.
    if (y != z->_right_child) {
      x_parent = y->_parent;
      if (x) x->_parent = y->_parent;
      y->_parent->_left_child = x;
      y->_right_child = z->_right_child;
      z->_right_child->_parent = y;
    }
    // If the successor was the right child of the node to be erased, the right
    // child of the successor only needs to follow successor.
    else
      x_parent = y;
    if (root == z)
      root = y;
    else if (z->_parent->_left_child == z)
      z->_parent->_left_child = y;
    else
      z->_parent->_right_child = y;
    y->_parent = z->_parent;
    std::swap(y->_color, z->_color);
    // y is now points to the node to be actually erased
    y = z;
  }  // !SECTION
  // SECTION: (Case B) One or no child node exists. x is now successor here.
  // y: The node to be erased
  // if y == z
  else {
    x_parent = y->_parent;
    if (x) x->_parent = y->_parent;
    if (root == z)
      root = x;
    else {
      if (z->_parent->_left_child == z)
        z->_parent->_left_child = x;
      else
        z->_parent->_right_child = x;
    }
    // If the node to be erased was leftmost node
    if (leftmost == z) {
      if (z->_right_child == 0)
        leftmost = z->_parent;
      else
        leftmost = _rb_tree_node_base::_minimum(x);
    }
    // If the node to be erased was rightmost node
    if (rightmost == z) {
      if (z->_left_child == 0)
        rightmost = z->_parent;
      else
        rightmost = _rb_tree_node_base::_maximum(x);
    }
  }  // !SECTION
  // SECTION: Check rb-tree qualification due to the color to be erased
  // NOTE: y: The color to be erased
  // NOTE: x: (Case A) successor 가 데리고 있던 자식 노드 (Case B) successor
  // Solve by Case 2 if the color to be erased was black
  if (y->_color == BLACK) {
    while (x != root && (x == 0 || x->_color == BLACK)) {
      if (x == x_parent->_left_child) {
        // Brother node of x
        _rb_tree_node_base* w = x_parent->_right_child;
        // (Case 2-d)
        if (w->_color == RED) {
          w->_color = BLACK;
          x_parent->_color = RED;
          _rb_tree_rotate_left(x_parent, root);
          w = x_parent->_right_child;
        }
        // (Case 2-c)
        if ((w->_left_child == 0 || w->_left_child->_color == BLACK) &&
            (w->_right_child == 0 || w->_right_child->_color == BLACK)) {
          w->_color = RED;
          x = x_parent;
          x_parent = x_parent->_parent;
        }
        // (Case 2-b)
        else {
          if (w->_right_child == 0 || w->_right_child->_color == BLACK) {
            w->_left_child->_color = BLACK;
            w->_color = RED;
            _rb_tree_rotate_right(w, root);
            w = x_parent->_right_child;
          }
          // (Case 2-a)
          w->_color = x_parent->_color;
          x_parent->_color = BLACK;
          if (w->_right_child) w->_right_child->_color = BLACK;
          _rb_tree_rotate_left(x_parent, root);
          break;
        }
      }
      // x was the right child of the parent node
      // right <-> left from the code above
      else {
        _rb_tree_node_base* w = x_parent->_left_child;
        // (Case 2-d)
        if (w->_color == RED) {
          w->_color = BLACK;
          x_parent->_color = RED;
          _rb_tree_rotate_right(x_parent, root);
          w = x_parent->_left_child;
        }
        // (Case 2-c)
        if ((w->_left_child == 0 || w->_left_child->_color == BLACK) &&
            (w->_right_child == 0 || w->_right_child->_color == BLACK)) {
          w->_color = RED;
          x = x_parent;
          x_parent = x_parent->_parent;
        }
        // (Case 2-b) x 의 형제 노드의 왼쪽 자식만 black
        else {
          if (w->_left_child == 0 || w->_left_child->_color == BLACK) {
            w->_right_child->_color = BLACK;
            w->_color = RED;
            _rb_tree_rotate_left(w, root);
            w = x_parent->_left_child;
          }
          // (Case 2-a)
          w->_color = x_parent->_color;
          x_parent->_color = BLACK;
          if (w->_left_child) w->_left_child->_color = BLACK;
          _rb_tree_rotate_right(x_parent, root);
          break;
        }
      }
    }
    // Change red-and-black into black
    if (x) x->_color = BLACK;
  }
  // Return the node to be erased to deallocate outside
  return y;
}
}  // namespace ft
#endif
