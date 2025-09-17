/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:34:46 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 20:05:37 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    //std::cout << "ICharacter constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter& other)
{
    //std::cout << "ICharacter copy constructor called" << std::endl;
    *this = other;
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    //std::cout << "ICharacter copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

ICharacter::~ICharacter()
{
    //std::cout << "ICharacter destructor called" << std::endl;
}
