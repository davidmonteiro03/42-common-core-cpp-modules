/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 10:16:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string inputFilename(argv[1]);
	std::string outputFilename(inputFilename + ".replace");
	std::string s1(argv[2]), s2(argv[3]);
	std::ifstream inputFile(inputFilename.c_str());
	std::ofstream outputFile(outputFilename.c_str());
	if (inputFile.fail() || outputFile.fail())
	{
		std::cerr << argv[0] << ": error opening files." << std::endl;
		return 1;
	}
	std::string buffer = "";
	while (!inputFile.eof())
	{
		char buf[BUFSIZ];
		std::memset(buf, 0, sizeof(buf));
		inputFile.read(buf, sizeof(buf));
		buffer += buf;
	}
	if (s1.empty())
	{
		outputFile << buffer;
		return 0;
	}
	for (std::size_t i = 0; i < buffer.size(); i++)
	{
		std::size_t pos = buffer.find(s1, i);
		if (pos != std::string::npos && pos == i)
		{
			outputFile << s2;
			i += s1.size() - 1;
		}
		else
			outputFile << buffer[i];
	}
	return 0;
}
