/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeSort.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:31:43 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/14 21:38:28 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUESORT_HPP
#define DEQUESORT_HPP

#include <deque>
#include <set>
#include <iostream>
#include <string>

class DequeSort 
{
protected:
    std::deque<int> dq;
private:
    static unsigned long comparison_count;
    std::deque<int>& mergeInsertSort(std::deque<int>& arr);
    void binaryInsert(std::deque<int>& sorted, int element);
    std::deque<int> getJacobsthalNumbers(int size);
    std::deque<int> computeJacobsthalOrder(int size);
public:
    DequeSort(const std::deque<int>& input);
    DequeSort(const DequeSort& copy);
    DequeSort& operator=(const DequeSort& copy);
    ~DequeSort();
    void sort();
    const std::deque<int>& getSortedData() const;
    static unsigned long getComparisonCount();
    static void resetComparisonCount();
};

#endif