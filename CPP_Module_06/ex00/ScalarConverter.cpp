/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:04:01 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/12 22:12:47 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    //std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    //std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    //std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    //std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (ScalarConverter::isChar(literal))
        ScalarConverter::convertFromChar(literal);
    else if (ScalarConverter::isInt(literal))
        ScalarConverter::convertFromInt(literal);
    else if (ScalarConverter::isFloat(literal))
        ScalarConverter::convertFromFloat(literal);
    else if (ScalarConverter::isDouble(literal))
        ScalarConverter::convertFromDouble(literal);
    else
        std::cout << "Invalid input" << std::endl;
}

// bool ScalarConverter::isChar(const std::string &literal)
// {
//     return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
// }

bool ScalarConverter::isChar(const std::string &literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return true;

    if ((literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') ||
        (literal.length() == 3 && literal[0] == '"' && literal[2] == '"'))
        return true;

    return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
    int value;
    std::stringstream ss(literal);
    ss >> value;
    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    if (literal == "nanf" ||  literal == "-inff" || literal == "+inff")
        return (true);
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return (false);
    std::stringstream ss(literal.substr(0, literal.length() - 1));
    float value;
    ss >> value;
    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    if (literal == "nan" ||  literal == "-inf" || literal == "+inf")
        return (true);
    std::stringstream ss(literal);
    double value;
    ss >> value;
    return !ss.fail() && ss.eof();
}

void ScalarConverter::convertFromChar(const std::string& literal)
{
    char c;
    if (literal.length() == 1)
        c = literal[0];
    else
        c = literal[1];
    std::cout << "char: '" << c << "' " << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& literal)
{
    std::stringstream ss(literal);
    long value;
    ss >> value;
    
    if (ss.fail() || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        int i = static_cast<int>(value);
        if (i >= 32 && i < 127)
            std::cout << "char: '" << static_cast<char>(i) << "'\n";
        else
            std::cout << "char: Non displayable\n";
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }    
}

void ScalarConverter::convertFromFloat(const std::string& literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return ;
    }
    std::stringstream ss(literal.substr(0, literal.length() - 1));
    float value;
    ss >> value;
    if (ss.fail() || value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        if (value < static_cast<float>(std::numeric_limits<int>::min()) || value > static_cast<float>(std::numeric_limits<int>::max()))
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
        }
        else
        {
            int i = static_cast<int>(value);
            if (i >= 32 && i < 127)
                std::cout << "char: '" << static_cast<char>(i) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << i << std::endl;        
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
}

void ScalarConverter::convertFromDouble(const std::string& literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return ;
    }
    std::stringstream ss(literal);
    double value;
    ss >> value;
    if (ss.fail() || value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        if (value < static_cast<double>(std::numeric_limits<int>::min()) || value > static_cast<double>(std::numeric_limits<int>::max()))
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
        }
        else
        {
            int i = static_cast<int>(value);
            if (i >= 32 && i < 127)
                std::cout << "char: '" << static_cast<char>(i) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << i << std::endl;        
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
}
