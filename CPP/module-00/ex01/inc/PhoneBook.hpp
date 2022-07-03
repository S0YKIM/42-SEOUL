/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:14:33 by sokim             #+#    #+#             */
/*   Updated: 2022/07/03 20:16:33 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class	PhoneBook {
private:
	int		idx;
	Contact	contacts[8];

public:
	PhoneBook();
	void	Start() const;
	void	Add();
	void	Search() const;
};

#endif
