/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:36:00 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 16:14:29 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main() {
    // Test 1: Valid bureaucrat creation
    try {
        Bureaucrat bob("Bob", 42);
        std::cout << "Test 1: Created bureaucrat: " << bob << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Test 1 failed: " << e.what() << std::endl;
    }

    // Test 2: Grade too high
    try {
        Bureaucrat alice("Alice", 0);
        std::cerr << "Test 2 failed: Should have thrown GradeTooHighException" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Test 2: Caught expected exception: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Test 2 failed: Unexpected exception: " << e.what() << std::endl;
    }

    // Test 3: Grade too low
    try {
        Bureaucrat charlie("Charlie", 151);
        std::cerr << "Test 3 failed: Should have thrown GradeTooLowException" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Test 3: Caught expected exception: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Test 3 failed: Unexpected exception: " << e.what() << std::endl;
    }

    // Test 4: Grade increment and decrement
    try {
        Bureaucrat dave("Dave", 2);
        std::cout << "Test 4: Initial: " << dave << std::endl;
        dave.incrementGrade();
        std::cout << "Test 4: After increment: " << dave << std::endl;
        dave.decrementGrade();
        std::cout << "Test 4: After decrement: " << dave << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Test 4 failed: " << e.what() << std::endl;
    }

    // Test 5: Copy constructor
    try {
        Bureaucrat eve("Eve", 10);
        Bureaucrat eveCopy(eve); // Copy constructor
        std::cout << "Test 5: Original: " << eve << std::endl;
        std::cout << "Test 5: Copy: " << eveCopy << std::endl;
        eve.incrementGrade();
        std::cout << "Test 5: Original after increment: " << eve << std::endl;
        std::cout << "Test 5: Copy unchanged: " << eveCopy << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Test 5 failed: " << e.what() << std::endl;
    }

    // Test 6: Copy assignment operator
    try {
        Bureaucrat frank("Frank", 50);
        Bureaucrat gina("Gina", 100);
        std::cout << "Test 6: Before assignment - Frank: " << frank << ", Gina: " << gina << std::endl;
        gina = frank; // Copy assignment
        std::cout << "Test 6: After assignment - Frank: " << frank << ", Gina: " << gina << std::endl;
        frank.incrementGrade();
        std::cout << "Test 6: After Frank increment - Frank: " << frank << ", Gina: " << gina << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Test 6 failed: " << e.what() << std::endl;
    }

    // Test 7: Increment beyond limit
    try {
        Bureaucrat harry("Harry", 1);
        std::cout << "Test 7: Initial: " << harry << std::endl;
        harry.incrementGrade();
        std::cerr << "Test 7 failed: Should have thrown GradeTooHighException" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Test 7: Caught expected exception: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Test 7 failed: Unexpected exception: " << e.what() << std::endl;
    }

    // Test 8: Decrement beyond limit
    try {
        Bureaucrat ian("Ian", 150);
        std::cout << "Test 8: Initial: " << ian << std::endl;
        ian.decrementGrade();
        std::cerr << "Test 8 failed: Should have thrown GradeTooLowException" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Test 8: Caught expected exception: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Test 8 failed: Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
