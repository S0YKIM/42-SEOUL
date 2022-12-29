/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:50:36 by sokim             #+#    #+#             */
/*   Updated: 2022/12/29 15:40:36 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <type_traits>

#include "iterator_base_types.hpp"

namespace ft {
template <typename Iter>
class reverse_iterator
    : public iterator<typename iterator_traits<Iter>::iterator_category,
                      typename iterator_traits<Iter>::value_type,
                      typename iterator_traits<Iter>::difference_type,
                      typename iterator_traits<Iter>::pointer,
                      typename iterator_traits<Iter>::reference> {
 protected:
  Iter current;

 public:
  typedef typename iterator_traits<Iter> traits;

  typedef typename traits::difference_type difference_type;
  typedef typename traits::reference reference;
  typedef typename traits::pointer pointer;

 public:
  /* Default constructor */
  reverse_iterator() : current() {}

  /* Constructor to set current using base iterator */
  explicit reverse_iterator(Iter baseIt) : current(baseIt) {}

  /* Normal copy constructor */
  reverse_iterator(const reverse_iterator &other) : current(other.current) {}

  /* Copy constructor copying from other type */
  template <typename IterType>
  reverse_iterator(const reverse_iterator<IterType> &other)
      : current(other.base()) {}

  /* Getter function for current */
  Iter base() const { return current; }

  // NOTE: Operator overloading
  // SECTION: Dereference operators
  /* Return element of which position is just before current */
  reference operator*() const {
    Iter tmp = current;

    --tmp;
    return *tmp;
  }

  pointer operator->() const {
    Iter tmp = current;

    --tmp;
    return tmp;
  }  // !SECTION

  // SECTION: Subscript operator
  reference operator[](difference_type n) const {
    Iter tmp = current - n;

    return *tmp;
  }  // !SECTION

  // SECTION: Increment and decrement operators
  reverse_iterator &operator++() {
    --current;
    return *this;
  }

  reverse_iterator operator++(int) {
    reverse_iterator tmp(*this);

    --current;
    return tmp;
  }

  reverse_iterator &operator--() {
    ++current;
    return *this;
  }

  reverse_iterator operator--(int) {
    reverse_iterator tmp(*this);

    ++current;
    return tmp;
  }  // !SECTION

  // SECTION: Arithmetic operators
  reverse_iterator operator+(difference_type n) const {
    reverse_iterator tmp(current - n);

    return tmp;
  }

  reverse_iterator &operator+=(difference_type n) {
    current -= n;
    return *this;
  }

  reverse_iterator operator-(difference_type n) const {
    reverse_iterator tmp(current + n);

    return tmp;
  }

  reverse_iterator &operator-=(difference_type n) {
    current += n;
    return *this;
  }  // !SECTION
};

// NOTE: Non-member functions
// SECTION: Relational operators
template <typename IterTypeL, typename IterTypeR>
inline bool operator==(const reverse_iterator<IterTypeL> &lhs,
                       const reverse_iterator<IterTypeR> &rhs) {
  return lhs.base() == rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline bool operator!=(const reverse_iterator<IterTypeL> &lhs,
                       const reverse_iterator<IterTypeR> &rhs) {
  return lhs.base() != rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline bool operator<(const reverse_iterator<IterTypeL> &lhs,
                      const reverse_iterator<IterTypeR> &rhs) {
  return lhs.base() > rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline bool operator<=(const reverse_iterator<IterTypeL> &lhs,
                       const reverse_iterator<IterTypeR> &rhs) {
  return lhs.base() >= rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline bool operator>(const reverse_iterator<IterTypeL> &lhs,
                      const reverse_iterator<IterTypeR> &rhs) {
  return lhs.base() < rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline bool operator>=(const reverse_iterator<IterTypeL> &lhs,
                       const reverse_iterator<IterTypeR> &rhs) {
  return lhs.base() <= rhs.base();
}  // !SECTION

// SECTION: Arithmetic operators
template <typename Iter>
inline typename reverse_iterator<Iter>::difference_type operator-(
    const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
  return rhs.base() - lhs.base();
}

template <typename Iter>
inline reverse_iterator<Iter> operator+(
    typename reverse_iterator<Iter>::difference_type n,
    const reverse_iterator<Iter> &rhs) {
  reverse_iterator<Iter> tmp(rhs.base() - n);

  return tmp;
}  // !SECTION
}  // namespace ft
#endif
