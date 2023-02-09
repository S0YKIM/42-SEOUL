/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:32:00 by sokim             #+#    #+#             */
/*   Updated: 2023/02/09 14:01:58 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void test_stack() {
  ft::stack<int> stack_int_1;
  ft::stack<int> stack_int_2;
  size_t size_1;
  size_t size_2;

  for (int i = 1; i <= 10; i++) stack_int_1.push(i);
  for (int i = 1; i <= 20; i++) stack_int_2.push(i);

  std::cout << "****************************************" << std::endl;
  std::cout << "*          Compare two stacks          *" << std::endl;
  std::cout << "****************************************" << std::endl;
  if (stack_int_1 == stack_int_2)
    std::cout << "stack no.1 is equal to stack no.2" << std::endl;
  else if (stack_int_1 < stack_int_2)
    std::cout << "stack no.1 is smaller than stack no.2" << std::endl;
  else if (stack_int_1 > stack_int_2)
    std::cout << "stack no.1 is larger than stack no.2" << std::endl;
  std::cout << std::endl;

  std::cout << "****************************************" << std::endl;
  std::cout << "*         Int stack (1) - Pop          *" << std::endl;
  std::cout << "****************************************" << std::endl;
  size_1 = stack_int_1.size();
  for (size_t idx = 0; idx < size_1; idx++) {
    std::cout << stack_int_1.top() << std::endl;
    stack_int_1.pop();
  }
  std::cout << std::endl << std::endl;

  std::cout << "****************************************" << std::endl;
  std::cout << "*         Int stack (2) - Pop          *" << std::endl;
  std::cout << "****************************************" << std::endl;
  size_2 = stack_int_2.size();
  for (size_t idx = 0; idx < size_2; idx++) {
    std::cout << stack_int_2.top() << std::endl;
    stack_int_2.pop();
  }
  std::cout << std::endl;
}
