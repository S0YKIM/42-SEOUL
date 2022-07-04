/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:30:50 by sokim             #+#    #+#             */
/*   Updated: 2022/07/04 21:43:55 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	name = "";
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

void	Zombie::announce() const {
	std::cout << name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
