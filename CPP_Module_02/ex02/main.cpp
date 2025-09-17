/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:41:51 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 15:47:36 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}

// int main() 
// {
//     // Testing constructors
//     Fixed a;              // Default constructor
//     Fixed b(10);          // Int constructor
//     Fixed c(42.42f);      // Float constructor
//     Fixed d(b);           // Copy constructor

//     std::cout << "a: " << a << std::endl;  // Should print 0
//     std::cout << "b: " << b << std::endl;  // Should print 10
//     std::cout << "c: " << c << std::endl;  // Should print approximately 42.42
//     std::cout << "d: " << d << std::endl;  // Should print 10 (copy of b)

//     // Assignment operator
//     a = Fixed(1234.4321f);
//     std::cout << "a (after assignment): " << a << std::endl;

//     // Arithmetic operators
//     Fixed e = b + c;
//     Fixed f = c - b;
//     Fixed g = b * c;
//     Fixed h = c / b;

//     std::cout << "b + c = " << e << std::endl;
//     std::cout << "c - b = " << f << std::endl;
//     std::cout << "b * c = " << g << std::endl;
//     std::cout << "c / b = " << h << std::endl;

//     // Comparison operators
//     std::cout << std::boolalpha;
//     std::cout << "b > c? " << (b > c) << std::endl;
//     std::cout << "b < c? " << (b < c) << std::endl;
//     std::cout << "b == d? " << (b == d) << std::endl;
//     std::cout << "a != b? " << (a != b) << std::endl;

//     // Increment / decrement
//     Fixed i;
//     std::cout << "i: " << i << std::endl;  // 0
//     std::cout << "++i: " << ++i << std::endl;  // pre-increment
//     std::cout << "i++: " << i++ << std::endl;  // post-increment
//     std::cout << "i: " << i << std::endl;
//     std::cout << "--i: " << --i << std::endl;  // pre-decrement
//     std::cout << "i--: " << i-- << std::endl;  // post-decrement
//     std::cout << "i: " << i << std::endl;

//     // min/max functions
//     Fixed &minVal = Fixed::min(b, c);
//     const Fixed &maxVal = Fixed::max(b, c);
//     std::cout << "min(b, c) = " << minVal << std::endl;
//     std::cout << "max(b, c) = " << maxVal << std::endl;

//     return 0;
// }
