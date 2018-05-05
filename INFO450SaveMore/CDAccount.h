#pragma once
#include "stdafx.h"
#include "BankAccount.h"
#include <iostream>
#include <string>
using namespace std;

class CDAccount : public BankAccount
{
private:
	// declare constants for interest rates and term variable
	const double FIVEYEARRATE = 0.10;
	const double LESSERRATE = 0.05;
	int term;
public:
	//default constructor for CDAccount
	CDAccount(int term, int acctNumber, double acctBalance);
	void assessInterest();


};
