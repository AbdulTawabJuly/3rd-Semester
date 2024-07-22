//#include<iostream>
//using namespace std;
//
//template<class t>
//class DList
//{
//private:
//	class Node
//	{
//	public:
//		t data;
//		Node* next;
//		Node* prev;
//	};
//	Node* head;
//	Node* tail;
//public:
//	DList()
//	{
//		head = new Node;
//		tail = new Node;
//		head->next = tail;
//		head->prev = nullptr;
//		tail->next = nullptr;
//		tail->prev = head;
//	}
//
//	void InsertStart(t element)
//	{
//		Node* temp = new Node;
//		temp->data = element;
//		temp->prev = head;
//		temp->next = head->next;
//		head->next->prev = temp; 
//		head->next = temp;
//	}
//
//	void InsertatEnd(t element)
//	{
//		Node* temp = new Node;
//		temp->data = element;
//		temp->next = tail;
//		temp->prev = tail->prev;
//		tail->prev->next = temp;
//		tail->prev = temp;
//	}
//
//	void Print()
//	{
//		Node* temp = head->next;
//		while (temp->next != nullptr)
//		{
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//	}
//
//	void PrintReverse()
//	{
//		Node* temp = tail->prev;
//		while (temp->prev != nullptr)
//		{
//			cout << temp->data << " ";
//			temp = temp->prev;
//		}
//	}
//
//	void Swap(int n)
//	{
//		Node* temphead = head;
//		Node* temptail = tail;
//		for (int i = 0; i < n; i++)
//		{
//			temphead = temphead->next;
//			temptail = temptail->prev;
//		}
//		int temp = temphead->data;
//		temphead->data = temptail->data;
//		temptail->data = temp;
//	}
//
//};
//int main()
//{
//	DList<int>DL1;
//	DL1.InsertStart(3);
//	DL1.InsertStart(2);
//	DL1.InsertStart(1);
//	DL1.InsertatEnd(4);
//	DL1.InsertatEnd(5);
//	DL1.InsertatEnd(6);
//	DL1.Print();
//	cout << endl;
//	DL1.PrintReverse();
//	cout << endl;
//	DL1.Swap(2);
//	DL1.Print();
//}
