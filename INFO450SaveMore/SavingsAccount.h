#pragma once
#include "stdafx.h"
#include "BankAccount.h"
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount :public BankAccount
{
private:
	//declare constants for apr and fees
	const double FIRSTAPR = 0.01;
	const double SECONDAPR = 0.02;
	const double WITHDRAWFEE = 2.00;
public:
	//default constructor for Savings
	SavingsAccount(int acctNumber, double acctBalance);
	int withdrawFunds(double withdrawAmount);
	void deposit(double depositAmount);
	void assessInterest();


};

