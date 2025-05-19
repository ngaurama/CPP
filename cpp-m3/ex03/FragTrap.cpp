/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:26:05 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/19 19:29:04 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap String constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called for " << name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) 
{
    ClapTrap::operator=(copy);
    std::cout << "FragTrap assignment operator called\n";
    return *this;
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap destructor called for " << name << std::endl;
}


void FragTrap::highFivesGuys()
{
std::cout << "FragTrap " << name << " requests a high five! ✋" << std::endl;}