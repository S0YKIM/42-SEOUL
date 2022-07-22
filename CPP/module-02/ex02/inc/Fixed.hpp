/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:36:47 by sokim             #+#    #+#             */
/*   Updated: 2022/07/07 10:03:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
private:
	int					fixedPointValue;
	static const int	fractionalBits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &origin);
	~Fixed();

	// Assignment operator overloading
	Fixed &operator=(const Fixed &origin);

	// Comparison operator overloading
	bool	operator<(const Fixed &target);
	bool	operator>(const Fixed &target);
	bool	operator<=(const Fixed &target);
	bool	operator>=(const Fixed &target);
	bool	operator==(const Fixed &target);
	bool	operator!=(const Fixed &target);

	// Arithmetic operator overloading
	Fixed	operator+(const Fixed target);
	Fixed	operator-(const Fixed target);
	Fixed	operator*(const Fixed target);
	Fixed	operator/(const Fixed target);

	// Increment, decrement operator overloading
	// Prefix
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	// Postfix
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed 		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
