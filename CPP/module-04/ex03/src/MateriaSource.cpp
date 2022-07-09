/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:27:47 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 19:32:22 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i =0; i < MATERIAS_CNT; i++) {
		materias_[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &origin) {
	*this = origin;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &origin) {
	if (this == &origin)
		return (*this);
	for (int i = 0; i < MATERIAS_CNT; i++) {
		if (origin.materias_[i])
			materias_[i] = origin.materias_[i]->clone();
		else
			this->materias_[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MATERIAS_CNT; i++) {
		if (materias_[i])
			delete materias_[i];
	}
}

void	MateriaSource::learnMateria(AMateria *newMateria) {
	for (int i = 0; i < MATERIAS_CNT; i++) {
		if (!materias_[i]) {
			materias_[i] = newMateria;
			return ;
		}
	}
	std::cout << "You can't learn new materia." << std::endl;
}

AMateria	*MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < MATERIAS_CNT; i++) {
		if (materias_[i] && materias_[i]->getType() == type) {
			return materias_[i]->clone();
		}
	}
	std::cout << "You can't create the materia." << std::endl;
	return (NULL);
}
