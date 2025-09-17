/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:57:45 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/11 20:02:09 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();

    void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
