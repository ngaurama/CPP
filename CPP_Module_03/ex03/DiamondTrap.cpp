/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:47:37 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/07 21:44:13 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
        : ClapTrap(), ScavTrap(), FragTrap(), name("Default")
{
    hitPoints = FragTrap_hitPoints;//FragTrap::hitPoints;
    energyPoints = ScavTrap_energyPoints;//ScavTrap::energyPoints;
    attackDamage = FragTrap_attackDamage;//FragTrap::attackDamage;
    std::cout << "DiamondTrap default constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
        : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    hitPoints = FragTrap_hitPoints;//FragTrap::hitPoints;
    energyPoints = ScavTrap_energyPoints;//ScavTrap::energyPoints;
    attackDamage = FragTrap_attackDamage;//FragTrap::attackDamage;
    std::cout << "DiamondTrap String constructor called for " << name << std::endl;
    //std::cout << "Hipoints: " << hitPoints << "\nEnergy Points: " << energyPoints << "\nAttack Damage: " << attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor called for " << name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
        this->name = copy.name;
        hitPoints = copy.hitPoints;
        energyPoints = copy.energyPoints;
        attackDamage = copy.attackDamage;
    }
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << ", and my ClapTrap name is " << ClapTrap::name << std::endl;
}