/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:52:18 by sokim             #+#    #+#             */
/*   Updated: 2022/07/07 11:16:48 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

// integer -> fixed-point value
Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = num << this->fractionalBits;
}

// floating point number -> fixed-point value
Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = (int)roundf(num * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &origin) {
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed&	Fixed::operator=(const Fixed &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origin)
		return (*this);
	this->fixedPointValue = origin.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return ((float)this->fixedPointValue / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const {
	return (this->fixedPointValue / (1 << this->fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}
