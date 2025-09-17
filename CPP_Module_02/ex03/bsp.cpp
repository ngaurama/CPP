/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:06:39 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 17:59:48 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Point = A + da1(B - C) + da2(C - A)

float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float result = ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    return (result < 0) ? -result : result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float ax = a.getX().toFloat();
    float ay = a.getY().toFloat();

    float bx = b.getX().toFloat();
    float by = b.getY().toFloat();

    float cx = c.getX().toFloat();
    float cy = c.getY().toFloat();

    float px = point.getX().toFloat();
    float py = point.getY().toFloat();

    float totalArea = area(ax, ay, bx, by, cx, cy);
    float area1 = area(px, py, bx, by, cx, cy);
    float area2 = area(ax, ay, px, py, cx, cy);
    float area3 = area(ax, ay, bx, by, px, py);
    
    if (area1 + area2 + area3 == totalArea)
    {
        if (!area1 || !area2 || !area3)
            return false;
        return true;
    }
    return false;
    //second method with vector kinda thing
    // float w1;
    // float w2;
    
    // w1 = (((ax * (cy - ay)) + ((py - ay) * (cx - ax)) - (px * (cy - ay)))) / (((by - ay) * (cx - ax)) - ((bx - ax) * (cy - ay)));
    // w2 = (py - ay - (w1 * (by - ay))) / (cy - ay);

    // if (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1)
    //     return true;
    // else
    //     return false;
}