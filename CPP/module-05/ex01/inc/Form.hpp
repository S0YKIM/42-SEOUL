/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:20 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 10:43:13 by sokim            ###   ########.fr       */
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
	~Form();

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	// 관료의 그레이드가 충분하면 사인하고 아니면 실패
	void		beSigned(const Bureaucrat &signer);

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
