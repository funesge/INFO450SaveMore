#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
	int accountNumber;
	double interestRate;
	double accountBalance;
public:
	//default constructor for Bank Account
	BankAccount(int acctNumber, double acctBalance);	
	// virtual function because some accounts require redefining
	virtual int withdrawFunds(double withdrawAmount);
	void deposit(double depositAmount);
	void displayAccountInfo();
	
};