/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:30:33 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/13 21:36:53 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

// template <typename T, typename F>
// void iter(T *arr, size_t length, F func)
// {
//     for (size_t i = 0; i < length; ++i)
//         func(arr[i]);
// }

template< typename T >

void	iter(const T *array, size_t arr_len, void (*func)(const T &))
{
	if (array == NULL || func == NULL)
		return ;
	for (size_t i = 0; i < arr_len; i++)
		func(array[i]);
}

//won't work for lamdas: [](int const &x) { print(x); }

#endif // ITER_HPP
