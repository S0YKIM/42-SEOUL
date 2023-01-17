/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:32:00 by sokim             #+#    #+#             */
/*   Updated: 2023/01/17 15:21:30 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <sstream>

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
  std::cout << std::endl;
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

  std::cout << "****************************************" << std::endl;
  std::cout << "*             Element Access           *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Change the data in the 2nd element by []." << std::endl
            << std::endl;
  v[1] = 42;
  print_info(v);

  std::cout << "- Change the data in the 8th element by at()." << std::endl
            << std::endl;
  v.at(7) = 42;
  print_info(v);

  std::cout << "- Change the data in the 1st element by front()." << std::endl
            << std::endl;
  v.front() = 42;
  print_info(v);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                Resize                *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Resize to 1." << std::endl << std::endl;
  v.resize(1);
  print_info(v);

  std::cout << "- Resize to 5." << std::endl << std::endl;
  v.resize(5, 0);
  print_info(v);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                Erase                 *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Erase the first element." << std::endl << std::endl;
  v.erase(v.begin());
  print_info(v);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                Assign                *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Assign five '100's to the vector." << std::endl << std::endl;
  v.assign(5, 100);
  print_info(v);

  std::cout << "- Assign data from istringstream." << std::endl << std::endl;
  std::istringstream str("1 2 3 4 5 6 7 8 9 10");
  v.assign(std::istream_iterator<int>(str), std::istream_iterator<int>());
  print_info(v);

  std::cout << "****************************************" << std::endl;
  std::cout << "*            Range Constructor         *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Create another temporary vector." << std::endl << std::endl;
  ft::vector<int> tmp(v.begin(), v.end());
  print_info(tmp);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                Clear                 *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Clear the vector." << std::endl << std::endl;
  v.clear();
  print_info(v);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                Swap                  *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Swap the vectors." << std::endl << std::endl;
  v.swap(tmp);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                   v                  *" << std::endl;
  std::cout << "****************************************" << std::endl;
  print_info(v);

  std::cout << "****************************************" << std::endl;
  std::cout << "*                tmp                   *" << std::endl;
  std::cout << "****************************************" << std::endl;
  print_info(tmp);

  std::cout << "****************************************" << std::endl;
  std::cout << "*         Relational Operators         *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Compare two vectors \"v\" and \"other\"\n\n";
  if (v == tmp)
    std::cout << "v == tmp\n\n";
  else if (v < tmp)
    std::cout << "v < tmp\n\n";
  else if (v > tmp)
    std::cout << "v > tmp\n\n";
}

void test_const_vector() {
  const ft::vector<int> v(5, 42);
  const ft::vector<int> other(10, 0);

  print_info(v);
  print_info(other);

  std::cout << "****************************************" << std::endl;
  std::cout << "*             Element Access           *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- v[1]: ";
  std::cout << v[1] << std::endl << std::endl;
  try {
    std::cout << "- v.at(1): ";
    std::cout << v.at(1) << std::endl << std::endl;
    std::cout << "- v.at(7): ";
    std::cout << v.at(7) << std::endl << std::endl;
  } catch (...) {
    std::cout << "Exception: Index out of range.\n\n";
  }

  std::cout << "****************************************" << std::endl;
  std::cout << "*         Relational Operators         *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Compare two vectors \"v\" and \"other\"\n\n";
  if (v == other)
    std::cout << "v == other\n\n";
  else if (v < other)
    std::cout << "v < other\n\n";
  else if (v > other)
    std::cout << "v > other\n\n";
}
