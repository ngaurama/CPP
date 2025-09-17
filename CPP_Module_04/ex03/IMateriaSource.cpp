/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:34:46 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 20:05:45 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
    //std::cout << "IMateriaSource constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
    //std::cout << "IMateriaSource copy constructor called" << std::endl;
    *this = other;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
    //std::cout << "IMateriaSource copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

IMateriaSource::~IMateriaSource()
{
    //std::cout << "IMateriaSource destructor called" << std::endl;
}
