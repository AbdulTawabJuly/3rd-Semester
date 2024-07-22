//#include <iostream>
//
//using namespace std;
//
//template<class T>
//class Heap
//{
//private:
//	T* arr;
//	int capacity;
//	int size;
//public:
//	Heap()
//	{
//		arr = new T[16];
//		capacity = 16;
//		size = 1;
//	}
//	void insert(T val)
//	{
//		int i = size;
//		if (i >= capacity)
//		{
//			T* newArr = new T[capacity * 2];
//			for (int i = 0; i < size; i++)
//			{
//				newArr[i] = arr[i];
//			}
//			capacity *= 2;
//			delete[] arr;
//			arr = newArr;
//		}
//		arr[i] = val;
//		size++;
//		while (i > 1)
//		{
//			if (arr[i] > arr[i / 2])
//			{
//				T c = arr[i];
//				arr[i] = arr[i / 2];
//				arr[i / 2] = c;
//			}
//			else
//				break;
//			i /= 2;
//		}
//	}
//	T extractMax()
//	{
//		if (size - 1 == 0)
//			throw std::logic_error("Empty heap!");
//		T c = arr[1];
//		arr[1] = arr[size - 1];
//		size--;
//		Heapify(1);
//		return c;
//	}
//	void Heapify(int i)
//	{
//		while (i < size)
//		{
//			if (2 * i < size && arr[i] < arr[2 * i]) //left child
//			{
//				T c = arr[i];
//				arr[i] = arr[2 * i];
//				arr[2 * i] = c;
//				i *= 2;
//			}
//			else if (2 * i + 1 < size && arr[i] < arr[2 * i + 1])
//			{
//				T c = arr[i];
//				arr[i] = arr[2 * i + 1];
//				arr[2 * i + 1] = c;
//				i = i * 2 + 1;
//			}
//			else
//				break;
//		}
//	}
//	void Print()
//	{
//		for (int i = 1; i < size; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//	void DeleteKey(int idx)
//	{
//		if (idx < 1 || idx >= size)
//		{
//			throw std::logic_error("Fuck off");
//		}
//		arr[idx] = arr[1] + 1;
//		while (idx > 1)
//		{
//			if (arr[idx] > arr[idx / 2])
//			{
//				T c = arr[idx];
//				arr[idx] = arr[idx / 2];
//				arr[idx / 2] = c;
//			}
//			else
//				break;
//			idx /= 2;
//		}
//		extractMax();
//	}
//	~Heap()
//	{
//		delete[] arr;
//	}
//};
//int main()
//{
//	Heap<int> h;
//	h.insert(10);
//	h.insert(20);
//	h.insert(230);
//	h.insert(240);
//	h.insert(69);
//	h.insert(50);
//	h.insert(30);
//	h.Print();
//	cout << h.extractMax() << endl;
//	h.Print();
//
//	h.DeleteKey(4);
//	h.Print();
//	system("pause");
//	return 0;
//}