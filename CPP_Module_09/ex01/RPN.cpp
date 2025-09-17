/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:58:46 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/28 21:17:57 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    
}

RPN::RPN(const RPN& copy)
{
    *this = copy;
}

RPN::~RPN()
{
    
}

RPN& RPN::operator=(const RPN& copy)
{
    if (this != &copy)
    {
        this->rpn = copy.rpn;
    }
    return *this;
}

bool RPN::isOperator(const std::string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token)
{
    if (token.length() != 1 || !isdigit(token[0]))
        return false;
    return true;
}

bool RPN::validateRPN(const std::string& input)
{
    std::istringstream iss(input);
    std::string token;
    int numberCount = 0;
    int operatorCount = 0;

    while (iss >> token)
    {
        if (isNumber(token))
            numberCount++;
        else if (isOperator(token))
            operatorCount++;
        else
            return false;
    }
    return numberCount == operatorCount + 1 && numberCount >= 1;;
}

double RPN::operation(double a, double b, char op)
{
    switch (op)
    {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/':
            if (a == 0)
            {
                std::cerr << "Error: Division by zero" << std::endl;
                throw std::runtime_error("Division by zero");
            }
            return b / a;
        default:
            std::cerr << "Error: Invalid operator" << std::endl;
            throw std::runtime_error("Invalid operator");
    }
}

void RPN::calculate(std::string& str)
{
    if (!validateRPN(str))
    {
        std::cerr << "Error: Invalid input." << std::endl;
        return ;
    }
    std::istringstream iss(str);
    std::string token;
    while (iss >> token)
    {
        if (isNumber(token))
        {
            std::stringstream ss(token);
            double val;
            ss >> val;
            rpn.push(val);
        }
        else if (isOperator(token))
        {
            if (rpn.size() < 2)
            {
                std::cerr << "Error: Insufficient operands" << std::endl;
                return;
            }
            double a = rpn.top(); rpn.pop();
            double b = rpn.top(); rpn.pop();
            try
            {
                double result = operation(a, b, token[0]);
                rpn.push(result);
            }
            catch (const std::runtime_error&)
            {
                return;
            }
        }
    }
    if (rpn.size() != 1)
    {
        std::cerr << "Error: Invalid expression" << std::endl;
        return;
    }
    double result = rpn.top();
    if (result == static_cast<int>(result))
        std::cout << static_cast<int>(result) << std::endl;
    else
        std::cout << result << std::endl;
}
