//#include<iostream>
//using namespace std;
//template<class T>
//class DList
//{
//private:
//
//	class DNode
//	{
//	public:
//		T data;
//		DNode* next;
//		DNode* prev;
//	}; 
//	DNode* head;
//	DNode* tail;
//public:
//	DList()
//	{
//		head = new DNode;
//		tail = new DNode;
//		head->next = tail;
//		head->prev = nullptr;
//		tail->next = nullptr;
//		tail->prev = head;
//	}
//
//	void InsertatStart(T d)
//	{
//		DNode* temp = new DNode;
//		temp->data = d;
//		temp->prev = head;
//		temp->next = head -> next;
//		head->next->prev = temp;
//		head->next = temp;
//	}
//
//	void InsertatEnd(T d)
//	{
//		DNode* temp=new DNode;
//		temp->data = d;
//		temp->next = tail;
//		temp->prev = tail -> prev;
//		tail->prev->next = temp;
//		tail->prev = temp;
//	}
//
//	void Print()
//	{
//			if (head == nullptr)
//			{
//				cout << "Linked List is Empty" << endl;
//			}
//			else
//			{
//				DNode* temp;
//				temp = head->next;
//				while (temp != tail)
//				{
//					cout << temp->data << " ";
//					temp = temp->next;
//				}
//			}
//	}
//
//	void PrintRev()
//	{
//		DNode* temp=tail->prev;
//		while (temp != head)
//		{
//			cout <<temp->data <<" ";
//			temp = temp->prev;
//
//		}
//	}
//
//	void DeleteatStart()
//	{
//		DNode* temp = head->next;
//		head->next->prev = head;
//		head->next = temp -> next;
//		delete temp;
//
//	}
//
//	void DeleteatEnd()
//	{
//		DNode* temp = tail->prev;
//		temp->prev->next = tail;
//		tail->prev = temp->prev;
//		delete temp;
//	}
//	void Swap(int n)
//	{
//		DNode* swapheadtemp=head->next;
//		DNode* swaptailtemp=tail->prev;
//		for (int i = 0; i < n; i++)
//		{
//			swapheadtemp = swapheadtemp->next;
//			swaptailtemp = swaptailtemp->prev;
//			
//		}
//		int newtemp = swapheadtemp->data;
//		swapheadtemp->data = swaptailtemp->data;
//		swaptailtemp->data = newtemp;
//
//    }
//
//	~DList()
//	{
//		while (head->next != tail)
//		{
//			DeleteatStart();
//		}
//	}
//};
//int main()
//{
//	DList<int> DL1;
//	DL1.InsertatStart(1);
//	DL1.InsertatStart(2);
//	DL1.InsertatStart(3);
//	DL1.InsertatStart(4);
//	DL1.InsertatStart(9);
//	DL1.Print();
//	cout << endl;
//	DL1.InsertatEnd(7);
//	DL1.InsertatEnd(6);
//	DL1.InsertatEnd(0);
//	DL1.Print();
//	cout << endl;
//	DL1.PrintRev();
//	cout << endl;
//	DL1.DeleteatStart();
//	DL1.Print();
//	cout << endl;
//	DL1.DeleteatEnd();
//	DL1.Print();
//	cout << endl;
//	DL1.Swap(2);
//	DL1.Print();
//	cout << endl;
//}