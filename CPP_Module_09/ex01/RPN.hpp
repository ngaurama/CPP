/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:58:19 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/28 20:58:08 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <sstream>

class RPN
{
private:
    std::stack<double> rpn;
    bool validateRPN(const std::string& input);
    bool isNumber(const std::string& token);
    bool isOperator(const std::string& token);
    double operation(double a, double b, char op);
public:
    RPN();
    RPN(const RPN& copy);
    RPN& operator=(const RPN& copy);
    ~RPN();
    void calculate(std::string& str);
};

#endif