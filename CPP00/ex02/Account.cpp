/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:39:49 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 10:40:21 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0; 
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t t = time(NULL);
	std::tm buf;
	std::tm tm = *localtime_r(&t, &buf);

	std::cout << "[" << tm.tm_year + 1900
		<< std::setfill('0') << std::setw(2) << tm.tm_mon
		<< std::setfill('0') << std::setw(2) << tm.tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << tm.tm_hour
		<< std::setfill('0') << std::setw(2) << tm.tm_min
		<< std::setfill('0') << std::setw(2) << tm.tm_sec << "] ";
}

int	Account::getNbAccounts(void)
{
	return  (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int  Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{

	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" <<_totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" 
		<< _amount << ";deposits:" << _nbDeposits 
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int p_amount = 0;

	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" 
		<< p_amount << ";deposit:" << deposit
		<< ";amount:" << _amount << ";nb_deposits:" 
		<< _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int p_amount = 0;

	Account::_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" 
			<< _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	p_amount = _amount;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	std::cout << "index:" << _accountIndex << ";p_amount:" 
		<< p_amount << ";withdrawal:" << withdrawal
		<< ";amount:" << _amount << ";nb_withdrawals:" 
		<< _nbWithdrawals << std::endl;

	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" 
		<< _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" 
		<< _amount << ";closed" << std::endl;
}
