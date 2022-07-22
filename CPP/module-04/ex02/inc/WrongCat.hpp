/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:08:13 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 14:17:42 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat &origin);
	WrongCat &operator=(const WrongCat &origin);
	~WrongCat();

	void	makeSound() const;
};

#endif
