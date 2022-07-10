/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:19 by sokim             #+#    #+#             */
/*   Updated: 2022/07/10 17:03:20 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
private:
	const std::string	name_;
	int					grade_;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &origin);
	Bureaucrat &operator=(const Bureaucrat &origin);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return ("Grade too low");
		}
	};

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return ("Grade too high");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);

#endif
