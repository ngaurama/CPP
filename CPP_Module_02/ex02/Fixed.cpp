/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:31:53 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/19 16:59:38 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intValue)
{
	//std::cout << "Int constructor called\n";
	_value = intValue << _bits;
}

Fixed::Fixed(const float floatValue)
{
	//std::cout << "Float constructor called\n";
	_value = roundf(floatValue * (1 << _bits));
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called\n";
	this->_value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->_value = copy.getRawBits();
	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _bits);
	// 256 because of bits being 8 basically
}

int Fixed::toInt(void) const
{
	return (_value >> _bits); // basically just doing the shift back, so like 1344 >> 8 becomes 5
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
   Fixed result;
   result.setRawBits(this->_value + other._value);
   return result; 
}

Fixed Fixed::operator-(const Fixed &other) const
{
   Fixed result;
   result.setRawBits(this->_value - other._value);
   return result; 
}

Fixed Fixed::operator*(const Fixed &other) const
{
   Fixed result;
   long long temp = static_cast<long long>(this->_value) * other._value;
   result.setRawBits(static_cast<int>(temp >> _bits));
   return result; 
}

Fixed Fixed::operator/(const Fixed &other) const
{
   Fixed result;
   long long temp = (static_cast<long long>(this->_value) << _bits)/ other._value;
   result.setRawBits(static_cast<int>(temp));
   return result; 
}

Fixed &Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--()
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a > b) ? b : a;    
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a > b) ? b : a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a < b) ? b : a;    
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a < b) ? b : a;
}
