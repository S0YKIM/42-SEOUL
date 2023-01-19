/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:10:51 by sokim             #+#    #+#             */
/*   Updated: 2023/01/19 18:33:13 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP

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
}  // namespace ft

#endif
