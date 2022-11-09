#include "Account.hpp"
#include <time.h>
#include <iostream>

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
	std::cout << "[" << buf << "]" << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"<< getNbDeposits() \
	<< ";withdrawls:" << getNbWithdrawals() << std::endl;
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
		<< ";nb_withdrawal:" << _nbWithdrawals \
		<< std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (0);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:"<< _nbDeposits \
	<< ";withdrawls:" << _nbWithdrawals << std::endl;
}

Account::~Account(void)
{
}
