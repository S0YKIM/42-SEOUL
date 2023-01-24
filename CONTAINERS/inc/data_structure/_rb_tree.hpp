/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:10:51 by sokim             #+#    #+#             */
/*   Updated: 2023/01/24 16:08:52 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "rb_tree_iterator.hpp"

namespace ft {
/**
 * @brief Left rotate
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
// TODO: Implement _rb_tree
template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc = std::allocator<Val> >
class _rb_tree {};
}  // namespace ft

#endif
