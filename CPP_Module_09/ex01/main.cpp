/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:58:14 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/28 21:01:53 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN rpnCalc;
    if (argc != 2)
    {
        std::cerr << "Error\nUsage: ./RPN <single digit numbers and operators with spaces in between>" << std::endl;
        return (1);
    }
    std::string str = argv[1];
    rpnCalc.calculate(str);
    return 0;
}
