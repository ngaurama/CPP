/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:34:46 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 19:06:02 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice& copy);
    Ice& operator=(const Ice& copy);
    virtual ~Ice();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif // ICE_HPP
