/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:52:51 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/23 21:28:49 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
protected:
    void executeAction() const;
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
    ~PresidentialPardonForm();
};

#endif // PRESIDENTIALPARDONFORM_HPP
