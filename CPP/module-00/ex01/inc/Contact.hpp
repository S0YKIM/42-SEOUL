/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:14:41 by sokim             #+#    #+#             */
/*   Updated: 2022/07/03 20:20:57 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class	Contact {
private:
	std::string first_name;
	std::string	last_name;
	std::string	nickname;
	std::string phone_number;
	std::string	darkest_secret;

public:
	Contact();
	Contact(std::string first_name, std::string last_name, \
		std::string nickname, std::string phone_number, std::string darkest_secret);
	void	Add();
	void	Search();
};

#endif
