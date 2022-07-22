/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:35:49 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 15:38:23 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();

	Form	*makeForm(std::string type, std::string target);

	class NoMatchTypeException : public std::exception {
	public:
		const char	*what() const throw();
	};
};

#endif
