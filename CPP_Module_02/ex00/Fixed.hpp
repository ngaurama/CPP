/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:31:49 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 15:24:19 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed 
{
private:
    int _value;
    static const int _bits;

public:
    Fixed();
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& copy);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
