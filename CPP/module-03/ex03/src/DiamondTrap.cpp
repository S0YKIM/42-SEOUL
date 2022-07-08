/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:54:52 by sokim             #+#    #+#             */
/*   Updated: 2022/07/08 15:40:42 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called." << std::endl;
	this->name = "Default";
	this->maxHitPoints = FragTrap::MAX_HIT_POINTS;
	this->hitPoints = FragTrap::MAX_HIT_POINTS;
	this->energyPoints = ScavTrap::ENERGY_POINTS;
	this->attackDamage = FragTrap::ATTACK_DAMAGE;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap " << name << " constructed." << std::endl;
	this->name = name;
	this->maxHitPoints = FragTrap::MAX_HIT_POINTS;
	this->hitPoints = FragTrap::MAX_HIT_POINTS;
	this->energyPoints = ScavTrap::ENERGY_POINTS;
	this->attackDamage = FragTrap::ATTACK_DAMAGE;
}

DiamondTrap::DiamondTrap(const DiamondTrap &origin) {
	std::cout << "DiamondTrap " << origin.name << " copied." << std::endl;
	*this = origin;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &origin) {
	std::cout << "DiamondTrap " << origin.name << " assigned." << std::endl;
	if (this == &origin)
		return (*this);
	this->name = origin.name;
	this->maxHitPoints = origin.maxHitPoints;
	this->hitPoints = origin.hitPoints;
	this->energyPoints = origin.energyPoints;
	this->attackDamage = origin.attackDamage;
	ClapTrap::operator=(origin);
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destructed." << std::endl;
}

void	DiamondTrap::attack(const std::string &target) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "I'm " << this->name << " and also " << this->ClapTrap::name << std::endl;
}
