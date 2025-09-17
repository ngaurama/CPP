/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:24:09 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/06 22:19:48 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char* dataFile, const char* inputFile) 
    : dataFileName(dataFile ? strdup(dataFile) : 0),
      inputFileName(inputFile ? strdup(inputFile) : 0)
{
    csvData = parseFile(dataFileName, ',');
    inputData = parseFile(inputFileName, '|');
    //std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : dataFileName(other.dataFileName ? strdup(other.dataFileName) : 0),
      inputFileName(other.inputFileName ? strdup(other.inputFileName) : 0),
      csvData(other.csvData),
      inputData(other.inputData)
{
    //std::cout << "BitcoinExchange copy constructor called" << std::endl;
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    //std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
    if (this != &other)
    {
        if (dataFileName)
            free(const_cast<char*>(dataFileName));
        if (inputFileName)
            free(const_cast<char*>(inputFileName));
        dataFileName = other.dataFileName ? strdup(other.dataFileName) : 0;
        inputFileName = other.inputFileName ? strdup(other.inputFileName) : 0;
        csvData = other.csvData;
        inputData = other.inputData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    //std::cout << "BitcoinExchange destructor called" << std::endl;
    if (dataFileName)
        free(const_cast<char*>(dataFileName));
    if (inputFileName)
        free(const_cast<char*>(inputFileName));
}

std::string BitcoinExchange::trim(const std::string & source) 
{
    std::string s(source);
    size_t start = s.find_first_not_of(" \n\r\t");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \n\r\t");
    return s.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(int year, int month, int day) 
{
    if (month < 1 || month > 12) 
        return false;

    if (year < 0 || year > 9999)
        return false;
    static const int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int maxDay = daysInMonth[month - 1];
    if (month == 2) 
    {
        bool leap = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
        if (leap) 
            maxDay = 29;
    }
    if (day < 1 || day > maxDay) 
        return false;
    return true;
}

int BitcoinExchange::dateStringToInt(const std::string& dateStr) 
{
    if (dateStr.length() < 10 || dateStr[4] != '-' || dateStr[7] != '-' || dateStr.length() > 10)
        return -1;
    
    for (size_t i = 0; i < dateStr.length(); ++i)
    {
        if (i == 4 || i == 7)
        {
            if (dateStr[i] != '-')
                return -1;
        }
        else if (!std::isdigit(dateStr[i]))
            return -1;
    }
    
    int year = std::atoi((dateStr.substr(0, 4)).c_str());
    int month = std::atoi((dateStr.substr(5, 2)).c_str());
    int day = std::atoi((dateStr.substr(8, 2)).c_str());
    if (!isValidDate(year, month, day))
        return (-1);
    std::string compact = dateStr.substr(0, 4) + dateStr.substr(5, 2) + dateStr.substr(8, 2);
    return std::atoi(compact.c_str());
}

void BitcoinExchange::parseLine(std::vector<DateData>& data, const std::string& line, const char delimiter)
{
    double errorValue = std::numeric_limits<double>::quiet_NaN();
    double dValue;
    std::stringstream ss(line);
    std::string dateStr, strValue, extra;
    if (!std::getline(ss, dateStr, delimiter))
    {
        data.push_back(DateData(std::string("Error: bad input => ") + line, -1, errorValue));
        return ;
    }
    if (!std::getline(ss, strValue, delimiter))
    {
        data.push_back(DateData(std::string("Error: bad input => ") + line, -1, errorValue));
        return ;
    }
    if (std::getline(ss, extra, delimiter))
    {
        data.push_back(DateData(std::string("Error: bad input => ") + line, -1, errorValue));
        return ;
    }
    dateStr = trim(dateStr);
    strValue = trim(strValue);
    std::stringstream doubler(strValue);
    if (!(doubler >> dValue))
    {
        data.push_back(DateData(std::string("Error: bad input => ") + line, -1, errorValue));
        return ;
    }
    if (dValue < 0)
    {
        data.push_back(DateData(std::string("Error: not a positive number."), -1, errorValue));
        return ;
    }
    else if (dValue < static_cast<double>(std::numeric_limits<int>::min()) || dValue > static_cast<double>(std::numeric_limits<int>::max()))
    {
        data.push_back(DateData(std::string("Error: too large a number."), -1, errorValue));
        return ;
    }
    else if (dValue > 1000 && delimiter == '|')
    {
        data.push_back(DateData(std::string("Error: value not in range 0-1000."), -1, errorValue));
        return ;
    }
    int dateInt = dateStringToInt(dateStr);
    if (dateInt == -1)
    {
        data.push_back(DateData(std::string("Error: Invalid date."), -1, errorValue));
        return ;
    }
    if (delimiter == '|' && dateInt < csvData.begin()->dateInt)
    {
        data.push_back(DateData(std::string("Error: Date is too old."), -1, errorValue));
        return;
    }
    data.push_back(DateData(dateStr, dateInt, dValue));
}

int BitcoinExchange::validateHeader(const std::string line)
{
    std::stringstream headerSS(line);
    std::string col1, col2;
    if (!std::getline(headerSS, col1, '|') || !std::getline(headerSS, col2, '|'))
    {
        std::cerr << "Error: Header line format invalid." << std::endl;
        return 0;
    }
    col1 = trim(col1);
    col2 = trim(col2);
    if (col1 != "date" || col2 != "value")
    {
        std::cerr << "Warning: Unexpected header. Expected 'date | value' but got '" << col1 << " | " << col2 << "'." << std::endl;
        return 0;
    }
    return 1;
}

std::vector<DateData> BitcoinExchange::parseFile(const char* filename, const char delimiter)
{
    std::vector<DateData> data;
    std::ifstream inFile(filename);
    if (!inFile)
    {
        std::cerr << "Error: could not open file" << std::endl;
        return data;
    }
    std::string line;
    std::getline(inFile, line);
    if (delimiter == '|')
        if (validateHeader(line) == 0)
            return data;
    while(std::getline(inFile,line))
    {
        parseLine(data, line, delimiter);
    }
    inFile.close();
    return (data);
}

void BitcoinExchange::calculate()
{
    std::cout << std::setprecision(10);
    for (std::vector<DateData>::iterator it = inputData.begin(); it != inputData.end(); ++it) 
    {
        if (it->dateStr.rfind("Error:", 0) == 0)
        {
            std::cout << it->dateStr << std::endl;
            continue;
        }
        const DateData* match = findMatching(it->dateInt);
        if (!match)
        {
            std::cout << "Error: no data available for or before " << it->dateStr << std::endl;
            continue;
        }
        double result = it->value * match->value;
        std::cout << it->dateStr << " => " << it->value << " = " << result << std::endl;
    }
}

struct CompareDateDataToInt 
{
    bool operator()(const DateData& data, int val) const 
    {
        return data.dateInt < val;
    }
};


const DateData* BitcoinExchange::findMatching(int targetDate) 
{
    std::vector<DateData>::iterator it = std::lower_bound(csvData.begin(), csvData.end(), targetDate, CompareDateDataToInt());

    if (it == csvData.begin() && it->dateInt < targetDate)
        return 0;
    if (it != csvData.end() && it->dateInt == targetDate)
        return &(*it);
    if (it != csvData.begin()) 
        --it;
    return &(*it);
}
