/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:24:56 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/12 19:49:38 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

Form::Form() : _name("Default"), _signed(false), _gradeSign(150) ,_gradeExec(150)
{
    //std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec)
    : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    //std::cout << "Form parameter constructor called" << std::endl;
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    //std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    //std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form()
{
    //std::cout << "Form destructor called" << std::endl;
}

const std::string Form::getName() const
{
    return _name;
}

int Form::getGradeExec() const
{
    return _gradeExec;
}

int Form::getGradeSign() const
{
    return _gradeSign;
}

bool Form::getSigned() const
{
    return _signed;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() <= _gradeSign)
        _signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream& out, const Form& form)
{
    out << "Name: " << form.getName() << ", Signed: " << (form.getSigned() ? "true" : "false")
        << ", Sign grade: " << form.getGradeSign() << ", Execute grade: " << form.getGradeExec() << std::endl;
    return out;
}
