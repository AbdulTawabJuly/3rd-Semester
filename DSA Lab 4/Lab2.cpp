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
//	void ReversePrint()
//	{
//		Node* tail1 = tail;
//		Node* head1 = head;
//		while (head1 != tail1)
//		{
//			if (head1->next == tail1)
//			{
//				cout << tail1->data << " ";
//				tail1 = head1;
//				head1 = head;
//			}
//			else
//			{
//				head1 = head1->next;
//			}
//			if (head1 == tail1)
//			{
//				cout << head1->data << " ";
//				break;
//			}
//		}
//	}
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
//	L1.InsertatStart(4);
//	L1.InsertatStart(7);
//	L1.InsertatStart(9);
//	L1.InsertatEnd(2);
//	L1.InsertatStart(3);
//	L1.InsertatStart(7);
//	L1.InsertatStart(1);
//	L1.Print();
//	cout << endl;
//	cout << "Searching 2" << endl;
//	L1.Search(2);
//	cout << "Searching 9" << endl;
//	L1.Search(9);
//	cout << "Searching 7" << endl;
//	L1.Search(7);
//	cout << "Printing Linked List in Reverse Order" << endl;
//	L1.ReversePrint();
//	cout << endl;
//	system("pause");
//	return 0;
//}