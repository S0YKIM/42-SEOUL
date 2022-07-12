/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:49:17 by sokim             #+#    #+#             */
/*   Updated: 2022/07/12 16:03:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base	*generate() {
	srand(time(NULL));
	switch (rand() % 3) {
	case 0:
		return new A();
		break;
	case 1:
		return new B();
		break;
	case 2:
		return new C();
		break;
	default:
		std::cerr << "Failed to generate random instance." << std::endl;
		break;
	}
	return (NULL);
}

void	identify(Base *p)
{
	// dynamic_cast가 성공하면 변환된 포인터, 실패하면 NULL 반환
	if (dynamic_cast<A*>(p))
		std::cout << "This is A class." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is B class." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is C class." << std::endl;
	else
		std::cerr << "Identification Failed: Pointer" << std::endl;
}

void	identify(Base& p)
{
	// dynamic_cast가 성공하면 변환된 참조자, 실패하면 throw exception
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "This is A class." << std::endl;
		return ;
	}
	catch (std::exception& e) {
		(void) e;
	}

	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "This is B class." << std::endl;
		return;
	}
	catch (std::exception& e)
	{
		(void) e;
	}

	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "This is C class." << std::endl;
		return;
	}
	catch (std::exception& e)
	{
		(void) e;
		std::cerr << "Identification Failed: Reference" << std::endl;
	}
}
