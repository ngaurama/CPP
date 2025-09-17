/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:55:18 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/14 17:28:52 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <exception> 
#include <vector>
#include <iterator>
#include <climits>

class Span
{
private:
    unsigned int _capacity;
    std::vector<int> _numbers;
public:
    Span(unsigned int N);
    Span(const Span &copy);
    Span& operator=(const Span &copy);
    ~Span();
    void addNumber(int num);
    template <typename T>
    void addNumbers(T begin, T end);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};

template <typename T>
void Span::addNumbers(T begin, T end)
{
    unsigned int rangeSize = std::distance(begin, end);
    if (_numbers.size() + rangeSize > _capacity)
        throw std::out_of_range("Adding range exceeds Span capacity");
    _numbers.insert(_numbers.end(), begin, end);
}

#endif
