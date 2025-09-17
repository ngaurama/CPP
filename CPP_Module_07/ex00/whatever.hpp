/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:16:06 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/13 20:58:32 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T> 
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
const T &min(const T &x, const T &y)
{
    return (x == y) ? y : (x < y ? x : y);
}

template <typename T>
const T &max(const T &x, const T &y)
{
    return (x == y) ? y : (x > y ? x : y);
}

#endif // WHATEVER_HPP
