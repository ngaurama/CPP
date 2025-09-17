/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:00:59 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/04 15:50:38 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdint.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0) 
{

	++_nbAccounts;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

Account::~Account(void) 
{
	--_nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}


void Account::makeDeposit(int deposit) 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit;

	_amount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	_totalAmount += deposit;

	std::cout << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}


bool Account::makeWithdrawal(int withdrawal) 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;

	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		++_nbWithdrawals;
		++_totalNbWithdrawals;
		_totalAmount -= withdrawal;

		std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals
				  << std::endl;
		return true;
	} else {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
}

void Account::displayStatus(void) const 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void Account::displayAccountsInfos(void) 
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

void Account::_displayTimestamp(void) 
{
	time_t t = time(0);
	tm* now = localtime(&t);

	std::cout << "["
			  << (now->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << now->tm_mon + 1
			  << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
			  << std::setw(2) << std::setfill('0') << now->tm_hour
			  << std::setw(2) << std::setfill('0') << now->tm_min
			  << std::setw(2) << std::setfill('0') << now->tm_sec
			  << "] ";
}
