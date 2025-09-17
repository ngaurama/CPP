/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:43:44 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 22:30:30 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::UnknownFormException::UnknownFormException(const std::string& formName)
    : _message("Unknown form name: " + formName)
{
}

Intern::UnknownFormException::~UnknownFormException() throw()
{
}

const char* Intern::UnknownFormException::what() const throw()
{
    return _message.c_str();
}

Intern::Intern()
{
    //std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    //std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    //std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern()
{
    //std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubberyForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

struct FormInfo
{
    std::string name;
    AForm* (Intern::*formCreator)(std::string);
};

AForm* Intern::makeForm(std::string name, std::string target)
{
    static const FormInfo forms[] = {
        {"shrubbery creation", &Intern::createShrubberyForm },
        {"robotomy request", &Intern::createRobotomyForm},
        {"presidential pardon", &Intern::createPresidentialForm}
    };
    
    std::string lowerForm = name;
    for (size_t i = 0; i < lowerForm.length(); i++)
        lowerForm[i] = std::tolower(name[i]);
    for (int i = 0; i < 3; i++)
    {
        if (lowerForm == forms[i].name)
        {
            AForm* form = (this->*forms[i].formCreator)(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    throw UnknownFormException(name);
}

