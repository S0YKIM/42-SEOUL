/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:38:06 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 17:44:31 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cmath>

class Convert {
public:
	Convert();
	Convert(const Convert &origin);
	Convert &operator=(const Convert &origin);
	~Convert();

	char	toChar();
	int		toInt();
	float	toFloat();
	double	toDouble();

	void	printChar();
	void	printInt();
	void	printFloat();
	void	printDouble();
	void	printAll();
}

#endif
