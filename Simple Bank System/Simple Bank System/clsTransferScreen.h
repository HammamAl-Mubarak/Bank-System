#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsTransferScreen :protected clsScreen
{

private:
	static clsBankClient _CheckIfClientExist(string AccountNumber)
	{
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return Client;
	}

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "___________________\n\n";
		cout << "Full Name  : " << Client.FullName();
		cout << "\nAcc. Number: " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n___________________\n\n";
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen");

		string AccountNumber_TransferFrom, AccountNumber_TransferTo;

		cout << "\nPlease Enter Account Number To Transfer From: ";
		AccountNumber_TransferFrom = clsInputValidate::ReadString();

		clsBankClient Client1 = _CheckIfClientExist(AccountNumber_TransferFrom);
		_PrintClientCard(Client1);

		cout << "Please Enter Account Number To Transfer To: ";
		AccountNumber_TransferTo = clsInputValidate::ReadString();

		while (AccountNumber_TransferFrom == AccountNumber_TransferTo)
		{
			cout << "\nYou cannot transfer to the same account. Enter another: ";
			AccountNumber_TransferTo = clsInputValidate::ReadString();
		}

		clsBankClient Client2 = _CheckIfClientExist(AccountNumber_TransferTo);
		_PrintClientCard(Client2);

		float TransferAmount = ReadAmount(Client1);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operation? [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client1.Transfer(TransferAmount, Client2,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
				_PrintClientCard(Client1);
				_PrintClientCard(Client2);
				return;
			}
			cout << "\nTransfer Failed \n";
			_PrintClientCard(Client1);
			_PrintClientCard(Client2);
		}
	}

};

