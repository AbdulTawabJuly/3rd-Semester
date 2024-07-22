//#include<iostream>
//using namespace std;
//class Node
//{
//public:
//	int data;
//	Node* next;
//	Node(int val)
//	{
//		data = val;
//		next = NULL;
//	}
//};
//
//void InsertatStart(int val,Node*&head)
//{
//	Node* n = new Node(val);
//	n->next = head;
//	head = n;
//}
//
//void InsertatEnd(int val, Node*& head)
//{
//	Node* n = new Node(val);
//	if (head == NULL)
//	{
//		head = n;
//		return;
//	}
//
//	Node* temp =head;
//	while (temp->next != NULL)
//	{
//		temp = temp->next;
//	}
//	temp->next= n;
//}
//
//void Display(Node* head)
//{
//	Node* temp = head;
//	while (temp != NULL)
//	{
//		cout << temp->data << " -> ";
//		temp = temp->next;
//	}
//	cout << "NULL"<<endl;
//	
//}
//
//bool Search(int val, Node* head)
//{
//	Node* temp = head;
//	while (temp != NULL)
//	{
//		if (temp->data == val)
//		{
//			return true;
//		}
//		temp = temp->next;
//	}
//	return false;
//}
//
//bool IsEmpty(Node* head)
//{
//	Node* temp = head;
//	if (temp == NULL)
//	{
//		return true;
//	}
//	return false;
//}
//
//void DeleteALL(int val, Node*& head)
//{
//	Node* temp = head;
//	while (temp->next != NULL)
//	{
//		while (temp->next->data != val)
//		{
//			temp = temp->next;
//		}
//
//		Node* todelete = temp->next;
//		temp->next = temp->next->next;
//		delete todelete;
//	}
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
//	Node* head=NULL;
//
//	InsertatStart(1, head);
//
//	Display(head);
//
//	InsertatEnd(5, head);
//
//	Display(head);
//	InsertatEnd(7, head);
//	InsertatEnd(7, head);
//	Display(head);
//	DeleteALL(7, head);
//	Display(head);
//
//	DeleteatStart(head);
//	Display(head);
//
//	/*cout << Search(5, head) << endl;;
//	cout << IsEmpty(head);*/
//}