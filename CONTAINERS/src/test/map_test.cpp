/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:32:00 by sokim             #+#    #+#             */
/*   Updated: 2023/02/09 13:19:48 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

#include <sstream>
#include <string>
#include <vector>

#include "test.hpp"

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
void print_rb_tree(const std::string& prefix,
                   const ft::_rb_tree_node_base* node, bool isLeft) {
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
    std::cout << "(" << x->_value.first << ", ";
    std::cout << x->_value.second << ")" << PRINT_RESET << std::endl;

    // enter the next tree level - left and right branch
    ::print_rb_tree<T>(prefix + (!isLeft ? "│   " : "    "), node->_right_child,
                       false);
    ::print_rb_tree<T>(prefix + (!isLeft ? "│   " : "    "), node->_left_child,
                       true);
  } else {
    std::cout << prefix;
    std::cout << (!isLeft ? "├── (R) " : "└── (L) ");
    std::cout << PRINT_WHITE << "NIL" << PRINT_RESET << std::endl;
  }
}

template <typename T>
void print_rb_tree(ft::_rb_tree_iterator<T> it) {
  ft::_rb_tree_node_base* header = it._node;

  if (header->_parent == NULL) return;
  // root 시작
  ::print_rb_tree<T>("", header->_parent, false);
  std::cout << "\n\n";
}

void test_map() {
  ft::map<int, std::string> m;

  std::cout << "****************************************" << std::endl;
  std::cout << "*                 Insert               *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Insert a pair of (1, 'a').\n\n";
  m.insert(ft::make_pair(1, "a"));
  print_rb_tree(m.end());

  std::cout << "- Insert a pair of (2, 'b') to the first place.\n\n";
  m.insert(m.begin(), ft::make_pair(2, "b"));
  print_rb_tree(m.end());

  std::cout << "- Insert a range from (3, 'c') to (5, 'e').\n\n";
  std::vector<ft::pair<int, std::string> > v;
  v.push_back(ft::make_pair(3, "c"));
  v.push_back(ft::make_pair(4, "d"));
  v.push_back(ft::make_pair(5, "e"));
  m.insert(v.begin(), v.end());
  print_rb_tree(m.end());

  std::cout << "****************************************" << std::endl;
  std::cout << "*                 Erase                *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Erase the leftmost node (1, 'a').\n\n";
  m.erase(m.begin());
  print_rb_tree(m.end());

  std::cout << "- Erase the node (3, 'c').\n\n";
  m.erase(3);
  print_rb_tree(m.end());

  std::cout << "****************************************" << std::endl;
  std::cout << "*                 Count                *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Count the number of nodes of which key is 4.\n\n";
  std::cout << m.count(4) << std::endl << std::endl;

  std::cout << "****************************************" << std::endl;
  std::cout << "*                 Swap                *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Create another map.\n\n";
  ft::map<int, std::string> other(v.begin(), v.end());
  print_rb_tree(other.end());

  std::cout << "- Swap two maps.\n\n";
  swap(m, other);
  print_rb_tree(m.end());
  print_rb_tree(other.end());
}
