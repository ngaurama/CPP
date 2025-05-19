/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:06:43 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/19 17:38:58 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {};

Point::Point(float x1, float y1)
    : x(x1), y(y1) {};

Point::Point(const Point &copy)
    : x(copy.x), y(copy.y) {}

Point &Point::operator=(const Point &copy)
{
    (void)copy;
    return (*this);        
}

Point::~Point(){}
