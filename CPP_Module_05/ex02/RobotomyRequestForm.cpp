/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:52:51 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/12 20:04:13 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request", 72, 45), _target(target)
{
    srand(time(NULL));
    //std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
    //std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    //std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    //std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "*Drilling noises: brr brr brr*\n";
    if (rand() % 2== 0)
       std::cout << _target << " has been robotomized!" << std::endl;
    else
        std::cout << _target << " robotomy failed :(\n";
}
