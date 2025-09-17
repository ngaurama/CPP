/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:31:53 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 17:37:28 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed()
    : _value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called\n";
    _value = intValue << _bits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called\n";
    _value = roundf(floatValue * (1 << _bits));
    std::cout << _value <<std::endl;
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
    //std::cout << "getRawBits member function called\n";
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _bits); //256 because of bits being 8
}

int Fixed::toInt(void) const
{
    return _value >> _bits; //basically just doing the shift back, so like 1344 >> 8 becomes 5
}

std::ostream &operator<<(std::ostream& out, const Fixed& value) 
{
    out << value.toFloat();
    return out;
}
