/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:50:00 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/21 16:26:16 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>


static std::string replaceAll(const std::string& content,
	const std::string& s1, const std::string& s2)
{
	std::string result;
	std::string::size_type pos = 0;
	std::string::size_type found;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content, pos, std::string::npos);
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return 1;
	}

	std::ifstream in(filename.c_str(), std::ios::binary);
	if (!in.is_open())
	{
		std::cerr << "Error: cannot open input file: " << filename << std::endl;
		return 1;
	}

	std::string content((std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>());
	in.close();

	std::string result = replaceAll(content, s1, s2);

	std::string outName = filename + ".replace";
	std::ofstream out(outName.c_str(), std::ios::binary);
	if (!out.is_open())
	{
		std::cerr << "Error: cannot create output file: " << outName << std::endl;
		return 1;
	}
	
	out << result;
	out.close();
	return 0;
}
