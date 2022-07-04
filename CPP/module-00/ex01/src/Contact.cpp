/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:14:38 by sokim             #+#    #+#             */
/*   Updated: 2022/07/04 17:38:38 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	index = -1;
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::Contact(int index, std::string first_name, std::string last_name, \
		std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->index = index;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string	Contact::Truncate(std::string original) const
{
	if (original.length() > MAX_FIELD_LEN)
		return (original.substr(0, MAX_FIELD_LEN - 1) + ".");
	return (original);
}

int		Contact::GetIndex() const
{
	return (index);
}

void	Contact::DisplayContact() const
{
	std::cout << "|" << std::setw(MAX_FIELD_LEN) << index;
	std::cout << "|" << std::setw(MAX_FIELD_LEN) << Truncate(first_name);
	std::cout << "|" << std::setw(MAX_FIELD_LEN) << Truncate(last_name);
	std::cout << "|" << std::setw(MAX_FIELD_LEN) << Truncate(nickname);
	std::cout << "|" << std::endl;
}

void	Contact::DisplaySearchedContact() const
{
	if (index == -1)
	{
		std::cout << "******************  ERROR  ******************" << std::endl;
		std::cout << "Invalid input! No contact saved there yet." << std::endl;
		std::cout << "*********************************************" << std::endl << std::endl;
		return ;
	}
	std::cout << "*********************************************" << std::endl;
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
	std::cout << "*********************************************" << std::endl << std::endl;
}
