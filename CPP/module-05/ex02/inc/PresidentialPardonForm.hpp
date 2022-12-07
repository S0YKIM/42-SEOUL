/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:53:53 by sokim             #+#    #+#             */
/*   Updated: 2022/07/25 19:23:28 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_FORM_HPP
#define P_FORM_HPP

#include "Form.hpp"

#define PRESIDENTIAL_SIGN_GRADE 25
#define PRESIDENTIAL_EXEC_GRADE 5

class PresidentialPardonForm : public Form {
private:
	std::string	target_;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &origin);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &origin);
	~PresidentialPardonForm();

	const std::string	&getTarget() const;

	void		execute(Bureaucrat const &executor) const;
};

#endif
