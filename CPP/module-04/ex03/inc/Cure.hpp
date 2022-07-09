/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:26:53 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 18:16:50 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public :
	Cure();
	Cure(const Cure &origin);
	Cure &operator=(const Cure &origin);
	~Cure();

	AMateria	*clone() const;
	void		use(ICharacter &target);
};

#endif
