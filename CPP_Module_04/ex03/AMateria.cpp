/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:34:46 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 20:04:56 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    type = "Default";
    //std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
    this->type = type;
    //std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
    //std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    //std::cout << "AMateria copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

AMateria::~AMateria()
{
    //std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "* nothing happens *" << std::endl;
}
