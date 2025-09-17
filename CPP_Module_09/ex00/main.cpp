/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:24:09 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/27 21:24:30 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    const char* dataFilename = "data.csv";
    std::ifstream fd(dataFilename);
    if (!fd)
    {
        std::cout << "Error: unable to open data file." << std::endl;
        return (1);
    }
    fd.close();
    BitcoinExchange btc(dataFilename, argv[1]);
    btc.calculate();
    return 0;
}
