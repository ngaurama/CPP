/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:39:27 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 20:39:02 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Default character")
{
    //std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(std::string const& name) : name(name)
{
    //std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(const Character& other) : name(other.name)
{
    //std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other)
{
    //std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                delete inventory[i];
                inventory[i] = 0;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character()
{
    //std::cout << "Character destructor called" << std::endl;
    for (int i = 0;i < 4; i++)
    {
        if (inventory[i])
        {
            delete inventory[i];
            inventory[i] = 0;
        }
    }
}

std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == 0)
        {
            inventory[i] = m;
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx]) 
    {
        delete inventory[idx];
        inventory[idx] = 0;
    }}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >=4 || inventory[idx] == 0)
        return;
    inventory[idx]->use(target);
}
