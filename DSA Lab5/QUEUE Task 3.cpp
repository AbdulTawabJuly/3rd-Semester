//#include <iostream>
//using namespace std;
//
//template<class T>
//class Queue
//{
//private:
//	T* Arr;
//	int front;
//	int rear;
//	int size;
//	int maxsize;
//public:
//	Queue(int s = 10)
//	{
//		Arr = new T[s];
//		maxsize = s;
//		size = 0;
//		front = -1;
//		rear = 0;
//	}
//
//	bool IsFull()
//	{
//		return (size == maxsize);
//	}
//
//	void Enqueue(T d)
//	{
//		if (!IsFull())
//		{
//			Arr[rear % maxsize] = d;
//			rear++; 
//			size++;
//			return;
//		}
//		else
//			return;
//	}
//
//	void AlternativeManner()
//	{
//		Queue<int> List2(size);
//		int i = (size / 2) ;
//		int j = 0;
//		for (; i < rear ; i++, j++)
//		{
//			List2.Enqueue(Arr[j]);
//			List2.Enqueue(Arr[i]);
//		}
//		for (i = 0; i < rear; i++)
//		{
//			Arr[i] = List2.Arr[i];
//		}
//	}
//
//	void Print()
//	{
//		for (int i = front + 1; i < rear; i++)
//		{
//			cout << Arr[i] << " ";
//		}
//	}
//};
//
//
//int main()
//{
//	Queue<int> List;
//	List.Enqueue(4);
//	List.Enqueue(8);
//	List.Enqueue(9);
//	List.Enqueue(7);
//	List.Enqueue(6);
//	List.Enqueue(5);
//	List.Enqueue(2);
//	List.Enqueue(3);
//	cout << "Elements in the QUEUE : ";
//	List.Print();
//	cout << endl;
//	cout << "QUEUE After Alteration : ";
//	List.AlternativeManner();
//	List.Print();
//	cout << endl;
//
//
//}
//
