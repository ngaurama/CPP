/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:04:01 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/12 22:07:57 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        std::cerr << "Usage: ./convert <literal>\n";
        return (1);
    }
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
    {
        std::string testLiterals[] = {
            "'c'",
            "42",
            "0",
            "-42",
            "4.2f",
            "-4.2f",
            "0.0f",
            "nanf",
            "+inff",
            "-inff",
            "4.2",
            "-4.2",
            "0.0",
            "nan",
            "+inf",
            "-inf",
            "hello",   // invalid
            "123abc",  // invalid
            "42.0f",
            "0.05",
            "'a'",
            "'\\n'",   // non-displayable char input
            "''",
            "' '",
            "c",
            "2147483648", // int overflow
            "-2147483649", // int underflow
            "2147483647", // int max
            "-2147483648" // int min
        };

        for (size_t i = 0; i < sizeof(testLiterals)/sizeof(testLiterals[0]); ++i)
        {
            std::cout << "Input: " << testLiterals[i] << std::endl;
            ScalarConverter::convert(testLiterals[i]);
            std::cout << "---------------------" << std::endl;
        }
    }
    return 0;
}

