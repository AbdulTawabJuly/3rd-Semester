//#include<iostream>
//using namespace std;
//
//template<class t>
//class List
//{
//
//private:
//
//	class Node
//	{
//
//	public:
//		t data;
//		Node* next;
//
//		Node()
//		{
//			next = nullptr;
//		}
//	};
//
//	Node* head;
//	Node* tail;
//	int size;
//
//public:
//
//	List()
//	{
//		head = tail = nullptr;
//		size = 0;
//	}
//
//	void InsertAtStart(t obj)
//	{
//		Node* temp = new Node;
//		temp->data = obj;
//		temp->next = head;
//		if (!head)
//			head = tail = temp;
//		else
//			head = temp;
//
//	}
//
//	void InsertatEnd(t d)
//	{
//		if (head == nullptr)
//		{
//			InsertAtStart(d);
//			size++;
//		}
//		else
//		{
//			Node* temp = new Node;
//			temp->data = d;
//			temp->next = nullptr;
//			tail->next = temp;
//			tail = temp;
//			size++;
//		}
//	}
//
//	void InsertSorted(t element)
//	{
//		if (head == nullptr)
//		{
//			InsertAtStart(element);
//			size++;
//		}
//		else if (head == tail || head->data > element || tail->data < element)
//		{
//			if (head->data > element)
//			{
//				InsertAtStart(element);
//				size++;
//			}
//			else
//			{
//				InsertatEnd(element);
//				size++;
//			}
//		}
//		else
//		{
//			Node* curr = new Node;
//			curr->data = element;
//
//			Node* temp = head;
//			while (temp != nullptr)
//			{
//				if (temp->data < curr->data && temp->next->data > curr->data)
//				{
//					curr->next = temp->next;
//					temp->next = curr;
//					break;
//				}
//				temp = temp->next;
//			}
//			size++;
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
//
//	void DeleteAtEnd()
//	{
//		if (head == nullptr)
//		{
//			return;
//		}
//
//		if (head == tail)
//		{
//			delete head;
//			head = tail = nullptr;
//		}
//
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
//	void DeleteSpecific(int PID)
//	{
//		Node* temp = head;
//		Node* todelete;
//		int length = 0;
//
//		while (temp != nullptr)
//		{
//			length++;
//			temp = temp->next;
//		}
//
//		if (PID == 1)
//		{
//			DeleteAtStart();
//			return;
//		}
//
//		else if (length == 1)
//		{
//			DeleteAtStart();
//			return;
//		}
//
//		temp = head;
//		Node* temp2 = head;
//		while (temp->data != PID && temp != nullptr)
//		{
//			temp2 = temp;
//			temp = temp->next;
//		}
//		if (temp == head)
//		{
//			DeleteAtStart();
//			return;
//		}
//		todelete = temp;
//		temp2->next = temp->next;
//		delete todelete;
//	}
//
//	void Print()
//	{
//		if (head == nullptr)
//		{
//			cout << "Memory is Empty" << endl;
//		}
//		else
//		{
//			Node* temp;
//			temp = head;
//			while (temp != nullptr)
//			{
//				cout << temp->data;
//				temp = temp->next;
//			}
//		}
//		cout << endl;
//	}
//
//	bool isEmpty()
//	{
//		if (head == nullptr)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//
//	bool FirstFit(int Req_Mem)
//	{
//		Node* temp = head;
//		while (temp != nullptr)
//		{
//			if (temp->data >= Req_Mem)
//			{
//				return true;
//			}
//			temp = temp->next;
//		}
//		return false;
//		cout << "Block of Memory was not Found" << endl << endl;
//	}
//
//	Node* FirstFitReturn(int Req_Mem)
//	{
//		Node* temp = head;
//		t* best = 0;
//		while (temp != nullptr)
//		{
//			if (temp->data >= Req_Mem)
//			{
//				return &(temp->data);
//			}
//			temp = temp->next;
//		}
//		cout << "Block of Memory was not Found" << endl << endl;
//		//return;
//	}
//
//	int BestFit(int Req_Mem)
//	{
//		int best = 0;
//		bool flag = false;
//		Node* temp = head;
//		while (temp != NULL)
//		{
//			if (temp->data > Req_Mem)
//			{
//				if (flag)
//				{
//					best = temp->data;
//				}
//
//				else if (best < temp->data)
//				{
//					best = best;
//				}
//				else
//				{
//					best = temp->data;
//				}
//				flag = false;
//			}
//			temp = temp->next;
//		}
//		cout << "Block of Memory was not Found" << endl << endl;
//	}
//
//	/*int CheckPoolforMem(int Size)
//	{
//		Node* temp = head;
//		while (temp != nullptr)
//		{
//			if (temp->data == Size)
//			{
//				return true;
//			}
//			temp = temp->next;
//		}
//		return false;
//	}*/
//
//	bool Search(t obj)
//	{
//		Node* temp = head;
//		while (temp != nullptr)
//		{
//			if (temp->data == obj)
//			{
//				return true;
//			}
//			temp = temp->next;
//		}
//		return false;
//
//	}
//
//	t* GetPoolStartingAddress()
//	{
//		Node* temp = head;
//		return &(temp->data);
//	}
//
//	t* GetCurrentAddress()
//	{
//		Node* temp = tail;
//		return&(temp->data);
//	}
//
//	t* GetPoolTotalMemory()
//	{
//		Node* temp = tail;
//		return&(temp->data);
//	}
//
//	List& operator=(t rhs)
//	{
//		Node* temp = head;
//		while (temp != nullptr)
//		{
//			if (temp->data == rhs)
//			{
//				temp->data = rhs;
//			}
//			temp = temp->next;
//		}
//		return *this;
//	}
//
//	List& operator!=(t rhs)
//	{
//		Node* temp = head;
//		if (temp != rhs)
//			return true;
//		else
//			return false;
//
//	}
//
//	t* Get_Program(int id)
//	{
//		Node* curr = head;
//		while (curr != 0)
//		{
//			if ((curr->data).GetID() == id)
//			{
//				return &(curr->data);
//			}
//			curr = curr->next;
//		}
//	}
//
//	bool Search_Program_By_ID(int id)
//	{
//		Node* curr = head;
//		while (curr != 0)
//		{
//			if ((curr->data).GetID() == id)
//			{
//				return true;
//			}
//			curr = curr->next;
//		}
//		return false;
//	}
//
//	void Merging()
//	{
//		Node* temp = head;
//		while (temp->next != nullptr)
//		{
//			if (temp->data /= temp->next->data)
//			{
//				temp->data += temp->next->data;
//			}
//		}
//	}
//};
//
//class Block
//{
//
//private:
//
//	int start_byte_ID;
//	int total_bytes;
//
//public:
//
//	Block()
//	{
//		start_byte_ID = 0;
//		total_bytes = 0;
//	}
//
//	Block(int StartID, int Size)
//	{
//		start_byte_ID = StartID;
//		total_bytes = Size;
//	}
//
//	Block& operator=(Block& rhs)
//	{
//		start_byte_ID = rhs.start_byte_ID;
//		total_bytes = total_bytes + rhs.total_bytes;
//
//		return *this;
//	}
//
//	bool operator/=(Block& rhs)
//	{
//		if (start_byte_ID + total_bytes == rhs.start_byte_ID)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	Block& operator+=(Block& rhs)
//	{
//		start_byte_ID = start_byte_ID;
//		total_bytes = +total_bytes + rhs.total_bytes;
//
//		return *this;
//	}
//
//	friend ostream& operator<<(ostream& out, Block& obj)
//	{
//		cout << " [ " << obj.start_byte_ID << " , " << obj.total_bytes << " ]   ";
//		return out;
//	}
//
//	int GetStartingAddress()
//	{
//		return start_byte_ID;
//	}
//
//
//	void SetStartByte(int Start)
//	{
//		start_byte_ID = Start;
//	}
//
//	void SetTotal_Bytes(int total)
//	{
//		total_bytes = total;
//	}
//
//	int GetTotalBytes()
//	{
//		return total_bytes;
//	}
//
//	bool operator<(Block& rhs)
//	{
//		if (start_byte_ID < rhs.start_byte_ID)
//			return true;
//		else
//			return false;
//	}
//
//
//	bool operator>(Block& rhs)
//	{
//		if (start_byte_ID > rhs.start_byte_ID)
//			return true;
//		else
//			return false;
//	}
//
//	bool operator>=(int data)
//	{
//		if (total_bytes >= data)
//			return true;
//		else
//			return false;
//	}
//
//	bool operator==(int Size)
//	{
//		if (total_bytes == Size)
//			return true;
//		else
//			return false;
//	}
//};
//
//class Program
//{
//	friend class MMS;
//private:
//
//	int Program_ID;
//	int Size;
//	List<Block> block;
//
//public:
//
//	Program()
//	{
//		Program_ID = 0;
//		Size = 0;
//	}
//
//	Program(int ID, int s)
//	{
//		Program_ID = ID;
//		Size = s;
//	}
//
//	Program& operator=(Block& rhs)
//	{
//		Block temp(rhs.GetStartingAddress(), rhs.GetTotalBytes());
//		block.InsertatEnd(temp);
//	}
//
//	friend ostream& operator<<(ostream& out, Program& obj)
//	{
//		cout << "P" << obj.Program_ID << " : ";
//		cout << " [ " << obj.Size << " ] ->";
//		obj.block.Print();
//		return out;
//	}
//
//	bool operator==(Program& obj)
//	{
//		if (Program_ID == obj.Program_ID)
//			return true;
//		else
//			return false;
//	}
//
//	bool operator!=(int PID)
//	{
//		if (Program_ID != PID)
//			return true;
//		else
//			return false;
//	}
//
//	int GetID()
//	{
//		return Program_ID;
//	}
//};
//
//
//class MMS
//{
//private:
//	List<Block> Pool;
//	List<Program>Prog;    // Prog is Initially NULL/ZERO 
//	int Size_of_Memory;
//	bool Strategy;       //true for best fit and false for first fit
//
//public:
//	MMS(int size, bool choice)
//	{
//		Size_of_Memory = size;
//		Strategy = choice;
//		Block temp(0, size);
//		Pool.InsertSorted(temp);
//	}
//	void GetMemory(int ID, int Req_Memory)
//	{
//		if (Size_of_Memory >= Req_Memory)  // delete Check pool for Memory Function
//		{
//			if (Strategy == true)
//			{
//
//			}
//
//			else
//			{
//				Program Progtemp(ID, Req_Memory);
//				if (!Prog.isEmpty())
//				{
//					if (Pool.FirstFit(Req_Memory))
//					{
//						if (Prog.Search(Progtemp))
//						{
//
//							Program* temp = Prog.Get_Program(ID);
//							int Starting_Address = Pool.GetPoolStartingAddress()->GetStartingAddress();//change for best fit and first fit
//							Pool.GetPoolStartingAddress()->SetStartByte(Req_Memory + Pool.GetPoolStartingAddress()->GetStartingAddress());
//							Pool.GetPoolTotalMemory()->SetTotal_Bytes(Pool.GetPoolTotalMemory()->GetTotalBytes() - Req_Memory);
//							Block Blocktemp(Starting_Address, Req_Memory);
//							(temp->block).InsertatEnd(Blocktemp);
//							temp->Size = temp->Size + Req_Memory;
//							Size_of_Memory = Size_of_Memory - Req_Memory;
//						}
//
//						else
//						{
//							int Starting_Address = Pool.GetPoolStartingAddress()->GetStartingAddress();
//							Pool.GetPoolStartingAddress()->SetStartByte(Req_Memory + Pool.GetPoolStartingAddress()->GetStartingAddress());
//							Pool.GetPoolTotalMemory()->SetTotal_Bytes(Pool.GetPoolTotalMemory()->GetTotalBytes() - Req_Memory);
//							Block tempo(Starting_Address, Req_Memory);
//							Prog.InsertatEnd(Progtemp);
//							(Progtemp.block).InsertatEnd(tempo);
//							Program* temp = Prog.Get_Program(ID);
//							(temp->block).InsertatEnd(tempo);
//							Size_of_Memory = Size_of_Memory - Req_Memory;
//						}
//					}
//				}
//				else
//				{
//					int Starting_Address = Pool.GetPoolStartingAddress()->GetStartingAddress();
//					Pool.GetPoolStartingAddress()->SetStartByte(Req_Memory + Pool.GetPoolStartingAddress()->GetStartingAddress());
//					Pool.GetPoolTotalMemory()->SetTotal_Bytes(Pool.GetPoolTotalMemory()->GetTotalBytes() - Req_Memory);
//					Block tempo(Starting_Address, Req_Memory);
//					Prog.InsertatEnd(Progtemp);
//					(Progtemp.block).InsertatEnd(tempo);
//					Program* temp = Prog.Get_Program(ID);
//					(temp->block).InsertatEnd(tempo);
//					Size_of_Memory = Size_of_Memory - Req_Memory;
//				}
//			}
//		}
//		else
//		{
//			cout << "Not Enough Memory in the Pool" << endl;
//		}
//	}
//
//	void Delete(int PID)
//	{
//		if (Prog.Search_Program_By_ID(PID))
//		{
//			Program* temp = Prog.Get_Program(PID);
//			while (!temp->block.isEmpty())
//			{
//				//int Mem = temp->block.GetPoolTotalMemory()->GetTotalBytes();
//				int total = temp->block.GetPoolTotalMemory()->GetTotalBytes();
//				int start = temp->block.GetCurrentAddress()->GetStartingAddress();
//				Block b1(start, total);
//				Pool.InsertSorted(b1);
//				(temp->block).DeleteAtEnd();
//				Size_of_Memory = Size_of_Memory - total;
//				//Pool.GetPoolTotalMemory()->SetTotal_Bytes(Pool.GetPoolTotalMemory()->GetTotalBytes() + Mem);
//				//Pool.GetPoolStartingAddress()->SetStartByte(Pool.GetPoolStartingAddress()->GetStartingAddress() - Mem);
//			}
//			Prog.DeleteSpecific(PID);
//		}
//		else
//		{
//			cout << "Given Program ID Doesn't Exists" << endl;
//		}
//	}
//
//	void PrintPool()
//	{
//		cout << "POOL -> ";
//		Pool.Print();
//	}
//
//	void Print()
//	{
//		Prog.Print();
//		cout << endl;
//	}
//};
//int main()
//{
//	MMS Ram(10000, false);
//	Ram.PrintPool();
//	cout << endl;
//	Ram.GetMemory(1, 40);
//	Ram.GetMemory(2, 20);
//	Ram.GetMemory(3, 20);
//	Ram.GetMemory(1, 30);
//	Ram.GetMemory(2, 40);
//	Ram.GetMemory(3, 50);
//	Ram.Print();
//	Ram.PrintPool();
//	Ram.Delete(3);
//	Ram.Delete(2);
//	Ram.Print();
//	Ram.PrintPool();
//	Ram.GetMemory(4, 40);
//	/*Ram.GetMemory(4, 50);
//	Ram.GetMemory(5, 30);
//	Ram.GetMemory(5, 40);
//	Ram.Print();
//	Ram.PrintPool();
//	cout << endl;*/
//
//}