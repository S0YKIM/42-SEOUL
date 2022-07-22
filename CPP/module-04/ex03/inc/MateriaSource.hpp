/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:26:15 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 18:03:02 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MATERIAS_CNT 4

class MateriaSource : public IMateriaSource {
private :
	AMateria	*materias_[MATERIAS_CNT];

public :
	MateriaSource();
	MateriaSource(const MateriaSource &origin);
	MateriaSource &operator=(const MateriaSource &origin);
	~MateriaSource();

	void		learnMateria(AMateria *origin);
	AMateria*	createMateria(std::string const & type);
};

#endif
