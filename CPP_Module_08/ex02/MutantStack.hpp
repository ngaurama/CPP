/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:22:03 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/27 14:37:16 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTATNTSTACK_HPP
#define MUTATNTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {};
    MutantStack(const MutantStack& other) : std::stack<T>(other) {};
    MutantStack& operator=(const MutantStack& other)
    {
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {};
    
    //the underlying container of stack is deque, for which stack has a protected member 'c'
    //link: https://en.cppreference.com/w/cpp/container/stack/
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    //okay so we assign the values for them as well
    iterator begin() 
    {
        return this->c.begin();
    }
    iterator end() 
    {
        return this->c.end();
    }

    const_iterator begin() const
    {
        return this->c.begin();
    }
    const_iterator end() const
    {
        return this->c.end();
    }

    reverse_iterator rbegin() 
    {
        return this->c.rbegin();
    }
    reverse_iterator rend() 
    {
        return this->c.rend();
    }

    const_reverse_iterator rbegin() const
    {
        return this->c.rbegin();
    }
    const_reverse_iterator rend() const
    {
        return this->c.rend();
    }
};

#endif