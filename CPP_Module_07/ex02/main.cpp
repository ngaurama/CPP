/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:46:19 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/13 21:56:41 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); ++i)
        numbers[i] = i * 10;

    for (unsigned int i = 0; i < numbers.size(); ++i)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    
    try 
    {
        std::cout << numbers[10] << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    //copy
    Array<int> copy = numbers;

    copy[0] = 999;
    std::cout << "Original numbers[0]: " << numbers[0] << std::endl;
    std::cout << "Copy numbers[0]: " << copy[0] << std::endl;

    // const access check
    const Array<int> constArray = numbers;
    std::cout << "constArray[1]: " << constArray[1] << std::endl;

    //constArray[1] = 100; // causes compiletime error

    return 0;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
