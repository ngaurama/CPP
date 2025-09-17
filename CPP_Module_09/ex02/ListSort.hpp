/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:32:11 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/14 21:46:07 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTSORT_HPP
#define LISTSORT_HPP

#include <list>
#include <deque>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>

class ListSort
{
protected:
    std::list<int> lst;
private:
    std::list<int>& mergeInsertSort(std::list<int>& arr);
    void binaryInsert(std::list<int>& sorted, int element);
    std::list<int> getJacobsthalNumbers(int size);
    std::list<int> computeJacobsthalOrder(int size);
    static unsigned long comparison_count;
public:
    ListSort(const std::list<int>& input);
    ListSort(const ListSort& copy);
    ListSort& operator=(const ListSort& copy);
    ~ListSort();
    void sort();
    const std::list<int>& getSortedData() const;
    static unsigned long getComparisonCount();
    static void resetComparisonCount();
};

#endif
