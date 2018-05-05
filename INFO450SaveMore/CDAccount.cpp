#include "stdafx.h"
#include "CDAccount.h"
#include <iostream>
#include <string>

CDAccount::CDAccount(int acctNumber, double acctBalance, int term) :BankAccount(acctNumber, acctBalance)
{
	if (term < 5)
	{
		interestRate = LESSERRATE;
	}
	else if (term > 4)
	{
		interestRate = FIVEYEARRATE;
	}
	assessInterest();
}

void CDAccount::assessInterest()
{
	//calculates monthly interest
	accountBalance += (accountBalance*(interestRate) / 12);
}
