//#include<iostream>
//using namespace std;
//
//struct Node
//{
//	int val;
//	Node* next;
//
//	Node(int data)
//	{
//		val = data;
//		next = NULL;
//	}
//};
//
//void Push(int val, Node*& top)
//{
//	Node* temp = new Node (val); // Insert top element
//	temp->next = top;
//	top=temp;
//
//}
//
//void Pop(Node*& top)
//{
//	if (top == NULL)
//	{
//		cout << "Stack Overflow" << endl;
//	}
//	else
//	{
//		Node* temp = top; // Pop/Delete the top element
//		top = top->next;
//		delete temp;
//	}
//}
//
//int Peek(Node*& top)
//{
//	Node* temp = top; // Only return  the value of top element
//	return temp->val;
//}
//
//void Display(Node* top)
//{
//	Node* temp = top;
//	if (temp == NULL)
//	{
//		cout << "Stact is Empty" << endl;
//	}
//
//	while (temp != NULL)
//	{
//		cout << temp->val << endl;
//		temp = temp->next;
//	}
//}
//
//int Size(Node* top)
//{
//	Node* temp = top;
//	int count = 0;
//	while (temp->next != NULL)
//	{
//		count++;
//		temp = temp->next;
//	}
//
//	return count+1;
//
//}
//
//int IsEmpty(Node* top)
//{
//	if (top == NULL)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//
//void Push2(int data,Node*& top)
//{
//	Node* temp = top;
//
//	temp->next = top;
//	temp->val = data;
//
//}
//
//void DeleteMiddle(Node*& top)
//{
//	Node* temp = top;
//	int size = Size(top);
//	if (size % 2 == 1)
//	{
//		int index = size / 2;
//		index = index-1;
//		int i = 0;
//		while (i < index)
//		{
//			temp = temp->next;
//			i++;
//		}
//		Node* todelete = temp->next;
//		temp->next = temp->next->next;
//		delete todelete;
//
//	}
//	else if (size % 2 == 0)
//	{
//		int index = size / 2;
//		index = index + 1;
//		int i = 0;
//		while (i < index)
//		{
//			temp = temp->next;
//			i++;
//		}
//		Node* todelete = temp->next;
//		temp->next = temp->next->next;
//		delete todelete;
//	}
//}
//int main()
//{
//
// // 2nd Page Question -->
//
//	class Node* top=NULL;
//	Push(1, top);
//	Push(2, top);
//	Push(3, top);
//	Push(4, top);
//	//Push(5, top);
//
//	DeleteMiddle(top);
//
//	Display(top);
//	cout << endl;
//
//	Pop(top);
//
//	Display(top);
//	cout << endl;
//
//	cout<<Peek(top);
//	cout << endl;
//
//	Display(top);
//	cout << endl;
//
//	//-->
//
//	//3rd Page Question-->
//
//	cout << Size(top);
//	cout << endl;
//
//	cout << IsEmpty(top);
//	cout << endl;
//
//
//}