#include<iostream>
using namespace std;


template<class T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
public:
	List()
	{
		head = tail = nullptr;

	}

	void InsertAtEnd(T d)
	{
		if (head == nullptr)
		{
			Node* temp = new Node;
			temp->data = d;
			head = tail = temp;
			head->next = tail;
			tail->next = head;
		}
		else
		{
			Node* temp = new Node;
			temp->data = d;
			tail->next = temp;
			temp->next = head;
			tail = temp;
		}
	}
	
	void Print()
	{
		Node* curr = new Node;
		curr = head;
		while (curr != tail)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << tail->data;
	}

	bool Check()
	{
		Node* temp = head;
		while (temp !=tail)
		{
			if (temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u' || temp->data == 'A' || temp->data == 'E' || temp->data == 'I' || temp->data == 'O' || temp->data == 'U')
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	bool Check_Y()
	{
		Node* temp = head;
		while (true)
		{
			if (temp->data=='y' || temp->data=='Y')
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	
	void Latin()
	{
		if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u' || head->data == 'A' || head->data == 'E' || head->data == 'I' || head->data == 'O' || head->data == 'U')
		{
			InsertAtEnd('-');
			InsertAtEnd('w');
			InsertAtEnd('a');
			InsertAtEnd('y');
		}

		else 
		{
			if (Check())
			{
				InsertAtEnd('-');
				while (true)
				{
					Rotate();
					if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u' || head->data == 'A' || head->data == 'E' || head->data == 'I' || head->data == 'O' || head->data == 'U')
					{
						break;
					}
				}
				InsertAtEnd('a');
				InsertAtEnd('y');
			}

			else
			{
				if (Check_Y())
				{
					InsertAtEnd('-');
					while (true)
					{
						Rotate();
						if (head->data == 'Y' || head->data == 'y')
						{
							break;
						}
					}
					InsertAtEnd('a');
					InsertAtEnd('y');
				}
				else
				{
					InsertAtEnd('-');
					InsertAtEnd('w');
					InsertAtEnd('a');
					InsertAtEnd('y');

				}
			}
		}
	}

	void Rotate()
	{
		tail->next = head;
		tail = head;
		head = head->next;
	}
};
int main()
{
	char Rotate[100];
	cout << "Enter Word/String which you want in Latin Form : ";
	cin.getline(Rotate,100);
	List<char>L1;
	int length = strlen(Rotate);
	for (int i = 0; i < length; i++)
	{
		L1.InsertAtEnd(Rotate[i]);
	}
	cout << "String Before Changing it into Latin : ";
	L1.Print();
	cout << endl;
	cout << "String After Changing it into Latin : ";
	L1.Latin();
	L1.Print();
} 