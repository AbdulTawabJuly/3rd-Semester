//#include <iostream>
//
//using namespace std;
//
//template<class T>
//
//class List
//{
//
//private:
//
//	class Node
//	{
//	public:
//		T data;
//		Node* next;
//	};
//
//public:
//
//	Node* head;
//	Node* tail;
//
//	List()
//	{
//		head = tail = nullptr;
//	}
//
//	void InsertatStart(T d)
//	{
//		Node* temp = new Node;
//		temp->data = d;
//		temp->next = head;
//		if (!head)
//		{
//			head = tail = temp;
//		}
//		else
//		{
//			head = temp;
//		}
//
//	}
//
//	void InsertatEnd(T d)
//	{
//		if (head == nullptr)
//		{
//			InsertatStart(d);
//		}
//		else
//		{
//
//			Node* temp = new Node;
//			temp->data = d;
//			temp->next = nullptr;
//			tail->next = temp;
//			tail = temp;
//
//		}
//	}
//
//	void InsertSorted(T const element)
//	{
//		if (head == nullptr)
//		{
//			InsertatStart(element);
//		}
//		else if(head == tail||head->data>element||tail->data<element)
//		{
//			if (head->data > element)
//			{
//				InsertatStart(element);
//			}
//			else
//			{
//				InsertatEnd(element);
//			}
//		}
//		else
//		{
//			Node* curr = new Node;
//			curr->data = element;
//
//			Node* temp = head;
//			while (temp != nullptr)
//			{
//				if (temp->data<=curr->data && temp->next->data>=curr->data)
//				{
//					curr->next = temp->next;
//					temp->next = curr;
//					break;
//				}
//				temp = temp->next;
//			}
//		}
//	}
//
//	void DeleteatStart()
//	{
//		if (head != nullptr)
//		{
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//		}
//		else
//			tail = nullptr;
//	}
//
//	void DeleteatEnd()
//	{
//		if (head == nullptr)
//		{
//			return;
//		}
//		if (head == tail)
//		{
//			delete head;
//			head = tail = nullptr;
//		}
//		else
//		{
//			Node* t = head;
//			while (t->next != tail)
//			{
//				t = t->next;
//			}
//			delete tail;
//			tail = t;
//			tail->next = nullptr;
//		}
//	}
//
//	void deleteDuplicate()
//	{
//		Node* temp = head;
//		if (head != tail)
//		{
//			while (temp != tail)
//			{
//				if (temp->data == temp->next->data)
//				{
//					Node* temp2 = temp->next;
//					temp->next = temp2->next;
//					delete temp2;
//				}
//				temp = temp->next;
//			}
//		}
//	}
//
//	void Print()
//	{
//		if (head == nullptr)
//		{
//			cout << "Linked List is Empty" << endl;
//		}
//		else
//		{
//			Node* temp;
//			temp = head;
//			while (temp != nullptr)
//			{
//				cout << temp->data << " ";
//				temp = temp->next;
//			}
//		}
//	}
//
//	void PrintNth(int index)
//	{
//		Node* temp = head;
//		int i = 0;
//		while (temp != NULL)
//		{
//			if (i == index)
//			{
//				cout << temp->data << " " << endl;
//			}
//			temp = temp -> next;
//			i++;
//		}
//		
//
//	}
//
//	bool Search(T d)
//	{
//		Node* temp;
//		temp = head;
//		while (temp != NULL)
//		{
//			if (temp->data == d)
//			{
//				cout << "Element Found " << endl;
//				return true;
//			}
//			temp = temp->next;
//		}
//		cout << "Element Not Found" << endl;
//		return false;
//	}
//
//	~List()
//	{
//		while (head)
//		{
//			DeleteatStart();
//		}
//	}
//	
//};
//
//
//
//int main()
//{
//
//
//	List <int> L1;
//
//	L1.InsertSorted(5);
//	L1.InsertSorted(3);
//	L1.InsertSorted(4);
//	L1.InsertSorted(1);
//	L1.InsertSorted(6);
//	L1.InsertSorted(4);
//	L1.Print();
//	L1.DeleteatEnd();
//	cout << endl;
//	L1.Print();
//	cout << endl;
//	L1.PrintNth(2);
//	L1.DeleteatStart();
//	L1.Print();
//	cout << endl;
//	L1.deleteDuplicate();
//	L1.Print();
//	cout << endl;
//	//system("pause");
//	return 0;
//}