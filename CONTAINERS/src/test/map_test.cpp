/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:32:00 by sokim             #+#    #+#             */
/*   Updated: 2023/02/08 18:59:07 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

#include <sstream>
#include <string>

#include "test.hpp"

void test_map() {
  ft::map<int, std::string> m;

  std::cout << "****************************************" << std::endl;
  std::cout << "*                 Insert               *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "- Insert 'a' to 'c'." << std::endl << std::endl;
  m.insert(ft::make_pair(1, "a"));
  m.insert(ft::make_pair(2, "b"));
  m.insert(ft::make_pair(3, "c"));
}
