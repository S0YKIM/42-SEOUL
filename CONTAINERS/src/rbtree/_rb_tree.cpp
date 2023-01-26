/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:29:36 by sokim             #+#    #+#             */
/*   Updated: 2023/01/26 16:00:06 by sokim            ###   ########.fr       */
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
        leftmost = _rb_tree_node_base::minimum(x);
    }
    // If the node to be erased was rightmost node
    if (rightmost == z) {
      if (z->_left_child == 0)
        rightmost = z->_parent;
      else
        rightmost = _rb_tree_node_base::maximum(x);
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

/**
 * @brief Insert a new node with the given value to the tree.
 *
 * @tparam Key
 * @tparam Val
 * @tparam KeyOfValue
 * @tparam Compare
 * @tparam Alloc
 * @param x Usually 0, sometimes leftmost or rightmost node.
 * @param y Address of a node which is going to be the parent of the new node.
 * @param value The value which the new node will have.
 * @return _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
 */
template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::_insert(
    _base_ptr x, _base_ptr y, const value_type& value) {
  link_type node;

  // Case 1: Add the new node as the left child of y.
  if (y == &_impl._header || x || _key_compare(KeyOfValue()(value), _key(y))) {
    node = _create_node(value);
    _left(y) = node;
    if (y == &_impl._header) {
      _root() = node;
      _rightmost() = node;
    } else if (y == _leftmost())
      _leftmost() = node;
  }
  // Case 2: Add the new node as the right child of y.
  else {
    node = _create_node(value);
    _right(y) = node;
    if (y == _rightmost()) _rightmost() = node;
  }
  _parent(node) = y;
  _left(node) = 0;
  _right(node) = 0;
  // Check if it still satisfies the properties of rbtree after insertion.
  _rb_tree_rebalance_after_insertion(node, _impl._header._parent);
  // Update the size of the rbtree.
  ++_impl._node_count;
  return iterator(node);
}

template <typename Key, typename Val, typename KeyOfValue, typename Compare,
          typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::const_iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::_insert(
    _const_base_ptr x, _const_base_ptr y, const value_type& value) {
  link_type node;

  // Case 1: Add the new node as the left child of y.
  if (y == &_impl._header || x || _key_compare(KeyOfValue()(value), _key(y))) {
    node = _create_node(value);
    _left(y) = node;
    if (y == &_impl._header) {
      _root() = node;
      _rightmost() = node;
    } else if (y == _leftmost())
      _leftmost() = node;
  }
  // Case 2: Add the new node as the right child of y.
  else {
    node = _create_node(value);
    _right(y) = node;
    if (y == _rightmost()) _rightmost() = node;
  }
  _parent(node) = y;
  _left(node) = 0;
  _right(node) = 0;
  // Check if it still satisfies the properties of rbtree after insertion.
  _rb_tree_rebalance_after_insertion(node, _impl._header._parent);
  // Update the size of the rbtree.
  ++_impl._node_count;
  return const_iterator(node);
}
}  // namespace ft
