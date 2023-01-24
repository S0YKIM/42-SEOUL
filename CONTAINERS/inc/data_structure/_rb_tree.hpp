/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:10:51 by sokim             #+#    #+#             */
/*   Updated: 2023/01/24 21:34:37 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP

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

  // TODO: Implement struct _rb_tree_impl
  node_allocator& get_node_allocator() {
    return *static_cast<node_allocator*>(&this->_impl);
  }

  const node_allocator& get_node_allocator() const {
    return *static_cast<node_allocator*>(&this->_impl);
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
  _rb_tree_node* _get_node() { _impl._node_allocator::allocate(1); }

  /**
   * @brief Deallocate the given node.
   *
   * @param node The node to be deallocated
   */
  void _put_node(_rb_tree_node* node) {
    _impl._node_allocator::deallocate(node, 1);
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
    } catch (...) {
      _put_node(tmp);
      throw std::exception(
          "ft::_rb_tree::_create_node() Failed to create node.");
    }
    return tmp;
  }
};
}  // namespace ft

#endif
