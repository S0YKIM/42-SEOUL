/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:29:36 by sokim             #+#    #+#             */
/*   Updated: 2023/01/24 19:58:09 by sokim            ###   ########.fr       */
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
  // NOTE: y: (Case A) 삭제할 노드의 successor (Case B) 삭제할 노드
  _rb_tree_node_base* y = z;
  // NOTE: x: (Case A) successor 가 데리고 있던 자식 노드 (Case B) successor
  // successor가 삭제한 노드의 자리를 대신하게 되면 successor의 자리를 대신함
  _rb_tree_node_base* x = 0;
  _rb_tree_node_base* x_parent = 0;
  // SECTION: successor 결정
  // (Case B) 왼쪽 자식이 없으면 successor 를 오른쪽 자식으로 정함
  // 오른쪽 자식도 없다고 하더라도 문제는 없음
  if (y->_left_child == 0) x = y->_right_child;
  // 왼쪽 자식이 존재하는 경우
  else {
    // (Case B) 오른쪽 자식이 없다면 successor 를 왼쪽 자식으로 정함
    if (y->_right_child == 0) x = y->_left_child;
    // (Case A) 두 자식 노드가 모두 존재함
    else {
      // 삭제될 노드의 successor
      y = y->_right_child;
      while (y->_left_child) y = y->_left_child;
      x = y->_right_child;
    }
  }  // !SECTION
  // SECTION: (Case A) 두 자식이 모두 존재했던 경우
  if (y != z) {
    // 왼쪽 자식의 부모를 successor 로 바꿔줌
    z->_left_child->_parent = y;
    // successor 의 왼쪽 자식을 삭제될 노드의 왼쪽 자식으로 변경
    y->_left_child = z->_left_child;
    // successor 가 삭제될 노드의 오른쪽 자식이 아니었던 경우
    // 즉, 오른쪽 자식 노드가 왼쪽 서브 트리를 가지고 있었던 경우
    // successor 가 자리를 옮기게 되면 그의 자식 노드(x)가 길을 잃으므로 적절히
    // 옮겨준다
    if (y != z->_right_child) {
      // successor 를 삭제할 노드의 자리로 옮기기 전에 x 의 부모를 successor 의
      // 부모로 변경
      x_parent = y->_parent;
      if (x) x->_parent = y->_parent;
      // successor 의 부모 노드의 왼쪽 자식을 x 로 변경
      y->_parent->_left_child = x;
      // successor 의 오른쪽 자식을 삭제할 노드의 오른쪽 자식으로 변경
      y->_right_child = z->_right_child;
      // 삭제할 노드의 오른쪽 자식의 부모 노드를 successor 로 변경
      z->_right_child->_parent = y;
    }
    // successor 가 삭제될 노드의 오른쪽 자식이었던 경우
    // 즉, 오른쪽 자식 노드가 왼쪽 서브 트리를 가지지 않았던 경우
    // successor 의 오른쪽 자식은 그대로 successor 를 따라간다
    else
      x_parent = y;
    // 삭제할 노드가 루트 노드였던 경우, 루트 노드를 successor 로 변경
    if (root == z) root = y;
    // 삭제할 노드가 부모 노드의 왼쪽 자식이었던 경우, 부모 노드의 왼쪽 자식을
    // successor 로 변경
    else if (z->_parent->_left_child == z)
      z->_parent->_left_child = y;
    // 삭제할 노드가 부모 노드의 오른쪽 자식이었던 경우, 부모 노드의 오른쪽
    // 자식을 successor 로 변경
    else
      z->_parent->_right_child = y;
    // successor 의 부모 노드를 삭제할 노드의 부모 노드로 변경
    y->_parent = z->_parent;
    // 삭제할 노드와 successor 의 색을 스왑
    std::swap(y->_color, z->_color);
    // NOTE: y 가 이제 실제로 삭제된 노드를 가리킴
    y = z;
  }  // !SECTION
  // SECTION: (Case B) 삭제할 노드의 자식 노드가 하나만 존재하거나 두 자식 노드
  // 모두 없었던 경우. 여기선 x 가 successor
  else {
    x_parent = y->_parent;
    // successor 의 부모 노드를 삭제할 노드의 부모 노드로 변경
    if (x) x->_parent = y->_parent;
    // 삭제할 노드가 루트 노드였던 경우 루트 노드를 successor 로 변경
    if (root == z)
      root = x;
    else {
      // 삭제할 노드가 부모의 왼쪽 자식이었던 경우, 부모의 왼쪽 자식을 successor
      // 로 변경
      if (z->_parent->_left_child == z) z->_parent->_left_child = x;
      // 삭제할 노드가 부모의 오른쪽 자식이었던 경우, 부모의 오른쪽 자식을
      // successor 로 변경
      else
        z->_parent->_right_child = x;
    }
    // 삭제할 노드가 트리의 leftmost 였던 경우
    if (leftmost == z) {
      // leftmost 의 오른쪽 자식이 없는 경우(->자식 노드가 둘 다 없음),
      // leftmost 를 기존 leftmost 의 부모 노드로 변경
      if (z->_right_child == 0) leftmost = z->_parent;
      // leftmost 의 오른쪽 자식이 있는 경우, 그 오른쪽 자식의 왼쪽 서브
      // 트리(자기 자신 포함) 중에서 가장 작은 노드를 leftmost 로 변경
      // 이 경우, leftmost 의 오른쪽 자식이 successor 였을 것임
      else
        leftmost = _rb_tree_node_base::minimum(x);
    }
    // 삭제할 노드가 트리의 rightmost 였던 경우
    if (rightmost == z) {
      // 삭제할 노드의 왼쪽 자식이 없는 경우(->자식 노드가 둘 다 없음),
      // rightmost 를 기존 rightmost 의 부모 노드로 변경
      if (z->_left_child == 0) rightmost = z->_parent;
      // rightmost 의 왼쪽 자식이 있는 경우, 그 왼쪽 자식의 오른쪽 서브
      // 트리(자기 자신 포함) 중에서 가장 큰 노드를 rightmost 로 변경
      // 이 경우, rightmost 의 왼쪽 자식이 successor 였을 것임
      else
        rightmost = _rb_tree_node_base::maximum(x);
    }
  }  // !SECTION
  // SECTION: 삭제되는 색에 따른 레드블랙트리 속성 검사
  // NOTE: y: 삭제된 노드
  // NOTE: x: (Case A) successor 가 데리고 있던 자식 노드 (Case B) successor
  // 삭제되는 색이 black 인 경우 Case 2 로 해결
  if (y->_color == BLACK) {
    while (x != root && (x == 0 || x->_color == BLACK)) {
      // x 가 부모의 왼쪽 자식이었을 경우
      if (x == x_parent->_left_child) {
        // x 의 형제 노드
        _rb_tree_node_base* w = x_parent->_right_child;
        // (Case 2-d) x 의 형제 노드가 red
        if (w->_color == RED) {
          w->_color = BLACK;
          x_parent->_color = RED;
          _rb_tree_rotate_left(x_parent, root);
          w = x_parent->_right_child;
        }
        // (Case 2-c) x 의 형제 노드의 두 자식이 모두 black
        if ((w->_left_child == 0 || w->_left_child->_color == BLACK) &&
            (w->_right_child == 0 || w->_right_child->_color == BLACK)) {
          w->_color = RED;
          x = x_parent;
          x_parent = x_parent->_parent;
        }
        // (Case 2-b) x 의 형제 노드의 오른쪽 자식만 black
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
      // x 가 부모의 오른쪽 자식이었을 경우
      // 위의 코드에서 right <-> left 서로 바꾸면 됨
      else {
        _rb_tree_node_base* w = x_parent->_left_child;
        // (Case 2-d) x 의 형제 노드가 red
        if (w->_color == RED) {
          w->_color = BLACK;
          x_parent->_color = RED;
          _rb_tree_rotate_right(x_parent, root);
          w = x_parent->_left_child;
        }
        // (Case 2-c) x 의 형제 노드의 두 자식이 모두 black
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
    // red-and-black 을 black 으로 바꿔줌(black 이면 변화 없음)
    if (x) x->_color = BLACK;
  }
  // 밖에서 메모리 해제하기 위해 트리에서 삭제된 노드 반환
  return y;
}
}  // namespace ft
