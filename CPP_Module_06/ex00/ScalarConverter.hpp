/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:04:01 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/12 22:07:44 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ScalarConverter& operator=(const ScalarConverter& copy);
    ~ScalarConverter();
public:
    static void convert(const std::string& literal);
private:
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);
    
    static void convertFromChar(const std::string &literal);
    static void convertFromInt(const std::string &literal);
    static void convertFromFloat(const std::string &literal);
    static void convertFromDouble(const std::string &literal);
};
    

#endif // SCALARCONVERTER_HPP
