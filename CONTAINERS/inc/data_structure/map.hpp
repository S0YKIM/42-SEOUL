/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:49:41 by sokim             #+#    #+#             */
/*   Updated: 2023/01/26 20:36:28 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef>     // std::ptrdiff_t
#include <functional>  // std::less
#include <memory>      // std::allocator

#include "_rb_tree.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<pair<const Key, T>>>
class map {
 public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef pair<const Key, T> value_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;

  typedef size_t size_type;
  typedef std::ptrdiff_t difference_type;

  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;

 private:
  typedef _rb_tree<key_type, value_type, ft::select_first<value_type>,
                   key_compare, allocator_type>
      base_structure;
  base_structure base;

 public:
  typedef typename base::iterator iterator;
  typedef typename base::const_iterator const_iterator;
  typedef typename base::reverse_iterator reverse_iterator;
  typedef typename base::const_reverse_iterator const_reverse_iterator;

  class value_compare {
    friend class map<Key, T, Compare, Alloc>;

   protected:
    key_compare comp;
    value_compare(key_compare c) : comp(c) {}

   public:
    bool operator()(const value_type& x, const value_type& y) const {
      return comp(x.first, y.first);
    }
  };
};
}  // namespace ft

#endif
