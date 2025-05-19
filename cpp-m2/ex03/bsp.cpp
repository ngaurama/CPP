/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:06:39 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/19 17:39:14 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

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
    
    float w1;
    float w2;
    
    w1 = (((ax * (cy - ay)) + ((py - ay) * (cx - ax)) - (px * (cy - ay)))) / (((by - ay) * (cx - ax)) - ((bx - ax) * (cy - ay)));
    w2 = (py - ay - (w1 * (by - ay))) / (cy - ay);

    if (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1)
        return true;
    else
        return false;
}