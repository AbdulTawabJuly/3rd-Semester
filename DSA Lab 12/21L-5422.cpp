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
//	/*HashItem()
//	{
//		key = 0;
//		status = 0;
//	}*/
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
//			hashArray[i].SetValue(0);
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
//
//		delete[] hashArray;
//
//		hashArray = new HashItem<v>[capacity * 2];
//		for (int i = 0; i < capacity * 2; i++)
//		{
//			hashArray[i].SetValue(0);
//
//		}
//
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
//	void Insert(int const key, v  value)
//	{
//		int index = HashFunc(key);
//
//		if (hashArray[index] == 0 || hashArray[index] == 1)
//		{
//			hashArray[index].SetValue(value);
//			hashArray[index].SetStatus(2);
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
//				if (hashArray[index] == 0)
//				{
//					check = false;
//				}
//				else
//					i++;
//			}
//			hashArray[index].SetValue(value);
//			currentElements++;
//		}
//		else
//		{
//			bool check = true;
//			int i = 1;
//			int index = 0;
//			while (check == true)
//			{
//				index = getNextCandidateIndex(value, i);
//				if (hashArray[index] == 0 || hashArray[index] == 1)
//				{
//					check = false;
//				}
//				else
//					i++;
//			}
//			hashArray[index].SetValue(value);
//			currentElements++;
//		}
//	}
//	v* Get(v const key) const
//	{
//		int index = HashFunc(key);
//
//	}
//	bool deleteKey(v const key) const
//	{
//
//	}
//	~HashMap()
//	{
//
//	}
//};
//
//
//int main()
//{
//	HashMap<int> HT;
//
//	HT.Insert(2, 1089);
//	HT.Insert(4, 10);
//	HT.Insert(3, 89);
//	HT.Insert(2, 1229);
//
//	HT.Insert(1, 1);
//	HT.Insert(9, 99);
//	HT.Insert(7, 101);
//	HT.Insert(6, 69);
//
//	HT.Insert(6, 301);
//
//	
//
//	return 0;
//}