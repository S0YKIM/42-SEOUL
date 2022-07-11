/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:38:04 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 20:32:35 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : {}
//멤버 변수 추가

Convert(const Convert &origin) {
	*this = origin;
}

Convert &operator=(const Convert &origin) {
	if (this == &origin)
		return (*this);
	// 멤버 변수 복사
	return (*this);
}

Convert::~Convert() {}
