/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:27:33 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/14 17:28:11 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _capacity(N), _numbers() {}

Span::Span(const Span& copy) : _capacity(copy._capacity), _numbers(copy._numbers) {}

Span& Span::operator=(const Span& copy)
{
    if (this != &copy)
    {
        _capacity = copy._capacity;
        _numbers = copy._numbers;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int num)
{
    if (_numbers.size() >= _capacity)
        throw std::out_of_range("Going out of range mate");
    _numbers.push_back(num);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = UINT_MAX;
    size_t minIndex = 0;
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (diff < minSpan)
        {
            minSpan = diff;
            minIndex = i - 1;
        }
    }
    (void)minIndex;
    //for debug
    //std::cout << "Shortest span is between: " << sorted[minIndex] << " and " << sorted[minIndex + 1] << std::endl;
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find span");
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    //for debug
    //std::cout << "Longest span is betweeen: " << max << " and " << min << std::endl;
    return static_cast<unsigned int>(max - min);
}
