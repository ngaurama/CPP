/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:44:34 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 18:03:43 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* brain;
public:
    Dog();
    Dog(const Dog& copy);
    Dog& operator=(const Dog& copy);
    virtual ~Dog();
    
    void makeSound() const;
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
};

#endif // DOG_HPP
