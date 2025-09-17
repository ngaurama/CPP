/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:43:44 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 22:15:15 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Intern
{
public:
    class UnknownFormException : public std::exception
    {
        public:
            UnknownFormException(const std::string & formName);
            ~UnknownFormException() throw();
            const char* what() const throw();
        private:
            std::string _message;
    };
    Intern();
    Intern(const Intern& copy);
    Intern& operator=(const Intern& copy);
    ~Intern();
    AForm* makeForm(std::string name, std::string target);
private:
    AForm* createShrubberyForm(std::string target);
    AForm* createRobotomyForm(std::string target);
    AForm* createPresidentialForm(std::string target);
};

#endif // INTERN_HPP
