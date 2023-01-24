/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:30:21 by sokim             #+#    #+#             */
/*   Updated: 2023/01/10 16:43:44 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <algorithm>  // FIXME
#include <deque>
#include <iostream>
#include <stack.hpp>
#include <stack>
#include <string>
#include <utility>  // FIXME
#include <vector>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
#define COUNT 10

struct Buffer {
  int idx;
  char buff[BUFFER_SIZE];
};

template <typename T>
class MutantStack : public ft::stack<T> {
 public:
  MutantStack() {}
  MutantStack(const MutantStack<T>& src) { *this = src; }
  MutantStack<T>& operator=(const MutantStack<T>& rhs) {
    this->c_ = rhs.c_;
    return *this;
  }
  ~MutantStack() {}

  typedef typename ft::stack<T>::container_type::iterator iterator;

  iterator begin() { return this->c_.begin(); }
  iterator end() { return this->c_.end(); }
};

int main() {
  {
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
    std::cout << "*             Int stack (1)            *" << std::endl;
    std::cout << "****************************************" << std::endl;
    size_1 = stack_int_1.size();
    for (size_t idx = 0; idx < size_1; idx++) {
      std::cout << stack_int_1.top() << std::endl;
      stack_int_1.pop();
    }
    std::cout << std::endl << std::endl;

    std::cout << "****************************************" << std::endl;
    std::cout << "*             Int stack (2)            *" << std::endl;
    std::cout << "****************************************" << std::endl;
    size_2 = stack_int_2.size();
    for (size_t idx = 0; idx < size_2; idx++) {
      std::cout << stack_int_2.top() << std::endl;
      stack_int_2.pop();
    }
    std::cout << std::endl;
  }
  {
    MutantStack<char> iterable_stack;

    std::cout << "****************************************" << std::endl;
    std::cout << "*         Iterable char stack          *" << std::endl;
    std::cout << "****************************************" << std::endl;
    for (char letter = 'a'; letter <= 'z'; letter++)
      iterable_stack.push(letter);
    for (MutantStack<char>::iterator it = iterable_stack.begin();
         it != iterable_stack.end(); it++) {
      std::cout << *it;
    }
    std::cout << std::endl << std::endl;
  }
  {
    Buffer buf;
    ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;

    std::cout << "****************************************" << std::endl;
    std::cout << "*      User defined buffer stack       *" << std::endl;
    std::cout << "****************************************" << std::endl;
    for (int idx = 0; idx < 10; idx++) {
      int i;
      for (i = 0; i < idx; i++) buf.buff[i] = i + 'a';
      buf.buff[i] = '\0';
      buf.idx = idx;
      stack_deq_buffer.push(buf);
    }
    for (int idx = 0; idx < 10; idx++) {
      std::cout << stack_deq_buffer.top().buff << std::endl;
      stack_deq_buffer.pop();
    }
    std::cout << std::endl;

    const int a = 1;
    const int& ref = a;
  }
  return (0);
}
