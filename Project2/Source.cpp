//#include<iostream>
//using namespace std;
//
//class Block;
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
//
//
//		Node& operator=(Node& rhs)
//		{
//			data = rhs.data;
//
//			return *this;
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
//	int CheckPoolforMem(int Size)
//	{
//		Node* temp = head;
//		while (temp != nullptr)
//		{
//			if (temp->data == Size)
//			{
//
//				return true;
//			}
//			temp = temp->next;
//		}
//		return false;
//	}
//
//	//void UpdateLL(t obj)
//	//{
//	//	Node* temp = head;
//	//	temp->data = obj;
//
//	//	/*while (temp != nullptr)
//	//	{
//	//		if (temp->data == obj)
//	//		{
//	//			temp->data += obj;
//	//			return;
//	//		}
//	//		else
//	//		{
//	//			temp = temp->next;
//	//		}
//	//	}*/
//	//}
//
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
//	
//
//	void ChangePoolData(int a, int b)
//	{
//
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
//	t* SearchProgram(int id)
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
//	/*List& operator/=(t rhs)
//	{
//		Node* temp = head;
//		temp->data /= rhs
//
//	}*/
//
//	/*List& operator+=(t &obj)
//	{
//		data += obj.dat;
//
//		return *this;
//	}*/
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
//	//Block& operator=(Block& rhs)
//	//{
//	//	start_byte_ID = rhs.start_byte_ID;
//	//	//total_bytes = total_bytes + rhs.total_bytes;
//
//	//	return *this;
//	//}
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
//	bool operator==(int Size)
//	{
//		if (total_bytes == Size)
//			return true;
//		else
//			return false;
//	}
//
//	/*Block& operator=(Block& rhs)
//	{
//		start_byte_ID = rhs.start_byte_ID;
//		total_bytes = rhs.total_bytes;
//	}*/
//
//	/*Block& operator+=(Block&rhs)
//	{
//		total_bytes += rhs.total_bytes;
//		return *this;
//	}*/
//};
//
//class Program
//{
//	//friend ostream& operator<(ostream&, Program&);
//	friend class MMS;
//
//private:
//
//	int Program_ID;
//	int Size;
//	//int PrevSize;
//	List<Block> block;
//
//public:
//
//	Program()
//	{
//		Program_ID = 0;
//		Size = 0;
//		//PrevSize = 0;
//	}
//
//	Program(int ID, int s)
//	{
//		Program_ID = ID;
//		Size = s;
//	}
//
//
//	//Program& operator=(Program& rhs)
//	//{
//		//Program_ID = rhs.Program_ID;
//		//Size = rhs.Size;
//		//Block temp(PrevSize,rhs.Size);
//		//PrevSize = PrevSize + Size;
//		//block.InsertatEnd(temp);
//		//return *this;
//	//}
//
//	Program& operator=(Block& rhs)
//	{
//		Block temp(rhs.GetStartingAddress(), rhs.GetTotalBytes());
//		block.InsertatEnd(temp);
//	}
//
//	////Program& operator+=(Program& rhs)
//	//{
//	//	Size += rhs.Size;
//	//	Block temp(0,Size);
//	//	//block.InsertatEnd(temp);
//	//	block.InsertatEnd(temp);
//	//	return *this;
//	//}
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
//	int GetID()
//	{
//		return Program_ID;
//	}
//	/*bool check(List<Program>)
//	{
//
//	}*/
//};
//
//
//
//class MMS
//{
//private:
//	List<Block> Pool;
//	List<Program>Prog;   
//	int Size_of_Memory;
//	int Available;
//	bool Strategy;       
//
//public:
//	MMS(int size, bool choice)
//	{
//		Size_of_Memory = Available = size;
//		Strategy = choice;
//		Block temp(0, size);
//		Pool.InsertSorted(temp);
//	}
//	void GetMemory(int ID, int Req_Memory)
//	{
//		Available = Available - Req_Memory;
//		if (!Pool.CheckPoolforMem(Req_Memory))
//		{
//			Program Progtemp(ID, Req_Memory);
//			if (!Prog.isEmpty())
//			{
//				if (Prog.Search(Progtemp))
//				{
//					Program* temp = Prog.SearchProgram(ID);
//					int Starting_Address = Pool.GetPoolStartingAddress()->GetStartingAddress();//change for best fit and first fit
//					Block Blocktemp(Starting_Address, Req_Memory);
//					//Progtemp.block.InsertatEnd(Blocktemp);
//					//Prog = Progtemp;
//					(temp->block).InsertatEnd(Blocktemp);
//					temp->Size = temp->Size + Req_Memory;
//					//Pool.GetPoolStartingAddress().SetStartByte(Starting_Address + Req_Memory);
//					//Pool.SetTotal_Bytes(Available);
//					//Pool.ChangePoolData(Pool.GetPoolStartingAddress().GetStartingAddress(), Pool.);
//					//Prog.InsertatEnd(Progtemp);
//					//Prog.InsertatEnd(Blocktemp)
//				}
//
//				else
//				{
//					int Starting_Address = Pool.GetPoolStartingAddress()->GetStartingAddress();
//					Block tempo(Starting_Address, Req_Memory);
//					Prog.InsertatEnd(Progtemp);
//					Program* temp = Prog.SearchProgram(ID);
//					(temp->block).InsertatEnd(tempo);
//				}
//			}
//			else
//			{
//				int Starting_Address = Pool.GetPoolStartingAddress()->GetStartingAddress();
//				Block tempo(Starting_Address, Req_Memory);
//				Prog.InsertatEnd(Progtemp);
//				Program* temp = Prog.SearchProgram(ID);
//				(temp->block).InsertatEnd(tempo);
//			}
//		}
//	}
//
//	void Print()
//	{
//		Prog.Print();
//		cout << endl;
//	}
//
//};
//
//int main()
//{
//	MMS Ram(10000, true);
//	cout << endl;
//
//	Ram.GetMemory(1, 40);
//
//	Ram.GetMemory(2, 30);
//
//	Ram.GetMemory(3, 40);
//
//	Ram.GetMemory(4, 30);
//
//	Ram.GetMemory(5, 20);
//
//	Ram.GetMemory(6, 40);
//
//	Ram.GetMemory(1, 20);
//
//	Ram.GetMemory(1, 20);
//
//	Ram.GetMemory(5, 30);
//
//	Ram.GetMemory(4, 20);
//
//	Ram.Print();
//
//	cout << endl;
//}