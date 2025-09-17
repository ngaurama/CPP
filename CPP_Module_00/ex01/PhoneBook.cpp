/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:14:47 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/04 15:45:50 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() {}

void Contact::setter(int index, const std::string &str)
{
    if (index >= 0 && index < 5)
        fields[index] = str;
}

std::string Contact::getter(int index) const
{
    if (index >= 0 && index < 5)
        return fields[index];
    return "";
}

PhoneBook::PhoneBook() {}

void PhoneBook::addContact(int index, const Contact &newContact)
{
    if (index >= 0 && index < 8)
        array[index] = newContact;
}

std::string truncate(const std::string &str) 
{
    return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

void PhoneBook::searchContact()
{    
    if (array[0].getter(0).empty()) 
    {
        std::cout << "No contacts saved yet.\n";
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < 8; i++)
    {
        std::string str = array[i].getter(0);
        if (str.empty())
            break;
        std::cout << std::setw(10) << i << "|"
            << std::setw(10) << truncate(str) << "|"
            << std::setw(10) << truncate(array[i].getter(1)) << "|"
            << std::setw(10) << truncate(array[i].getter(2)) << "\n";    
    }
    int index;
    bool valid = false;
    do 
    {
        std::cout << "Enter an index to view full contact: ";
        if (!(std::cin >> index)) 
        {
            std::cin.clear();
            std::cout << "Invalid input. Try Again\n";
        }
        else if (index < 0 || index >= 8 || array[index].getter(0).empty()) 
            std::cout << "Invalid index. Try Again.\n";
        else
            valid = true;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!valid);
    
    std::cout << "First Name: "     << array[index].getter(0) << "\n";
    std::cout << "Last Name: "      << array[index].getter(1) << "\n";
    std::cout << "Nickname: "       << array[index].getter(2) << "\n";
    std::cout << "Phone Number: "   << array[index].getter(3) << "\n";
    std::cout << "Darkest Secret: " << array[index].getter(4) << "\n";
}
