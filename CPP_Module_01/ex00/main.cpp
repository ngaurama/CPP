/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:57:48 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/11 20:04:09 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() 
{
    // Heap-allocated
    Zombie* heapZombie = newZombie("Heap_Zombie");
    heapZombie->announce();
    delete heapZombie;

    // Stack-allocated
    randomChump("Stack_Zombie");
    return 0;
}
