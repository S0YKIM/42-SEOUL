/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:00:22 by sokim             #+#    #+#             */
/*   Updated: 2022/07/14 14:32:50 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main() {
	{
		std::cout << "*******************************************" << std::endl;
		std::cout << "*               BASIC TEST                *" << std::endl;
		std::cout << "*******************************************" << std::endl;
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << "*******************************************" << std::endl;
		std::cout << "*               CUSTOM TEST               *" << std::endl;
		std::cout << "*******************************************" << std::endl;
		MutantStack<int>	mstack;

		for (int i = 1; i <= 5; i++)
			mstack.push(i);

		std::cout << "Top : " << mstack.top() << std::endl;
		std::cout << "Size : " << mstack.size() << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "Custom stack : ";
		while (it != ite) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		std::cout << "Reverse stack : ";
		while (rit != rite) {
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;
	}
	return (0);
}
