/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:36:00 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 18:40:21 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade for too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade () const
{
    return _grade;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat) 
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}