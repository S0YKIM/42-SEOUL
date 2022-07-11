/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:20 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 10:42:14 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	name_;
	bool				isSigned_;
	const int			gradeToSign_;
	const int			gradeToExecute_;

public:
	Form();
	Form(const std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const &origin);
	Form &operator=(Form const &origin);
	virtual ~Form();

	std::string	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void				beSigned(const Bureaucrat &signer);
	virtual void		execute(const Bureaucrat &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif
