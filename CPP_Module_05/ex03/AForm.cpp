/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:24:56 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 21:23:36 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Form not signed!";
}

AForm::AForm(std::string name, int gradeSign, int gradeExec)
    : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    //std::cout << "Form parameter constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    //std::cout << "Form copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    //std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm()
{
    //std::cout << "Form destructor called" << std::endl;
}

const std::string AForm::getName() const
{
    return _name;
}

int AForm::getGradeExec() const
{
    return _gradeExec;
}

int AForm::getGradeSign() const
{
    return _gradeSign;
}

bool AForm::getSigned() const
{
    return _signed;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() <= _gradeSign)
        _signed = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw NotSignedException();
    if (executor.getGrade() > _gradeExec)
        throw GradeTooLowException();
    executeAction();
}

std::ostream &operator<<(std::ostream& out, const AForm& form)
{
    out << "Name: " << form.getName() << ", Signed: " << (form.getSigned() ? "true" : "false")
        << ", Sign grade: " << form.getGradeSign() << ", Execute grade: " << form.getGradeExec();
    return out;
}
