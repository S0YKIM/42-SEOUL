/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:32:00 by sokim             #+#    #+#             */
/*   Updated: 2023/01/12 21:17:47 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template <typename Iter>
static void print_vector(Iter it, Iter ite) {
  while (it != ite) {
    std::cout << *it;
    ++it;
    if (it == ite)
      std::cout << std::endl;
    else
      std::cout << ", ";
  }
}

template <typename T>
static void print_info(const ft::vector<T> &v) {
  std::cout << "size: " << v.size() << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;
  print_vector(v.begin(), v.end());
}

void test_vector() {
  ft::vector<int> v;

  std::cout << "****************************************" << std::endl;
  std::cout << "*                Pushback              *" << std::endl;
  std::cout << "****************************************" << std::endl;
  for (int i = 1; i < 6; i++) v.push_back(i);
  print_info(v);
}
