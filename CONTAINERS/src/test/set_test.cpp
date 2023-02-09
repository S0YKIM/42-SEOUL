/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:32:00 by sokim             #+#    #+#             */
/*   Updated: 2023/02/09 13:50:47 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define PRINT_RED "\033[0;31m"
#define PRINT_GREEN "\033[0;32m"
#define PRINT_YELLOW "\033[0;33m"
#define PRINT_BLUE "\033[0;34m"
#define PRINT_MAGENTA "\033[0;35m"
#define PRINT_CYAN "\033[0;36m"
#define PRINT_WHITE "\033[0;37m"
#define PRINT_GRAY "\033[0;38m"
#define PRINT_RESET "\033[0m"

template <typename T>
void print_set(const std::string& prefix, const ft::_rb_tree_node_base* node,
               bool isLeft) {
  if (node != NULL) {
    typedef const ft::_rb_tree_node<T>* link_type;
    link_type x = static_cast<link_type>(node);
    std::cout << prefix;
    if (prefix.size() > 0)
      std::cout << (!isLeft ? "├── (R)" : "└── (L)");
    else {
      std::cout << "└── (root)";
      isLeft = true;
    }

    // print the value of the node
    std::string color = PRINT_RED;
    (x->_color == ft::RED) ? color = PRINT_RED : color = PRINT_WHITE;
    std::cout << color;
    std::cout << "(" << x->_value << ")" << PRINT_RESET << std::endl;

    // enter the next tree level - left and right branch
    ::print_set<T>(prefix + (!isLeft ? "│   " : "    "), node->_right_child,
                   false);
    ::print_set<T>(prefix + (!isLeft ? "│   " : "    "), node->_left_child,
                   true);
  } else {
    std::cout << prefix;
    std::cout << (!isLeft ? "├── (R) " : "└── (L) ");
    std::cout << PRINT_WHITE << "NIL" << PRINT_RESET << std::endl;
  }
}

template <typename T>
void print_set(ft::_rb_tree_const_iterator<T> it) {
  const ft::_rb_tree_node_base* header = it._node;

  if (header->_parent == NULL) return;
  // root 시작
  ::print_set<T>("", header->_parent, false);
  std::cout << "\n\n";
}

void test_set() {
  ft::set<int> s;

  std::cout << "****************************************" << std::endl;
  std::cout << "*                 Insert               *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Insert (1).\n\n";
  s.insert(1);
  print_set(s.end());

  std::cout << "- Insert (2) to the first place.\n\n";
  s.insert(s.begin(), 2);
  print_set(s.end());

  std::cout << "- Insert a range from (3) to (5).\n\n";
  std::vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  s.insert(v.begin(), v.end());
  print_set(s.end());

  std::cout << "****************************************" << std::endl;
  std::cout << "*                 Erase                *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Erase the leftmost node (1).\n\n";
  s.erase(s.begin());
  print_set(s.end());

  std::cout << "- Erase the node (3).\n\n";
  s.erase(3);
  print_set(s.end());

  std::cout << "****************************************" << std::endl;
  std::cout << "*                 Count                *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Count the number of nodes of which key is 4.\n\n";
  std::cout << s.count(4) << std::endl << std::endl;

  std::cout << "****************************************" << std::endl;
  std::cout << "*                 Swap                *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Create another set.\n\n";
  ft::set<int> other(v.begin(), v.end());
  print_set(other.end());

  std::cout << "- Swap two sets.\n\n";
  swap(s, other);
  print_set(s.end());
  print_set(other.end());
}
