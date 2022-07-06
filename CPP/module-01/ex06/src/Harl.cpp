/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:39:38 by sokim             #+#    #+#             */
/*   Updated: 2022/07/06 13:19:50 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// private
void	Harl::debug() {
	std::cerr << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cerr << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cerr << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error() {
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// public
Harl::Harl() {
}

Harl::~Harl() {
}

int		Harl::selectOption(std::string level) {
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	option = -1;
	for (int i = 0; i < 4; i++) {
		if (level == levels[i])
			option = i;
	}
	return (option);
}

void	Harl::complain(std::string level) {
	void	(Harl::*func[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int	option;
	option = selectOption(level);
	switch (option) {
		case 0:
			(this->*func[0])();
		case 1:
			(this->*func[1])();
		case 2:
			(this->*func[2])();
		case 3:
			(this->*func[3])();
			break ;
		default:
			std::cout << "Probably complaining about insignificant problems" << std::endl;
			break ;
	}
}
