/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:54:49 by sokim             #+#    #+#             */
/*   Updated: 2022/07/05 19:32:11 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replaceWord(std::string line, std::string s1, std::string s2) {
	std::string				result;
	std::string::size_type	pos;
	std::string::size_type	start;

	start = 0;
	pos = line.find(s1, start);
	while (pos != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		start = pos + s2.length();
		pos = line.find(s1, start);
	}
	return (line);
}

int	replaceFile(std::string filename, std::string s1, std::string s2) {
	std::ifstream			ifile(filename);
	std::string				line;
	std::string::size_type	found;

	if (!ifile)
	{
		std::cout << "<ERROR> : " << filename << " does not exist." << std::endl;
		return (false);
	}

	std::ofstream	ofile(filename + ".replace");
	while (std::getline(ifile, line)) {
		found = line.find(s1);
		if (found != std::string::npos) {
			ofile << replaceWord(line, s1, s2) << std::endl;
		}
	}
	ifile.close();
	ofile.close();
	return (true);
}

int	main(int argc, char **argv) {
	std::string	filename;
	std::string	s1;
	std::string	s2;
	int			result;
	
	if (argc != 4)
	{
		std::cout << "<ERROR> Please input: " << argv[0] << " <filename> <string1> <string2> " << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "<ERROR> Some strings are empty." << std::endl;
		return (1);
	}

	result = replaceFile(filename, s1, s2);
	if (!result)
		return (1);
	return (0);
}
