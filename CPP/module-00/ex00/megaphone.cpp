/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:20:13 by sokim             #+#    #+#             */
/*   Updated: 2022/07/03 12:41:30 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*make_str_upper(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
	return (str);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			argv[i] = make_str_upper(argv[i]);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return (0);
}
