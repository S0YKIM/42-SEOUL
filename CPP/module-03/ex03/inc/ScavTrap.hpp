/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:12:30 by sokim             #+#    #+#             */
/*   Updated: 2022/07/08 15:39:34 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &origin);
	ScavTrap &operator=(const ScavTrap &origin);
	~ScavTrap();

	void	attack(const std::string &target);

	void	guardGate();

	static const int	MAX_HIT_POINTS = 100;
	static const int	ENERGY_POINTS = 50;
	static const int	ATTACK_DAMAGE = 20;
};

#endif
