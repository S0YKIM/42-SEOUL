/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:06:18 by sokim             #+#    #+#             */
/*   Updated: 2022/07/04 17:18:59 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	while (true)
	{	
		phonebook.Start();
		std::cout << "> ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.AddContact();
		else if (command == "SEARCH")
			phonebook.SearchContact();
		else if (command == "EXIT" || std::cin.eof())
			break ;
		else
		{
			std::cout << "*******************  ERROR  *******************" << std::endl;
			std::cout << "ERROR: Available options are (ADD, SEARCH, EXIT)" << std::endl;
			std::cout << "***********************************************" << std::endl << std::endl;
		}
	}
	return (0);
}
