/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:00:48 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/14 21:38:23 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DequeSort.hpp"

DequeSort::DequeSort(const std::deque<int>& input) : dq(input)
{
    
}
DequeSort::DequeSort(const DequeSort& copy)
{
    *this = copy;
}
DequeSort& DequeSort::operator=(const DequeSort& copy)
{
    if (this != &copy)
        this->dq = copy.dq;
     return *this;
}

DequeSort::~DequeSort()
{
    
}


void DequeSort::sort() 
{
    mergeInsertSort(dq);
}

const std::deque<int>& DequeSort::getSortedData() const 
{
    return dq;
}

unsigned long DequeSort::comparison_count = 0;

unsigned long DequeSort::getComparisonCount() 
{
    return comparison_count;
}

void DequeSort::resetComparisonCount() 
{
    comparison_count = 0;
}

std::deque<int> DequeSort::getJacobsthalNumbers(int size)
{
    int J0 = 0;
    int J1 = 1;
    std::deque<int> seq;
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

std::deque<int> DequeSort::computeJacobsthalOrder(int size)
{
    std::deque<int> jacobsthal = getJacobsthalNumbers(size);
    std::deque<int> order;
    std::set<int> used_indices;
    int remaining = size;
    size_t i = 1;
    
    while (i < jacobsthal.size() && remaining > 0)
    {
        int start = std::min(jacobsthal[i], remaining - 1);
        int end = jacobsthal[i - 1];
        if (start >= end)
        {
            for (int j = start; j >= end; --j) 
            {
                if (j < remaining && used_indices.find(j) == used_indices.end()) {
                    order.push_back(j);
                    used_indices.insert(j);
                }
            }
        }
        remaining = jacobsthal[i];
        i++;
    }
    for (int j = size - 1; j >=0; --j)
    {
        if (used_indices.find(j) == used_indices.end())
        {
            order.push_back(j);
            used_indices.insert(j);
        }
    }
    return order;    
}

void DequeSort::binaryInsert(std::deque<int>& arr, int element)
{
    if (arr.empty()) 
    {
        arr.push_back(element);
        return;
    }
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        comparison_count++;
        if (arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    arr.insert(arr.begin() + low, element);
}

std::deque<int>& DequeSort::mergeInsertSort(std::deque<int>& arr)
{
    int length = arr.size();
    if (length <= 2)
    {
        if (length == 2 && arr[0] > arr[1])
        {
            comparison_count++;
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return arr;
    }
    std::deque<int> mainChain;
    std::deque<int> losers;
    int oddElement = -1;
    bool hasOdd = false;
    for (size_t i = 0; i < arr.size(); i+=2)
    {
        if (i + 1 >= arr.size()) 
        {
            oddElement = arr[i];
            hasOdd = true;
            break;
        }
        comparison_count++;
        if (arr[i] <= arr[i + 1]) 
        {
            mainChain.push_back(arr[i + 1]);
            losers.push_back(arr[i]);
        }
        else 
        {
            mainChain.push_back(arr[i]);
            losers.push_back(arr[i + 1]);
        }
    }
    mainChain = mergeInsertSort(mainChain);
    std::deque<int> insertionOrder = computeJacobsthalOrder(losers.size());
    std::deque<int> result = mainChain;

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int index = insertionOrder[i];
        if (index < (int)losers.size())
            binaryInsert(result, losers[index]);
    }
    if (hasOdd)
        binaryInsert(result, oddElement);
    arr = result;
    return (arr);
}
