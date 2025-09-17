/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:30:33 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/13 21:37:36 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printIt(const T &x)
{
    std::cout << x << ", ";
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    ::iter(arr1, 5, printIt<int>);
    std::cout << std::endl;
    char arr2[] = {'a', 'b', 'c', 'd', 'e'};
    ::iter(arr2, 5, printIt<char>);
    std::cout << std::endl;
    std::string arr3[] = {"apple", "banana", "cat", "dogs and stuff"};
    ::iter(arr3, 4, printIt<std::string>);
    std::cout << std::endl;
    return 0;
}
