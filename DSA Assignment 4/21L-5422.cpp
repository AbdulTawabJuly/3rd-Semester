#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<Windows.h>;
using namespace std;

class BookData
{
	// Most of the Functions of this class is either getter or setter or overloaded operator
	// These operators dont need to be explained as they are very small
	// User can Differentiate between them easily
private:
	int ISSN;
	string Title;
	int RefBooks;
	int Available;
	list<char*>Authors;
public:
	BookData()
	{
		ISSN = 0;
		Title.clear();
		RefBooks = 0;
		Available = 0;
	}
	BookData(int issn, string title, int ref, int avail, int noofaut, char** arr)
	{
		ISSN = issn;
		Title = title;
		RefBooks = ref;
		Available = avail;
		for (int i = 0; i < noofaut; i++)
		{
			Authors.push_back(arr[i]);
		}
	}
	BookData& operator=(BookData obj)
	{
		ISSN = obj.ISSN;
		Title = obj.Title;
		RefBooks = obj.RefBooks;
		Available = obj.Available;
		Authors = obj.Authors;
		return *this;
	}

	BookData& operator=(string tit)
	{
		Title = tit;
		return *this;
	}
	BookData& operator=(int Ref)
	{
		RefBooks = Ref;
		return *this;
	}
	BookData& operator/=(int Avail)
	{
		Available = Avail;
		return *this;
	}
	BookData& operator= (char* AddAuthors)
	{
		Authors.push_back(AddAuthors);
		return *this;
	}
	BookData& operator-=(int entries)
	{
		while (entries != 0)
		{
			Authors.pop_back();
			entries--;
		}
		return *this;
	}
	int GetISSN()
	{
		return ISSN;
	}
	bool operator==(int No)
	{
		if (this->ISSN == No)
		{
			return true;
		}
		return false;
	}
	friend ostream& operator<<(ostream& out, BookData& obj)
	{
		out << "Book's ISSN : " << obj.ISSN << endl;
		out << "Book's Tittle : " << obj.Title << endl;
		out << "No of Reference Books : " << obj.RefBooks << endl;
		out << "No of Available Books : " << obj.Available << endl;
		out << "Authors Name's :  ";
		list<char*>::iterator it;
		if (!obj.Authors.empty())
		{
			for (it = obj.Authors.begin(); it != obj.Authors.end(); it++)
			{
				cout << *it << "  ";
			}
			cout << endl;
		}
		else
		{
			cout << "Book Has No Authors" << endl;
		}
		cout << endl;
		return out;
	}
	~BookData()
	{
		// Destructor is Empty because we have used List which is PreDefined  So no need to Delete it
		// It will be deleted by its defined destructor
	}
};
template <class T>
class HashMap
{
private:
	vector<list<T>> DataTable;
	int TableSize;
	int CurrLists;
	int CurrElements;
public:

