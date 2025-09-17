/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:24:08 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/09 18:59:14 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int amount = 2;
    std::cout << "\n--- Creating array of Animals ---\n";
    Animal* animals[amount];

    for (int i = 0; i < amount / 2; i++)
        animals[i] = new Dog();
    for (int i = amount / 2; i < amount; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Testing makeSound() ---\n";
    for (int i = 0; i < amount; ++i)
        animals[i]->makeSound();

    std::cout << "\n--- Deep Copy Test: Dog ---\n";
    Dog originalDog;
    originalDog.setIdea(0, "Chase the mailman");

    Dog copiedDog = originalDog;
    originalDog.setIdea(0, "Sleep on the couch");

    std::cout << "Original Dog Idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea: " << copiedDog.getIdea(0) << std::endl;

    std::cout << "\n--- Deep Copy Test: Cat ---\n";
    Cat originalCat;
    originalCat.setIdea(0, "Nap in the sun");

    Cat copiedCat = originalCat;
    originalCat.setIdea(0, "Knock over the glass");

    std::cout << "Original Cat Idea: " << originalCat.getIdea(0) << std::endl;
    std::cout << "Copied Cat Idea: " << copiedCat.getIdea(0) << std::endl;

    std::cout << "\n--- Deleting array of Animals ---\n";
    for (int i = 0; i < amount; ++i)
        delete animals[i];


    //TESTING ABSTRACTIOn
    // Animal a;
    // a.makeSound(0);
    std::cout << "\n--- Done ---\n";
    return 0;
}

