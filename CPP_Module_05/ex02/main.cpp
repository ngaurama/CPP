/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:36:00 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/12 20:07:04 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void handleException(const std::exception& e) 
{
    std::cout << "Error: " << e.what() << std::endl;
}

void handleException() 
{
    std::cout << "Error: Unknown exception" << std::endl;
}

int main() {
    //srand(time(NULL));

    std::cout << "=== Test 1: ShrubberyCreationForm Success ===" << std::endl;
    try 
    {
        Bureaucrat nacho("Nacho", 130);
        ShrubberyCreationForm shrub("home");
        nacho.signForm(shrub);
        nacho.executeForm(shrub);
        std::cout << shrub << std::endl;
    } 
    catch (const std::exception& e) 
    {
        handleException(e);
    } 
    catch (...) 
    {
        handleException();
    }
    std::cout << std::endl;

    std::cout << "=== Test 2: ShrubberyCreationForm Not Signed ===" << std::endl;
    try 
    {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("garden");
        bob.executeForm(shrub);
    } 
    catch (const std::exception& e) 
    {
        handleException(e);
    } 
    catch (...) 
    {
        handleException();
    }
    std::cout << std::endl;

    std::cout << "=== Test 3: RobotomyRequestForm Success ===" << std::endl;
    try 
    {
        Bureaucrat charlie("Charlie", 40);
        //Bureaucrat charlie("Charlie", 100); //Fails with exec but passes with sign
        RobotomyRequestForm robot("Bender");
        charlie.signForm(robot);
        charlie.executeForm(robot);
        std::cout << robot << std::endl;
    } 
    catch (const std::exception& e) 
    {
        handleException(e);
    } 
    catch (...) 
    {
        handleException();
    }
    std::cout << std::endl;

    std::cout << "=== Test 5: PresidentialPardonForm Success ===" << std::endl;
    try 
    {
        Bureaucrat eve("Eve", 5);
        PresidentialPardonForm pardon("Zaphod");
        eve.signForm(pardon);
        eve.executeForm(pardon);
        std::cout << pardon << std::endl;
    } 
    catch (const std::exception& e) 
    {
        handleException(e);
    } 
    catch (...) 
    {
        handleException();
    }
    return 0;
}