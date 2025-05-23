/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:34:45 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/20 20:40:40 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}

// void printHeader(const std::string& msg) {
// 	std::cout << "\n\033[1;36m==== " << msg << " ====\033[0m\n";
// }

// int main() {
// 	printHeader("Basic Learn & Use Test");
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);  // * shoots an ice bolt at bob *
// 	me->use(1, *bob);  // * heals bob's wounds *

// 	printHeader("Equip More Than 4 Test");
// 	me->equip(src->createMateria("ice"));
// 	me->equip(src->createMateria("cure"));
// 	me->equip(src->createMateria("ice")); // Should be ignored or managed safely

// 	printHeader("Use Invalid Slot");
// 	me->use(4, *bob);  // Should do nothing or error safely
// 	me->use(-1, *bob); // Invalid index

// 	printHeader("Unequip and Use Test");
// 	me->unequip(0);   // Unequip slot 0
// 	me->use(0, *bob); // Should do nothing
// 	me->equip(src->createMateria("ice")); // Fill back slot 0

// 	printHeader("Unknown Materia");
// 	tmp = src->createMateria("fire"); // Should return nullptr
// 	if (!tmp)
// 		std::cout << "Unknown materia not created.\n";

// 	printHeader("Character Deep Copy Test");
// 	Character* copy = new Character(*(Character*)me);  // Copy of 'me'
// 	copy->use(0, *bob); // Should act like 'me'
// 	copy->use(1, *bob);
// 	delete copy;  // Should free its own copies

// 	printHeader("Delete All Characters & Source");
// 	delete bob;
// 	delete me;
// 	delete src;
// 	std::cout << "\n\033[1;32mAll tests passed (check with Valgrind for leaks).\033[0m\n";
// 	return 0;
// }
