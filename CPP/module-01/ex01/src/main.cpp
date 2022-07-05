/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:06:34 by sokim             #+#    #+#             */
/*   Updated: 2022/07/05 14:36:30 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie*	horde;
	int		num;
	
	num = 5;
	horde = zombieHorde(num, "zombie");

	for (int i = 0; i < num; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
