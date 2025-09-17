/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:57:48 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 14:41:55 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) 
{
    int N = 5;
    (void)argc;
    (void)argv;
    std::string name = "Crazy Dave";
    Zombie *horde = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
    return 0;
}
