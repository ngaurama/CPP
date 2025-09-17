/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:46:19 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/13 21:55:38 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;
public:
    Array() : _data(0), _size(0){}
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}    
    Array(const Array& copy) : _data(0), _size(0)
    {
        _size = copy._size;
        if (_size > 0)
        {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = copy._data[i];
        }
    }
    Array& operator=(const Array& copy)
    {
        if(this == &copy)
            return (*this);
        T* newData = 0;
        if (copy._size > 0)
        {
            newData = new T[copy._size];
            for (unsigned int i = 0; i < copy._size; ++i)
                newData[i] = copy._data[i];
        }
        delete[] _data;
        _data = newData;
        _size = copy._size;

        return *this;
    }
    ~Array()
    {
        delete[] _data;
    }

    unsigned int size() const
    {
        return this->_size;
    }

    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }
    const T& operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }
};

#endif // ARRAY_HPP
