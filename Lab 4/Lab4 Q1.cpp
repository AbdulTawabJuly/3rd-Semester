//#include<iostream>
//using namespace std;
//
//template< class T>
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
//
//	class Iterator
//	{
//		friend class List<T>;
//	private:
//		Node* curr;
//	public:
//
//		Iterator()
//		{
//			curr = nullptr;
//		}
//
//		Iterator(Node* c)
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
//
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
//	}
//
//	Node* First()
//	{
//		return head;
//	}
//
//	void InsertatStart(T element)
//	{
//		Iterator temp;
//		temp.curr = First();
//		if (temp.Not_Null())
//		{
//			Node* temp=new Node;
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
//	void Print()
//	{
//		Iterator temp;
//		temp.curr = First();
//		while (temp.Not_Null())
//		{
//			cout << (temp.curr)->data << " ";
//			temp.curr = temp.Next();
//		}
//	}
//
//	void PrintNth(int n)
//	{
//		Iterator temp;
//		temp.curr = First();
//		int count = 1;
//		while (temp.Not_Null())
//		{
//			if (count == n)
//			{
//				cout << (temp.curr)->data << " ";
//			}
//
//			count++;
//			temp.curr = temp.Next();
//		}
//	}
//
//	bool Search(T const& element)
//	{
//		Iterator temp;
//		temp.curr = First();
//		int index = 1;
//		while (temp.Not_Null())
//		{
//			if (temp.curr->data == element)
//			{
//				cout << "Element Found on " << index << " th index";
//				return true;
//
//			}
//
//			index++;
//			temp.curr = temp.Next();
//		}
//		cout << "Element Not Found" << endl;
//		return false;
//	}
//
//	void DeleteatStart()
//	{
//		if (head != nullptr)
//		{
//			Iterator temp;
//			temp.curr = First();
//			head = head->next;
//			delete temp.curr;
//		}
//		else
//			tail = nullptr;
//	}
//
//	int Sum()
//	{
//
//		Iterator temp;
//		temp.curr = First();
//		int sum = 0;
//		while (temp.Not_Null())
//		{
//			sum+= (temp.curr)->data ;
//			temp.curr = temp.Next();
//		}
//
//		return sum;
//	}
//
//	~List()
//	{
//		while (head)
//		{
//			DeleteatStart();
//		}
//		
//	}
//};
//
//int main()
//{
//	List <int>L1;
//	L1.InsertatStart(99); 
//	L1.InsertatStart(88); 
//	L1.InsertatStart(77); 
//	L1.InsertatStart(66); 
//	L1.InsertatStart(55); 
//	L1.InsertatStart(44);
//	L1.InsertatStart(33); 
//	L1.InsertatStart(22); 
//	L1.InsertatStart(11); 
//	L1.InsertatStart(1); 
//	
//	L1.Print();
//
//	cout << endl;
//
//	cout << "Printing Specific Node" << endl;
//	L1.PrintNth(5);
//
//	cout << endl;
//
//	cout << "Searching Element" << endl;
//	L1.Search(88);
//
//	cout << endl;
//
//	cout << "Delete at Start" << endl;
//	L1.DeleteatStart();
//	L1.Print();
//
//	cout << endl;
//
//	cout << "Again Deleting at Start" << endl;
//	L1.DeleteatStart();
//	L1.Print();
//
//	cout << endl;
//
//	cout << "Printing Sum of the Linked List" << endl;
//	cout<<L1.Sum();
//}
