/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:24:56 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 19:30:00 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeSign;
    const int _gradeExec;
public:
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    Form();
    Form(std::string name, int gradeSign, int gradeExec);
    Form(const Form& copy);
    Form& operator=(const Form& copy);
    ~Form();

    void beSigned(Bureaucrat& bureaucrat);
    const std::string getName() const;
    bool getSigned() const;
    int getGradeSign() const;
    int getGradeExec() const;
};

std::ostream &operator<<(std::ostream& out, const Form& form);

#endif // FORM_HPP
