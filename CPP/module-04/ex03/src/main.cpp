/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:27:44 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 20:52:39 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main() {
	// IMateriaSource: 추상 클래스
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// ICharacter: 추상 클래스
	ICharacter	*me = new Character("me");

	// AMateria: 추상 클래스
	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->displayInventory();
	
	// ICharacter: 추상 클래스
	ICharacter	*someone = new Character("someone");
	me->use(0, *someone);
	me->use(1, *someone);

	// Inventory 를 꽉 채운 경우
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->displayInventory();

	// Inventory size 를 초과해서 장비 불가능
	me->equip(tmp);

	delete someone;
	delete me;
	delete src;
	return(0);
}
