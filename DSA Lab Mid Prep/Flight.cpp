//#include <iostream>
//#include<string>
//using namespace std;
//
//template <class T>
//class List {
//private:
//	class Node {
//	public:
//		T data;
//		Node* next;
//	};
//
//public:
//	Node* head;
//	Node* tail;
//	List() {
//		head = tail = NULL;
//	}
//	void InsertAtStart(T info) {
//		Node* temp = new Node;
//		temp->data = info;
//		temp->next = head;
//		if (head == NULL) {
//			head = tail = temp;
//		}
//		if (head != NULL) {
//			head = temp;
//		}
//	}
//	void InsertAtEnd(T info) {
//		if (head == NULL) {
//			InsertAtStart(info);
//		}
//		else {
//			Node* temp = new Node;
//			temp->data = info;
//			temp->next = NULL;
//			tail->next = temp;
//			tail = temp;
//		}
//	}
//	void Print() {
//		if (head == NULL) {
//			return;
//		}
//		else {
//
//			Node* Current = head;
//			while (Current != nullptr)
//			{
//				if (Current->next != nullptr)
//				{
//					cout << Current->data << " -> ";
//					Current = Current->next;
//				}
//				else
//				{
//					cout << Current->data << " ";
//					Current = Current->next;
//				}
//			}
//			cout << endl;
//		}
//	}
//
//	void DeleteAtStart()
//	{
//		if (head != nullptr)
//		{
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//		}
//		else
//			tail = nullptr;
//	}
//	void DeleteAtEnd()
//	{
//		if (head == nullptr)
//		{
//			return;
//		}
//		if (head == tail)
//		{
//			delete head;
//			head = tail = nullptr;
//		}
//		else
//		{
//			Node* temp = head;
//			while (temp->next != tail)
//			{
//				temp = temp->next;
//			}
//			delete tail;
//			tail = temp;
//			tail->next = nullptr;
//		}
//	}
//
//	void DeleteReservation(T name)
//	{
//		Node* temp = head;
//		Node* todelete;
//		if (temp->data == name)
//		{
//			DeleteAtStart();
//			return;
//		}
//		else if (tail->data == name)
//		{
//			DeleteAtEnd();
//			return;
//		}
//		temp = head;
//		while (temp->next->data != name && temp != nullptr)
//		{
//
//			temp = temp->next;
//		}
//		todelete = temp->next;
//		temp->next = todelete->next;
//		delete todelete; 
//	}
//
//	void CheckReservation(T name)
//	{
//		Node* temp = head;
//		while (temp != nullptr)
//		{
//			if (temp->data == name)
//			{
//				cout << name << " has a ticket reserved on the Flight" << endl;
//				return;
//			}
//			temp = temp->next;
//		}
//		cout << name << " has NO ticket reserved on the Flight"<<endl;
//		return;
//	}
//	void DeleteAlternate()
//	{
//		Node* temp = head->next;
//		int i = 0;
//		while (temp != nullptr)
//		{
//			Node*todelete
//			temp = temp->next->next;
//		}
//	}
//	List ShiftPassengers()
//	{
//		List<string> F;
//		Node* temppp = head;
//		Node* prev=temppp;
//		int i = 0;
//		while (temppp!= nullptr)
//		{
//			if (i % 2 != 0)
//			{
//				F.InsertAtEnd(temppp->data);
//				Node*todelete = temppp;
//				prev->next = todelete->next;
//				delete todelete;
//			}
//			prev = temppp;
//			temppp = temppp->next;
//			i++;
//		}
//		return F;
//	}
//};
//
//int main() {
//
//	List<string> Flight1;
//	cout << "Members of the Flight : ";
//	Flight1.InsertAtEnd("Amna");
//	Flight1.InsertAtEnd("Aniya");
//	Flight1.InsertAtEnd("Fatima");
//	Flight1.InsertAtEnd("Nida");
//	Flight1.InsertAtEnd("Zainab");
//	Flight1.InsertAtEnd("Doha");
//	Flight1.Print();
//	cout << "Cancelling Reservation :";
//	/*Flight1.DeleteReservation("Nida");
//	Flight1.DeleteReservation("Doha");*/
//	Flight1.Print();
//	cout << "Checking Reservation" << endl;
//	Flight1.CheckReservation("Zainab");
//	Flight1.CheckReservation("Nida");
//	Flight1.CheckReservation("Abu");
//	Flight1.Print();
//	cout << "Shifting Passengers "<<endl<<endl<<endl;
//	List<string> Flight2;
//	Flight2=Flight1.ShiftPassengers();
//	Flight1.Print();
//	Flight2.Print();
//}