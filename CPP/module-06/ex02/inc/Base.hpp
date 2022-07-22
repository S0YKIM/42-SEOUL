/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:49:19 by sokim             #+#    #+#             */
/*   Updated: 2022/07/12 16:09:50 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>

class Base {
public:
	virtual	~Base();
};

Base	*generate();
void	identify(Base *p);
void	identify(Base &p);

#endif
