/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:36:18 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/14 21:49:09 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListSort.hpp"

ListSort::ListSort(const std::list<int>& input) : lst(input)
{
    
}

ListSort::ListSort(const ListSort& copy) 
{
    *this = copy;
}

ListSort& ListSort::operator=(const ListSort& copy) 
{
    if (this != &copy) 
        this->lst = copy.lst;
    return (*this);
}

ListSort::~ListSort()
{
    
}

void ListSort::sort()
{
    mergeInsertSort(lst);
}

const std::list<int>& ListSort::getSortedData() const 
{
    return lst;
}

unsigned long ListSort::comparison_count = 0;

unsigned long ListSort::getComparisonCount() 
{
    return comparison_count;
}

void ListSort::resetComparisonCount() 
{
    comparison_count = 0;
}

std::list<int> ListSort::getJacobsthalNumbers(int size)
{
    int J0 = 0;
    int J1 = 1;
    std::list<int> seq;
    seq.push_back(J0);
    seq.push_back(J1);

    while (J1 < size) 
    {
        int J2 = J1 + 2 * J0;
        seq.push_back(J2);
        J0 = J1;
        J1 = J2;
    }
    return (seq);
}

std::list<int> ListSort::computeJacobsthalOrder(int size)
{
    std::list<int> jacobsthal = getJacobsthalNumbers(size);
    std::list<int> order;
    std::set<int> used_indices;
    int remaining = size;
    std::list<int>::iterator it = jacobsthal.begin();
    
    if (it != jacobsthal.end())
        ++it;

    while (it != jacobsthal.end() && remaining > 0)
    {
        int start = std::min(*it, remaining - 1);
        std::list<int>::iterator itPrev = it;
        --itPrev;
        int end = *itPrev;
        if (start >= end)
        {
            for (int j = start; j >= end; --j)
            {
                if (j < remaining && used_indices.find(j) == used_indices.end())
                {
                    order.push_back(j);
                    used_indices.insert(j);
                }
            }
        }
        remaining = *it;
        ++it;
    }
    for (int j = size - 1; j >= 0; --j)
    {
        if (used_indices.find(j) == used_indices.end())
        {
            order.push_back(j);
            used_indices.insert(j);
        }
    }
    return (order);
}

void ListSort::binaryInsert(std::list<int>& arr, int element)
{
    if (arr.empty()) 
    {
        arr.push_back(element);
        return;
    }
    int low = 0;
    int high = arr.size() - 1;
    std::list<int>::iterator it;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        it = arr.begin();
        std::advance(it, mid);
        comparison_count++;
        if (*it < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    it = arr.begin();
    std::advance(it, low);
    arr.insert(it, element);
}

std::list<int>& ListSort::mergeInsertSort(std::list<int>& arr)
{
    int length = arr.size();
    if (length <= 2)
    {
        if (length == 2)
        {
            std::list<int>::iterator it1 = arr.begin();
            std::list<int>::iterator it2 = it1;
            comparison_count++;
            ++it2;
            if (*it1 > *it2)
                std::iter_swap(it1, it2);            
        }
        return arr;
    }
    std::list<int> mainChain;
    std::list<int> losers;
    std::list<int>::iterator it = arr.begin();
    int oddElement = -1;
    bool hasOdd = false;
    while (it != arr.end())
    {
        std::list<int>::iterator first = it++;
        if (it == arr.end()) 
        {
            oddElement = *first;
            hasOdd = true;
            break;
        }
        std::list<int>::iterator second = it++;
        comparison_count++;
        if (*first <= *second) 
        {
            mainChain.push_back(*second);
            losers.push_back(*first);
        }
        else 
        {
            mainChain.push_back(*first);
            losers.push_back(*second);
        }
    }
    mainChain = mergeInsertSort(mainChain);
    std::list<int> insertionOrder = computeJacobsthalOrder(losers.size());
    std::list<int> result = mainChain;
    std::list<int>::iterator orderIt = insertionOrder.begin();
    while (orderIt != insertionOrder.end())
    {
        int index = *orderIt;
        if (index < (int)losers.size())
        {
            std::list<int>::iterator loserIt = losers.begin();
            std::advance(loserIt, index);
            binaryInsert(result, *loserIt);
        }
        ++orderIt;
    }
    if (hasOdd)
        binaryInsert(result, oddElement);
    arr = result;
    return (arr);
}
