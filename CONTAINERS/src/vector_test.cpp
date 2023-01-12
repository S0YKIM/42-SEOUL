/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:32:00 by sokim             #+#    #+#             */
/*   Updated: 2023/01/12 21:37:57 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template <typename Iter>
static void print_vector(Iter it, Iter ite) {
  while (it != ite) {
    std::cout << *it;
    ++it;
    if (it == ite)
      std::cout << std::endl << std::endl;
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
  std::cout << "- Push back five times." << std::endl << std::endl;
  for (int i = 1; i < 6; i++) v.push_back(i);
  print_info(v);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                Reserve               *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Reserve 3: There will be no change." << std::endl
            << std::endl;
  v.reserve(3);
  print_info(v);

  std::cout << "- Reserve 10: The capacity should change." << std::endl
            << std::endl;
  v.reserve(10);
  print_info(v);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                Insert                *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Insert one element." << std::endl << std::endl;
  v.insert(v.begin() + 1, 100);
  print_info(v);

  std::cout << "- Insert five elements." << std::endl << std::endl;
  v.insert(v.begin() + 2, 5, 42);
  print_info(v);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                Popback               *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Pop back three times." << std::endl << std::endl;
  for (int i = 0; i < 3; i++) v.pop_back();
  print_info(v);
}
