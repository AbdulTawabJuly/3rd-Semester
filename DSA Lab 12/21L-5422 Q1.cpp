//#include<iostream>
//using namespace std;
//
//template <class v>
//struct HashItem
//{
//	int key;
//	v value;
//	short status;
//
//	void SetStatus(int s)
//	{
//		status = s;
//	}
//	void SetValue(v val)
//	{
//		value = val;
//	}
//	void SetKey(int k)
//	{
//		key = k;
//	}
//	v GetValue()
//	{
//		return value;
//	}
//	short GetStatus()
//	{
//		return status;
//	}
//	int CheckStatus()
//	{
//		if (status == 0)
//			return 0;
//		else if (status == 1)
//			return 1;
//		else if (status == 2)
//			return 2;
//	}
//	bool operator==(int k)
//	{
//		if (status == k)
//			return true;
//		else
//			return false;
//	}
//	bool operator!=(int k)
//
//	{
//		if (status != k)
//			return true;
//		else
//			return false;
//	}
//	bool operator/=(int k)
//	{
//		if (key == k)
//			return true;
//		else
//			return false;
//	}
//	//Assignment operator
//	HashItem& operator=(HashItem& obj)
//	{
//		key = obj.key;
//		value = obj.value;
//		status = obj.status;
//		return *this;
//	}
//};
//
//template <class v>
//class HashMap
//{
//private:
//	HashItem<v>* hashArray;
//	int capacity;
//	float LoadFactor;
//	int currentElements;
//
//public:
//	HashMap()
//	{
//		hashArray = new HashItem<v>[10];
//		capacity = 10;
//		LoadFactor = 0;
//		currentElements = 0;
//
//		for (int i = 0; i < capacity; i++)
//		{
//			hashArray[i].SetStatus(0);
//		}
//	}
//	HashMap(int const cap)
//	{
//		if (cap < 1)
//		{
//			cout << "Wrong Capacity" << endl;
//			return;
//		}
//		hashArray = new HashItem<v>[cap];
//		capacity = cap;
//		LoadFactor = 0;
//		currentElements = 0;
//
//		for (int i = 0; i < cap; i++)
//		{
//			hashArray[i].SetValue(0);
//			hashArray[i].SetStatus(0);
//		}
//	}
//	int HashFunc(int key)
//	{
//		return key % capacity;
//	}
//	virtual int getNextCandidateIndex(int key, int i)
//	{
//		int index = HashFunc(key) + i;
//		return index;
//	}
//	float GetLoadFactor()
//	{
//		float ret = currentElements % capacity;
//		return ret;
//	}
//	void doubleCapacity()
//	{
//		HashItem<v>* temp = new HashItem<v>[capacity];// temp Array pointing to previous hashArray 
//		for (int i = 0; i < capacity; i++)
//		{
//			temp[i] = hashArray[i];
//		}
//		delete[] hashArray;
//		hashArray = new HashItem<v>[capacity * 2];
//		int prev = capacity;
//		currentElements = 0;
//		capacity = capacity * 2;
//
//		for (int j = 0; j < prev; j++)
//		{
//			hashArray[j] = temp[j];
//		}
//		delete[] temp;
//	}
//	void Insert(int const key, v value)
//	{
//		int index = HashFunc(key);
//		if (hashArray[index] == 0 || hashArray[index] == 1) // 0 -> Empty , 1 -> Deleted
//		{
//			hashArray[index].SetValue(value);
//			hashArray[index].SetStatus(2);
//			hashArray[index].SetKey(key);
//			currentElements++;
//		}
//		else if (GetLoadFactor() > capacity * 0.75)
//		{
//			doubleCapacity();
//			int i = 1;
//			bool check = true;
//			int index = 0;
//			while (check == true)
//			{
//				index = getNextCandidateIndex(key, i);
//				if (index >= capacity)
//				{
//					index = index % capacity;
//				}
//
//				if (hashArray[index] == 0 || hashArray[index] == 1)  
//				{
//					check = false;
//				}
//				else
//					i++;
//			}
//			hashArray[index].SetValue(value);
//			hashArray[index].SetStatus(2);
//			hashArray[index].SetKey(key);
//			currentElements++;
//		}
//		else
//		{
//			bool check = true;
//			int i = 1;
//			int index = 0;
//			while (check == true)
//			{
//				index = getNextCandidateIndex(key, i);
//				if (index >= capacity)
//				{
//					index = index % capacity;
//				}
//
//				if (hashArray[index] == 0 || hashArray[index] == 1)
//				{
//					check = false;
//				}
//				else
//					i++;
//			}
//			hashArray[index].SetValue(value);
//			hashArray[index].SetStatus(2);
//			hashArray[index].SetKey(key);
//			currentElements++;
//		}
//	}
//	v* Get(int const key)
//	{
//		int index = HashFunc(key);
//		bool check = true;
//		int NoofChecks = 0;
//		while (check == true)
//		{
//			if (index >= capacity)
//			{
//				index = index % capacity;
//			}
//			if (hashArray[index] != 1 && hashArray[index] != 0)
//			{
//				if (hashArray[index] /= key)
//				{
//					v val = hashArray[index].GetValue();
//					v* temp = new v(val);
//					return temp;
//					check = false;
//				}
//				else if (NoofChecks == capacity)
//				{
//					cout << "Key Not Found" << endl;
//					return nullptr;
//				}
//				else
//				{
//					index++;
//					NoofChecks++;
//				}
//			}
//			if (hashArray[index] == 1||hashArray[index]==0)
//			{
//				index++;
//				NoofChecks++;
//			}
//		}
//	}
//	bool deleteKey(int const key)
//	{
//		int indextodelete = HashFunc(key);
//		bool check = false;
//		int NoofChecks = 0;
//		while (check == false)
//		{
//			if (hashArray[indextodelete] != 1 && hashArray[indextodelete] != 0)  // Checking Status
//			{
//				if (hashArray[indextodelete] /= key) // Checking if the key exists
//				{
//					check = true;
//					break;
//				}
//				else if (NoofChecks == capacity)
//				{
//					cout << "Key Not Found" << endl;
//					return false;
//				}
//				else
//				{
//					indextodelete++;
//					NoofChecks++;
//				}
//			}	
//			if (indextodelete >= capacity)
//			{
//				indextodelete = indextodelete % capacity;
//			}
//		}
//		hashArray[indextodelete].SetStatus(1);
//		return true;
//	}
//	void PrintKey(int const key)
//	{
//		int indextoPrint = HashFunc(key);
//		int NoofChecks = 0;
//		bool check = false;
//		while (check == false)
//		{
//			if (hashArray[indextoPrint] != 1 && hashArray[indextoPrint] != 0)  // Checking Status
//			{
//				if (hashArray[indextoPrint] /= key) // Checking if the key exists
//				{
//					check = true;
//					break;
//				}
//				else if (NoofChecks == capacity)
//				{
//					cout << "Key Not Found";
//					return;
//				}
//			}
//			indextoPrint++;
//			NoofChecks++;
//		}
//		cout << "Key : " << key << endl;
//		cout << "Value : "<< hashArray[indextoPrint].GetValue() << endl;
//		cout << "Status : " << hashArray[indextoPrint].GetStatus() << endl;
//	}
//	virtual ~HashMap()
//	{
//		delete[] hashArray;
//		hashArray = nullptr;
//	}
//};
//
//
//int main()
//{
//	HashMap<string>* HT = new HashMap<string>;
//	HT->Insert(2, "Hamza");
//	HT->Insert(4, "Ahmad");
//	HT->Insert(3, "Hassan");
//	HT->Insert(1, "Ubaid");
//	HT->Insert(9, "Zaid");
//	HT->Insert(6, "tawab");
//	HT->Insert(5, "Ali");
//	HT->Insert(13, "Sibtain");
//
//	cout << "Printing Key 13 " << endl;
//	HT->PrintKey(13);
//	cout << endl;
//
//	cout << "Deleting Key 13 " << endl;
//	HT->deleteKey(13);
//	cout << endl;
//
//	cout << "Printing Key 13 " << endl;
//	HT->PrintKey(13);
//	cout << endl;
//
//	cout << endl;
//	cout << "Ussing Get Function on Key -> 2" << endl;
//	string* temp = HT->Get(2);
//	cout << *temp;
//
//	return 0;
//}