/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:24:56 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 21:23:40 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeSign;
    const int _gradeExec;
protected:
    virtual void executeAction() const = 0;
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
    class NotSignedException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    
    AForm(std::string name, int gradeSign, int gradeExec);
    AForm(const AForm& copy);
    AForm& operator=(const AForm& copy);
    virtual ~AForm();

    const std::string getName() const;
    bool getSigned() const;
    int getGradeSign() const;
    int getGradeExec() const;
    void beSigned(Bureaucrat& bureaucrat);
    void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream& out, const AForm& form);

#endif // FORM_HPP
