// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CDAccount.h"
#include <iostream>
#include <string>

using namespace std;
//function called in main to display basic instruction
void displayInstructions();

int main()
{
	//allocating memory for inputs
	int inputAcctNumber = NULL;
	double inputAcctBalance = NULL;
	double inputDeposit = NULL;
	double inputWithdraw = NULL;
	//term needed for certificates
	int term = NULL;
	char answer;

	//base class pointers for run-time polymorphism
	BankAccount *savingAccount = NULL;
	BankAccount *checkingAccount = NULL;
	BankAccount *cdAccount = NULL;

	//call instructions function
	displayInstructions();
	//ask user for saving account info
	cout << "Please enter the information required for";
	cout<<" your savings account." << endl;
	cout << "Please enter Saving Account Number: ";
	cin >> inputAcctNumber;
	do
	{
		cout << "Please enter the beginning balance for savings: ";
		cin >> inputAcctBalance;
		if (inputAcctBalance < 0)
		{
			cout << "Balance cannot be less than 0!!!" << endl;
		}
	} while (inputAcctBalance < 0);
	//allocate memory for savings account
	savingAccount = new SavingsAccount(inputAcctNumber, inputAcctBalance);
	cout << endl;

	//ask user for checking info
	cout << "Please enter the information required for ";
	cout <<"your checking account." << endl;
	cout << "Please enter Checking Account Number: ";
	cin >> inputAcctNumber;
	do
	{
		cout << "Please enter the beginning balance for Checking: ";
		cin >> inputAcctBalance;
		if (inputAcctBalance < 0)
		{
			cout << "Balance cannot be less than 0!!!" << endl;
		}
	} while (inputAcctBalance < 0);
	//allocate memory for checking account
	checkingAccount = new CheckingAccount(inputAcctNumber, inputAcctBalance);
	cout << endl;

	//ask user for CD account info
	cout << "Please enter the information required for ";
	cout << "your Certificate account." << endl;
	cout << "Please enter Certificate Account Number: ";
	cin >> inputAcctNumber;
	do
	{
		cout << "Please enter the beginning balance for Certificate: ";
		cin >> inputAcctBalance;
		if (inputAcctBalance < 0)
		{
			cout << "Balance cannot be less than 0!!!" << endl;
		}
	} while (inputAcctBalance < 0);
	//asks user for term input
	cout << "Please enter the years in the term for certificate account: ";
	cin >> term;
	cdAccount = new CDAccount(inputAcctNumber, inputAcctBalance, term);
	cout << endl;

	//User will be asked to enter deposits for each account
	cout << "You will need to enter deposit information for accounts." << endl;
	cout << "Please enter deposit amount for Savings: ";
	cin >> inputDeposit;
	//allocates deposit object dynamically with membership operator
	savingAccount->deposit(inputDeposit);
	cout << endl;

	cout << "Please enter deposit amount for Checking: ";
	cin >> inputDeposit;
	//allocates deposit object dynamically with membership operator
	checkingAccount->deposit(inputDeposit);
	cout << endl;

	cout << "Please enter deposit amount for Certificate: ";
	cin >> inputDeposit;
	//allocates deposit object dynamically with membership operator
	cdAccount->deposit(inputDeposit);

	//user will be asked for withdrawal amounts
	cout << "You will now be asked to input withdrawal amounts." << endl;
	cout << "Please enter withdrawal amount for Savings account" << endl;
	cout << "(note automatic fee of $2 will be applied): ";
	cin >> inputWithdraw;
	savingAccount->withdrawFunds(inputWithdraw);
	cout << endl;

	cout << "Please enter withdrawal amount for Checking," << endl;
	cout << "(note if balance falls below $500, a $5 fee will incur): ";
	cin >> inputWithdraw;
	checkingAccount->withdrawFunds(inputWithdraw);
	cout << endl;

	cout << "Please enter withdrawal amount Certifcate: ";
	cin >> inputWithdraw;
	cdAccount->withdrawFunds(inputWithdraw);
	cout << endl;

	//ask user if they would like to order checks
	cout << "Before we display your updated account info, would" << endl;
	cout << "you like to order checks for checking account?" << endl;
	cout << "Enter y or Y for yes(Note a $15 dollar fee on balance " << endl;
	cout<<"and if balance is below $500, a $5 fee will incur): ";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		checkingAccount->orderCheck();
	}
	cout << endl;

	//display account information
	cout << "Savings account info:" << endl;
	savingAccount->displayAccountInfo();
	cout << endl;
	cout << "Checking account info:" << endl;
	checkingAccount->displayAccountInfo();
	cout << endl;
	cout << "Certificate account info:" << endl;
	cdAccount->displayAccountInfo();

	//delete keyword used to free memory and avoid garbage
	delete savingAccount;
	delete checkingAccount;
	delete cdAccount;

	return 0;
}

//function will be called in main
void displayInstructions()
{
	cout << "Welcome to the SaveMore program!"<<endl;
	cout << "This program will create 3 bank";
	cout <<" accounts based on your inputs." << endl;
	cout << "you will be asked to input information such as balance, " << endl;
	cout << "withdrawal amount, deposit amount, and other information ";
	cout << "depending on the account type." << endl;
	cout << "You will be required to enter account number and balance";
	cout << " for each account first." << endl;
	cout << endl;

}

