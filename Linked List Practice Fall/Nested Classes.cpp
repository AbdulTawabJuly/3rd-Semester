//
//#include<iostream>
//using namespace std;
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
//	};
//	Node* head;
//	Node* tail;
//public:
//	List()
//	{
//		head = tail = nullptr;
//	}
//
//	void InsertatStart(T d)
//	{
//		Node* temp=new Node;
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
//	}
//
//	void InsertatEnd(T d)
//	{
//		if (head == NULL)
//		{
//			InsertatStart(d);
//		}
//
//		Node* temp = new Node;
//		temp->data = d;
//		temp->next = nullptr;
//		tail->next = temp;
//		tail = temp;
//	}
//
//	void Print()
//	{
//		Node* temp = head;
//		while (temp != NULL)
//		{
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//	}
//
//	void Search(T element)
//	{
//		Node* temp = head;
//		int i = 0;
//		while (temp != NULL)
//		{
//			
//			if (temp->data == element)
//			{
//				cout << "Element Found on " << i << " index" << endl;
//				return;
//			}
//			temp = temp->next;
//			i++;
//		}
//		cout << "Element Not Found" << endl;
//	}
//
//	void Reverse()
//	{
//		Node* temphead = head;
//		Node* temptail = tail;
//		while(temphead != temptail)
//		{
//			if (temphead->next == temptail)
//			{
//				cout << temptail->data<<" ";
//				temptail = temphead;
//				temphead = head;
//			}
//			
//			else
//			temphead = temphead->next;
//
//			if (temphead == temptail)
//			{
//				cout << temphead->data << " ";
//				break;
//			}
//		}
//	}
//
//
//};
//
//int main()
//{
//	List <int>L1;
//	L1.InsertatStart(4);
//	L1.InsertatStart(7);
//	L1.InsertatStart(9);
//	L1.InsertatEnd(2);
//	L1.InsertatStart(3);
//	L1.InsertatStart(7);
//	L1.InsertatStart(1);
//	
//	L1.Print();
//
//	cout << endl;
//	L1.Search(2);
//	L1.Search(9);
//	L1.Search(7);
//
//	L1.Reverse();
//
//	
//}