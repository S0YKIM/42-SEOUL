/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:56:11 by sokim             #+#    #+#             */
/*   Updated: 2022/07/08 09:43:57 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void) {
	FragTrap	robot("Robot");

	robot.displayStatus();
	
	robot.attack("Target 1");
	robot.attack("Target 2");
	robot.attack("Target 3");
	robot.displayStatus();

	robot.takeDamage(3);
	robot.displayStatus();

	robot.beRepaired(20);
	robot.displayStatus();

	robot.beRepaired(1);
	robot.displayStatus();
	
	robot.highFivesGuys();
	return (0);
}
