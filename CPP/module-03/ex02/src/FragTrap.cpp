/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:57:03 by sokim             #+#    #+#             */
/*   Updated: 2022/07/08 09:48:51 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called." << std::endl;
	this->name = "";
	this->maxHitPoints = 100;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " constructed." << std::endl;
	this->name = name;
	this->maxHitPoints = 100;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &origin) {
	std::cout << "FragTrap " << origin.name << " copied." << std::endl;
	*this = origin;
}

FragTrap &FragTrap::operator=(const FragTrap &origin) {
	std::cout << "FragTrap " << origin.name << " assigned." << std::endl;
	if (this == &origin)
		return (*this);
	this->name = origin.name;
	this->maxHitPoints = origin.maxHitPoints;
	this->hitPoints = origin.hitPoints;
	this->energyPoints = origin.energyPoints;
	this->attackDamage = origin.attackDamage;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destructed." << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << "✋ HighFivesGuys ✋" << std::endl;
}
