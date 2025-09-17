/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:14:26 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/12 22:22:37 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() 
{
    Data d;
    d.name = "Nitai";
    d.age = 19;

    // Data test;
    // test.name = "Failed";
    // test.age = 0;

    uintptr_t raw = Serializer::serialize(&d);
    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &d)
    {
        std::cout << "Pointer matched!\n";
        std::cout << "Name: " << ptr->name << "\n";
        std::cout << "Age: " << ptr->age << "\n";
    } 
    else 
        std::cerr << "Pointer mismatch.\n";
    return 0;
}
