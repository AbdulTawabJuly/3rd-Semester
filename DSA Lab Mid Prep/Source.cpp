//#include<iostream>
//using namespace std;
//
//template<class T>
//class Queue
//{
//private:
//	class Node
//	{
//	public:
//		T data;
//		Node* next;
//	};
//	int maxsize;
//	int size;
//	Node* front;
//	Node* rear;;
//public:
//
//	Queue(int s = 10)
//	{
//		maxsize = s;
//		size = 0;
//		front = nullptr;
//		rear = nullptr;
//	}
//
//	bool IsFull()
//	{
//		if (size == maxsize)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool IsEmpty()
//	{
//		if (size == 0)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	void Print()
//	{
//		Node* temp = front;
//		while (temp != nullptr)
//		{
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//	}
//
//	bool Enqueue(T d)
//	{
//		if (!IsFull())
//		{
//			Node* temp = new Node;
//			temp->data = d;
//			temp->next = front;
//			if (front == nullptr)
//			{
//				front = rear = temp;
//				size++;
//			}
//			else
//			{
//				front = temp;
//				size++;
//			}
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool Dequeue()
//	{
//		if (!IsEmpty())
//		{
//			Node* temp = front;
//			if (front == rear)
//			{
//				delete front;
//				front = rear = nullptr;
//				size--;
//			}
//			else
//			{
//				front = front->next;
//				delete temp;
//				size--;
//			}
//
//			return true;
//		}
//		else
//		{
//			rear = nullptr;
//			return false;
//		}
//	}
//
//	int GetSize()
//	{
//		return size;
//	}
//
//	int GetFront()
//	{
//		return front->data;
//	}
//
//	int GetRear()
//	{
//		return rear->data;;
//	}
//};
//
//int main()
//{
//	Queue <int>List;
//	//Entering Elements in the QUEUE
//	List.Enqueue(1);
//	List.Enqueue(2);
//	List.Enqueue(3);
//	List.Enqueue(4);
//	List.Enqueue(5);
//	List.Enqueue(6);
//	List.Enqueue(7);
//	List.Enqueue(8);
//	List.Enqueue(9);
//	List.Enqueue(10);
//	cout << "Printing QUEUE : ";
//	List.Print();
//	cout << endl;
//	cout << "Checking If Queue is Full or not : ";
//	cout << List.IsFull();
//	cout << endl;
//	cout << "Checking If Queue is Empty or not : ";
//	cout << List.IsEmpty();
//	cout << endl;
//	cout << "Elements on the Rear of the Queue : ";
//	cout << List.GetRear();
//	cout << endl;
//	cout << "Elements on the Front of the Queue : ";
//	cout << List.GetFront();
//	cout << endl;
//	cout << "Size of Array : ";
//	cout << List.GetSize();
//	cout << endl;
//	List.Dequeue();
//	List.Dequeue();
//	cout << "List After Dequeue Operation : ";
//	List.Print();
//	cout << endl;
//	cout << "Size of Array After : ";
//	cout << List.GetSize();
//	cout << endl << endl;
//}