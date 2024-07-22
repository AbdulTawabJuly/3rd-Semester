#include<iostream>
using namespace std;

template<class T>
class MaxHeap
{
private:
	T* arr;
	int capacity;
	int size;
public:
	MaxHeap()
	{
		arr = nullptr;
		capacity = 0;
		size = 0;
	}
	MaxHeap(int c)
	{
		arr = new T[c];
		capacity = c;
		size = 0;
	}
	void Swap(T& d, T& d2)
	{
		T temp = d;
		d = d2;
		d2 = temp;
	}
	bool IsFull()
	{
		if (size == capacity)
			return true;
		else
			return false;
	}
	void Insert(T d)
	{
		int i = size;
		if (i >= capacity)
		{
			T* Arr = new T[capacity * 2];
			for (int i = 1; i < size; i++)
			{
				Arr[i] = arr[i];
			}

			capacity = capacity * 2;
			delete []arr;
			arr = Arr;

		}
		else if (!IsFull())
		{
			arr[++size] = d;
			// size++;
			i = size;
			while (i > 1)
			{
				if (arr[i] > arr[i / 2])
				{
					Swap(arr[i], arr[i / 2]);
				}
				else
				{
					break;
				}
				i = i / 2;
			}
		}
	}
	void InputWithArray(int InputArr[], int _size)
	{
		for (int i = 0; i < _size; i++)
		{
			Insert(InputArr[i]);
		}
	}
	void Print()
	{
		int i = 1;
		while (i <= size)
		{
			cout << arr[i] << " ";
			i++;
		}
	}
	bool CheckMaxHeap(int Arr[],int size,int i)
	{
		return true;
	}
	T ReturnMax()
	{
		return arr[1];
	}
	void Heapify(int i)
	{
		int largest = 1;

			if (2 * i <= size && arr[2 * i] > arr[largest])
				largest = 2 * i;

			if (2 * i + 1 <= size && arr[2 * i + 1] > arr[largest])
				largest = 2 * i + 1;

			if (i != largest)
			{
				Swap(arr[i], arr[largest]);
				Heapify(largest);
			}
		

	}
	T ExtractMax()
	{
		int i = 1;
		T max = arr[i];
		arr[1] = arr[size];
		size--;
		Heapify(1);
		return max;
	}

	T ReturnkthMax(int k)
	{
		for (int i = 1; i < k; i++)
			ExtractMax();

		return ExtractMax();
	}
	bool CheckMaxHeap(T* arr ,int s)
	{
		if (s > size)
			return true;
		if (2 * s <= size && arr[2 * s] > arr[s])
			return false;
		if (2 * s + 1 <= size && arr[2 * s + 1] > arr[s])
			return false;

		CheckMaxHeap(arr, 2 * s);
		CheckMaxHeap(arr, 2 * s + 1);
	}
	bool CheckMaxHeap()
	{
		return CheckMaxHeap(arr, 1);
	}
};
int main()
{
	MaxHeap<int>obj(10);
	int arr[10] = { 14,19,42,33,26,31,27,44,35,10};
	obj.InputWithArray(arr, 10);
	//obj.CheckMaxHeap(arr,10,1);
	obj.Print();
	cout << endl;
	cout << obj.ReturnMax();

	cout << obj.ReturnkthMax(2);
}
