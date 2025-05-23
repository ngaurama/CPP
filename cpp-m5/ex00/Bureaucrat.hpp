/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:36:00 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 16:18:22 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    class GradeTooHighException : std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : std::exception
    {
        public:
            const char* what() const throw();
    };
    
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& copy);
    ~Bureaucrat();
    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

    
#endif // BUREAUCRAT_HPP
