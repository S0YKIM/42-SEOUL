/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:56:11 by sokim             #+#    #+#             */
/*   Updated: 2022/07/08 11:25:30 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap	robot("Robot");

	robot.whoAmI();
	robot.displayStatus();
	
	robot.attack("Target 1");
	robot.attack("Target 2");
	robot.attack("Target 3");
	robot.displayStatus();

	robot.guardGate();
	robot.takeDamage(3);
	robot.displayStatus();

	robot.beRepaired(20);
	robot.displayStatus();

	robot.beRepaired(1);
	robot.displayStatus();
	
	robot.highFivesGuys();
	return (0);
}
