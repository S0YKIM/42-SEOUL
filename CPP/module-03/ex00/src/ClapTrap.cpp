/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:56:13 by sokim             #+#    #+#             */
/*   Updated: 2022/07/07 15:33:04 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called." << std::endl;
	this->name = "";
	this->max_hit_points = 10;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
	this->name = name;
	this->max_hit_points = 10;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &origin) {
	std::cout << "ClapTrap " << origin.name << " copied." << std::endl;
	*this = origin;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &origin) {
	std::cout << "ClapTrap " << origin.name << " assigned." << std::endl;
	if (this == &origin)
		return (*this);
	this->name = origin.name;
	this->hit_points = origin.hit_points;
	this->energy_points = origin.energy_points;
	this->attack_damage = origin.attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructed." << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->hit_points <= 0 || this->energy_points <= 0) {
		std::cout << this->name << " can't attack anyone. It seems to be broken!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attack_damage;
	std::cout << " points of damage!" << std::endl;
	this->energy_points -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points <= 0) {
		std::cout << "ClapTrap " << this->name << "'s HP is already zero!" << std::endl;
		return ;
	}
	this->hit_points -= amount;
	if (this->hit_points <= 0)
		this->hit_points = 0;
	std::cout << "ClapTrap " << this->name << " takes damage, losing ";
	std::cout << amount << " points of HP!" << std::endl;
	std::cout << "ClapTrap " << this->name << "'s HP is now " << this->hit_points << "." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hit_points <= 0 || this->energy_points <= 0) {
		std::cout << "ClapTrap " << this->name << " can't be repaired. It seems to be broken." << std::endl;
		return ;
	}
	std::cout << this->name << " got " << amount << " HP points back from repair." << std::endl;
	this->energy_points -= 1;
	this->hit_points += amount;
	if (this->hit_points > this->max_hit_points)
		this->hit_points = this->max_hit_points;
}

void	ClapTrap::displayStatus() {
	std::cout << "******************** " << this->name << "'s status " << "********************" << std::endl;
	std::cout << "- Hit Points: " << this->hit_points << std::endl;
	std::cout << "- Energy Points: " << this->energy_points << std::endl;
	std::cout << "- Attack Damage: " << this->attack_damage << std::endl;
	std::cout << "**********************************************************" << std::endl;
}
