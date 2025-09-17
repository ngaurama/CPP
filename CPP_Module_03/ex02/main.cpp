/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:07:41 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/19 19:27:48 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap titan("Titan");

    titan.attack("Intruder");
    titan.takeDamage(30);
    titan.beRepaired(20);
    titan.highFivesGuys();

    FragTrap clone(titan);

    clone.attack("Enemy Clone");
    clone.highFivesGuys();

    FragTrap assigned;
    assigned = clone;

    assigned.attack("Assigned Target");
    assigned.highFivesGuys();

    return 0;
}
