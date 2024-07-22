#include<iostream>
using namespace std;
class Garments
{
	char name[20];
public:
	char* getName()
	{
		return name;
	}
	virtual int calculatePrice() = 0;

};
class Upper :public Garments
{
	int collerSize;
public:
	virtual int getCollerSize() = 0;
	Upper(int c)
	{
		collerSize = c;
	}
	int getcoller()
	{
		return collerSize;
	}
};
class Lower :public Garments
{
	int waist;
public:
	virtual int getWaist() = 0;
	Lower(int w)
	{
		waist = w;
	}
	int waistGet()
	{
		return waist;
	}
};
class Shirt :public Upper
{
public:
	Shirt(int c) :Upper(c)
	{

	}
	int calculatePrice()
	{
		return getcoller() * 20 + 10;
	}
	int getCollerSize()
	{
		int L = getcoller() - 1;
		return L;
	}
};
class Pajama :public Lower
{
public:
	int calculatePrice()
	{
		return waistGet() * 15 + 50;
	}
	int getWaist()
	{
		int W = waistGet() - 1;
		return W;
	}
	Pajama(int w) :Lower(w)
	{

	}
};
class Trouser :public Lower
{
public:
	int calculatePrice();
	int getWaist();
	Trouser(int w) :Lower(w)
	{

	}

};
int Trouser::calculatePrice()
{
	return waistGet() * 20 + 100;
}
int Trouser::getWaist()
{
	int W = waistGet() - 1;
	return W;
}
int main()
{
	int counter = 0;
	Garments* ptr[10];
	for (int i = 0; i < 10; i++)
	{
		ptr[i] = 0;
	}
	int option;

	cout << "Do you want to \n 1. Add item to the cart \n2.Remove item\n3.Make Payment" << endl;
	cin >> option;
	if (option < 1 || option > 3)
	{
		cout << "invalid input";
	}
	while (option == 1)
	{
		cout << "What do you want to buy:\n1.Shirt\n2.Pajama\n3.Trouser" << endl;
		int opt;
		cin >> opt;
		if (opt < 1 || opt > 3)
		{
			cout << "invalid input";
		}
		if (opt == 1)
		{
			int i = 0;
			int c;
			cout << "What should be the collersize ";
			cin >> c;
			while (ptr[i] != 0)
			{

				i++;
			}
			if (i == 10)
			{
				cout << "Your cart is full ." << endl;
			}
			if (i == 10)
			{
				break;
			}
			cout << "Shirt added to cart" << endl << endl;
			cout << "items Added in cart : " << ++counter << endl;
			ptr[i] = new Shirt(c);
		}
		if (opt == 2)
		{
			int i = 0;
			int w;
			cout << "What should be the waist ";
			cin >> w;
			while (ptr[i] != 0)
			{

				i++;
			}
			if (i == 10)
			{
				cout << "Your cart is full ." << endl;
			}
			if (i == 10)
			{
				break;
			}
			cout << "Pajama added to cart" << endl;
			cout << "items Added in cart : " << ++counter << endl;
			ptr[i] = new Pajama(w);

		}
		if (opt == 3)
		{
			int w;
			int i = 0;
			while (ptr[i] != 0)
			{

				i++;
			}
			if (i == 10)
			{
				cout << "Your cart is full " << endl;
			}
			if (i == 10)
			{
				break;
			}
			cout << "What should be the waist";
			cin >> w;

			cout << "Trouser added to cart" << endl;
			cout << "items Added in cart : " << ++counter << endl;
			ptr[i] = new Trouser(w);
		}
		cout << "Do you want to \n 1. Add item to the cart \n2.Remove item\n3.Make Payment";
		cin >> option;
		if (option != 1)
		{
			break;
		}
	}

	while(option == 2)
	{
		int del = 0;
		cout << "Which Item do you want to delete\nEnter Number " << endl;
		cin >> del;
		if (ptr[del-1] == 0)
		{
			cout << "Invalid Input" << endl;
		}
		else
		{
			if (ptr[del] != 0)
			{
				for (int i = del-1; ptr[i] != 0; i++)
				{
					ptr[i] = 0;
					ptr[i] = ptr[i + 1];
				}
				
			}
			else if (ptr[del] == 0)
			{
				ptr[del-1]=0;
			}
		}

		cout << "Do you want to \n 1. Add item to the cart \n2.Remove item\n3.Make Payment";
		cin >> option;
		if (option != 2)
		{
			break;
		}
	}

	if (option == 3)
	{
		int i = 0;
		int total = 0;
		while (ptr[i] != 0)
		{
			total = total + ptr[i]->calculatePrice();
			i++;
		}
		cout << "Your bill = " << total;
	}

	system("pause");
	return 0;
}