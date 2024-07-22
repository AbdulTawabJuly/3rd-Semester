//#include<iostream>
//#include<list>
//#include<vector>
//#include<string>
//using namespace std;
//
//int prime = 23;
//
//bool isprime(int n)
//{
//	if (n % 2 == 0)
//		return false;
//	for (int i = n / 2; i > 1; i--)
//	{
//		if ((n % i) == 0)
//			return false;
//	}
//	return true;
//}
//
//
//class book {
//private:
//	int issn;
//	int copies;
//	int available;
//	string title;
//	list<string> authors;
//public:
//	book(int iss = 0, int cop = 0, int avail = 0, string tit = "NO Name")
//	{
//		issn = iss;
//		copies = cop;
//		available = avail;
//		title = tit;
//	}
//	int issngetter()
//	{
//		return issn;
//	}
//	void setauthorname(string st)
//	{
//		authors.push_back(st);
//	}
//	bool operator ==(book obj)
//	{
//		if (this->issngetter() == obj.issngetter())
//			return true;
//		return false;
//	}
//	void printissn()
//	{
//		cout << issn << " \n";
//	}
//	book& operator = (const book obj)
//	{
//
//		issn = obj.issn;
//		copies = obj.copies;
//		available = obj.available;
//		title = obj.title;
//		authors = obj.authors;
//		return *this;
//
//	}
//	friend ostream& operator << (ostream& os, book obj)
//	{
//		cout << "\t\t-----Book's Data-----";
//		cout << "\nTitle : " << obj.title;
//		cout << "\nISSN : " << obj.issn;
//		cout << "\nNumber of Copies : " << obj.copies;
//		cout << "\nAvailable Copies : " << obj.available;
//		cout << "\nAuthors : ";
//
//
//		list<string> ::iterator it;
//		for (it = obj.authors.begin(); it != obj.authors.end(); it++)
//		{
//			cout << *it << endl;
//		}
//
//		return os;
//	}
//};
//
////class item
////{
////private:
////	list<book> L;
////public:
////	item()
////	{
////
////	}
////	void insert_in_list(book data)
////	{
////		L.push_front(data);
////	}
////	void delete_in_list(book data)
////	{
////		L.remove(data);
////	}
////};
//
//class hashmap
//{
//private:
//	vector<list<book>> Table;
//	int tablesize;
//	int currsize;
//public:
//	hashmap()
//	{
//		Table.resize(2);
//		tablesize = currsize = 0;
//	}
//	int generate_index(int key)
//	{
//		int temp = 0;
//		temp = (3 * key) + 5;
//		temp = temp % prime;
//		temp = temp % Table.size();
//		return temp;
//	}
//	void insert(int key, book data)
//	{
//		int index = generate_index(key);
//		Table[index].push_back(data);
//		currsize++;
//		float loadfactor = (float(currsize)) / float(Table.size());
//		if (loadfactor > 0.5)
//		{
//			tablesize = 2 * Table.size();
//			Table.resize(tablesize);
//			remap();
//		}
//	}
//	void remap()
//	{
//		list<book> ::iterator it;
//		vector<list<book>> T2;
//		T2.resize(Table.size());
//		book B;
//		for (int i = 0; i < Table.size() / 2; i++)
//		{
//			for (it = Table[i].begin(); it != Table[i].end(); it++)
//			{
//				B = *it;
//				int index = generate_index((*it).issngetter());
//				T2[index].push_back(B);
//			}
//		}
//		Table = T2;
//		prime = getprime();					//to ensure that the prime number used in hash function is greater than table size
//	}
//	void delete_book(int key)
//	{
//		book b1(key, 0, 0);
//		key = generate_index(key);
//		list<book>::iterator it1;
//		bool isfound = 0;
//		for (it1 = Table[key].begin(); it1 != Table[key].end(); it1++)
//		{
//			if (*it1 == b1)
//			{
//				isfound = 1;
//				break;
//			}
//		}
//		if (isfound)
//		{
//			it1 = Table[key].erase(it1);
//			cout << "\nDeleted!!!\n";
//			return;
//		}
//		else
//		{
//			cout << "\nBook with the given ISSN not found!!!\n";
//		}
//	}
//	void print()
//	{
//		list<book>::iterator iter;
//		for (int i = 0; i < Table.size(); i++)
//		{
//			for (iter = Table[i].begin(); iter != Table[i].end(); iter++)
//			{
//				cout << *iter;
//			}
//		}
//	}
//	int currsizegetter()
//	{
//		return currsize;
//	}
//	void printspecific(int iss)
//	{
//		book B(iss);
//		iss = generate_index(iss);
//		list<book> ::iterator it;
//		for (it = Table[iss].begin(); it != Table[iss].end(); it++)
//		{
//			if (*it == B)
//			{
//				cout << *it;
//				return;
//			}
//		}
//		cout << "\nThere's no existing book with the given ISSN!!!\n";
//
//		/*book B(iss,0,0);
//		list<book>:: iterator it;
//		for (int i = 0; i < Table.size(); i++)
//		{
//			for (it = Table[i].begin(); it != Table[i].end(); it++)
//			{
//				if (*it == B)
//				{
//					cout << *it;
//					return;
//				}
//			}
//		}
//		cout << "The Book with the given ISSN doesnt exist!!!";*/
//
//	}
//
//	void update(book B)
//	{
//		int index = generate_index(B.issngetter());
//		list<book>::iterator it;
//		for (it = Table[index].begin(); it != Table[index].end(); it++)
//		{
//			if (*it == B)
//			{
//				*it = B;
//				return;
//			}
//		}
//	}
//	void PrintHashTable()
//	{
//		list<book>::iterator iter;
//		for (int i = 0; i < Table.size(); i++)
//		{
//			cout << "\nRow # " << i + 1;
//			for (iter = Table[i].begin(); iter != Table[i].end(); iter++)
//			{
//				(*iter).printissn();
//			}
//		}
//	}
//	int getprime()
//	{
//		int k = Table.size() + 1;
//		if (k % 2 == 0)
//			k++;
//		while (!isprime(k))
//		{
//			k += 2;
//		}
//		return k;
//	}
//	~hashmap()
//	{
//
//	}
//};
//
//
//
//int main()
//{
//	hashmap H1;
//	int n = 0;
//a:
//	cout << "\t--------------Library Implemented by Hashmaps--------------\n\n\n";
//	cout << "1- Insert a Book Record\n2- Review a Book Record\n3- Delete a Book Record\n";
//	cout << "4- Update a Book Record\n5- Watch all Book's Data\n6- Print The Hash Table\n7- Exit";
//	cin >> n;
//	switch 👎
//	{
//		case 1:
//		{
//			int k = 0;
//			int issn = 0;
//			int copies = 0;
//			int available = 0;
//			string title;
//			cout << "Start inserting the Book Data...\n1- Insert ISSN : ";
//			cin >> issn;
//			cout << "2- Insert no of Copies : ";
//			cin >> copies;
//			cout << "3-Insert the Title of the Book : ";
//			cin.ignore(1,'\n');
//			getline(cin, title);
//			cout << "4-How many authors of the book ...?";
//			cin >> k;
//			book B(issn, copies, copies, title);
//			for (int i = 0; i < k; i++)
//			{
//				cout << "Enter author's name : ";
//				string st;
//				cin.ignore(1,'\n');
//				getline(cin, st);
//				B.setauthorname(st);
//
//			}
//			H1.insert(issn,B);
//			cout << "\nBook Inserted!\n";
//			break;
//		}
//		case 2:
//		{
//			int issn = 0;
//			cout << "\nEnter the ISSN to watch that book's data\n";
//			cin >> issn;
//			H1.printspecific(issn);
//			break;
//		}
//		case 3:
//		{
//			int issn = 0;
//			cout << "Enter The ISSN : ";
//			cin >> issn;
//			H1.delete_book(issn);
//			break;
//		}
//		case 4:
//		{
//			int k = 0;
//			int issn = 0;
//			int copies = 0;
//			int available = 0;
//			string title;
//
//			cout << "Start Entering the Data to be Updated!!!\nISSN : ";
//			cin >> issn; cout << "\nCopies : "; cin >> copies; cout << "\nAvailable : "; cin >> available;
//			book B1(issn, copies, available, title);
//			cout << "3-Insert the Title of the Book : ";
//			cin.ignore(1,'\n');
//			getline(cin, title);
//			cout << "4-How many authors of the book ...?";
//			cin >> k;
//			for (int i = 0; i < k; i++)
//			{
//				cout << "Enter author's name : ";
//				string st;
//				cin.ignore(1,'\n');
//				getline(cin, st);
//				B1.setauthorname(st);
//
//			}
//			H1.update(B1);
//			break;
//		}
//		case 5:
//		{
//			cout << "\n\nThe Library has " << H1.currsizegetter() << " Books\n";
//			H1.print();
//			break;
//		}
//		case 6:
//		{
//			H1.PrintHashTable();
//			break;
//		}
//		case 7:
//		{
//			goto endd;
//			break;
//		}
//		default:
//		{
//			cout << "Enter a Valid Number!!!";
//			system("CLS");
//			goto a;
//		}
//	}
//	goto a;
//
//
//endd:
//	system("pause");
//	return 0;
//}