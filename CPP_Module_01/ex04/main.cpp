/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:06:02 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 14:57:07 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string replaceInLine(std::string line, const std::string s1, const std::string s2)
{
    size_t pos = 0;
    size_t match;
    std::string result;
    while ((match = line.find(s1, pos)) != std::string::npos)
    {
        result += line.substr(pos, match - pos);
        result += s2;
        pos += match + s1.length();
    }
    result += line.substr(pos);
    return (result);   
}

int main(int argc, char **argv) 
{
    if (argc != 4) 
    {
        std::cerr << "Usage: ./sedIsForLosers <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    std::ifstream inFile(filename.c_str());
    if (!inFile)
    {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return (1);
    }
    std::string new_filename = filename + ".replace";
    std::ofstream outFile(new_filename.c_str());
    if (!outFile)
    {
        std::cerr << "Error: Cannot create file " << filename + ".replace" << "\n";
        return (1);
    }

    std::string line;
    while (std::getline(inFile, line))
        outFile << replaceInLine(line, s1, s2) << "\n";
    inFile.close();
    outFile.close();
    std::cout << "All done!\n";
    return (0);
}
