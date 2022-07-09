/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:26:57 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 18:24:33 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public :
	Ice();
	Ice(const Ice &origin);
	Ice &operator=(const Ice &origin);
	~Ice();

	AMateria	*clone() const;
	void		use(ICharacter &target);
};

#endif
