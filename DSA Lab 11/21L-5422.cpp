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
		if (d < 0)
			return;

		int i = size;
		if (i >= capacity)
		{
			T* Arr = new T[capacity * 2];
			for (int i = 0; i < size; i++)
			{
				Arr[i] = arr[i];
			}

			capacity = capacity * 2;
			delete[] arr;
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

	MaxHeap(const MaxHeap& rhs)  // Copy Constructor
	{
		//size = rhs.size;
		/*for (int i = 0; i < rhs.size; i++)
		{
			arr[i] = rhs.arr[i];
		}*/
		size = 0;
		InputWithArray(rhs.arr, rhs.size);
	}

	bool CheckMaxHeap(int Arr[], int size, int i)
	{
		return true;
	}
	T ReturnMax()
	{
		return arr[1];
	}
	void Heapify(int i)
	{
		int largest = i;

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
		for (int i = 1; i < k-1; i++)
			ExtractMax();

		return ExtractMax();
	}
	bool CheckMaxHeap(T* arr, int s)
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
	void BuildMaxHeap(T* arr, int s)
	{
		for (int i = s / 2; i >= 1; i--)
		{
			Heapify(i);
		}
	}
	void MergeHeaps(T* arr1, T* arr2)
	{
		InputWithArray(arr1, 11);
		InputWithArray(arr2, 11);
		BuildMaxHeap(arr, 20);
	}
	int GetCapacity()
	{
		return capacity;
	}
	T* GetArr()
	{
		return arr;
	}

	void HeapSort()
	{
		int size1 = size;
		for (int i = 0; i < size1; i++)
		{
			T temp = ExtractMax();
			arr[size + 1] = temp;

		}
		size = size1;
	}

	~MaxHeap()
 	{
		cout << "Destructor called" << endl;
		if (arr != nullptr)
		{
			delete[] arr;
		}
		
		//free arr[];
	}
};


int main()
{
	
	int Arr1[10] = { 14,19,42,33,26,31,27,44,35,10 };
	int size1 = sizeof(Arr1) / sizeof(Arr1[0]);

	MaxHeap<int>Heap1(size1);
	Heap1.InputWithArray(Arr1, 10);


	//int Arr2[10] = { 17,29,61,9,55,49,38,77,91,39 };
	//int size2 = sizeof(Arr2) / sizeof(Arr2[0]);
	//MaxHeap<int> Heap2(10);
	//Heap2.InputWithArray(Arr2, 10);

	//cout << "Heap 1 : ";
	//Heap1.Print();
	//cout << endl;

	//cout << "Heap 2 : ";
	//Heap2.Print();
	//cout << endl;

	//cout << "Checking if Heap1 is Max Heap or Not: ";
	//Heap1.CheckMaxHeap();
	//cout << endl;

	//cout << "Merging Heap 1 and Heap 2:  " ;
	//int size = Heap1.GetCapacity() + Heap2.GetCapacity();
	//MaxHeap<int> Heap3(size);
	//Heap3.MergeHeaps(Heap1.GetArr(), Heap2.GetArr());
	//Heap3.Print();
	//cout << endl;

	/*cout << "Heap 1 Afer Heap Sort in Increasing Order " << endl;
	Heap1.HeapSort();
	Heap1.Print();
	cout << endl;
	cout << endl;*/

	//cout << "Getting Max of Heap 2 : ";
	//cout << Heap2.ExtractMax();
	//cout << endl;

	//cout << "Getting Kth Max of Heap 2 : " << endl;
	//cout << "K = 2" << endl;;
	//cout<<Heap2.ReturnkthMax(2);// You can Change k
	cout << endl;
}
