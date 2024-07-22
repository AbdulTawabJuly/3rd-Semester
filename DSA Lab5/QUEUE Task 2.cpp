#include<iostream>
using namespace std;

template<class T>
class Queue
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
	};
	int maxsize;
	int size;
	Node* front;
	Node* rear;;
public:

	Queue(int s = 10)
	{
		maxsize = s;
		size = 0;
		front = nullptr;
		rear = nullptr;
	}

	bool IsFull()
	{
		if (size == maxsize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Print()
	{
		Node* temp = front;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	bool Enqueue(T d)
	{
		if (!IsFull())
		{
			Node* temp = new Node;
			temp->data = d;
			temp->next = front;
			if (front == nullptr)
			{
				front = rear = temp;
				size++;
			}
			else
			{
				front = temp;
				size++;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Dequeue(T& d)
	{
		if (!IsEmpty())
		{
			Node* temp = front;
			if (front == rear)
			{
				d = front->data;
				delete front;
				front = rear = nullptr;
				size--;
			}
			else
			{
				d = front->data;
				front = front->next;
				delete temp;
				size--;
			}

			return true;
		}
		else
		{
			rear = nullptr;
			return false;
		}
	}

	bool AlternativeElements(int k)
	{
		if (front)
		{
			Node* temp = front;
			for (int i = 1; i < size; i++)
			{
				if (i % 4 == 3 || i % 4 == 0)
				{
					temp = temp->next;
					break;
				}
				else if (temp->data != (temp->next->data) - 1)
				{
					return false;
				}
				temp = temp->next;
			}
			return true;
		}
		else
		{
			cout << "QUEUE is Empty" << endl;
		}
		
	}

	int GetSize()
	{
		return size;
	}

	int GetFront()
	{
		return front->data;
	}

	int GetRear()
	{
		return rear->data;;
	}
};

int main()
{
	Queue<int>List;
	List.Enqueue(13);
	List.Enqueue(12);
	List.Enqueue(11);
	List.Enqueue(7);
	List.Enqueue(5);
	List.Enqueue(3);
	List.Enqueue(2);
	List.Enqueue(1);
	cout << "QUEUE : ";
	List.Print();
	cout << endl;
	cout << "Checking if QUEUE is Alternative or not : ";
	cout << List.AlternativeElements(3);
	cout << endl << endl;

}