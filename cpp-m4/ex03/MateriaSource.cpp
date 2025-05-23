/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:42:59 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 20:18:45 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    //std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    //std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    //std::cout << "MateriaSource copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

MateriaSource::~MateriaSource()
{
    //std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete templates[i];
        templates[i] = 0;
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == 0)
        {
            templates[i] = m->clone();
            delete m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return 0;
}
