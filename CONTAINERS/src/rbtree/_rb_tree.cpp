/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:29:36 by sokim             #+#    #+#             */
/*   Updated: 2023/01/24 17:10:18 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_rb_tree.hpp"
namespace ft {
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
}  // namespace ft
