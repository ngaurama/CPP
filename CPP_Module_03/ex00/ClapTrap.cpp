/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:13:43 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/07 21:25:28 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10),
	attackDamage(0)
{
	std::cout << "Default Constructor called\n";
}

ClapTrap::ClapTrap(std::string new_name) : name(new_name), hitPoints(10),
	energyPoints(10), attackDamage(0)
{
	std::cout << "String constructor called with name: " << name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) : name(copy.name),
	hitPoints(copy.hitPoints), energyPoints(copy.energyPoints),
	attackDamage(copy.attackDamage)
{
	std::cout << "Copy constructor called with name: " << name << "\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		name = copy.name;
		hitPoints = copy.hitPoints;
		attackDamage = copy.attackDamage;
		energyPoints = copy.energyPoints;
	}
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called on name: " << name << "\n";
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << " ,causing " << attackDamage << " points of damage!\n";
	}
	else
		std::cout << "ClapTrap " << name << " has no energy or is dead\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Current HP: " << hitPoints << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points! Current HP: " << hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " has no energy or is dead and cannot repair." << std::endl;
}
