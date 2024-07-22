//#include<iostream>
//using namespace std;
//
//template<class T>
//class List
//{
//private:
//	class Node
//	{
//	public:
//		T data;
//		Node* next;
//
//		Node()
//		{
//			next = nullptr;
//		}
//	};
//
//	Node* head;
//	Node* tail;
//	int size;
//
//public:
//
//	class Iterators
//	{
//		friend class List<T>
//	private:
//		Node* curr1;
//		Node* curr;
//
//	public:
//		Iterators()
//		{
//			curr = nullptr;
//		}
//		Iterators(Node* c)
//		{
//			curr = c;
//		}
//
//		bool Not_Null()
//		{
//			if (curr != nullptr)
//				return true;
//			else
//				return false;
//		}
//
//		bool Null()
//		{
//			if (curr == nullptr)
//				return true;
//			else
//				return false;
//		}
//
//		bool Not_Next_Null()
//		{
//			if (curr->next != nullptr)
//				return true;
//			else
//				return false;
//		}
//
//		Node* Next()
//		{
//			return curr->next;
//		}
//	};
//
//	List()
//	{
//		head = tail = nullptr;
//		size = 0;
//	}
//
//	Node* First()
//	{
//		return head;
//	}
//
//	void InsertAtStart(T element)
//	{
//		Iterator temp;
//		temp.curr = First();
//		if (temp.Null())
//		{
//			Node* temp = new Node;
//			temp->data = element;
//			temp->next = head;
//			head = tail = temp;
//		}
//		else
//		{
//			Node* temp2 = new Node;
//			temp2->data = element;
//			temp2->next = head;
//			head = temp2;
//		}
//	}
//
//	void InsertAtEnd(T element)
//	{
//		Iterators temp;
//		temp.curr = First();
//		if (temp.Null())
//		{
//			InsertAtStart(element);
//			size++;
//		}
//		else
//		{
//			Node* temp = new Node;
//			temp->data = element;
//			temp->next = nullptr;
//			tail->next = temp;
//			tail = temp;
//			size++;
//		}
//	}
//
//	/*void InsertSorted(T element)
//	{
//		Iterators temp;
//		temp.curr = First();
//		if (temp.Null())
//		{
//			InsertAtStart(element);
//			size++;
//		}
//		else if (head == tail || head->data > element || tail->data < element)
//		{
//			if (head->data > element)
//			{
//				InsertAtStart(element);
//				size++;
//			}
//			else
//			{
//				InsertAtEnd(element);
//				size++;
//			}
//		}
//		else
//		{
//			Node* current = new Node;
//			current->data = element;
//
//			Node* temp = head;
//			while (temp != nullptr)
//			{
//				if (temp->data < current->data && temp->next->data > curr->data)
//				{
//					current->next = temp->next;
//					temp->next = current;
//					break;
//				}
//				temp = temp->next;
//			}
//			size++;
//		}
//	}*/
//};
//int main()
//{
//	
//
//}
