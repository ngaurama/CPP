/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:36:19 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/14 14:37:53 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type): type(type) {}

const std::string &Weapon::getType() const
{
    return (type);
}

void Weapon::setType(const std::string &newType)
{
    type = newType;
}