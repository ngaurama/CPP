/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:57:45 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/14 14:06:37 by ngaurama         ###   ########.fr       */
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
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void setName(std::string name);
    void announce();
};

Zombie* zombieHorde( int N, std::string name );

#endif
