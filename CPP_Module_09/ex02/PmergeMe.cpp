/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:58:46 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/28 21:17:57 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : ListSort(std::list<int>()), DequeSort(std::deque<int>()) {}

PmergeMe::PmergeMe(const std::list<int>& lst, const std::deque<int>& dq)
    : ListSort(lst), DequeSort(dq), input_lst(lst), input_dq(dq) {}

PmergeMe::PmergeMe(const PmergeMe& copy)
    : ListSort(copy.input_lst), DequeSort(copy.input_dq), input_lst(copy.input_lst), input_dq(copy.input_dq) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) 
{
    if (this != &copy) 
    {
        ListSort::operator=(copy);
        DequeSort::operator=(copy);
        input_lst = copy.input_lst;
        input_dq = copy.input_dq;
    }
    return *this;
}

bool PmergeMe::isValidNumber(const std::string& token) {
    if (token.empty())
        return false;
    for (std::string::const_iterator it = token.begin(); it != token.end(); ++it) {
        if (!isdigit(static_cast<unsigned char>(*it)))
            return false;
    }
    return true;
}

bool PmergeMe::checkInput(int argc, char **argv) 
{
    std::set<int> seen;

    for (int i = 1; i < argc; ++i) 
    {
        std::stringstream ss(argv[i]);
        std::string token;
        while (ss >> token) 
        {
            if (!isValidNumber(token)) 
            {
                std::cerr << "Error: Invalid input '" << token << "'\n";
                return false;
            }
            int num = std::atoi(token.c_str());
            if (num < 0) 
            {
                std::cerr << "Error: Negative numbers not allowed" << std::endl;
                return false;
            }
            if (seen.count(num) > 0)
            {
                std::cerr << "Error: Duplicate number detected: " << num << std::endl;
                return false;
            }
            seen.insert(num);
            input_lst.push_back(num);
            input_dq.push_back(num);
        }
    }
    if (input_lst.empty()) 
    {
        std::cerr << "Error: Empty input" << std::endl;
        return false;
    }
    return true;
}

void PmergeMe::displayOutput() 
{
    std::cout << "Before: ";
    // std::cout << "List: \n";
    printContainer(input_lst);
    // std::cout << "Deque: \n";
    // printContainer(input_dq);

    // List timing
    std::list<int> list_copy = input_lst;
    ListSort list_sorter(list_copy);
    std::clock_t startList = std::clock();
    list_sorter.sort();
    
    std::clock_t endList = std::clock();
    double listDuration = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000.0;

    // Deque timing
    std::deque<int> deque_copy = input_dq;
    DequeSort deque_sorter(deque_copy);
    std::clock_t startDeque = std::clock();
    deque_sorter.sort();
    std::clock_t endDeque = std::clock();
    double dequeDuration = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "After: ";
    //std::cout << "List: \n";
    printContainer(list_sorter.getSortedData());
    // std::cout << "Deque: \n";
    // printContainer(deque_sorter.getSortedData());

    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::cout << "Time to process a range of " << list_sorter.getSortedData().size() << " elements with std::list : " << listDuration << " us\n";
    //std::cout << "Comparisons for std::list: " << ListSort::getComparisonCount() << "\n";
    std::cout << "Time to process a range of " << deque_sorter.getSortedData().size() << " elements with std::deque : " << dequeDuration << " us\n";
    //std::cout << "Comparisons for std::deque: " << DequeSort::getComparisonCount() << "\n";
}
