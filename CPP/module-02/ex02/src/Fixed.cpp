/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:37:10 by sokim             #+#    #+#             */
/*   Updated: 2022/07/07 11:04:30 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->fixedPointValue = 0;
}

// integer -> fixed-point value
Fixed::Fixed(const int num) {
	this->fixedPointValue = num << this->fractionalBits;
}

// floating point number -> fixed-point value
Fixed::Fixed(const float num) {
	this->fixedPointValue = (int)roundf(num * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &origin) {
	*this = origin;
}

Fixed&	Fixed::operator=(const Fixed &origin) {
	if (this == &origin)
		return (*this);
	this->fixedPointValue = origin.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed &target) {
	return (this->getRawBits() < target.getRawBits());
}

bool	Fixed::operator>(const Fixed &target) {
	return (this->getRawBits() > target.getRawBits());
}

bool	Fixed::operator<=(const Fixed &target) {
	return (this->getRawBits() <= target.getRawBits());
}

bool	Fixed::operator>=(const Fixed &target) {
	return (this->getRawBits() >= target.getRawBits());
}

bool	Fixed::operator==(const Fixed &target) {
	return (this->getRawBits() == target.getRawBits());
}

bool	Fixed::operator!=(const Fixed &target) {
	return (this->getRawBits() != target.getRawBits());
}

Fixed	Fixed::operator+(const Fixed target) {
	Fixed	result;

	result.setRawBits(this->getRawBits() + target.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed target) {
	Fixed	result;

	result.setRawBits(this->getRawBits() - target.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed target) {
	Fixed	result;

	result.setRawBits(this->getRawBits() * target.getRawBits() / (1 << this->fractionalBits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed target) {
	Fixed	result;

	result.setRawBits(this->getRawBits() / target.getRawBits() * (1 << this->fractionalBits));
	return (result);
}

Fixed	&Fixed::operator++(void) {
	++(this->fixedPointValue);
	return (*this);
}

Fixed	&Fixed::operator--(void) {
	--(this->fixedPointValue);
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);

	++(this->fixedPointValue);
	return (temp);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);

	--(this->fixedPointValue);
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

int		Fixed::getRawBits(void) const {
	return (this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return ((float)this->fixedPointValue / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const {
	return (this->fixedPointValue / (1 << this->fractionalBits));
}

Fixed::~Fixed() {
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}
