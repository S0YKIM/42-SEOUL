/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:10:51 by sokim             #+#    #+#             */
/*   Updated: 2023/01/26 12:13:16 by sokim            ###   ########.fr       */
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
      header._color = RED;
      header._parent = 0;
      header._left_child = &header;
      header._right_child = &header;
    }
  };

  _rb_tree_impl<Compare> _impl;

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
    } catch (std::exception& e) {
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
  }

  /**
   * @brief Get the reference of the root node base.
   */
  _base_ptr& _root() { return _impl._header._parent; }
  const_base_ptr& _root() const { return _impl._header._parent; }

  /**
   * @brief Get the reference of the leftmost node base.
   */
  _base_ptr& _leftmost() { return _impl._header._left_child; }
  const_base_ptr& _leftmost() const { return _impl._header._left_child; }

  /**
   * @brief Get the reference of the rightmost node base.
   */
  _base_ptr& _rightmost() { return _impl._header._right_child; }
  const_base_ptr& _rightmost() const { return _impl._header._right_child; }

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
};
}  // namespace ft

#endif
