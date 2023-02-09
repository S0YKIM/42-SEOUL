/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:49:23 by sokim             #+#    #+#             */
/*   Updated: 2023/02/09 14:37:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {
template <typename T, typename Container = ft::vector<T> >
class stack;

template <typename T, typename Container>
inline bool operator==(const ft::stack<T, Container>& lhs,
                       const ft::stack<T, Container>& rhs);

template <typename T, typename Container>
inline bool operator<(const ft::stack<T, Container>& lhs,
                      const ft::stack<T, Container>& rhs);

template <typename T, typename Container>
class stack {
 public:
  template <typename T1, typename C1>
  friend bool operator==(const ft::stack<T1, C1>& lhs,
                         const ft::stack<T1, C1>& rhs);

  template <typename T1, typename C1>
  friend bool operator<(const ft::stack<T1, C1>& lhs,
                        const ft::stack<T1, C1>& rhs);

  typedef Container container_type;
  typedef typename Container::value_type value_type;
  typedef typename Container::size_type size_type;
  typedef typename Container::reference reference;
  typedef typename Container::const_reference const_reference;

 protected:
  Container c;

 public:
  /**
   * @brief Default constructor or copy constructor
   */
  explicit stack(const container_type& con = container_type()) : c(con) {}

  /**
   * @brief Returns a read or write reference to the data at the first element
   * of the stack
   */
  reference top() { return c.back(); }

  /**
   * @brief Returns a read-only constant reference to the data at the first
   * element of the stack
   */
  const_reference top() const { return c.back(); }

  /**
   * @brief Returns true if the stack is empty
   */
  bool empty() const { return c.empty(); }

  /**
   * @brief Returns the number of elements in the stack
   */
  size_type size() const { return c.size(); }

  /**
   * @brief Creates an element at the top of the stack and assigns the given
   * data to it
   */
  void push(const value_type& value) { c.push_back(value); }

  /**
   * @brief Removes the top element from the stack
   */
  void pop() { c.pop_back(); }
};

template <typename T, typename Container>
inline bool operator==(const ft::stack<T, Container>& lhs,
                       const ft::stack<T, Container>& rhs) {
  return lhs.c == rhs.c;
}

template <typename T, typename Container>
inline bool operator<(const ft::stack<T, Container>& lhs,
                      const ft::stack<T, Container>& rhs) {
  return lhs.c < rhs.c;
}

template <typename T, typename Container>
inline bool operator!=(const ft::stack<T, Container>& lhs,
                       const ft::stack<T, Container>& rhs) {
  return !(lhs == rhs);
}

template <typename T, typename Container>
inline bool operator<=(const ft::stack<T, Container>& lhs,
                       const ft::stack<T, Container>& rhs) {
  return !(rhs < lhs);
}

template <typename T, typename Container>
inline bool operator>(const ft::stack<T, Container>& lhs,
                      const ft::stack<T, Container>& rhs) {
  return rhs < lhs;
}

template <typename T, typename Container>
inline bool operator>=(const ft::stack<T, Container>& lhs,
                       const ft::stack<T, Container>& rhs) {
  return !(lhs < rhs);
}
}  // namespace ft

#endif
