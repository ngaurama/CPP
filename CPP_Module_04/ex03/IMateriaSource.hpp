/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:34:46 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 19:52:24 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
public:
    IMateriaSource();
    IMateriaSource(const IMateriaSource& copy);
    IMateriaSource& operator=(const IMateriaSource& copy);
    virtual ~IMateriaSource();

    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif // IMATERIASOURCE_HPP
