/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:31:53 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/19 15:48:03 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed()
    : _value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called\n";
    this->_value = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    if (this != &copy)
        this->_value = copy.getRawBits();
    std::cout << "Copy assignment operator called\n";
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}
