/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:58:14 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/30 00:18:21 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
    PmergeMe merged;
    if (!merged.checkInput(argc, argv)) 
        return 1;
    merged.displayOutput();
    return 0;
}
