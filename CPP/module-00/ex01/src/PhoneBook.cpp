/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:14:37 by sokim             #+#    #+#             */
/*   Updated: 2022/07/04 18:40:55 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	idx = 0;
}

void	PhoneBook::Start() const
{
	std::cout << std::endl << "*********************************" << std::endl;
	std::cout << "Awesome phonebook!" << std::endl;
	std::cout << "Below are the commands you can use." << std::endl << std::endl;
	std::cout << "ADD : Save a new contact" << std::endl;
	std::cout << "SEARCH : Display a specific contact" << std::endl;
	std::cout << "EXIT : Quit the phonebook" << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;
}

void	PhoneBook::AddContact()
{
	std::string	input[5];

	std::cout << "*********************************" << std::endl;
	std::cout << "Fill in the form to add a contact." << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, input[0]);
	if (std::cin.eof())
		exit(0);
	std::cout << "Last name: ";
	std::getline(std::cin, input[1]);
	if (std::cin.eof())
		exit(0);
	std::cout << "Nickname: ";
	std::getline(std::cin, input[2]);
	if (std::cin.eof())
		exit(0);
	std::cout << "Phone number: ";
	std::getline(std::cin, input[3]);
	if (std::cin.eof())
		exit(0);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input[4]);
	if (std::cin.eof())
		exit(0);
	if (input[0] == "" || input[1] == "" || input[2] == "" || input[3] == "" || input[4] == "")
	{
		std::cout << "***********  ERROR  ***********" << std::endl;
		std::cout << "You must fill in all the fields." << std::endl;
		std::cout << "*******************************" << std::endl << std::endl;
		return ;
	}
	contacts[idx] = Contact(idx, input[0], input[1], input[2], input[3], input[4]);
	if (idx == 7)
		idx = 0;
	else
		idx += 1;
}

int	PhoneBook::DisplayContactList()
{
	int	cnt;

	cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].GetIndex() == -1)
			break ;
		contacts[i].DisplayContact();
		cnt++;
	}
	if (cnt == 0)
	{
		std::cout << "There is no contact saved yet." << std::endl;
		return (false);
	}
	return (true);
}

void	PhoneBook::SearchContact()
{
	int	input;
	int	exist;

	exist = DisplayContactList();
	if (!exist)
		return ;
	std::cout << "Search contact by index: " << std::endl;
	std::cin >> input;
	std::cin.ignore();
	if (std::cin.eof())
		exit(0);
	if (std::cin.fail() || input < 0 || input > 7)
	{
		std::cin.clear();
		std::cout << "******************  ERROR  ******************" << std::endl;
		std::cout << "Invalid input! Enter number between 0 and 7." << std::endl;
		std::cout << "*********************************************" << std::endl << std::endl;
		return ;
	}
	contacts[input].DisplaySearchedContact();
}
