/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:07:15 by sokim             #+#    #+#             */
/*   Updated: 2023/01/17 15:49:42 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <string>

#include "test.hpp"

#if 1  // CREATE A REAL STL EXAMPLE
#include <map>
#include <stack>
#include <vector>
namespace ft = std;
#else
#include <map.hpp>
#include <stack.hpp>
#include <vector.hpp>
#endif

#include <stdlib.h>
#include <time.h>  // time()

int main() {
  time_t start, end;
  time_t result;

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
  start = time(NULL);

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
  end = time(NULL);
  result = end - start;
  std::cout << "****************************************" << std::endl;
  std::cout << "*           Execution Time             *" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "Execution time: " << result << " seconds\n";
  // system("leaks containers");
  return 0;
}
