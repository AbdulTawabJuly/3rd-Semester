//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Node
//{
//private:
//	friend class List;  //List class is friend of Node class to access its attributes
//
//	string name;
//	int ID;
//	string role;
//	double salary;
//	Node* next;
//
//public:
//
//	Node()   //default constructor
//	{
//		next = nullptr;
//	}
//
//	Node(int _ID, string _name, string _role, double _salary)    //overloaded constructor
//	{
//		name = _name;
//
//		ID = _ID;
//
//		role = _role;
//
//		salary = _salary;
//
//		next = nullptr;
//	}
//};
//
//
//class List
//{
//	Node* head;    //List class has head pointer as the starting point of the linked list
//
//public:
//
//	List()   //default constructor
//	{
//		head = nullptr;
//	}
//
//	void InsertStaff(Node* newlyHired)
//	{
//		if (head == nullptr)       //if list is empty
//		{
//			head = newlyHired;                                 //insertion if list is empty
//		}
//
//		else if (newlyHired->ID < head->ID)                    //insertion before the head
//		{
//			newlyHired->next = head;
//			head = newlyHired;
//		}
//
//
//		else if (head->next == nullptr)                        //insertion after the head if size of linked list is 1
//		{
//			head->next = newlyHired;
//		}
//
//		else
//		{
//			Node* temp = head;
//			Node* temporary = head->next;
//
//			while (temporary != nullptr)
//			{
//				if (newlyHired->ID < temporary->ID && newlyHired->ID > temp->ID)     //insertion in the middle
//				{
//					temp->next = newlyHired;
//					newlyHired->next = temporary;
//					return;
//				}
//
//				temp = temp->next;
//				temporary = temporary->next;
//			}
//
//			temporary = newlyHired;      //insertion at the end
//			temp->next = temporary;
//		}
//	}
//
//	void DeleteStaff(int ID)  //given the ID, the respective employee is deleted and removed from the linked list
//	{
//		if (head == nullptr)
//		{
//			cout << "Empty list." << endl;
//			return;
//		}
//
//		else if (head->ID == ID && head->next == nullptr)          //deleting the head node if ID matches and size of linked list is 1
//		{
//			delete head;
//			head = nullptr;
//			return;
//		}
//
//		else if (head->ID == ID && head->next != nullptr)          //deleting the head node by storing it in temp and moving the head pointer to next node
//		{
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//			return;
//		}
//
//		else
//		{
//			Node* prev = nullptr;
//			Node* currNode = head;
//
//			while (currNode != nullptr)
//			{
//				if (currNode->ID == ID && currNode->next == nullptr)                  //deletion at the end
//				{
//					delete currNode;
//					prev->next = nullptr;
//					return;
//				}
//
//				else if (currNode->ID == ID && currNode->next != nullptr)             //deletion in the middle
//				{
//					Node* temp = currNode;
//					currNode = currNode->next;
//					prev->next = currNode;
//					delete temp;
//					return;
//				}
//
//				prev = currNode;
//				currNode = currNode->next;
//			}
//		}
//	}
//
//	void UpdateRole(int ID, string updatedRole)  //updates the role of a given employee by the provided string e.g "Manager"
//	{
//		if (head == nullptr)
//		{
//			cout << "Empty list." << endl;
//			return;
//		}
//
//		else
//		{
//			Node* temp = head;
//
//			while (temp != nullptr)
//			{
//				if (temp->ID == ID)
//				{
//					temp->role = updatedRole;
//				}
//
//				temp = temp->next;
//			}
//		}
//	}
//
//	void IncremenetSalaryOfEmployee(int ID, double incrementPercentage)  //increments salary of an employee by a given percentage
//	{
//		if (head == nullptr)
//		{
//			cout << "Empty list." << endl;
//			return;
//		}
//
//		Node* temp = head;
//
//		while (temp != nullptr)
//		{
//			if (temp->ID == ID)
//			{
//				temp->salary = temp->salary + temp->salary * incrementPercentage / 100;         //incrementing salary with the given percentage
//			}
//			temp = temp->next;
//		}
//	}
//
//	void UpdateSalaryOfAllEmployees(double incrementPercentage)  //to update salary of every employee with a given percentage
//	{
//		if (head == nullptr)
//		{
//			cout << "Empty list." << endl;
//			return;
//		}
//
//		Node* temp = head;
//
//		while (temp != nullptr)
//		{
//			temp->salary = temp->salary + (temp->salary * incrementPercentage / 100);
//			temp = temp->next;
//		}
//	}
//
//	void DisplayRecordsOfSpecificStaff(string _role)  //to display employees type wise e.g "Manager" - will list all the Managers and theirs details
//	{
//		if (head == nullptr)
//		{
//			cout << "Empty list." << endl;
//			return;
//		}
//
//		Node* temp = head;
//
//		while (temp != nullptr)
//		{
//			if (temp->role == _role)  //if roles match, display the employee details
//			{
//				cout << "ID: " << temp->ID << endl;
//				cout << "Name: " << temp->name << endl;
//				cout << "Role: " << temp->role << endl;
//				cout << "Salary: " << temp->salary << endl << endl;
//			}
//
//			temp = temp->next;
//		}
//	}
//
//	void DisplayAllEmployees()  //to display details of the employess
//	{
//		if (head == nullptr)
//		{
//			cout << "Empty list." << endl;
//			return;
//		}
//
//		Node* temp = head;
//
//		while (temp != nullptr)
//		{
//			cout << "ID: " << temp->ID << endl;
//			cout << "Name: " << temp->name << endl;
//			cout << "Role: " << temp->role << endl;
//			cout << "Salary: " << temp->salary << endl << endl;
//
//			temp = temp->next;
//		}
//	}
//};
//
//void Decision(int i)
//{
//	cout << endl;
//
//	cout << "Enter any number to continue using the application " << endl;
//
//	cin >> i;
//}
//
//void main()
//{
//	int i;
//
//	int ID;
//	string name;
//	string role;
//	double salary;
//
//	List list;
//
//	while (true)
//	{
//		system("CLS");
//		cout << "							Welcome to Employee Management System " << endl;
//		cout << "							By: Hamza Ahmad(L20-1323) " << endl;
//		cout << "							Input strings(name, role) as one-word " << endl;
//		cout << endl << endl;
//		cout << "Enter 1 if you want to create and insert an Employee Node" << endl;
//		cout << "Enter 2 if you want to delete an Employee Node" << endl;
//		cout << "Enter 3 if you want to upgrade salaries of all employess" << endl;
//		cout << "Enter 4 if you want to upgrade salary of a specific employee" << endl;
//		cout << "Enter 5 if you want to upgrade role of an employee" << endl;
//		cout << "Enter 6 if you want to display specific employee by type" << endl;
//		cout << "Enter 7 if you want to display all employees" << endl;
//		cout << endl << "Enter -1 if you want to terminate the application " << endl;
//		cout << endl << endl;
//
//		cin >> i;
//
//		if (i == -1)
//		{
//			system("CLS");
//			cout << "Program Terminated " << endl << endl;
//			break;
//		}
//
//		else if (i == 1)
//		{
//			system("CLS");
//			cout << "Enter ID: ";
//			cin >> ID;
//			cout << endl;
//			cout << "Enter Name: ";
//			cin >> name;
//			cout << endl;
//			cout << "Enter Role: ";
//			cin >> role;
//			cout << endl;
//			cout << "Enter Salary: ";
//			cin >> salary;
//			cout << endl;
//
//			Node* temp = new Node(ID, name, role, salary);
//
//			list.InsertStaff(temp);
//
//			Decision(i);
//		}
//
//		else if (i == 2)
//		{
//			system("CLS");
//			int temp_ID;
//			cout << "Enter ID of employee that you want to delete " << endl;
//			cin >> temp_ID;
//
//			list.DeleteStaff(temp_ID);
//
//			Decision(i);
//		}
//		else if (i == 3)
//		{
//			system("CLS");
//			int increment_perc;
//			cout << "Enter the increment percentage you want to upgrade salaries of everyone with " << endl;
//			cin >> increment_perc;
//
//			list.UpdateSalaryOfAllEmployees(increment_perc);
//
//			Decision(i);
//		}
//		else if (i == 4)
//		{
//			system("CLS");
//			int temp_ID;
//			int increment_perc;
//			cout << "Enter the employee ID " << endl;
//			cin >> temp_ID;
//			cout << "Enter the increment percentage of their salary " << endl;
//			cin >> increment_perc;
//
//			list.IncremenetSalaryOfEmployee(temp_ID, increment_perc);
//
//			Decision(i);
//		}
//		else if (i == 5)
//		{
//			system("CLS");
//			int temp_ID;
//			string updated_role;
//			cout << "Enter the employee ID " << endl << endl;
//			cin >> temp_ID;
//			cout << "Enter their updated role " << endl;
//			cin >> updated_role;
//
//			list.UpdateRole(temp_ID, updated_role);
//
//			Decision(i);
//		}
//		else if (i == 6)
//		{
//			system("CLS");
//			string _role;
//			cout << "Enter the specific role of the respective employees you want to be displayed " << endl;
//			cin >> _role;
//
//			list.DisplayRecordsOfSpecificStaff(_role);
//
//			Decision(i);
//		}
//		else if (i == 7)
//		{
//			system("CLS");
//			list.DisplayAllEmployees();
//
//			Decision(i);
//		}
//	}
//
//	system("pause");
//}