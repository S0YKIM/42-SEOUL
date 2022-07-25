/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:54:08 by sokim             #+#    #+#             */
/*   Updated: 2022/07/25 19:30:00 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_FORM_HPP
#define R_FORM_HPP

#include "Form.hpp"

#define ROBOTOMY_SIGN_GRADE 72
#define ROBOTOMY_EXEC_GRADE 45

class RobotomyRequestForm : public Form {
private:
	std::string	target_;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &origin);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& origin);
	~RobotomyRequestForm();

	const std::string	&getTarget() const;

	void		execute(Bureaucrat const &executor) const;
};

#endif
