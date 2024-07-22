//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next;
//
//	Node(int val)
//	{
//		data = val;
//		next = NULL;
//	}
//};
//
//void InsertatStart(int val, Node*& head)
//{
//	Node* n = new Node(val);
//	n->next = head;
//	head = n;
//}
//
//void InsertatEnd(int val, Node*& head)
//{
//	Node* n = new Node(val);
//
//	if (head == NULL)
//	{
//		head = n;
//		return;
//	}
//
//	Node* temp = head;
//	while (temp->next != NULL)
//	{
//		temp = temp->next;
//	}
//	temp->next = n;
//}
//
//bool Search(int key, Node* Head)
//{
//	Node* temp = Head;
//	while (temp != NULL)
//	{
//		if (temp->data == key)
//		{
//			return true;
//		}
//		temp = temp->next;
//	}
//	return false;
//}
//
//void Display(Node* Head)
//{
//
//	Node* temp = Head;
//	while (temp != NULL)
//	{
//		cout << temp->data << " -> ";
//		temp = temp->next;
//	}
//	cout << "NULL" << endl;
//}
//
//void Deletion(int val, Node*& head)
//{
//	Node* temp = head;
//	while (temp->next->data != val)
//	{
//		temp = temp->next;
//	}
//	Node* todelete = temp->next;
//	temp->next = temp->next->next;
//
//	delete todelete;
//}
//
//void DeleteatStart(Node*& head)
//{
//	Node* temp = head;
//	head = head->next;
//	delete temp;
//}
//
//int main()
//{
//	Node* Head = NULL;
//	InsertatEnd(1, Head);
//	InsertatEnd(2, Head);
//	InsertatEnd(3, Head);
//	InsertatEnd(4, Head);
//	InsertatEnd(5, Head);
//
//	Display(Head);
//
//	Deletion(5, Head);
//
//	Display(Head);
//
//	cout << Search(5, Head);
//}