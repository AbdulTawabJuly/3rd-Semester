#include<iostream>
using namespace std;
template<class T>
class Queue
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node()
		{
			next = nullptr;
		}
	};
	int maxsize;
	int size;
	Node* front;
	Node* rear;;
public:

	Queue(int s = 10)
	{
		maxsize = s;
		size = 0;
		front = nullptr;
		rear = nullptr;
	}

	bool IsFull()
	{
		if (size == maxsize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Print(Node*temp)
	{
		if(temp->next!=nullptr)
		Print(temp->next);
		cout << temp->data;
	}
	void Printing()
	{
		Node* temp = front;
		if (temp == nullptr)
			return;
		else
		{
			Print(temp);
		}
	}

	bool Enqueue(T d)
	{
		if (!IsFull())
		{
			Node* temp = new Node;
			temp->data = d;
			temp->next = front;
			if (front == nullptr)
			{
				front = rear = temp;
				size++;
			}
			else
			{
				front = temp;
				size++;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Dequeue()
	{
		if (!IsEmpty())
		{
			Node* temp = front;
			if (front == rear)
			{
				delete front;
				front = rear = nullptr;
				size--;
			}
			else
			{
				front = front->next;
				delete temp;
				size--;
			}

			return true;
		}
		else
		{
			rear = nullptr;
			return false;
		}
	}
	void Exe()
	{
		Node* temp = front;
		while (temp != nullptr)
		{
			temp->data--;
			temp->next;
		}
	}
};

class Process
{
private:
	string Processname;
	int No;
public:
	Process()
	{
		Processname.clear();
		No = 0;
	}
	Process(string _name, int _No)
	{
		Processname = _name;
		No = _No;
	}
	friend ostream& operator<<(ostream& out, Process& obj)
	{
		cout << obj.Processname << " -> ";
		cout <<" No of Instructions :  "<< obj.No;
		cout << endl;
		return out;
	}
	Process& operator--(int data)
	{
		if (this->No <= 3)
		{
			No = 0;
			cout << Processname << " has been executed"<<endl;
		}
		else
		{
			No = No - 3;
			cout << "3 Instructions Executed of " << Processname << endl;
		}
		return *this;
	}
	int GetNo()
	{
		return No;
	}
	void SetNo(int no)
	{
		No = no;
	}
};
class MainClass
{
private:
	int Total;
	Queue<Process>Processes;
public:
	MainClass(int _no)
	{
		Total = _no;
	}
	void AddProcess(string ProcessName, int NoofInst)
	{
		if (Total == 0)
		{
			cout << "Total No of Process Reached ";
			return;
		}
		Total--;
		Process temp(ProcessName, NoofInst);
		Processes.Enqueue(temp);
	}
	void Print()
	{ 
		Processes.Printing();
	}
	void Execute()
	{
		Processes.Exe();
	}
};
int main()
{
	int No_of_Processes = 0;
	cout << endl << "Enter Total No of Processes : ";
	cin >> No_of_Processes;
	cout << endl;
	MainClass obj(No_of_Processes);
	string temp;
	int tempInst;
	for (int i = 0; i < No_of_Processes; i++)
	{
		cout << "Enter name of Process " << i+1 << " : ";
		cin >> temp;
		cout << "Enter No of Instructions : ";
		cin >> tempInst;
		obj.AddProcess(temp, tempInst);
	}
	cout << endl << endl;
	cout << "Printing Queue : " << endl;
	obj.Print();
	cout << endl << "Executing the Processes One by One" << endl;
	obj.Execute();

}