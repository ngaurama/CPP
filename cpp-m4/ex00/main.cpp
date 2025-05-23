/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:44:34 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 17:20:51 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
    const WrongAnimal *wrong = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
    //Wrong
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    delete wrong;
    delete wrongCat;
	return (0);
}
