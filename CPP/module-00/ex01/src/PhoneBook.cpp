/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:14:37 by sokim             #+#    #+#             */
/*   Updated: 2022/07/03 20:29:59 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	idx = 0;
}

void	PhoneBook::Start() const
{
	std::cout << "*********************************" << std::endl;
	std::cout << "Welcome to awesome phonebook!" << std::endl;
	std::cout << "Below are the commands you can use." << std::endl << std::endl;
	std::cout << "ADD : Save a new contact" << std::endl;
	std::cout << "SEARCH : Display a specific contact" << std::endl;
	std::cout << "EXIT : Quit the phonebook" << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;
}

void	PhoneBook::Add()
{
	std::string	input[5];

	std::cout << "*********************************" << std::endl;
	std::cout << "Fill in the form to add a contact." << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, input[0]);
	std::cout << "Last name: ";
	std::getline(std::cin, input[1]);
	std::cout << "Nickname: ";
	std::getline(std::cin, input[2]);
	std::cout << "Phone number: ";
	std::getline(std::cin, input[3]);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input[4]);
	if (input[0] == "" || input[1] == "" || input[2] == "" || input[3] == "" || input[4] == "")
	{
		std::cout << "***********  ERROR  ***********" << std::endl;
		std::cout << "You must fill in all the fields." << std::endl;
		std::cout << "*******************************" << std::endl << std::endl;
		return ;
	}
	contacts[idx] = Contact(input[0], input[1], input[2], input[3], input[4]);
	if (idx == 7)
		idx = 0;
	else
		idx += 1;
}

void	PhoneBook::Search() const
{
	int	idx;

	std::cout << "Enter the index you want to search." << std::endl;
	std::cin >> idx;
}

