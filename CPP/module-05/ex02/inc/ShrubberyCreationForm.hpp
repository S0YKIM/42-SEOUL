/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:54:12 by sokim             #+#    #+#             */
/*   Updated: 2022/07/25 19:30:31 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FORM_HPP
#define S_FORM_HPP

#include "Form.hpp"

#define SHRUBERRY_SIGN_GRADE 145
#define SHRUBERRY_EXEC_GRADE 137

class ShrubberyCreationForm : public Form {
private:
	std::string	target_;

public :
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &origin);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &origin);
	~ShrubberyCreationForm();

	const std::string	&getTarget() const;

	void		execute(Bureaucrat const &executor) const;
};

#endif
