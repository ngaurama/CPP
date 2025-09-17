/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:06:45 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 15:48:55 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(float x1, float y1);
    Point(const Point &copy);
    Point &operator=(const Point &copy);
    ~Point();
    Fixed getX() const { return x; }
    Fixed getY() const { return y; }
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif