/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:54:11 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 16:57:19 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap String constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called for " << name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) 
{
    ClapTrap::operator=(copy);
    std::cout << "ScavTrap assignment operator called\n";
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if(energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ScavTrap " << name << " launches an attack on " << target
                  << ", causing " << attackDamage << " points of damage!\n";
    } 
    else
        std::cout << "ScavTrap " << name << " has no energy or is dead\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!\n";
}