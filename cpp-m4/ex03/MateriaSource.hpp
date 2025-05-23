/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:42:59 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 20:01:30 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* templates[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource& copy);
    MateriaSource& operator=(const MateriaSource& copy);
    virtual ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP
