/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:44:34 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 18:03:50 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* brain;
public:
    Cat();
    Cat(const Cat& copy);
    Cat& operator=(const Cat& copy);
    virtual ~Cat();

    void makeSound() const;
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
};

#endif // CAT_HPP
