/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:31:45 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/04 00:33:25 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string get_non_empty_input(const std::string &prompt) 
{
    std::string value;
    do 
    {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (value.empty())
            std::cout << "Field cannot be empty\n";
    } while (value.empty());
    return value;
}

int main(int argc, char **argv)
{
    PhoneBook P;
    std::string input;
    int keepTrack = 0;
    
    (void)argc;
    (void)argv;
    do 
    {
        input.clear();
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            Contact contact;
            contact.setter(0, get_non_empty_input("Enter a First Name: "));
            contact.setter(1, get_non_empty_input("Enter a Last Name: "));
            contact.setter(2, get_non_empty_input("Enter a nickname: "));
            contact.setter(3, get_non_empty_input("Enter a Phone Number: "));
            contact.setter(4, get_non_empty_input("Enter the Darkest Secret: "));
            P.addContact(keepTrack % 8, contact);
            keepTrack++;
        }
        else if (input == "SEARCH")
            P.searchContact();
    } while (input != "EXIT");
    return 0;
}
