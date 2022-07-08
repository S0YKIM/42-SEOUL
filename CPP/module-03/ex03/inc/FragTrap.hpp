/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:57:45 by sokim             #+#    #+#             */
/*   Updated: 2022/07/08 15:38:36 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &origin);
	FragTrap &operator=(const FragTrap &origin);
	~FragTrap();

	void highFivesGuys();

	static const int	MAX_HIT_POINTS = 100;
	static const int	ENERGY_POINTS = 100;
	static const int	ATTACK_DAMAGE = 30;
};

#endif