	HashMap()		//Defaault Constructor 
	{
		DataTable.resize(11);
		TableSize = 11;
		CurrLists = 0;
		CurrElements = 0;
	}
	HashMap(int Size)		// Overloaded Constructor
	{
		DataTable.resize(Size);
		TableSize = Size;
		CurrLists = 0;
		CurrElements = 0;
	}
	int HashFunction(int ISSN)
	{
		// Using Universal Hash Function ((ax+b) mod p ) mod m
		// a = Any Number less than table size (7) 
		// b = Any Number less than table size (9)
		// p = Any Prime Number Greator than table size (13)
		// m = Table Size

		int index = (7 * ISSN) + 9;
		index = index % 13;
		index = index % DataTable.size();
		return index;
	}
	float LoadFactor()		// Returns LoadFactor according to no of list in the table and table size
	{
		float LF = CurrLists / TableSize;
		return LF;
	}
	void Insert(int ISSN , BookData obj)
	{
		int index = HashFunction(ISSN);

		if (LoadFactor() > 0.75)			// If the table is 70 - 80 %  it rehashes the table
		{
			list<BookData>::iterator it;
			vector<list<T>>temp(2 * DataTable.size());
			TableSize = 2 * DataTable.size(); // Increase the Table Size
			DataTable.resize(TableSize);   // Resize it

			temp.resize(DataTable.size());  // Resize temp 
			T obj;

			for (int i = 0; i < DataTable.size() / 2; i++)
			{
				for (it = DataTable[i].begin(); it != DataTable[i].end(); it++)
				{
					obj = *it;
					int index = HashFunction((*it).GetISSN());   // Generate Index of Each Element According to new HashFunction()
					temp[index].push_back(obj);					// Push It in Temp
				}
			}

			DataTable = temp;							// Assign it back to DATATABLE
		}

		if (DataTable[index].empty())  // If Empty Insert Element in the list and increase no of list
		{
			DataTable[index].push_back(obj);
			CurrLists++;
			CurrElements++;
		}
		else if (!DataTable[index].empty())		 // If not Empty Insert Element in the list and do not increase no of list beacuse it was inseeted int the same list at the end
		{
			DataTable[index].push_back(obj);
			CurrElements++;
		}
	}
	void Print(int ISSN)
	{
		int index = HashFunction(ISSN);
		list<BookData>::iterator iter;
		for (iter = DataTable[index].begin(); iter != DataTable[index].end(); iter++)
		{
			if (*iter == ISSN)
			{
				cout << *iter;
				return;
			}
		}
		cout << "The Given ISSN Was Not Found" << endl;
	}
	void PrintAll()
	{
		list<BookData>::iterator iter;
		if (CurrLists == 0)
		{
			cout << "No Books in the Record" << endl;
			return;
		}
		for (int i = 0; i < TableSize; i++)
		{
			for (iter = DataTable[i].begin(); iter != DataTable[i].end(); iter++)
			{
				cout << *iter;	
			}
		}
	}
	void Delete(int ISSN)			// Calculate the Index and then search the element on that index if found delete it else return
	{
		int index = HashFunction(ISSN);
		bool Check = false;
		list<BookData>::iterator iter;
		for (iter = DataTable[index].begin(); iter != DataTable[index].end(); iter++)
		{
			if (*iter == ISSN)
			{
				Check = true;
				break;
			}
		}
		if (Check == true)
		{
			iter = DataTable[index].erase(iter);
			CurrLists--;
		}
	}
	bool Search(int ISSN)
	{
		int index = HashFunction(ISSN);
		list<BookData>::iterator iter;

		for (iter = DataTable[index].begin(); iter != DataTable[index].end(); iter++)
		{
			if (*iter == ISSN)
			{
				return true;
			}
		}
		return false;
	}
	void Update(int issn)   // Update the element on the index with the given choice
	{
		int choice = 0;
		int ref, avail, noofaut = 0;
		string newtit;
		char** authors;
		cout << "Press 1 -> To Change Title \nPress 2 -> To Change No of Reference Books \nPress 3 -> To Change No of Available Books \nPress 4 -> To Change Authors Details \n";
		cin >> choice;

		int index = HashFunction(issn);
		list<BookData>::iterator it;
		system("cls");
		if (choice == 1)
		{
			cout << "Enter New Title : ";
			cin.ignore();
			getline(cin, newtit);
			for (it = DataTable[index].begin(); it != DataTable[index].end(); it++)
			{
				if (*it == issn)
				{
					*it = newtit;
					return;
				}
			}
		}
		else if (choice == 2)
		{
			cout << "Enter New Number of Reference Books : ";
			cin >> ref;
			for (it = DataTable[index].begin(); it != DataTable[index].end(); it++)
			{
				if (*it == issn)
				{
					*it = ref;
					return;
				}
			}
		}
		else if (choice == 3)
		{
			cout << "Enter New Number of Available Books : ";
			cin >> avail;
			for (it = DataTable[index].begin(); it != DataTable[index].end(); it++)
			{
				if (*it == issn)
				{
					*it /= avail;
					return;
				}
			}
		}
		else if (choice == 4)
		{
			cout << " Press 1 -> Add New Author \n Press 2 -> Delete Previous Author : ";
			cin >> choice;
			if (choice == 1)
			{
				cout << "Enter No of Authors you Want to Add : ";
				cin >> noofaut;
				authors = new char* [noofaut];

				for (int j = 0; j < noofaut; j++)
				{
					authors[j] = new char[50];
				}
				cout << "Enter Names of Authors : ";
				for (int j = 0; j < noofaut; j++)
				{
					cin >> authors[j];
					for (it = DataTable[index].begin(); it != DataTable[index].end(); it++)
					{
						if (*it == issn)
						{
							*it = authors[j];
						}
					}
				}

			}
			else if (choice == 2)
			{
				int no = 0;
				cout << "Enter Number of Authors you want to delete : ";
				cin >> no;
				for (it = DataTable[index].begin(); it != DataTable[index].end(); it++)
				{
					if (*it == issn)
					{
						*it -= no;
						return;
					}
				}
			}
		}
	}

