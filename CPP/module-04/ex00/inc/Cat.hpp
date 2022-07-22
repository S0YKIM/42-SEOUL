/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:12:10 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 13:06:31 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &origin);
	Cat &operator=(const Cat &origin);
	~Cat();

	void	makeSound() const;
};

#endif
