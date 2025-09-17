/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:48:01 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 15:15:09 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments. Try ./harl_switch <LEVEL>\n";
        return (1);
    }
    Harl harl;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (levels[i] == argv[1])
            break;
    }       
    switch(i)
    {
        case 0:
            harl.complain("DEBUG");
            std::cout << "\n";
        case 1:
            harl.complain("INFO");
            std::cout << "\n";
        case 2:
            harl.complain("WARNING");
            std::cout << "\n";
        case 3:
            harl.complain("ERROR");
            //std::cout << "\n";
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    } 
    return 0;
}
