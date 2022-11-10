#include "Account.hpp"
#include <time.h>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount = initial_deposit + _totalAmount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	time_t ti;
	char buf[16];

	time(&ti);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&ti));
	std::cout << "[" << buf << "]";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"<< getNbDeposits() \
	<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
	<< ";p_amount:" << _amount - deposit \
	<< ";deposit:" << deposit \
	<< ";amount:" << _amount \
	<< ";nb_deposits:" << _nbDeposits \
	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex \
		<< ";p_amount:" << _amount \
		<< ";withdrawal:refused" \
		<< std::endl;
		return (false);
	}
	else
	{
		_amount = _amount - withdrawal;
		_totalAmount = _totalAmount - withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << " index:" << _accountIndex \
		<< ";p_amount:" << _amount + withdrawal \
		<< ";withdrawal:" << withdrawal \
		<< ";amount:" << _amount \
		<< ";nb_withdrawals:" << _nbWithdrawals \
		<< std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:"<< _nbDeposits \
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}
