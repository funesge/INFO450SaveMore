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
	//constructor for Bank Account
	BankAccount(int acctNumber, double acctBalance);	
	// virtual function because some accounts require redefining
	virtual int withdrawFunds(double withdrawAmount);
	virtual int deposit(double depositAmount);
	//virtual function needed by checking account
	virtual int orderCheck();
	//function needed by savings and certificate
	virtual void assessInterest();
	void displayAccountInfo();
	
};