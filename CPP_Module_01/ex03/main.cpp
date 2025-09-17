/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:43:27 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/14 14:49:38 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        // Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        //jim.setWeapon(club);
        jim.attack();
        Weapon club = Weapon("crude spiked club");
        jim.setWeapon(club);
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}