#include<iostream>
using namespace std;
template<class t>
class List
{
private:
	class Node
	{
	public:
		t data;
		Node* next;
	};
	Node* head;
	Node* tail;
public:

	List()
	{
		head = tail = nullptr;
	}

	void InsertatStart(t element)

	{
		Node* temp = new Node;
		temp->data = element;
		temp->next = head;
		if (head == nullptr)
			head = tail = temp;
		else
			head = temp;
	}

	void InsertatEnd(t const element)
	{
		if (head == nullptr)
		{
			InsertatStart(element);
		}

		Node* temp = new Node;
		temp->data = element;
		temp->next = nullptr;
		tail->next = temp;
		tail = temp;
	}

	void Print()
	{
		Node* temp = head;
		while (temp!= nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

	}

	void InsertSorted(t const element)
	{
		if (head == nullptr)
		{
			InsertatStart(element);
			
		}

		else if (head == tail || head->data > element || tail->data < element)
		{
			if (head->data > element)
			{
				InsertatStart(element);
			}
			else
			{
				InsertatEnd(element);
			}
		}
		
		else
		{
			Node* temp = head;
			Node* New = new Node;
			New->data = element;
			while (temp != nullptr)
			{
				if (temp->data<=New->data&&temp->next->data>New->data)
				{
					New->next = temp->next;
					temp->next = New;
					break;
				}
					temp = temp->next;
			}
		}
	}

	void PrintNth(int index)
	{
		int i = 0;
		Node* temp = head;
		while (temp != nullptr)
		{
			if (i == index-1)
			{
				cout << temp->data << " ";
				break;
			}
			i++;
			temp = temp->next;
		}
	}

	void Deleteatstart()
	{
		if (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else
			tail = nullptr;
	}

	void DeleteatEnd()
	{
		if (head == nullptr)
		{
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node* temp = head;
			while (temp->next != tail)
			{
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail->next = nullptr;
		}
	}

	void DeleteDuplicate()
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			if (temp->data == temp->next->data)
			{
				Node* todelete = temp->next;
				temp->next = temp->next->next;
				delete todelete;
			}
			temp = temp->next;
		}
	}

	List Union(List l2)
	{
		List <int>L3;
		Node* temp = head;
	
		while (temp != nullptr)
		{
			L3.InsertSorted(temp->data);
			temp = temp->next;
		}
		
		Node* temp2 = l2.head;
		while (temp2!= nullptr)
		{
			L3.InsertSorted(temp2->data);
			temp2 = temp2->next;
		}
		return L3;
	}
};
int main()
{
	List <int> L1;
	cout << "Linked List No 1 : ";
	L1.InsertSorted(5);
	L1.InsertSorted(1);
	L1.InsertSorted(3);
	L1.InsertSorted(2);
	L1.InsertSorted(4);
	L1.Print();
	cout << endl;
	List<int> L2;
	cout << "Linked List No 2 : ";
	L2.InsertSorted(7);
	L2.InsertSorted(6);
	L2.InsertSorted(8);
	L2.InsertSorted(10);
	L2.InsertSorted(9);
	L2.Print();
	cout << endl;
	cout << "Union : ";
	List<int>L3;
	L3 = L1.Union(L2);
	L3.Print();
}