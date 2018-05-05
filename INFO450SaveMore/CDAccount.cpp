#include "stdafx.h"
#include "CDAccount.h"
#include <iostream>
#include <string>

CDAccount::CDAccount(int term, int acctNumber, double acctBalance) :BankAccount(accountNumber, accountBalance)
{
	if (term < 5)
	{
		interestRate = LESSERRATE;
	}
	else if (term > 4)
	{
		interestRate = FIVEYEARRATE;
	}
}

void CDAccount::assessInterest()
{
	//calculates monthly interest
	accountBalance += (accountBalance*(interestRate) / 12);
}