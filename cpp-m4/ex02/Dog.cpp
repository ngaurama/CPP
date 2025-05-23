/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:44:34 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 18:08:15 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof!\n";
}

std::string Dog::getIdea(int index) const 
{
    return brain->getIdea(index);
}

void Dog::setIdea(int index, const std::string& idea) 
{
    brain->setIdea(index, idea);
}
