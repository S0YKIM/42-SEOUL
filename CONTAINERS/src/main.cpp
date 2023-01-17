/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:07:15 by sokim             #+#    #+#             */
/*   Updated: 2023/01/17 14:33:56 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int main() {
  int option = 0;

  std::cout << "****************************************" << std::endl;
  std::cout << "*          Enter number to test        *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "* [1] - Vector                         *" << std::endl;
  std::cout << "* [2] - Stack                          *" << std::endl;
  std::cout << "* [3] - Map                            *" << std::endl;
  std::cout << "* [4] - Set                            *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << std::endl;
  std::cin >> option;

  switch (option) {
    case 1:
      test_vector();
      // test_const_vector();
      break;
    case 2:
      std::cout << "2" << std::endl;
      break;
    case 3:
      std::cout << "3" << std::endl;
      break;
    case 4:
      std::cout << "4" << std::endl;
      break;
    default:
      std::cout << "Please enter a valid number." << std::endl;
      break;
  }
  return 0;
}
