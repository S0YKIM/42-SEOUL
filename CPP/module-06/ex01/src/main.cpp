/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:19:59 by sokim             #+#    #+#             */
/*   Updated: 2022/07/12 15:45:00 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static uintptr_t	serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

static Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main(void) {
	Data	a;
	a.num = 42;
	a.msg = "Hello world!";
	uintptr_t b = serialize(&a);
	Data	*c = deserialize(b);

	std::cout << "*******************************************" << std::endl;
	std::cout << "Original address: " << &a << std::endl;
	std::cout << "Original num: " << a.num << std::endl;
	std::cout << "Original msg: " << a.msg << std::endl;
	std::cout << "*******************************************" << std::endl << std::endl;

	std::cout << "*******************************************" << std::endl;
	std::cout << "Serialized dec: " << b << std::endl;
	std::cout << "Serialized hex: " << std::hex << b << std::dec << std::endl;
	std::cout << "*******************************************" << std::endl << std::endl;

	std::cout << "*******************************************" << std::endl;
	std::cout << "Deserialized address: " << c << std::endl;
	std::cout << "Deserialized num: " << c->num << std::endl;
	std::cout << "Deserialized msg: " << c->msg << std::endl;
	std::cout << "*******************************************" << std::endl << std::endl;

	return (0);
}
