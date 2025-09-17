/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:24:09 by ngaurama          #+#    #+#             */
/*   Updated: 2025/05/27 21:41:22 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <string.h>

struct DateData
{
    std::string dateStr;
    int dateInt;
    double value;

    DateData(const std::string& ds, int di, double v)
        : dateStr(ds), dateInt(di), value(v) {}
};

class BitcoinExchange
{
private:
    const char* dataFileName;
    const char* inputFileName;
    std::vector<DateData> csvData;
    std::vector<DateData> inputData;
    std::string trim(const std::string & source);
    bool isValidDate(int year, int month, int day); 
    int dateStringToInt(const std::string& dateStr);
    int validateHeader(const std::string line);
    void parseLine(std::vector<DateData>& data, const std::string& line, const char delimiter);
    const DateData* findMatching(int targetDate);
public:
    BitcoinExchange(const char* dataFile, const char* inputFile);
    BitcoinExchange(const BitcoinExchange& copy);
    BitcoinExchange& operator=(const BitcoinExchange& copy);
    ~BitcoinExchange();
    std::vector<DateData> parseFile(const char* filename, const char delimiter);
    void calculate();
};

#endif // BITCOINEXCHANGE_HPP
