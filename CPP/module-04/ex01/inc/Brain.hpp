/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:27:41 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 14:32:57 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
private:
	std::string	ideas[100];

public:
	Brain();
	Brain(const Brain &origin);
	Brain &operator=(const Brain &origin);
	~Brain();

	std::string	getIdea(int idx) const;
	void		setIdea(int idx, std::string idea);
};

#endif
