/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:05:45 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/27 14:19:25 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <vector>

int main() {
    try {
        std::cout << "=== Default Test ===" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Expected: 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Expected: 14

        std::cout << "\n=== Exception Test (Overfill) ===" << std::endl;
        try 
        {
            sp.addNumber(42);
        } catch (const std::exception& e) 
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Exception Test (Not Enough Numbers) ===" << std::endl;
        Span sp2(1);
        sp2.addNumber(1);
        try 
        {
            sp2.shortestSpan();
        }
        catch (const std::exception& e) 
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Range Add Test ===" << std::endl;
        int arr[] = {-24, -89, 333, 420, 69};
        std::vector<int> numbers(arr, arr + 4);
        Span sp3(10);
        sp3.addNumber(1);
        sp3.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

        std::cout << "\n=== Random Test (10,000 numbers) ===" << std::endl;
        Span sp4(10000);
        srand(time(NULL));
        for (int i = 0; i < 10000; ++i)
        {
            long num = rand();
            //std::cout << num << std::endl;
            sp4.addNumber(num);
        }
        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp4.longestSpan() << std::endl;

        std::cout << "\n=== Random Test (100,000 numbers) ===" << std::endl;
        Span sp5(100000);
        srand(time(NULL));
        for (int i = 0; i < 100000; ++i)
        {
            long num = rand();
            //std::cout << num << std::endl;
            sp5.addNumber(num);
        }
        std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
