#include "stdafx.h"
#include "CheckingAccount.h"
#include <iostream>
#include <string>

CheckingAccount::CheckingAccount(int acctNumber, double acctBalance) :BankAccount(acctNumber, acctBalance)
{
	interestRate = 0;
}

//function checks if withdrawal is possible and for low balance
int CheckingAccount::withdrawFunds(double withdrawAmount)
{
	if ((accountBalance - withdrawAmount) < 0)
	{
		return -1;
	}
	else if ((accountBalance - withdrawAmount) > 0)
	{
		accountBalance -= withdrawAmount;
		//uses checkBlance function to assess if fee needed
		checkBalance();
		return 0;

	}
}

int CheckingAccount::orderCheck()
{
	if (accountBalance > ORDERCHECKFEE)
	{
		accountBalance -= ORDERCHECKFEE;
		//uses checkBlance function to assess if fee needed
		checkBalance();
		return 0;
	}
	else if (accountBalance < ORDERCHECKFEE)
	{
		return -1;
	}
}

void CheckingAccount::checkBalance()
{
	if (accountBalance < 500)
	{
		accountBalance -= LOWBALANCEFEE;
	}
}