	~HashMap()
	{
		// Vector will be deleted by its pre defines destructor own its own
		// Same goes for List
	}
};

class Library
{
private:
	HashMap<BookData> HT;
public:

	void InputData()
	{
		int it = 0;
		int issn, ref, avail, noofaut = 0;
		string tit;
		char** authors;
		cout << "Enter Book's ISSN : ";
		cin >> issn;
		cout << "Enter Title of the Book : ";
		cin.ignore();
		getline(cin, tit);
		cout << "Enter No of Reference Books : ";
		cin >> ref;
		cout << "Enter No of Available Books : ";
		cin >> avail;
		cout << "Enter No of Authors : ";
		cin >> noofaut;
		authors = new char* [noofaut];
		for (int j = 0; j < noofaut; j++)
		{
			authors[j] = new char[50];
		}
		cout << "Enter Names of Authors : ";
		for (int j = 0; j < noofaut; j++)
		{
			cin >> authors[j];
		}
		cout << endl << endl;
		BookData tobeInserted(issn, tit, ref, avail, noofaut, authors);

		HT.Insert(issn, tobeInserted);
	}
	void Print(int ISSN)
	{
		HT.Print(ISSN);
	}
	void PrintAll()
	{
		HT.PrintAll();
	}
	void Update()
	{
		int issn;
		cout << "Enter ISSN of The Book You Want to Update : ";
		cin >> issn;
		system("cls");
		if (!HT.Search(issn))
		{
			cout << "The Given Book's Data Does Not Exists " << endl << endl;
			system("pause");
		}
		else
		{
			HT.Update(issn);
			cout << "Data has been Updated " << endl;
			cout << endl;
			system("pause");
		}
	}

	void Delete(int ISSN)
	{
		if (!HT.Search(ISSN))
		{
			cout << "The Given Book's Data Does Not Exists " << endl << endl;
			system("pause");
		}
		else
		{
			HT.Delete(ISSN);
			cout << "Data has been Deleted " << endl;
			cout << endl;
			system("pause");
		}
	}
	~Library()
	{
		 // This will call HashMaps -> Destructor which will Delete its vector and list own its own because its pre defined
	}
};
void Run()
{
	int choice = 0, choice1 = 0, choice2 = 0;
	Library LMS;
	while (true)
	{
		system("cls");
		cout << "							Welcome to Library Management System " << endl;
		cout << "							By: Abdul Tawab (21L-5422) " << endl;
		cout << endl << endl;
		cout << "Press 1 -> To Input Book's Data \nPress 2 -> To Review a Specific Book Data \nPress 3 -> To Update a Book's Data \nPress 4 -> To Delete a Book's Data \nPress 5 -> To Review All the Books \nPress 6 -> To Exit " << endl;
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			LMS.InputData();
		}
		else if (choice == 2)
		{
			system("cls");
			cout << "Enter ISSN of the Book you want To Review : ";
			cin >> choice1;
			LMS.Print(choice1);
			cout << endl;
			system("pause");
		}
		else if (choice == 3)
		{
			system("cls");
			LMS.Update();
			system("cls");
		}
		else if (choice == 4)
		{
			system("cls");
			cout << "Enter ISSN of the Book you want To Delete : ";
			cin >> choice2;
			LMS.Delete(choice2);
			system("cls");
		}
		else if (choice == 5)
		{
			system("cls");
			LMS.PrintAll();
			system("pause");
			system("cls");
		}
		else if (choice == 6)
		{
			system("cls");
			cout << endl;
			cout << "Thank You for your coorporation  ";
			cout << endl;
			cout << endl;
			break;
		}
	}
}
int main()
{
	system("color 74");
	Run();
}