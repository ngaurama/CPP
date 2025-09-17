/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:36:00 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/12 19:56:24 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Test 1: Valid Bureaucrat Creation ===" << std::endl;
    try 
    {
        Bureaucrat nacho("Nacho", 50);
        //Bureaucrat nacho("Nacho", 0);
        //Bureaucrat nacho("Nacho", 151);
        std::cout << "Name: " << nacho.getName() << ", Grade: " << nacho.getGrade() << std::endl;
        std::cout << nacho << std::endl;
    }   
    catch (std::exception& e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 2: Grade Increment and Decrement ===" << std::endl;
    try 
    {
        Bureaucrat nirvana("Nirvana", 50);
        std::cout << nirvana << std::endl;
        nirvana.incrementGrade();
        std::cout << "After increment: " << nirvana << std::endl;
        nirvana.decrementGrade();
        std::cout << "After decrement: " << nirvana << std::endl;
    }
    catch (std::exception& e) 
    {
        std::cerr << "failed: Unexpected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 3: Valid Form Creation ===" << std::endl;
    try 
    {
        Form taxForm("Tax Form", 50, 30);
        //Form taxForm("Tax Form", 0, 30);
        std::cout << taxForm;
    }
    catch (std::exception& e) 
    {
        std::cerr << "failed: Unexpected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 4: Successful Form Signing ===" << std::endl;
    try 
    {
        Bureaucrat grace("Grace", 40);
        //Bureaucrat grace("Grace", 60);
        Form permitForm("Permit Form", 50, 30);
        std::cout << permitForm;
        grace.signForm(permitForm);
        std::cout << "Signed status: " << permitForm.getSigned() << std::endl;
        std::cout << permitForm;
    }
    catch (std::exception& e) 
    {
        std::cerr << "failed: Unexpected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 5: Copy and Assignment ===" << std::endl;
    try 
    {
        Bureaucrat ivy("Ivy", 75);
        Bureaucrat ivyCopy(ivy); // Copy constructor
        std::cout << "Original: " << ivy << std::endl;
        std::cout << "Copy: " << ivyCopy << std::endl;
        Bureaucrat jill("Jill", 100);
        jill = ivy; // Assignment
        std::cout << "Assigned: " << jill << std::endl;

        Form budgetForm("Budget Form", 80, 60);
        Form budgetCopy(budgetForm); // Copy constructor
        std::cout << "Original: " << budgetForm;
        std::cout << "Copy: " << budgetCopy;

        Form otherForm("Other Form", 90, 70);
        otherForm = budgetForm; // Assignment
        std::cout << "Assigned: " << otherForm;
    }
    catch (std::exception& e) 
    {
        std::cerr << "failed: Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
