/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:14:41 by sokim             #+#    #+#             */
/*   Updated: 2022/07/04 17:17:28 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#define	MAX_CONTACT 8
#define MAX_FIELD_LEN 10

#include <iostream>
#include <iomanip>

class	Contact {
private:
	int	index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	Contact();
	Contact(int index, std::string first_name, std::string last_name, \
		std::string nickname, std::string phone_number, std::string darkest_secret);
	
	std::string	Truncate(std::string original) const;
	int			GetIndex() const;
	void		DisplayContact() const;
	void		DisplaySearchedContact() const;
};

#endif
