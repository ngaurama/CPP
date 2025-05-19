/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:41:51 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/19 18:03:23 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    // vertices of a triangle
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);

    Point point(6.0f, 1.0f);

    std::cout << "Point is " 
              << (bsp(a, b, c, point) ? "inside" : "outside") 
              << " the triangle." << std::endl;

    return 0;
}

