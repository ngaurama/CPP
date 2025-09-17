/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:23:22 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/12 19:40:39 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
    if (argc <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for (int i = 1; i < argc; i++)
        {
            std::string word(argv[i]); 
            for (size_t j = 0; j < word.length(); j++)
                std::cout << (char)toupper(word[j]);
        }
        std::cout << "\n";
    }
    return (0);
}
