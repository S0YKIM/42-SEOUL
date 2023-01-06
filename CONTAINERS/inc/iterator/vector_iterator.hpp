/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:11:36 by sokim             #+#    #+#             */
/*   Updated: 2023/01/06 11:24:41 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator_base_types.hpp"

namespace ft {
template <typename Iter>  // T*
class vector_iterator
    : public iterator<typename iterator_traits<Iter>::iterator_category,
                      typename iterator_traits<Iter>::value_type,
                      typename iterator_traits<Iter>::difference_type,
                      typename iterator_traits<Iter>::pointer,
                      typename iterator_traits<Iter>::reference> {
 public:
  typedef typename iterator_traits<Iter> traits;

  typedef typename traits::iterator_category iterator_category;
  typedef typename traits::value_type value_type;
  typedef typename traits::difference_type difference_type;
  typedef typename traits::pointer pointer;
  typedef typename traits::reference reference;

 private:
  Iter _current;

 public:
  /* Default constructor */
  vector_iterator() {}

  explicit vector_iterator(const Iter &current) : _current(current) {}

  /* Copy constructor */
  template <typename I1>
  inline vector_iterator(const vector_iterator<I1> &other)
      : _current(other.base()) {}

  /* Getter function for current */
  const Iter &base() const { return _current; }

  // NOTE Operator overloading
  // SECTION Forward iterator requirements
  reference operator*() const { return *_current; }

  pointer operator->() const { return _current; }

  vector_iterator &operator++() {
    ++_current;
    return *this;
  }

  vector_iterator operator++(int) {
    vector_iterator tmp(_current);

    ++_current;
    return tmp;
  }  // !SECTION

  // SECTION Bidirectional iterator requirements
  vector_iterator &operator--() {
    --_current;
    return *this;
  }

  vector_iterator oprator--(int) {
    vector_iterator tmp(_current);

    --_current;
    return tmp;
  }  // !SECTION

  // SECTION Random access iterator requirements
  reference operator[](const difference_type &n) const { return _current[n]; }

  vector_iterator operator+(const difference_type &n) const {
    vector_iterator tmp(_current + n);

    return tmp;
  }

  vector_iterator &operator+=(const difference_type &n) {
    _current += n;
    return *this;
  }

  vector_iterator operator-(const difference_type &n) const {
    vector_iterator tmp(_current - n);

    return tmp;
  }

  vector_iterator &operator-=(const difference_type &n) {
    _current -= n;
    return *this;
  }  // !SECTION
};

// NOTE Non-member functions
// NOTE Relational operators
// SECTION Forward iterator requirements
template <typename IterTypeL, typename IterTypeR>
inline bool operator==(const vector_iterator<IterTypeL> &lhs,
                       const vector_iterator<IterTypeR> &rhs) {
  return lhs.base() == rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline bool operator!=(const vector_iterator<IterTypeL> &lhs,
                       const vector_iterator<IterTypeR> &rhs) {
  return lhs.base() != rhs.base();
}

// SECTION Random access iterator requirements
template <typename IterTypeL, typename IterTypeR>
inline bool operator<(const vector_iterator<IterTypeL> &lhs,
                      const vector_iterator<IterTypeR> &rhs) {
  return lhs.base() < rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline bool operator<=(const vector_iterator<IterTypeL> &lhs,
                       const vector_iterator<IterTypeR> &rhs) {
  return lhs.base() <= rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline bool operator>(const vector_iterator<IterTypeL> &lhs,
                      const vector_iterator<IterTypeR> &rhs) {
  return lhs.base() > rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline bool operator>=(const vector_iterator<IterTypeL> &lhs,
                       const vector_iterator<IterTypeR> &rhs) {
  return lhs.base() >= rhs.base();
}

template <typename IterTypeL, typename IterTypeR>
inline typename vector_iterator<IterTypeL>::difference_type operator-(
    const vector_iterator<IterTypeL> &lhs,
    const vector_iterator<IterTypeR> &rhs) {
  return lhs.base() - rhs.base();
}

template <typename IterType>
inline vector_iterator<IterType> operator+(
    const typename vector_iterator<IterType>::difference_type n,
    const vector_iterator<IterType> &i) {
  vector_iterator tmp(n + i.base());

  return tmp;
}  // !SECTION
}  // namespace ft
#endif
