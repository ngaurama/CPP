/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:07:41 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/19 18:53:35 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main() 
{
    ClapTrap a("Alpha");
    ClapTrap b(a);               // Copy constructor
    ClapTrap c;                  
    c = a;                       // Copy assignment

    a.attack("Target-1");
    a.takeDamage(4);
    a.beRepaired(3);
    a.takeDamage(10);            // HP = 0
    a.attack("Target-2");
    a.beRepaired(5);           
    return 0;
}
