/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:41:51 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 18:03:44 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    // vertices of a triangle
    Point a(-2.0f, 0.0f);
    Point b(-5.0f, 3.0f);
    Point c(-5.0f, 0.0f);

    Point point(-2.0f, 0.0f);

    std::cout << "Point is " 
              << (bsp(a, b, c, point) ? "inside" : "outside") 
              << " the triangle." << std::endl;

    return 0;
}

