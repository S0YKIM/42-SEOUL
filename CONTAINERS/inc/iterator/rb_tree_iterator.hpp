/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:33:29 by sokim             #+#    #+#             */
/*   Updated: 2023/01/26 19:47:12 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_ITERATOR_HPP
#define RB_TREE_ITERATOR_HPP

#include <cstddef>   // std::ptrdiff_t
#include <iterator>  // std::bidirectional_iterator_tag

namespace ft {
enum _rb_tree_color { RED, BLACK };

/**
 * @brief Base class of _rb_tree_node class
 *
 * Because it will be only used to insert, delete, and rebalance in rbtree, it
 * doesn't need the info of the value that each node has.
 */
struct _rb_tree_node_base {
  typedef _rb_tree_node_base* _base_ptr;
  typedef const _rb_tree_node_base* _const_base_ptr;

  _rb_tree_color _color;

  _base_ptr _parent;
  _base_ptr _left_child;
  _base_ptr _right_child;

  static _base_ptr minimum(_base_ptr node) {
    while (node->_left_child) node = node->_left_child;
    return node;
  }

  static _const_base_ptr minimum(_const_base_ptr node) {
    while (node->_left_child) node = node->_left_child;
    return node;
  }

  static _base_ptr maximum(_base_ptr node) {
    while (node->_right_child) node = node->_right_child;
    return node;
  }

  static _const_base_ptr maximum(_const_base_ptr node) {
    while (node->_right_child) node = node->_right_child;
    return node;
  }
};

template <typename value_type>
struct _rb_tree_node : public _rb_tree_node_base {
  typedef _rb_tree_node<value_type>* _link_type;
  value_type _value;
};

template <typename Val>
struct _rb_tree_iterator {
  typedef Val value_type;
  typedef Val& reference;
  typedef Val* pointer;

  typedef std::bidirectional_iterator_tag iterator_category;
  typedef std::ptrdiff_t difference_type;

  typedef _rb_tree_iterator<Val> self;
  typedef _rb_tree_node_base::_base_ptr base_ptr;
  typedef _rb_tree_node<Val>* link_type;

  base_ptr _node;

  _rb_tree_iterator() : _node() {}
  _rb_tree_iterator(link_type node) : _node(node) {}

  /**
   * @brief Increment the iterator.
   *
   * If you increment the rightmost node, then it will become the header node
   * which represents nil node.
   */
  void _increment() {
    if (_node->_right_child) {
      _node = _node->_right_child;
      while (_node->_left_child) _node = _node->_left_child;
    } else {
      base_ptr tmp = _node->_parent;
      while (_node == tmp->_right_child) {
        _node = tmp;
        tmp = tmp->_parent;
      }
      if (_node->_right_child != tmp) _node = tmp;
    }
  }

  /**
   * @brief Decrement the base iterator.
   *
   * If you decrement the header node, then it will become the rightmost node.
   */
  void _decrement() {
    if (_node->_color == RED && _node->_parent->_parent == _node)
      _node = _node->_right_child;
    else if (_node->_left_child) {
      base_ptr tmp = _node->_left_child;
      while (tmp->_right_child) tmp = tmp->_right_child;
      _node = tmp;
    } else {
      base_ptr tmp = _node->_parent;
      while (_node == tmp->_left_child) {
        _node = tmp;
        tmp = tmp->_parent;
      }
      _node = tmp;
    }
  }

  // SECTION: Operator overloading
  reference operator*() const { return static_cast<link_type>(_node)->_value; }

  pointer operator->() const { return &(operator*()); }

  self& operator++() {
    _increment();
    return *this;
  }

  self operator++(int) {
    self tmp = *this;
    _increment();
    return tmp;
  }

  self& operator--() {
    _decrement();
    return *this;
  }

  self operator--(int) {
    self tmp = *this;
    _decrement();
    return tmp;
  }  // !SECTION
};

template <typename Val>
struct _rb_tree_const_iterator {
  typedef Val value_type;
  typedef const Val& reference;
  typedef const Val* pointer;

