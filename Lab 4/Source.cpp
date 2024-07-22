//#include<iostream>
//using namespace std;
//
//
//
//template <class T>
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
//	}
//	void InsertString(char list)
//	{
//		if (head == nullptr)
//		{
//			Node* temp = new Node;
//			temp->data = list;
//			head = tail = temp;
//			head->next = tail;
//			tail->next = head;
//		}
//		else
//		{
//			Node* temp = new Node;
//			temp->data = list;
//			tail->next = temp;
//			temp->next = head;
//			tail = temp;				// works as insert at start	
//		}
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
//	void Rotate(char* list)
//	{
//		bool flag = false;
//		bool flag2 = false;
//		int i = 0;
//		while (i < strlen(list))
//		{
//			if (list[i] == 'a' || list[i] == 'e' || list[i] == 'i' || list[i] == 'o' || list[i] == 'u' || list[i] == 'y' || list[i] == 'A' || list[i] == 'E' || list[i] == 'I' || list[i] == 'O' || list[i] == 'U' || list[i] == 'Y')
//			{
//				flag2 = true;
//				break;
//			}
//			i++;
//		}
//		if (list[0] == 'a' || list[0] == 'e' || list[0] == 'i' || list[0] == 'o' || list[0] == 'u' || list[0] == 'y' || list[0] == 'A' || list[0] == 'E' || list[0] == 'I' || list[0] == 'O' || list[0] == 'U' || list[0] == 'Y')
//		{
//			flag = true;
//		}
//		if (flag)
//		{
//			i = 0;
//			char word[4] = { '-','w','a','y' };
//			while (i < 4)
//			{
//				Node* temp = new Node;
//				temp->data = word[i];
//				tail->next = temp;
//				temp->next = head;
//				tail = temp;
//				i++;
//			}
//		}
//		else if (flag2)
//		{
//			Node* temp = new Node;			// Inserting '-' at the end
//			temp->data = '-';
//			tail->next = temp;
//			temp->next = head;
//			tail = temp;
//			while (i < strlen(list))
//			{
//				if (list[i] == 'a' || list[i] == 'e' || list[i] == 'i' || list[i] == 'o' || list[i] == 'u' || list[i] == 'y' || list[i] == 'A' || list[i] == 'E' || list[i] == 'I' || list[i] == 'O' || list[i] == 'U' || list[i] == 'Y')
//				{
//					break;
//				}
//				i++;
//			}
//			int count = 0;
//			while (count < i)			// adding alphabets before the vowel
//			{
//				Node* temp = new Node;
//				Node* temp2 = head;
//				temp->data = list[count];
//				tail->next = temp;
//				temp->next = head;
//				tail = temp;
//				head = temp2->next;
//				delete temp2;
//				count++;
//			}
//			char word[2] = { 'a','y' };
//			i = 0;
//			while (i < 2)
//			{
//				Node* temp = new Node;
//				temp->data = word[i];
//				tail->next = temp;
//				temp->next = head;
//				tail = temp;
//				i++;
//			}
//		}
//		else			// if all other conditions fail, that is there are no vowels
//		{
//			i = 0;
//			char word[4] = { '-','w','a','y' };
//			while (i < 4)
//			{
//				Node* temp = new Node;
//				temp->data = word[i];
//				tail->next = temp;
//				temp->next = head;
//				tail = temp;
//				i++;
//			}
//		}
//	}
//};
//
//int main()
//{
//	char* arr = new char[5];
//	cout << "Enter word: ";
//	cin >> arr;
//	List <char> l1;
//	int i = 0;
//	while (arr[i] != 0)
//	{
//		l1.InsertString(arr[i]);
//		i++;
//	}
//	l1.Print();				// printing list of nodes as it is
//	cout << endl << endl;
//	l1.Rotate(arr);
//	l1.Print();				// printing list of nodes after rotation
//}