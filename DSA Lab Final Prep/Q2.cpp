#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;
#define EMPTY 0
#define DELETED 1
#define OCCUPIED 2

template<class v>
struct HashItem
{
	v value;
	short status;
	HashItem()
	{
		status = EMPTY;
	}
};

template<class v>
class HashMap
{
protected:
	HashItem<v>* hashArray;
	int capacity;
	int currentElements;
	
	int num = 5;
public:
	int k;
	HashMap()
	{
		hashArray = new HashItem<v>[11];
		capacity = 11;
		currentElements = 0;
	}
	HashMap(int const size)
	{
		hashArray = new HashItem<v>[size];
		capacity = size;
		currentElements = 0;
	}
	int QuadraticProbing(int key, int i) 
	{
		return (key % HashMap<T>::capacity + (i * i)) % HashMap<T>::capacity;
	}
	int GetKey(string N)  // This Converts String into a key 
	{
		int length = N.size();
		int count = 0;
		for (int i = 0; i < length; i++)
		{
			count += N[i];
		}
		return count;
	}
	int HashFunction(int Key)
	{
		// Using Universal Hash Function ((ax+b) mod p ) mod m
		// a = Any Number less than table size (7) 
		// b = Any Number less than table size (9)
		// p = Any Prime Number Greator than table size (13)
		// m = Table Size

		int index = (7 * Key) + 9;
		index = index % 13;
		index = index % DataTable.size();
		return index;
	}
	void insert(string Name)
	{
		int key = GetKey(Name);

		int idx = HashFunction(key);

		if (hashArray[idx].status == OCCUPIED)//occupied
		{
			int i = 1;
			int j;
			bool found = false;
			while (true)
			{
				j = QuadraticProbing(key, i);
				if (hashArray[j].status != OCCUPIED)
				{
					idx = j;
					found = true;
					break;
				}
				if (j == idx) // we looped around
					break;
				i += 1;
			}
			if (found)
			{
				hashArray[idx].value = Name;
				hashArray[idx].status = OCCUPIED;//occupied
				currentElements += 1;
				if ((double)currentElements / capacity >= 0.75)
				{
					doubleCapacity();
				}
			}
		}
		else
		{
			hashArray[idx].value = Name;
			hashArray[idx].status = OCCUPIED;//occupied
			currentElements += 1;
			if ((double)currentElements / capacity >= 0.75)
			{
				doubleCapacity();
			}
		}
	}
	bool CompareStrings(string string1,string string2)
	{
		int check=0;
		int string1Length = string1.size();
		int string2Length = string2.size();
		if (string1Length != string2Length)
		{
			return -1;
		}
		else
		{
			int i = 0;
			while (i < string1Length)
			{
				if (string1[i] < string2[i] || string1[i] > string2[i])
				{
					return false;
				}
				if (string1[i] == string2[i])
				{
					i++;
				}
			}
			return true;
		}
	}

	bool deleteKey(string Name)
	{
		int idx = GetKey(Name);
		if (hashArray[idx].status == OCCUPIED && CompareStrings(hashArray[idx].value, Name))//found
		{
			hashArray[idx].status = DELETED;
			currentElements -= 1;
			return true;
		}
		else if (hashArray[idx].status == EMPTY)//not found
			return false;
		else
		{
			bool found = false;
			int i = 1;
			while (true)
			{
				int j = QuadraticProbing(key, i);
				if (hashArray[idx].status == OCCUPIED && hashArray[idx].key == key)
				{
					idx = j;
					found = true;
					break;
				}
				if (j == idx) //we looped around
					break;
				i += 1;
			}
			if (found)
			{
				hashArray[idx].status = DELETED;
				currentElements -= 1;
				return true;
			}
			return false;
		}
	}
	void doubleCapacity()
	{
		HashItem<v>* newArr = new HashItem<v>[capacity * 2];
		int p = currentElements;
		int q = capacity;
		currentElements = 0;
		capacity *= 2;
		HashItem<v>* curr = hashArray;
		hashArray = newArr;
		for (int i = 0; i < q; i++)
		{
			if (curr[i].status == OCCUPIED)
				insert(curr[i].key, curr[i].value);
		}
		delete[] curr;
	}
	~HashMap()
	{
		delete[] hashArray;
	}
};

class BookData
{
private:
	string author;
	HashMap<string>Books;
public:


};

class Library
{
private:

	HashMap<BookData>Data;


public:

};

int main()
{
	
	
	
	return 0;
}