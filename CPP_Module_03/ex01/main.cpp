/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:07:41 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/19 19:17:11 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ScavTrap titan("Titan");

    titan.attack("Intruder");
    titan.takeDamage(30);
    titan.beRepaired(20);
    titan.guardGate();

    ScavTrap clone(titan);

    clone.attack("Enemy Clone");
    clone.guardGate();

    ScavTrap assigned;
    assigned = clone;

    assigned.attack("Assigned Target");
    assigned.guardGate();

    return 0;
}
