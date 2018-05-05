#include "stdafx.h"
#include "BankAccount.h"
using namespace std;

BankAccount::BankAccount(int acctNumber, double acctBalance)
{
	//declare variables
	accountNumber = acctNumber;
	accountBalance = acctBalance;
}

int BankAccount::withdrawFunds(double withdrawAmount)
{
	//checks that balance isnt negative
	if ((accountBalance - withdrawAmount) < 0)
	{
		return -1;
	}
	else if ((accountBalance - withdrawAmount) > 0)
	{
		accountBalance -= withdrawAmount;
		return 0;
	}
}

int BankAccount::deposit(double depositAmount)
{
	if (depositAmount >= 0)
	{
		accountBalance += depositAmount;
		return 0;
	}
	else if (depositAmount < 0)
	{
		return -1;
	}
}

void BankAccount::displayAccountInfo()
{
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: " << accountBalance << endl;
	cout << "Interest Rate: " << interestRate << endl;
}