/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:06:25 by sokim             #+#    #+#             */
/*   Updated: 2023/01/26 20:10:28 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
template <typename T1, typename T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  first_type first;
  second_type second;

  pair() : first(), second() {}

  template <typename T, typename U>
  pair(const pair<T, U> &other) : first(other.first), second(other.second) {}

  pair(const first_type &a, const second_type &b) : first(a), second(b) {}

  pair &operator=(const pair &other) {
    if (this != &other) {
      first = other.first;
      second = other.second;
    }
    return *this;
  }

  void swap(pair &other) {
    std::swap(first, other.first);
    std::swap(second, other.second);
  }
};

template <typename T1, typename T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <typename T1, typename T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return !(lhs == rhs);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return lhs.first < rhs.first ||
         (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <typename T1, typename T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return rhs < lhs;
}

template <typename T1, typename T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return !(lhs < rhs);
}

template <typename T1, typename T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return !(rhs < lhs);
}

template <typename T1, typename T2>
void swap(pair<T1, T2> &x, pair<T1, T2> &y) {
  x.swap(y);
}

/**
 * @brief Constructs a pair object with its first element set to x and its
 * second element set to y.
 *
 * @tparam T1
 * @tparam T2
 * @param x
 * @param y
 * @return pair<T1, T2>
 */
template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
  return pair<T1, T2>(x, y);
}

/**
 * @brief Functor class used as KeyOfValue.
 *
 * @tparam pair
 *
 * By overloading operator(), it can operate like a function even if it is a
 * struct(or class). It returns a key of the given pair.
 * Usage example: select_first(pairName)
 */
template <typename pair>
struct select_first {
  typename pair::first_type &operator()(pair &x) const { return x.first; }
  const typename pair::first_type &operator()(const pair &x) const {
    return x.first;
  }
};
}  // namespace ft

#endif
