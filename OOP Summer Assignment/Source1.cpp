//#include<iostream>
//using namespace std;
//
//class ATM
//{
//private:
//	int totalCash;
//public:
//	ATM(int);
//	void setCash(int);
//	int getCash();
//	void ShowBalance();
//};
//class AccountHolder
//{
//private:
//	int AccountNumber;
//	int balance;
//public:
//	AccountHolder();
//	AccountHolder(int, int);
//	void setAccountNumber(int);
//	void setBalance(int);
//	int getAccountNumber();
//	int getBalance();
//};
//class Transaction :public ATM
//{
//private:
//	AccountHolder* arr;
//	int size;
//public:
//	Transaction(int, int);
//	void withdrawAmont(int, int);
//	void setData(int, int, int);
//	void showBalance();
//	void reSize(int);
//
//};
//
//ATM::ATM(int cash)
//{
//	totalCash = cash;
//}
//void ATM::setCash(int t_cash)
//{
//	totalCash += t_cash;
//}
//int ATM::getCash()
//{
//	return totalCash;
//}
//
//void ATM::ShowBalance()
//{
//	cout << "Your Balance is  : " << totalCash << endl;
//}
//
//
//
//
//Transaction::Transaction(int s = 0, int cash = 0) :ATM(cash)
//{
//	size = s;
//	if (size)
//	{
//		arr = new AccountHolder[size];
//		int i;
//		for (i = 0; i < size; i++)
//		{
//			arr[i].setAccountNumber(0);
//			arr[i].setBalance(0);
//		}
//	}
//	else
//	{
//		arr = NULL;
//	}
//}
//
//void Transaction::withdrawAmont(int Acc_num, int amount)
//{
//	bool flag = true;
//	int i;
//	for (i = 0; i < size; i++)
//	{
//		if (Acc_num == arr[i].getAccountNumber())
//		{
//			flag = false;
//			break;
//		}
//	}
//	if (flag == false)
//	{
//		if (arr[i].getBalance() >= amount)
//		{
//			if (getCash() >= amount)
//			{
//				arr[i].setBalance(arr[i].getBalance() - amount);
//				setCash(getCash() - amount);
//			}
//			else
//				cout << "Insuffiecient balance in account for this transaction" << endl;
//		}
//		else
//		{
//			cout << "Insuffiecient balance" << endl;
//		}
//	}
//	else
//		cout << "" << endl;
//}
//
//void Transaction::setData(int index, int Acc_num, int bal)
//{
//	if (index >= 0 && index <= size - 1)
//	{
//		if (arr[index].getAccountNumber() == 0)
//		{
//			bool flag = true;
//			int i;
//			for (i = 0; i < size; i++)
//			{
//				if (Acc_num == arr[i].getAccountNumber())
//				{
//					flag = false;
//					break;
//				}
//			}
//			if (flag == true)
//			{
//				arr[index].setAccountNumber(Acc_num);
//				arr[index].setBalance(bal);
//			}
//			else
//			{
//				cout << "Entered account number is invalid" << endl;
//			}
//		}
//		else
//		{
//			arr[index].setBalance(arr[index].getBalance() + bal);
//			setCash(getCash() + bal);
//		}
//	}
//	else
//	{
//		cout << "Entered index is invalid  " << endl;
//	}
//}
//
//void Transaction::showBalance()
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << "The Balance of " << i << " Account is " << arr[i].getBalance() << endl;
//	}
//}
//
//void Transaction::reSize(int S1)
//{
//	AccountHolder* array = new AccountHolder[S1];
//	int i;
//	for (i = 0; i < S1; i++)
//	{
//		array[i].setAccountNumber(arr[i].getAccountNumber());
//		array[i].setBalance(arr[i].getBalance());
//	}
//	if (size < S1)
//	{
//		int j = size;
//		while (j < S1)
//		{
//			array[i].setAccountNumber(0);
//			array[i].setBalance(0);
//			j++;
//		}
//	}
//	delete[]arr;
//	arr = array;
//	size = S1;
//}
//
//AccountHolder::AccountHolder()
//{
//	AccountNumber = 0;
//	balance = 0;
//}
//AccountHolder::AccountHolder(int Acc_num, int b)
//{
//	AccountNumber = Acc_num;
//	balance = b;
//}
//void AccountHolder::setAccountNumber(int num)
//{
//	AccountNumber = num;
//}
//void AccountHolder::setBalance(int bal)
//{
//	balance = bal;
//}
//int AccountHolder::getAccountNumber()
//{
//	return AccountNumber;
//}
//int AccountHolder::getBalance()
//{
//	return balance;
//}
//void showMenu()
//{
//	cout << "Enter 1 to insert a record" << endl;// for set data function
//	cout << "Enter 2 to update ATM cash" << endl;//
//	cout << "Enter 3 to update account holders balance" << endl;// this should handle the case of cash deposit.
//	cout << "Enter 4 to view ATM cash" << endl;//
//	cout << "Enter 5 to view account holder’s balance" << endl;
//	cout << "Enter 6 to resize the array" << endl;
//	cout << "Enter 7 to withdraw amount from the account" << endl;
//	cout << "Enter 0 to terminate the program" << endl;
//
//}
//int main()
//{
//	Transaction t1(3, 5000); //3 is the size of array and 5000 is ATM cash
//	int choice;
//
//	showMenu();
//	cout << "Enter your choice";
//	cin >> choice;
//
//	while (choice != 0)
//	{
//		if (choice == 1)
//		{
//			int ind, num, b;
//			cout << "Enter the index value: ";
//			cin >> ind;
//			cout << "Enter Account Number : ";
//			cin >> num;
//			cout << "ENter Balance :  ";
//			cin >> b;
//			t1.setData(ind, num, b);
//
//			cout << "Enter your choice";
//			cin >> choice;
//		}
//		if (choice == 2)
//		{
//			int cash;
//			cout << "Enter cash in Atm " << endl;
//			cin >> cash;
//			ATM A(cash);
//			A.setCash(cash);
//
//			cout << "Enter your choice";
//			cin >> choice;
//
//		}
//		if (choice == 3)
//		{
//			int b;
//			cout << "ENter balance : " << endl;
//			cin >> b;
//			AccountHolder Acc;
//			Acc.setBalance(b);
//
//			cout << "Enter your choice";
//			cin >> choice;
//		}
//		if (choice == 4)
//		{
//			ATM A(1);
//			cout << "Your ATM Cash is " << A.getCash() << endl;
//
//			cout << "Enter your choice";
//			cin >> choice;
//		}
//		if (choice == 5)
//		{
//			AccountHolder Acc;
//			cout << "AccountHolder Balance : " << Acc.getBalance() << endl;
//
//			cout << "Enter your choice";
//			cin >> choice;
//		}
//		if (choice == 6)
//		{
//			int size;
//			cout << "Enter the new size of array : ";
//			cin >> size;
//			t1.reSize(size);
//
//			cout << "Enter your choice";
//			cin >> choice;
//
//		}
//		if (choice == 7)
//		{
//			int num, am;
//			cout << "Enter account Number ";
//			cin >> num;
//			cout << "ENter the amount :";
//			cin >> am;
//			t1.withdrawAmont(num, am);
//
//			cout << "Enter your choice";
//			cin >> choice;
//		}
//
//
//	}
//
//	system("pause");
//	return 0;
//
//}