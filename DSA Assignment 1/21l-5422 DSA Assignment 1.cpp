#include<iostream>
#include<Windows.h>
using namespace std;
class Block;
template<class t>
class List
{
private:
	class Node
	{
	public:
		t data;
		Node* next;
		Node()
		{
			next = nullptr;
		}
	};
	Node* head;
	Node* tail;
	int size;
public:
	List()
	{
		head = tail = nullptr;
		size = 0;
	}
	void InsertAtStart(t obj)
	{
		Node* temp = new Node;
		temp->data = obj;
		temp->next = head;
		if (!head)
			head = tail = temp;
		else
			head = temp;
	}
	void InsertatEnd(t d)
	{
		if (head == nullptr)
		{
			InsertAtStart(d);
			size++;
		}
		else
		{
			Node* temp = new Node;
			temp->data = d;
			temp->next = nullptr;
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	void InsertSorted(t element)
	{
		if (head == nullptr)
		{
			InsertAtStart(element);
			size++;
		}
		else if (head == tail || head->data > element || tail->data < element)
		{
			if (head->data > element)
			{
				InsertAtStart(element);
				size++;
			}
			else
			{
				InsertatEnd(element);
				size++;
			}
		}
		else
		{
			Node* curr = new Node;
			curr->data = element;

			Node* temp = head;
			while (temp != nullptr)
			{
				if (temp->data < curr->data && temp->next->data > curr->data)
				{
					curr->next = temp->next;
					temp->next = curr;
					break;
				}
				temp = temp->next;
			}
			size++;
		}
	}
	void DeleteAtStart()
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
	void DeleteAtEnd()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head == tail)
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
	void DeleteSpecific(int PID)   // This function deletes a specific node according to Node ID
	{
		Node* temp = head;
		Node* todelete;
		int length = 0;
		if (temp->data == PID)
		{
			DeleteAtStart();
			return;
		}
		else if (tail->data == PID)
		{
			DeleteAtEnd();
			return;
		}
		temp = head;
		Node* temp2 = head;
		while (temp->next->data != PID && temp != nullptr)
		{

			temp = temp->next;
		}
		todelete = temp->next;
		temp->next = todelete->next;
		delete todelete;
	}
	void Print()
	{
		if (head == nullptr)
		{
			cout << "Memory is Empty" << endl;
		}
		else
		{
			Node* temp;
			temp = head;
			while (temp != nullptr)
			{
				cout << temp->data;
				temp = temp->next;
			}
		}
		cout << endl;
	}
	bool EmptyCheck()  // Checks if LL is empty or not
	{ 
		if (head == nullptr)
		{
			return true;
		}
		else
			return false;
	}
	bool FirstFit(int Req_Mem)  // This is an extra function only checks , doesnot returns
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data >= Req_Mem)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
		cout << "Block of Memory was not Found" << endl << endl;
	}
	t* FirstFitReturn(int Req_Mem)  // This Function Returns a suitable node according to First Fit
	{
		Node* temp = head;
		t* best = 0;
		while (temp != nullptr)
		{
			if (temp->data >= Req_Mem)
			{
				return &(temp->data);
			}
			temp = temp->next;
		}
		cout << "Block of Memory was not Found" << endl << endl;
	}
	t* BestFit(int Req_Mem)  // Checking Memory according to Best Fit
	{
		t* best = 0;
		bool flag = false;
		int diff = 100000000;
		Node* temp = head;
		while (temp != NULL)
		{
			if ((temp->data).Get_Total_Bytes() >= Req_Mem)
			{
				if (diff > (temp->data).Get_Total_Bytes() - Req_Mem)
				{
					diff = (temp->data).Get_Total_Bytes() - Req_Mem;
					best = &(temp->data);
				}
			}
			temp = temp->next;
		}
		return best;
	}
	bool Searching(t obj)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == obj)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	t* Get_Pool_Starting_Address()
	{
		Node* temp = head;
		return &(temp->data);
	}
	t* Get_Current_Address()
	{
		Node* temp = tail;
		return&(temp->data);
	}
	t* Get_Pool_Total_Memory()
	{
		Node* temp = tail;
		return&(temp->data);
	}
	List& operator=(t rhs)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == rhs)
			{
				temp->data = rhs;
			}
			temp = temp->next;
		}
		return *this;
	}
	List& operator!=(t rhs)
	{
		Node* temp = head;
		if (temp != rhs)
			return true;
		else
			return false;

	}
	t* Get_Program(int id)
	{
		Node* curr = head;
		while (curr != 0)
		{
			if ((curr->data).Get_Program_ID() == id)
			{
				return &(curr->data);
			}
			curr = curr->next;
		}
	}
	bool Search_Program_By_ID(int id)
	{
		Node* curr = head;
		while (curr != 0)
		{
			if ((curr->data).Get_Program_ID() == id)
			{
				return true;
			}
			curr = curr->next;
		}
		return false;
	}
	void Merging()
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			if (temp->data /= temp->next->data)  // This Conditions checks if they are equal or not, its a == operator but since I have already used it with different parameters so I have to create a new one with different signs
			{
				temp->data += temp->next->data;
				Node* todelete = temp->next;
				if (todelete == tail)
				{
					tail = temp;
				}
				temp->next = todelete->next;
				delete todelete;
			}
			temp = temp->next;
			if (temp == 0)
			{
				break;
			}
		}
	}
	void DeleteBlock(Block* temp)
	{
		Node* curr = head;
		if (&(head->data) == temp)
		{
			DeleteAtStart();
		}
		else if (&(tail->data) == temp)
		{
			DeleteAtEnd();
		}
		else
		{
			while (curr->next != 0)
			{
				if (&(curr->next->data) == temp)
				{
					Node* temp = curr->next;
					curr->next = temp->next;
					delete temp;
					break;
				}
				curr = curr->next;
				if (curr == 0)
				{
					break;
				}
			}
		}
	}
	~List()
	{
		while (head)
		{
			DeleteAtEnd();
		}
	}
};
class Block
{
private:
	int start_byte_ID;
	int total_bytes;
public:
	Block()
	{
		start_byte_ID = 0;
		total_bytes = 0;
	}
	Block(int StartID, int Size)
	{
		start_byte_ID = StartID;
		total_bytes = Size;
	}
	Block& operator=(Block& rhs)
	{
		start_byte_ID = rhs.start_byte_ID;
		total_bytes = total_bytes + rhs.total_bytes;

		return *this;
	}
	bool operator/=(Block& rhs)   // This is an extra function , it also plays a role of == function but since == already exists so I have to change its sign
	{
		if (start_byte_ID + total_bytes == rhs.start_byte_ID)
		{
			return true;
		}
		return false;
	}
	Block& operator+=(Block& rhs)  // This is used for Merging Only total bytes is added Starting Address Remains the same
	{
		start_byte_ID = start_byte_ID;
		total_bytes = +total_bytes + rhs.total_bytes;

		return *this;
	}
	friend ostream& operator<<(ostream& out, Block& obj)
	{
		cout << " [ " << obj.start_byte_ID << " , " << obj.total_bytes << " ]   ";
		return out;
	}
	int Get_Starting_Address()
	{
		return start_byte_ID;
	}
	void Set_Start_Byte(int Start)
	{
		start_byte_ID = Start;
	}
	void Set_Total_Bytes(int total)
	{
		total_bytes = total;
	}
	int Get_Total_Bytes()
	{
		return total_bytes;
	}
	bool operator<(Block& rhs)
	{
		if (start_byte_ID < rhs.start_byte_ID)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(Block& rhs)
	{
		if (start_byte_ID > rhs.start_byte_ID)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(int data)
	{
		if (total_bytes >= data)
			return true;
		else
			return false;
	}
	bool operator==(int Size)
	{
		if (total_bytes == Size)
			return true;
		else
			return false;
	}
};
class Program
{
	friend class Memory_Mangement_System;
private:
	int Program_ID;
	int Size;
	List<Block> block;
public:
	Program()
	{
		Program_ID = 0;
		Size = 0;
	}
	Program(int ID, int s)
	{
		Program_ID = ID;
		Size = s;
	}
	friend ostream& operator<<(ostream& out, Program& obj)
	{
		cout << "P" << obj.Program_ID << " : ";
		cout << " [ " << obj.Size << " ] ->";
		obj.block.Print();
		return out;
	}
	bool operator==(Program& obj)
	{
		if (Program_ID == obj.Program_ID)
			return true;
		else
			return false;
	}
	bool operator==(int PID)
	{
		if (Program_ID == PID)
			return true;
		else
			return false;
	}
	bool operator!=(int PID)
	{
		if (Program_ID != PID)
			return true;
		else
			return false;
	}
	int Get_Program_ID()
	{
		return Program_ID;
	}
	~Program()
	{

	}
};
class Memory_Mangement_System
{
private:
	List<Block> Pool;     // Pool has initially only block
	List<Program>Prog;    // Prog is Initially NULL/ZERO 
	int Size_of_Memory;
	bool Strategy;       //true for best fit and false for first fit
public:
	Memory_Mangement_System(int size, bool choice)
	{
		Size_of_Memory = size;
		Strategy = choice;
		Block temp(0, size);  // Pool has initially only block
		Pool.InsertSorted(temp);
	}
	void GetMemory(int ID, int Req_Memory)
	{
		if (Size_of_Memory >= Req_Memory)  
		{
			if (Strategy == true)
			{
				Program Progtemp(ID, Req_Memory);
				if (!Prog.EmptyCheck())  // Checking if the Prog LL is empty or not
				{
					if (Pool.BestFit(Req_Memory))  // Checking Pool For Memory According to Best Fit
					{
						if (Prog.Searching(Progtemp))   // If the Program already Exists than only a new node will be entered in its LL of Blocks
						{
							Block* btemp = Pool.BestFit(Req_Memory);  // this gives the block of pool according to best fit
							int Starting_Address = btemp->Get_Starting_Address(); // Starting address
							Block Blocktemp(Starting_Address, Req_Memory); // creating new block
							Program* temp = Prog.Get_Program(ID);
							if (btemp->Get_Total_Bytes() > Req_Memory)   // This condition check if btemp has memory greator than required than it only changes total bytes and starting byte address
							{
								btemp->Set_Start_Byte(btemp->Get_Starting_Address() + Req_Memory);
								btemp->Set_Total_Bytes(btemp->Get_Total_Bytes() - Req_Memory);
							}
							else // if btemp-> memory == required than it deletes that node from pool and insert it in Prog-> block LL 
							{
								Pool.DeleteBlock(btemp);
							}
							(temp->block).InsertatEnd(Blocktemp);
							temp->Size = temp->Size + Req_Memory;
							Size_of_Memory = Size_of_Memory - Req_Memory;
						}

						else  // If a Program doesnot exists already than a new node wwill be entered in Prog LL
						{
							Block* btemp = Pool.BestFit(Req_Memory);
							int Starting_Address = btemp->Get_Starting_Address();
							Block Blocktemp(Starting_Address, Req_Memory);
							if (btemp->Get_Total_Bytes() > Req_Memory)  // This is same as above
							{
								btemp->Set_Start_Byte(btemp->Get_Starting_Address() + Req_Memory);
								btemp->Set_Total_Bytes(btemp->Get_Total_Bytes() - Req_Memory);
							}
							else    // This is same as above
							{
								Pool.DeleteBlock(btemp);
							}
							Block tempo(Starting_Address, Req_Memory);
							Prog.InsertatEnd(Progtemp);
							Program* temp = Prog.Get_Program(ID);   // temp is temporary and it is used to enter block into LL of Prog
							(temp->block).InsertatEnd(tempo);
							Size_of_Memory = Size_of_Memory - Req_Memory;
						}
					}
					else
					{
						cout << "NO MEMORY AVAILABLE ACCORDING TO BEST FIT" << endl<<endl;
					}
				}
				else   // If Prog is Empty then a new node is entered in it , This will only only 1 time at the start of Program
				{
					Block* btemp = Pool.BestFit(Req_Memory);
					int Starting_Address = btemp->Get_Starting_Address();
					Block Blocktemp(Starting_Address, Req_Memory);
					if (btemp->Get_Total_Bytes() > Req_Memory)  // This is same as above
					{
						btemp->Set_Start_Byte(btemp->Get_Starting_Address() + Req_Memory);
						btemp->Set_Total_Bytes(btemp->Get_Total_Bytes() - Req_Memory);
					}
					else  // This is same as above
					{
						Pool.DeleteBlock(btemp);
					}
					Block tempo(Starting_Address, Req_Memory);
					Prog.InsertatEnd(Progtemp);
					Program* temp = Prog.Get_Program(ID);  // This is same as above
					(temp->block).InsertatEnd(tempo);
					Size_of_Memory = Size_of_Memory - Req_Memory;
				}
			}
			else    // This condition is for FIRST FIT
			{
				Program Progtemp(ID, Req_Memory);
				if (!Prog.EmptyCheck())
				{
					if (Pool.FirstFit(Req_Memory))
					{
						if (Prog.Searching(Progtemp))  // This conditon will execute when Program has already been made ie If P1 already exist and we want to enter a new node
						{
							Block* btemp = Pool.FirstFitReturn(Req_Memory);
							int Starting_Address = btemp->Get_Starting_Address();
							Block Blocktemp(Starting_Address, Req_Memory);

							Program* temp = Prog.Get_Program(ID);
							if (btemp->Get_Total_Bytes() > Req_Memory)  // Already Explained in the Previos if Conditon, it Performs the same function 
							{
								btemp->Set_Start_Byte(btemp->Get_Starting_Address() + Req_Memory);
								btemp->Set_Total_Bytes(btemp->Get_Total_Bytes() - Req_Memory);
							}
							else
							{
								Pool.DeleteBlock(btemp);
							}
							(temp->block).InsertatEnd(Blocktemp);
							temp->Size = temp->Size + Req_Memory;
							Size_of_Memory = Size_of_Memory - Req_Memory;
						}

						else
						{
							Block* btemp = Pool.FirstFitReturn(Req_Memory);
							int Starting_Address = btemp->Get_Starting_Address();
							Block Blocktemp(Starting_Address, Req_Memory);
							if (btemp->Get_Total_Bytes() > Req_Memory)   // Already Explained in the Previos if Conditon, it Performs the same function 
							{
								btemp->Set_Start_Byte(btemp->Get_Starting_Address() + Req_Memory);
								btemp->Set_Total_Bytes(btemp->Get_Total_Bytes() - Req_Memory);
							}
							else  // Already Explained
							{
								Pool.DeleteBlock(btemp);
							}
							Block tempo(Starting_Address, Req_Memory);
							Prog.InsertatEnd(Progtemp);
							Program* temp = Prog.Get_Program(ID);
							(temp->block).InsertatEnd(tempo);
							Size_of_Memory = Size_of_Memory - Req_Memory;
						}
					}
					else
					{
						cout << "NO MEMORY AVAILABLE ACCORDING TO FIRST FIT" << endl << endl;
					}
				}
				else   // This Condition is for the case when Prog is Initially null , this will only Execute once which is only first time
				{
					Block* btemp = Pool.FirstFitReturn(Req_Memory);
					int Starting_Address = btemp->Get_Starting_Address();
					Block Blocktemp(Starting_Address, Req_Memory);
					if (btemp->Get_Total_Bytes() > Req_Memory)
					{
						btemp->Set_Start_Byte(btemp->Get_Starting_Address() + Req_Memory);
						btemp->Set_Total_Bytes(btemp->Get_Total_Bytes() - Req_Memory);
					}
					else
					{
						Pool.DeleteBlock(btemp);
					}
					Block tempo(Starting_Address, Req_Memory);
					Prog.InsertatEnd(Progtemp);
					Program* temp = Prog.Get_Program(ID);
					(temp->block).InsertatEnd(tempo);
					Size_of_Memory = Size_of_Memory - Req_Memory;
				}
			}	
		}
		else
		{
		    cout<< "Not Enough Memory Left in the System" << endl;
		}
	}
	void Delete(int PID)
	{
		if (Prog.Search_Program_By_ID(PID))  // Search Program By ID
		{
			Program* temp = Prog.Get_Program(PID);  // Gets the address of that Program
			while (!temp->block.EmptyCheck())
			{
				int total = temp->block.Get_Pool_Total_Memory()->Get_Total_Bytes(); 
				int start = temp->block.Get_Current_Address()->Get_Starting_Address();
				Block b1(start, total);
				Pool.InsertSorted(b1); // Inserts same Node back into pool
				(temp->block).DeleteAtEnd(); //than delete it from Prog-> Block ->LL
				Size_of_Memory = Size_of_Memory - total;
			}
			Prog.DeleteSpecific(PID);
			Pool.Merging();
		}
		else
		{
			cout << "Given Program ID Doesn't Exists" << endl;
		}
	}
	void Merge()
	{
		Pool.Merging();
	}
	void PrintPool()
	{
		cout << "POOL -> ";
		Pool.Print();
	}
	void Print()
	{
		Prog.Print();
		cout << endl;
	}
	~Memory_Mangement_System()
	{
		Pool.DeleteAtEnd();
		Prog.DeleteAtEnd();
	}
};
void Menu()
{
	cout << "							Welcome to Memory Management System " << endl;
	cout << "							By: Abdul Tawab (L21-5422) " << endl;
	cout << endl << endl;
	cout << "\t\t\t\tAssalam o Alaikum" << endl << endl << endl;
	int choice;
	int size = 0, strategy;
	cout << "Enter Memory For Memory Management System Object : " << endl;
	cin >> size;
	cout << "Which Strategy would you like to choice (Press 1 for Best Fit and 0 For First Fit) : ";
	cin >> strategy;
	Memory_Mangement_System MMS(size, strategy);
	while (true)
	{
		system("CLS");
		cout << "\t\t\t\tAssalam o Alaikum" << endl;
		cout << "1-> Press 1 to create a new Program " << endl;
		cout << "2-> Press 2 to Delete a Program" << endl;
		cout << "3-> Press 3 to Print Memory" << endl;
		cout << "4-> Press 4 to Print Pool" << endl;
		cout << "5-> Press 5 to Print Both Memory and Pool" << endl;
		cout << "6-> Press 6 to Merge Pool" << endl;
		cout << "7-> Press -1 to Exit the System" << endl;
		cin >> choice;
		if (choice == -1)
		{
			system("CLS");
			cout << "Program Terminated" << endl;
			break;
		}
		else if (choice == 1)
		{
			system("CLS");
			int PID, mem;
			cout << "Enter Program ID : ";
			cin >> PID;
			cout << "Enter Memory For Your Program : ";
			cin >> mem;
			MMS.GetMemory(PID, mem);
		}
		else if (choice == 2)
		{
			system("CLS");
			int PID;
			cout << "Enter ID of the Program which you want to delete : ";
			cin >> PID;
			MMS.Delete(PID);
		}
		else if (choice == 3)
		{
			system("CLS");
			MMS.Print();
			system("pause");
		}
		else if (choice == 4)
		{
			system("CLS");
			MMS.PrintPool();
			system("pause");
		}
		else if (choice == 5)
		{
			system("CLS");
			MMS.PrintPool();
			MMS.Print();
			system("pause");
		}
		else if (choice == 6)
		{
			cout << "Pool has been Merged" << endl;
			MMS.Merge();
			system("pause");
		}
	}
}
int main()
{
    system("color 74");
	Menu();
	system("pause");
}
