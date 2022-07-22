/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:56:08 by sokim             #+#    #+#             */
/*   Updated: 2022/07/07 15:58:33 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap {
protected:
	std::string	name;
	int			maxHitPoints;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &origin);
	ClapTrap &operator=(const ClapTrap &origin);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	displayStatus();
};

#endif
