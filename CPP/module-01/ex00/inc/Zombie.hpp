/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:29:02 by sokim             #+#    #+#             */
/*   Updated: 2022/07/04 21:56:54 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie {
private:
	std::string	name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce() const;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
