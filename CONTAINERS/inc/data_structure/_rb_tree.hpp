/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:10:51 by sokim             #+#    #+#             */
/*   Updated: 2023/01/20 14:14:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <cstddef>  // std::ptrdiff_t
#include <iterator>

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

  _rb_tree_color _color;

  _base_ptr _parent;
  _base_ptr _left_child;
  _base_ptr _right_child;

  static _base_ptr minimum(_base_ptr node) {
    while (node->_left_child) node = node->_left_child;
    return node;
  }

  static _base_ptr maximum(_base_ptr node) {
    while (node->_right_child) node = node->_right_child;
    return node;
  }
};

template <typename value_type>
struct _rb_tree_node : public rb_tree_node_base {
  typedef _rb_tree_node<value_type>* _link_type;
  value_type _value;
};

struct _rb_tree_base_iterator {
  typedef _rb_tree_node_base::_base_ptr _base_ptr;
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef std::random_access_iterator_tag iterator_category;
  typedef std::ptrdiff_t difference_type;

  _base_ptr _node;

  /**
   * @brief Increment the base iterator.
   *
   * If you increment the rightmost node, then it will become the header node
   * which represents nil node.
   */
  void _increment() {
    if (_node->_right_child) {
      _node = _node->_right_child;
      while (_node->_left_child) _node = _node->_left_child;
    } else {
      _base_ptr p = _node->_parent;
      while (_node == p->_right_child) {
        _node = p;
        p = p->_parent;
      }
      if (_node->_right_child != p) _node = p;
    }
  }
};
}  // namespace ft

#endif
