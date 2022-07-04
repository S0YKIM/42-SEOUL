/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:30:59 by sokim             #+#    #+#             */
/*   Updated: 2022/07/04 22:10:10 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	randomName() {
	std::string names[5] = {"John", "Emma", "Brian", "Ann", "Lee"};

	return (names[rand() % 5]);
}

int	main(void)
{
	Zombie*	zombie1 = newZombie("zombie1");
	Zombie*	zombie2 = newZombie("zombie2");
	Zombie*	zombie3 = newZombie("zombie3");

	zombie1->announce();
	zombie2->announce();
	zombie3->announce();

	zombie1->~Zombie();
	zombie2->~Zombie();
	zombie3->~Zombie();

	randomChump(randomName());
	randomChump(randomName());
	randomChump(randomName());
	return (0);
}