  typedef _rb_tree_iterator<Val> iterator;

  typedef std::bidirectional_iterator_tag iterator_category;
  typedef std::ptrdiff_t difference_type;

  typedef _rb_tree_const_iterator<Val> self;
  typedef _rb_tree_node_base::_const_base_ptr base_ptr;
  typedef const _rb_tree_node<Val>* link_type;

  base_ptr _node;

  _rb_tree_const_iterator() : _node() {}
  explicit _rb_tree_const_iterator(link_type node) : _node(node) {}
  _rb_tree_const_iterator(const iterator& it) : _node(it._node) {}

  /**
   * @brief Increment the iterator.
   *
   * If you increment the rightmost node, then it will become the header node
   * which represents nil node.
   */
  void _increment() {
    if (_node->_right_child) {
      _node = _node->_right_child;
      while (_node->_left_child) _node = _node->_left_child;
    } else {
      base_ptr tmp = _node->_parent;
      while (_node == tmp->_right_child) {
        _node = tmp;
        tmp = tmp->_parent;
      }
      if (_node->_right_child != tmp) _node = tmp;
    }
  }

  /**
   * @brief Decrement the base iterator.
   *
   * If you decrement the header node, then it will become the rightmost node.
   */
  void _decrement() {
    if (_node->_color == RED && _node->_parent->_parent == _node)
      _node = _node->_right_child;
    else if (_node->_left_child) {
      base_ptr tmp = _node->_left_child;
      while (tmp->_right_child) tmp = tmp->_right_child;
      _node = tmp;
    } else {
      base_ptr tmp = _node->_parent;
      while (_node == tmp->_left_child) {
        _node = tmp;
        tmp = tmp->_parent;
      }
      _node = tmp;
    }
  }

  // SECTION: Operator overloading
  reference operator*() const { return static_cast<link_type>(_node)->_value; }

  pointer operator->() const { return &(operator*()); }

  self& operator++() {
    _increment();
    return *this;
  }

  self operator++(int) {
    self tmp = *this;
    _increment();
    return tmp;
  }

  self& operator--() {
    _decrement();
    return *this;
  }

  self operator--(int) {
    self tmp = *this;
    _decrement();
    return tmp;
  }  // !SECTION
};

// SECTION: Non-member function
template <typename Val>
inline bool operator==(const _rb_tree_iterator<Val>& lhs,
                       const _rb_tree_iterator<Val>& rhs) {
  lhs._node == rhs._node;
}

template <typename Val>
inline bool operator==(const _rb_tree_const_iterator<Val>& lhs,
                       const _rb_tree_const_iterator<Val>& rhs) {
  lhs._node == rhs._node;
}

template <typename Val>
inline bool operator==(const _rb_tree_iterator<Val>& lhs,
                       const _rb_tree_const_iterator<Val>& rhs) {
  lhs._node == rhs._node;
}

template <typename Val>
inline bool operator==(const _rb_tree_const_iterator<Val>& lhs,
                       const _rb_tree_iterator<Val>& rhs) {
  lhs._node == rhs._node;
}

template <typename Val>
inline bool operator!=(const _rb_tree_iterator<Val>& lhs,
                       const _rb_tree_iterator<Val>& rhs) {
  lhs._node != rhs._node;
}

template <typename Val>
inline bool operator!=(const _rb_tree_const_iterator<Val>& lhs,
                       const _rb_tree_const_iterator<Val>& rhs) {
  lhs._node != rhs._node;
}

template <typename Val>
inline bool operator!=(const _rb_tree_iterator<Val>& lhs,
                       const _rb_tree_const_iterator<Val>& rhs) {
  lhs._node != rhs._node;
}

template <typename Val>
inline bool operator!=(const _rb_tree_const_iterator<Val>& lhs,
                       const _rb_tree_iterator<Val>& rhs) {
  lhs._node != rhs._node;
}
}  // namespace ft

#endif
