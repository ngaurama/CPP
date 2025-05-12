/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:43 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/03 23:54:02 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <memory>
#include <iomanip>

class Contact
{
private:
    std::string fields[5];

public:
    Contact();
    void setter(int index, const std::string &str);
    std::string getter(int index) const;
};

class PhoneBook
{
private:
    Contact array[8];

public:
    PhoneBook();
    void addContact(int index, const Contact &newContact);
    void searchContact();
};


#endif