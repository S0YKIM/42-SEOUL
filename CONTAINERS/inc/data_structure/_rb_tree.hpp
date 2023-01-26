/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:10:51 by sokim             #+#    #+#             */
/*   Updated: 2023/01/26 16:12:17 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <exception>

#include "rb_tree_iterator.hpp"

namespace ft {
inline void _rb_tree_rotate_left(_rb_tree_node_base* node,
                                 _rb_tree_node_base*& root);

inline void _rb_tree_rotate_right(_rb_tree_node_base* node,
                                  _rb_tree_node_base*& root);

void _rb_tree_rebalance_after_insertion(_rb_tree_node_base* node,
                                        _rb_tree_node_base*& root);

_rb_tree_node_base* _rb_tree_rebalance_for_erase(
    _rb_tree_node_base* node, _rb_tree_node_base*& root,
    _rb_tree_node_base*& leftmost, _rb_tree_node_base*& rightmost);

// TODO: Implement _rb_tree
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

 public:
  typedef Key key_type;
  typedef Val value_type;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef _rb_tree_node* link_type;
  typedef const _rb_tree_node* const_link_type;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef Alloc allocator_type;

 protected:
  /**
   * @brief Contains the actual data(key_compare, header)
   *
   * @tparam Compare Functor to compare keys
   */
  template <typename KeyCompare>
  struct _rb_tree_impl : public node_allocator {
    KeyCompare _key_compare;
    _rb_tree_node_base _header;
    size_type _node_count;

    _rb_tree_impl(const node_allocator& a = node_allocator(),
                  const KeyCompare& comp = KeyCompare())
        : node_allocator(a), _key_compare(comp), _header(), _node_count(0) {
      _header._color = RED;
      _header._parent = 0;
      _header._left_child = &_header;
      _header._right_child = &_header;
    }
  };

  _rb_tree_impl<Compare> _impl;

  // NOTE: Member functions
  node_allocator& get_node_allocator() {
    return *static_cast<node_allocator*>(&_impl);
  }

  const node_allocator& get_node_allocator() const {
    return *static_cast<node_allocator*>(&_impl);
  }

  allocator_type get_allocator() const {
    return allocator_type(get_node_allocator());
  }

 protected:
  // SECTION: Node management
  /**
   * @brief Allocate a node.
   *
   * @return _rb_tree_node* The address of the node allocated
   */
  _rb_tree_node* _get_node() { _impl.node_allocator::allocate(1); }

  /**
   * @brief Deallocate the given node.
   *
   * @param node The node to be deallocated
   */
  void _put_node(_rb_tree_node* node) {
    _impl.node_allocator::deallocate(node, 1);
  }

  /**
   * @brief Create a node with the given value.
   *
   * @param value The given value
   * @return link_type The address of the created node
   */
  link_type _create_node(const value_type& value) {
    link_type tmp = _get_node();
    try {
      get_allocator().construct(&tmp->_value, value);
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
    get_allocator().destroy(&node->_value);
    _put_node(node);
  }  // !SECTION

  // SECTION: Element access
  /**
   * @brief Get the reference of the root node base.
   */
  _base_ptr& _root() { return _impl._header._parent; }
  _const_base_ptr& _root() const { return _impl._header._parent; }

  /**
   * @brief Get the reference of the leftmost node base.
   */
  _base_ptr& _leftmost() { return _impl._header._left_child; }
  _const_base_ptr& _leftmost() const { return _impl._header._left_child; }

  /**
   * @brief Get the reference of the rightmost node base.
   */
  _base_ptr& _rightmost() { return _impl._header._right_child; }
  _const_base_ptr& _rightmost() const { return _impl._header._right_child; }

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
  link_type _end() { return static_cast<link_type>(_impl._header); }
  const_link_type _end() const {
    return static_cast<const_link_type>(_impl._header);
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

  static const_link_type& _parent(_const_base_ptr node) {
    return static_cast<const_link_type&>(node->_parent);
  }

  /**
   * @brief Get the left child of the given node.
   *
   * @param node
   * @return link_type
   */
  static link_type& _left(_base_ptr node) {
    return static_cast<link_type>(node->_left_child);
  }

  static const_link_type _left(_const_base_ptr node) {
    return static_cast<const_link_type>(node->_left_child);
  }

  /**
   * @brief Get the right child of the given node.
   *
   * @param node
   * @return link_type
   */
  static link_type& _right(_base_ptr node) {
    return static_cast<link_type>(node->_right_child);
  }

  static const_link_type _right(_const_base_ptr node) {
    return static_cast<const_link_type>(node->_right_child);
  }

  /**
   * @brief Get the node which has the smallest key below the given node.
   *
   * @param node
   * @return _base_ptr
   */
  static _base_ptr _minimum(_base_ptr node) {
    return _rb_tree_node_base::minimum(node);
  }

  static _const_base_ptr minimum(_const_base_ptr node) {
    return _rb_tree_node_base::minimum(node);
  }

  /**
   * @brief Get the node which has the biggest key below the given node.
   *
   * @param node
   * @return _base_ptr
   */
  static _base_ptr _maximum(_base_ptr node) {
    return _rb_tree_node_base::maximum(node);
  }

  static _const_base_ptr maximum(_const_base_ptr node) {
    return _rb_tree_node_base::maximum(node);
  }  // !SECTION

 public:
  typedef _rb_tree_iterator<value_type> iterator;
  typedef _rb_tree_const_iterator<value_type> const_iterator;

  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  iterator _insert(_base_ptr x, _base_ptr y, const value_type& value);

  const_iterator _insert(_const_base_ptr x, _const_base_ptr y,
                         const value_type& value);

  // TODO: _M_insert_lower() 구현?
  link_type _copy(const_link_type x, link_type p);
};
}  // namespace ft
#endif
