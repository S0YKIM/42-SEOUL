/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:11:36 by sokim             #+#    #+#             */
/*   Updated: 2022/12/28 16:39:51 by sokim            ###   ########.fr       */
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
  // FIXME 만약 테스트했는데 iterator 상속 받는 것만으로 typedef 가 된다면 아래
  // 코드 지우기
 public:
  typedef typename iterator_traits<Iter> traits;

  typedef typename traits::iterator_category iterator_category;
  typedef typename traits::value_type value_type;
  typedef typename traits::difference_type difference_type;
  typedef typename traits::pointer pointer;
  typedef typename traits::reference reference;

 private:
  Iter current_;

 public:
  /* Default constructor */
  vector_iterator() {}

  explicit vector_iterator(const Iter &current) : current_(current) {}

  /* Copy constructor */
  template <typename I1>
  inline vector_iterator(const vector_iterator<I1> &other)
      : current_(other.base()) {}

  /* Getter function for current */
  const Iter &base() const { return current_; }

  // NOTE Operator overloading
  // SECTION Forward iterator requirements
  reference operator*() const { return *current_; }
  pointer operator->() const { return current_; }
  vector_iterator &operator++() {
    ++current_;
    return *this;
  }

  vector_iterator operator++(int) {
    vector_iterator tmp(current_);

    ++current_;
    return tmp;
  }  // !SECTION

  // SECTION Bidirectional iterator requirements
  vector_iterator &operator--() {
    --current_;
    return *this;
  }

  vector_iterator oprator--(int) {
    vector_iterator tmp(current_);

    --current_;
    return tmp;
  }  // !SECTION

  // SECTION Random access iterator requirements
  reference operator[](const difference_type &n) const { return current_[n]; }
  vector_iterator operator+(const difference_type &n) const {
    vector_iterator tmp(current_ + n);

    return tmp;
  }

  vector_iterator &operator+=(const difference_type &n) {
    current_ += n;
    return *this;
  }

  vector_iterator operator-(const difference_type &n) const {
    vector_iterator tmp(current_ - n);

    return tmp;
  }

  vector_iterator &operator-=(const difference_type &n) {
    current_ -= n;
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

template <typename IterType>
inline bool operator==(const vector_iterator<IterType> &lhs,
                       const vector_iterator<IterType> &rhs) {
  return lhs.base() == rhs.base();
}

template <typename IterType>
inline bool operator!=(const vector_iterator<IterType> &lhs,
                       const vector_iterator<IterType> &rhs) {
  return lhs.base() != rhs.base();
}  // !SECTION

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
