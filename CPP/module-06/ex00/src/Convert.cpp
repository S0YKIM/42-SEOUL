/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:38:04 by sokim             #+#    #+#             */
/*   Updated: 2022/07/12 15:11:43 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : input_(NULL), value_(0.0), isValid_(false) {}

Convert::Convert(std::string input) : input_(input) {
	// 마지막 유효한 숫자 뒤의 문자열에 대한 포인터
	char	*end = NULL;
	value_ = std::strtod(input.c_str(), &end);
	// \0 인 경우 유효 (예: 42)
	if (*end == '\0') 
		isValid_ = true;
	// f 인 경우 유효 (예: 42.0f)
	else if (std::strlen(end) == 1 && end[0] == 'f')
		isValid_ = true;
	else
		isValid_ = false;
}

Convert::Convert(const Convert &origin) {
	*this = origin;
}

Convert &Convert::operator=(const Convert &origin) {
	if (this == &origin)
		return (*this);
	input_ = origin.getInput();
	value_ = origin.getValue();
	isValid_ = origin.getIsValid();
	return (*this);
}

Convert::~Convert() {}

const std::string	&Convert::getInput() const {
	return (input_);
}

const double		&Convert::getValue() const {
	return (value_);
}

const bool			&Convert::getIsValid() const {
	return (isValid_);
}

char	Convert::toChar() {
	// 숫자가 아닌 값 예외 처리
	if (!isValid_ || std::isnan(value_) || std::isinf(value_))
		throw ImpossibleException();
	
	// char 범위를 벗어나는 오버플로우 예외 처리
	else if (value_ < CHAR_MIN || value_ > CHAR_MAX)
		throw OverflowException();
	
	// 출력 불가능 예외 처리
	else if (!std::isprint(value_))
		throw NonDisplayableException();
	
	return static_cast<char>(value_);
}

int		Convert::toInt() {
	// 숫자가 아닌 값 예외 처리
	if (!isValid_ || std::isnan(value_) || std::isinf(value_))
		throw ImpossibleException();
	
	// int 범위를 벗어나는 오버플로우 예외 처리
	else if (value_ < INT_MIN || value_ > INT_MAX)
		throw OverflowException();

	return static_cast<int>(value_);
}

float	Convert::toFloat() {
	// 숫자가 아닌 값 예외 처리
	if (!isValid_)
		throw ImpossibleException();
	
	// nan 과 inf 처리
	else if (std::isnan(value_) || std::isinf(value_))
		return static_cast<float>(value_);
	
	// float 범위를 벗어나는 오버플로우 예외 처리
	else if (value_ > FLT_MAX)
		throw OverflowException();

	return static_cast<float>(value_);
}

double	Convert::toDouble() {
	// 숫자가 아닌 값 예외 처리
	if (!isValid_)
		throw ImpossibleException();

	// nan 과 inf 처리
	else if (std::isnan(value_) || std::isinf(value_))
		return static_cast<double>(value_);
	
	// double 범위를 벗어나는 오버플로우 예외 처리
	else if (value_ > DBL_MAX)
		throw OverflowException();

	return static_cast<double>(value_);
}

void	Convert::printChar() {
	try {
		std::cout << "char: ";
		char c = toChar();
		std::cout << "'" << c << "'" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Convert::printInt() {
	try {
		std::cout << "int: ";
		int i = toInt();
		std::cout << i << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Convert::printFloat() {
	try {
		std::cout << "float: ";
		float f = toFloat();
		// 부호까지 출력
		if (std::isinf(f))
			std::cout << std::showpos << f << "f" << std::endl;
		else if (f != std::floor(f))
			std::cout << f << "f" << std::endl;
		// 내림 함수를 사용했는데 결과가 원본과 같으면 소수부가 0 이라는 의미
		else
			std::cout << f << ".0f" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Convert::printDouble() {
	try {
		std::cout << "double: ";
		double d = toDouble();
		// 부호까지 출력
		if (std::isinf(d))
			std::cout << std::showpos << d << std::endl;
		else if (d != std::floor(d))
			std::cout << d << std::endl;
		// 내림 함수를 사용했는데 결과가 원본과 같으면 소수부가 0 이라는 의미
		else
			std::cout << d << ".0" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Convert::printAll()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

const char	*Convert::ImpossibleException::what() const throw() {
	return "impossible";
}

const char* Convert::OverflowException::what() const throw() {
	return "overflow";
}

const char* Convert::NonDisplayableException::what() const throw() {
	return "Non displayable";
}
