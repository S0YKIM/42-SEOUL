/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:07:45 by sokim             #+#    #+#             */
/*   Updated: 2022/07/05 14:35:30 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string	name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	setName(std::string name);
	void	announce() const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
