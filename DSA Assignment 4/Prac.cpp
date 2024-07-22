//#include<iostream>
//#include<list>
//#include<cstring>
//
//using namespace std;
//
//class HashTables
//{
//private:
//	static const int HashGroups = 10;
//	list<pair<int, string>> table[HashGroups];
//
//public:
//
//	bool IsEmpty ()
//	{
//		int sum{};
//		for (int i{}; i < HashGroups; i++)
//		{
//			sum += table[i].size();
//		}
//
//		if (!sum)
//			return true;
//		else
//			return false;
//	}
//
//	int HastFunction(int key)
//	{
//		return key % HashGroups;
//	}
//
//	
//
//	void InsertItem(int key, string value)
//	{
//		int hashval = HastFunction(key);
//		auto& cell = table[hashval];
//		auto bitr = begin(cell);
//		bool KeyExist = false;
//		for (; bitr != end(cell); bitr++)
//		{
//			if (bitr->first == key)
//			{
//				KeyExist = true;
//				bitr->second = value;
//				cout << "Key Exist Value Replaced" << endl;
//			}
//		}
//
//		if (!KeyExist)
//		{
//			cell.emplace_back(key, value);
//		}
//		return;
//	}
//
//	void RemoveItem(int key)
//	{
//		int hashval = HastFunction(key);
//		auto& cell = table[hashval];
//		auto bitr = begin(cell);
//		bool KeyExist = false;
//		for (; bitr != end(cell); bitr++)
//		{
//			if (bitr->first == key)
//			{
//				KeyExist = true;
//				bitr = cell.erase(bitr);
//				cout << "Item Removes " << endl;
//			}
//		}
//
//		if (!KeyExist)
//		{
//			cout << "Item Not Found" << endl;
//		}
//		return;
//	}
//
//	void PrintTable()
//	{
//		for (int i{}; i < HashGroups; i++)
//		{
//			if (table[i].size() == 0)
//				continue;
//
//			auto bitr = table[i].begin();
//			for (; bitr != table[i].end(); bitr++)
//			{
//				cout << "Key : " << bitr->first << " Value:  " << bitr->second << endl;
//			}
//		}
//
//		return;
//	}
//};
//
//int main()
//{
//	HashTables HT;
//
//	if (HT.IsEmpty())
//	{
//		cout << "Correct Answer" << endl;
//	}
//	else
//	{
//		cout << "Incorrect" << endl;
//	}
//
//	HT.InsertItem(905, "Jim");
//	HT.InsertItem(201, "Tom");
//	HT.InsertItem(332, "Bob");
//	HT.InsertItem(124, "Sally");
//	HT.InsertItem(107, "Sandy");
//	HT.InsertItem(929, "Barb");
//	HT.InsertItem(928, "Rob");
//	HT.InsertItem(928, "Rick");
//
//	HT.PrintTable();
//
//	HT.RemoveItem(332);
//	HT.RemoveItem(100);
//
//
//
//	return 0;
//}