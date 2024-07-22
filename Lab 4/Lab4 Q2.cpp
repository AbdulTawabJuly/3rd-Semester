//#include<iostream>
//using namespace std;
//
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
//	};
//	Node* head;
//	Node* tail;
//public:
//	List()
//	{
//		head = tail = nullptr;
//
//	}
//	void InsertAtStart(T d)
//	{
//		if (head == nullptr)
//		{
//			Node* temp = new Node;
//			temp->data = d;
//			head = tail = temp;
//			head->next = tail;
//			tail->next = head;
//		}
//		else
//		{
//			Node* temp = new Node;
//			temp->data = d;
//			tail->next = temp;
//			temp->next = head;
//			head = temp;
//		}
//	}
//	void InsertAtEnd(T d)
//	{
//		if (head == nullptr)
//		{
//			Node* temp = new Node;
//			temp->data = d;
//			head = tail = temp;
//			head->next = tail;
//			tail->next = head;
//		}
//		else
//		{
//			Node* temp = new Node;
//			temp->data = d;
//			tail->next = temp;
//			temp->next = head;
//			tail = temp;
//		}
//	}
//	void InsertSpecific(T d, int index)
//	{
//		int currIndex = 0;
//		Node* curr = new Node;
//		curr = head;
//		Node* temp = new Node;
//		temp->data = d;
//		while (currIndex < index - 1)
//		{
//			curr = curr->next;
//			++currIndex;
//		}
//		temp->next = curr->next;
//		curr->next = temp;
//	}
//	void Print()
//	{
//		Node* curr = new Node;
//		curr = head;
//		while (curr != tail)
//		{
//			cout << curr->data << " ";
//			curr = curr->next;
//		}
//		cout << tail->data;
//	}
//	int Length()
//	{
//		int length = 0;
//		Node* curr = head;
//		while (curr != tail)
//		{
//			length++;
//			curr = curr->next;
//		}
//		length++;		// As tail was not counted above
//		return length;
//	}
//
//	void Copy(List l)
//	{
//		Node* curr = head;
//		while (curr != tail)
//		{
//			l.InsertAtEnd(curr->data);
//			curr = curr->next;
//		}
//		l.InsertAtEnd(curr->data);
//		l.Print();
//	}
//
//	void Search(T d)
//	{
//		Node* curr = new Node;
//		curr = head;
//		int index = 0;
//		while (curr->next != tail)
//		{
//			if (curr->data == d)
//			{
//				cout << "Found at index:" << index;
//				return;
//			}
//			curr = curr->next;
//			index++;
//		}
//		cout << "Not found!";
//		return;
//	}
//	void DeleteAtStart()
//	{
//		if (head->next == tail)
//		{
//			delete head;
//			tail->next = tail;
//		}
//		else
//		{
//			tail->next = head->next;
//			delete head;
//		}
//	}
//	void DeleteAtEnd()
//	{
//		if (head->next == tail)
//		{
//			delete tail;
//			head->next = head;
//		}
//		else
//		{
//			Node* curr = head;
//			while (curr->next != tail)
//			{
//				curr = curr->next;
//			}
//			curr->next = head;
//			tail = curr;
//		}
//	}
//	void DeleteSpecific(T d)
//	{
//		Node* curr = head;
//		Node* temp;
//		while (curr->next->data != d)
//			curr = curr->next;
//		temp = curr->next;
//		curr->next = curr->next->next;
//		delete temp;
//	}
//};
//
//
//int main()
//{
//	List <int> List1;
//	List1.InsertAtStart(5);
//	List1.InsertAtStart(1);
//	List1.InsertAtStart(3);
//	List1.InsertAtStart(8);
//	List1.InsertAtStart(2);
//	List1.Print();
//	cout << endl;
//	cout << "Length: " << List1.Length() << endl;
//	List1.InsertAtEnd(4);
//	List1.InsertAtEnd(4);
//	List1.InsertAtEnd(1);
//	List1.InsertAtEnd(87);
//	List1.Print();
//	List1.InsertSpecific(0, 2);
//	List1.InsertSpecific(69, 1);
//	cout << endl;
//	List1.Print();
//	cout << endl;
//	List1.Search(8);
//	List1.DeleteAtStart();
//	List1.DeleteAtStart();
//	List1.Print();
//}