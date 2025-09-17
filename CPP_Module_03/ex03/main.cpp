/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:07:41 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/07 21:44:59 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n=== ClapTrap Test ===\n";
    ClapTrap ct("Clappy");
    ct.attack("Target A");
    ct.takeDamage(5);
    ct.beRepaired(3);

    std::cout << "\n=== ScavTrap Test ===\n";
    ScavTrap st("Scavy");
    st.attack("Target B");       // uses ScavTrap::attack
    st.takeDamage(20);
    st.beRepaired(10);
    st.guardGate();              // ScavTrap's method

    std::cout << "\n=== FragTrap Test ===\n";
    FragTrap ft("Fraggy");
    ft.attack("Target C");       // uses ScavTap::attack
    ft.takeDamage(40);
    ft.beRepaired(15);
    ft.highFivesGuys();          // FragTrap's method

    std::cout << "\n=== DiamondTrap Test ===\n";
    DiamondTrap dt("Diamondy");
    dt.attack("Target D");       // uses ScavTraps attack
    dt.whoAmI();                 // DiamondTrap method
    dt.takeDamage(30);
    dt.beRepaired(25);

    std::cout << "\n=== Copy, assignment Test ===\n";
    DiamondTrap copy(dt);        // Copy constructor
    copy.whoAmI();

    DiamondTrap assigned;
    assigned = dt;               // Copy assignment operator
    assigned.whoAmI();

    std::cout << "\n=== Destructors Automatic ===\n";
    return 0;
}

