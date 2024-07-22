//#include<iostream>
//#include<vector>
//#include<list>
//#include<string>
//#include<Windows.h>;
//using namespace std;
//
//
//template <class T>
//class HashMap
//{
//private:
//	vector<vector<T>> DataTable;
//	int TableSize;
//	int CurrLists;
//	int CurrElements;
//public:
//
//	HashMap()		//Defaault Constructor 
//	{
//		DataTable.resize(11);
//		TableSize = 11;
//		CurrLists = 0;
//		CurrElements = 0;
//	}
//	HashMap(int Size)		// Overloaded Constructor
//	{
//		DataTable.resize(Size);
//		TableSize = Size;
//		CurrLists = 0;
//		CurrElements = 0;
//	}
//	int HashFunction(int ISSN)
//	{
//		// Using Universal Hash Function ((ax+b) mod p ) mod m
//		// a = Any Number less than table size (7) 
//		// b = Any Number less than table size (9)
//		// p = Any Prime Number Greator than table size (13)
//		// m = Table Size
//
//		int index = (7 * ISSN) + 9;
//		index = index % 13;
//		index = index % DataTable.size();
//		return index;
//	}
//	float LoadFactor()		// Returns LoadFactor according to no of list in the table and table size
//	{
//		float LF = CurrLists / TableSize;
//		return LF;
//	}
//	void Insert(int ISSN, BookData obj)
//	{
//		int index = HashFunction(ISSN);
//
//		if (LoadFactor() > 0.75)			// If the table is 70 - 80 %  it rehashes the table
//		{
//			list<BookData>::iterator it;
//			vector<list<T>>temp(2 * DataTable.size());
//			TableSize = 2 * DataTable.size(); // Increase the Table Size
//			DataTable.resize(TableSize);   // Resize it
//
//			temp.resize(DataTable.size());  // Resize temp 
//			T obj;
//
//			for (int i = 0; i < DataTable.size() / 2; i++)
//			{
//				for (it = DataTable[i].begin(); it != DataTable[i].end(); it++)
//				{
//					obj = *it;
//					int index = HashFunction((*it).GetISSN());   // Generate Index of Each Element According to new HashFunction()
//					temp[index].push_back(obj);					// Push It in Temp
//				}
//			}
//
//			DataTable = temp;							// Assign it back to DATATABLE
//		}
//
//		if (DataTable[index].empty())  // If Empty Insert Element in the list and increase no of list
//		{
//			DataTable[index].push_back(obj);
//			CurrLists++;
//			CurrElements++;
//		}
//		else if (!DataTable[index].empty())		 // If not Empty Insert Element in the list and do not increase no of list beacuse it was inseeted int the same list at the end
//		{
//			DataTable[index].push_back(obj);
//			CurrElements++;
//		}
//	}
//	void Print(int ISSN)
//	{
//		int index = HashFunction(ISSN);
//		list<BookData>::iterator iter;
//		for (iter = DataTable[index].begin(); iter != DataTable[index].end(); iter++)
//		{
//			if (*iter == ISSN)
//			{
//				cout << *iter;
//				return;
//			}
//		}
//		cout << "The Given ISSN Was Not Found" << endl;
//	}
//	void PrintAll()
//	{
//		list<BookData>::iterator iter;
//		if (CurrLists == 0)
//		{
//			cout << "No Books in the Record" << endl;
//			return;
//		}
//		for (int i = 0; i < TableSize; i++)
//		{
//			for (iter = DataTable[i].begin(); iter != DataTable[i].end(); iter++)
//			{
//				cout << *iter;
//			}
//		}
//	}
//	void Delete(int ISSN)			// Calculate the Index and then search the element on that index if found delete it else return
//	{
//		int index = HashFunction(ISSN);
//		bool Check = false;
//		list<BookData>::iterator iter;
//		for (iter = DataTable[index].begin(); iter != DataTable[index].end(); iter++)
//		{
//			if (*iter == ISSN)
//			{
//				Check = true;
//				break;
//			}
//		}
//		if (Check == true)
//		{
//			iter = DataTable[index].erase(iter);
//			CurrLists--;
//		}
//	}
//
//	bool Search(int ISSN)
//	{
//		int index = HashFunction(ISSN);
//		list<BookData>::iterator iter;
//
//		for (iter = DataTable[index].begin(); iter != DataTable[index].end(); iter++)
//		{
//			if (*iter == ISSN)
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//	
//	~HashMap()
//	{
//		// Vector will be deleted by its pre defines destructor own its own
//		// Same goes for List
//	}
//};
//
//class Library
//{
//private:
//	HashMap<BookData> HT;
//public:
//
//	void InputData()
//	{
//		int it = 0;
//		int issn, ref, avail, noofaut = 0;
//		string tit;
//		char** authors;
//		cout << "Enter Book's ISSN : ";
//		cin >> issn;
//		cout << "Enter Title of the Book : ";
//		cin.ignore();
//		getline(cin, tit);
//		cout << "Enter No of Reference Books : ";
//		cin >> ref;
//		cout << "Enter No of Available Books : ";
//		cin >> avail;
//		cout << "Enter No of Authors : ";
//		cin >> noofaut;
//		authors = new char* [noofaut];
//		for (int j = 0; j < noofaut; j++)
//		{
//			authors[j] = new char[50];
//		}
//		cout << "Enter Names of Authors : ";
//		for (int j = 0; j < noofaut; j++)
//		{
//			cin >> authors[j];
//		}
//		cout << endl << endl;
//		BookData tobeInserted(issn, tit, ref, avail, noofaut, authors);
//
//		HT.Insert(issn, tobeInserted);
//	}
//	void Print(int ISSN)
//	{
//		HT.Print(ISSN);
//	}
//	void PrintAll()
//	{
//		HT.PrintAll();
//	}
//	
//
//	void Delete(int ISSN)
//	{
//		if (!HT.Search(ISSN))
//		{
//			cout << "The Given Book's Data Does Not Exists " << endl << endl;
//			system("pause");
//		}
//		else
//		{
//			HT.Delete(ISSN);
//			cout << "Data has been Deleted " << endl;
//			cout << endl;
//			system("pause");
//		}
//	}
//	~Library()
//	{
//		// This will call HashMaps -> Destructor which will Delete its vector and list own its own because its pre defined
//	}
//};
//void Run()
//{
//	int choice = 0, choice1 = 0, choice2 = 0;
//	Library LMS;
//	while (true)
//	{
//		system("cls");
//		cout << "							Welcome to Library Management System " << endl;
//		cout << "							By: Abdul Tawab (21L-5422) " << endl;
//		cout << endl << endl;
//		cout << "Press 1 -> To Input Book's Data \nPress 2 -> To Review a Specific Book Data \nPress 3 -> To Update a Book's Data \nPress 4 -> To Delete a Book's Data \nPress 5 -> To Review All the Books \nPress 6 -> To Exit " << endl;
//		cin >> choice;
//		if (choice == 1)
//		{
//			system("cls");
//			LMS.InputData();
//		}
//		else if (choice == 2)
//		{
//			system("cls");
//			cout << "Enter ISSN of the Book you want To Review : ";
//			cin >> choice1;
//			LMS.Print(choice1);
//			cout << endl;
//			system("pause");
//		}
//		
//		else if (choice == 4)
//		{
//			system("cls");
//			cout << "Enter ISSN of the Book you want To Delete : ";
//			cin >> choice2;
//			LMS.Delete(choice2);
//			system("cls");
//		}
//		else if (choice == 5)
//		{
//			system("cls");
//			LMS.PrintAll();
//			system("pause");
//			system("cls");
//		}
//		else if (choice == 6)
//		{
//			system("cls");
//			cout << endl;
//			cout << "Thank You for your coorporation  ";
//			cout << endl;
//			cout << endl;
//			break;
//		}
//	}
//}
//int main()
//{
//	system("color 74");
//	Run();
//}