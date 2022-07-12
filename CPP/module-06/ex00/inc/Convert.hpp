/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:38:06 by sokim             #+#    #+#             */
/*   Updated: 2022/07/12 17:15:47 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cmath> // isnan, ininf, floor
#include <cstdlib> // strtod
#include <climits> // CHAR_MIN, CHAR_MAX
#include <cfloat> // FLT_MAX
#include <locale> // isprint
#include <iomanip> // setprecision


class Convert {
private:
	std::string	input_;
	double		value_;
	bool		isValid_;

public:
	Convert();
	Convert(std::string input);
	Convert(const Convert &origin);
	Convert &operator=(const Convert &origin);
	~Convert();

	const std::string	&getInput() const;
	const double		&getValue() const;
	const bool			&getIsValid() const;

	char	toChar();
	int		toInt();
	float	toFloat();
	double	toDouble();

	void	printChar();
	void	printInt();
	void	printFloat();
	void	printDouble();
	void	printAll();

	class ImpossibleException : public std::exception {
	public:
		const char	*what() const throw();
	};

	class OverflowException : public std::exception {
	public:
		const char	*what() const throw();
	};

	class NonDisplayableException : public std::exception {
	public:
		const char	*what() const throw();
	};
};

#endif
