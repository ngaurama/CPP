/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:58:19 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/28 20:58:08 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <set>
#include <iterator>
#include "DequeSort.hpp"
#include "ListSort.hpp"

class PmergeMe : public ListSort, public DequeSort
{
private:
    std::list<int> input_lst;
    std::deque<int> input_dq;
    template <typename T>
    void printContainer(const T& arr) 
    {
        for (typename T::const_iterator it = arr.begin(); it != arr.end(); ++it) {
            std::cout << *it;
            typename T::const_iterator itNext = it;
            ++itNext;
            if (itNext != arr.end())
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    bool isValidNumber(const std::string& token);
public:
    PmergeMe();
    PmergeMe(const std::list<int>& lst, const std::deque<int>& dq);
    PmergeMe(const PmergeMe& copy);
    PmergeMe& operator=(const PmergeMe& copy);
    ~PmergeMe();
    bool checkInput(int argc, char **argv);
    void displayOutput();
};

//List: fast insertion, slow access
//Deque: slower insertion, fast access
//https://baptiste-wicht.com/posts/2012/12/cpp-benchmark-vector-list-deque.html
//for mac:  ./PmergeMe `jot -r 6000 1 100000 | sort -n | uniq | head -n 3000 | tr '\n' ' '`
//for linux: ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
#endif
