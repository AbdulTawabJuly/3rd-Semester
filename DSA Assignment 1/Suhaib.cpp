//#include <iostream>
//using namespace std;
////Helper class to deal with the char array involved i.e Program ID
//class Helper
//{
//public:
//	static int StringLength(const char* str)
//	{
//		int i = 0;
//		while (str[i] != '\0')
//		{
//			i++;
//		}
//		return i;
//	}
//	static void StringCopy(char*& dest, char*& src)
//	{
//		int i = 0;
//		while (src[i] != '\0')
//		{
//			dest[i] = src[i];
//			i++;
//		}
//		dest[i] = '\0';
//	}
//	static void StringCopy(char dest[], const  char*& src)
//	{
//		int i = 0;
//		while (src[i] != '\0')
//		{
//			dest[i] = src[i];
//			i++;
//		}
//		dest[i] = '\0';
//	}
//	static char* GetStringFromBuffer(const char* str)
//	{
//		int length = StringLength(str);
//		length = length + 1;
//		char* dest = new char[length];
//		StringCopy(dest, str);
//		return dest;
//	}
//	static int CompareStrings(const char* string1, const char* string2)
//	{
//		int string1Length = StringLength(string1);
//		int string2Length = StringLength(string2);
//		int i = 0; int max = 0;
//		if (string1Length > string2Length) {
//			max = string1Length;
//		}
//		else {
//			max = string2Length;
//		}
//		while (i < max)
//		{
//			if (string1[i] != string2[i])
//			{
//				return 0;
//			}
//			//Otherwise keep traversing the strings
//			if (string1[i] == string2[i])
//			{
//				i++;
//			}
//		}
//		return 1;
//	}
//};
//class Block
//{
//private:
//	friend ostream& operator<<(ostream& out, const Block& rhs);
//	int start_Byte_ID;
//	int total_bytes;
//public:
//	Block(int start, int total)
//	{
//		start_Byte_ID = start;
//		total_bytes = total;
//	}
//	Block()
//	{
//		start_Byte_ID = 0;
//		total_bytes = 0;
//	}
//	Block(const Block& rhs)
//	{
//		start_Byte_ID = rhs.start_Byte_ID;
//		total_bytes = rhs.total_bytes;
//	}
//	int GetByteID()
//	{
//		return start_Byte_ID;
//	}
//	int GetTotalBytes()
//	{
//		return total_bytes;
//	}
//	void SetByteID(int byteID)
//	{
//		start_Byte_ID = byteID;
//	}
//	void SetTotalBytes(int total)
//	{
//		total_bytes = total;
//	}
//	//opertors used in Memory mangement class
//	bool operator <(Block& rhs)
//	{
//		if (start_Byte_ID < rhs.start_Byte_ID)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	bool operator>(Block& rhs)
//	{
//		if (start_Byte_ID > rhs.start_Byte_ID)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	bool operator ==(Block& rhs)
//	{
//		if (start_Byte_ID == rhs.start_Byte_ID)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//};
//ostream& operator<<(ostream& out, const Block& rhs)
//{
//	out << "Start ID    : " << rhs.start_Byte_ID << endl;
//	out << "Total Bytes : " << rhs.total_bytes;
//	return out;
//}
//
//template<class T>
//class List
//{
//	class Node
//	{
//	public:
//		T data;
//		Node* next;
//		Node()
//		{
//			next = 0;
//		}
//		~Node()
//		{
//			next = 0;
//		}
//	};
//	Node* head;
//	Node* tail;
//public:
//	class Iterator
//	{
//		friend class List<T>;
//	private:
//		Node* curr;
//	public:
//		Iterator()
//		{
//			curr = 0;
//		}
//		Iterator& operator++()
//		{
//			curr = curr->next;
//			return *this;
//		}
//		T* operator*()
//		{
//			return &(curr->data);
//		}
//		bool operator!=(Iterator& rhs)
//		{
//			if (curr != rhs.curr)
//			{
//				return true;
//			}
//
//			else { return false; }
//		}
//		Node* GetCurrent()
//		{
//			return curr;
//		}
//		Node* GetNext()
//		{
//			return curr->next;
//		}
//	};
//	Iterator Begin()
//	{
//		Iterator it;
//		it.curr = head;
//		return it;
//	}
//	Iterator End()
//	{
//		Iterator it;
//		it.curr = tail;
//		return it;
//	}
//	List()
//
//	{
//		head = 0;
//		tail = 0;
//	}
//	~List()
//	{
//		while (head)
//		{
//			DeleteAtStart();
//		}
//	}
//	void InsertAtStart(T& d)
//	{
//		Node* temp = new Node;
//		temp->data = d;
//		temp->next = head;
//		if (head == 0)
//		{
//			head = tail = temp;
//		}
//		else
//		{
//			head = temp;
//		}
//	}
//	void insertAtEnd(T& d)
//	{
//		if (head == 0)
//		{
//			InsertAtStart(d);
//		}
//		else
//		{
//			Node* temp = new Node;
//			temp->data = d;
//			temp->next = 0;
//			tail->next = temp;
//
//			tail = temp;
//		}
//	}
//	void Print()const
//	{
//		Node* curr = head;
//		while (curr != 0)
//		{
//			cout << curr->data << endl;
//			curr = curr->next;
//		}
//		cout << endl;
//	}
//	void InsertSorted(T d)
//	{
//		Node* curr = head;
//		if (head == 0)
//		{
//			InsertAtStart(d);
//		}
//
//		else if (d < head->data)
//		{
//			InsertAtStart(d);
//		}
//		else if (d > tail->data)
//		{
//			insertAtEnd(d);
//		}
//		else if (head != 0)
//		{
//			while (curr != 0)
//			{
//				if ((d > curr->data && d < curr->next->data) || d == curr->data)
//				{
//					Node* temp = new Node;
//					temp->next = curr->next;
//					curr->next = temp;
//					temp->data = d;
//					break;
//				}
//				curr = curr->next;
//			}
//		}
//	}
//	void DeleteAtStart()
//	{
//		if (head != 0)
//		{
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//		}
//		if (head == 0)
//		{
//			tail = 0;
//		}
//	}
//	void DeleteAtEnd()
//	{
//		if (head != 0)
//		{
//			if (head == tail)
//			{
//				delete head;
//				head = tail = 0;
//			}
//			else
//			{
//				Node* temp = head;
//				while (temp->next != tail)
//				{
//					temp = temp->next;
//				}
//				delete tail;
//				tail = temp;
//				tail->next = 0;
//			}
//		}
//	}
//	void DeleteElement(T* element)
//	{
//		Node* curr = head;
//		if (element == &(head->data))
//		{
//			DeleteAtStart();
//		}
//		else if (element == &(tail->data))
//		{
//			DeleteAtEnd();
//		}
//		else
//		{
//			while (curr->next != 0)
//			{
//				if (&(curr->next->data) == element)
//				{
//					Node* temp = curr->next;
//					curr->next = temp->next;
//					delete temp;
//					break;
//				}
//				curr = curr->next;
//			}
//		}
//	}
//};
//class Programs
//{
//private:
//	friend ostream& operator<<(ostream& out, const Programs& rhs);
//	char* ID;
//	int size;
//	List<Block>* blocks;
//public:
//	Programs(const char* id)
//	{
//		ID = Helper::GetStringFromBuffer(id);
//		size = 0;
//		blocks = 0;
//	}
//	Programs()
//	{
//		ID = 0;
//		size = 0;
//		blocks = 0;
//	}
//	~Programs()
//	{
//		delete[]ID;
//		size = 0;
//		delete blocks;
//	}
//	bool operator==(const char* id)
//	{
//		if (Helper::CompareStrings(ID, id))
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	void AllocateMemory(int byteStart, int s)
//	{
//		if (blocks == 0)
//		{
//			blocks = new List<Block>;
//			Block temp(byteStart, s);
//			size = size + s;
//			blocks->insertAtEnd(temp);
//		}
//		else
//		{
//			Block temp(byteStart, s);
//			size = size + s;
//			blocks->insertAtEnd(temp);
//		}
//	}
//	List<Block>* GetBlocks()
//	{
//		return blocks;
//	}
//};
//ostream& operator<<(ostream& out, const Programs& rhs)
//{
//	out << "ID     : " << rhs.ID << endl;
//	out << "Memory : " << rhs.size << endl;
//	rhs.blocks->Print();
//	return out;
//}
//class MemoryManagement
//{
//private:
//	List<Block>* pool;
//	List<Programs>* progs;
//	int sizeOfMemory;
//	bool strategy;
//public:
//	MemoryManagement(int size, bool strat)
//	{
//		sizeOfMemory = size;
//		strategy = strat;
//		pool = new List<Block>;
//		progs = 0;
//		Block init(0, sizeOfMemory);
//		pool->InsertAtStart(init);
//		pool->Print();
//	}
//	void MergeBlocks(List<Block>* pool, List<Block>* progBlocks)
//	{
//		//Takes blocks from program's block list and  move it back to pool
//		List<Block>::Iterator poolIt;
//		List<Block>::Iterator progBlockIt;
//		for (progBlockIt = progBlocks->Begin(); progBlockIt.GetCurrent() != 0; ++progBlockIt)
//		{
//			pool->InsertSorted(*(*progBlockIt));
//		}
//		int count = 1;
//
//		while (count != 0)
//		{
//			count = 0;
//			poolIt = pool->Begin();
//			for (poolIt = pool->Begin(); poolIt.GetNext() != 0;)
//			{
//				if (((*poolIt)->GetByteID() + (*poolIt)->GetTotalBytes()) == (poolIt.GetNext()->data).GetByteID())
//				{
//					(*poolIt)->SetTotalBytes((*poolIt)->GetTotalBytes() + (poolIt.GetNext()->data).GetTotalBytes());
//					pool->DeleteElement(&(poolIt.GetNext()->data));
//					count++;
//				}
//				++poolIt;
//				if (poolIt.GetCurrent() == 0)
//				{
//					break;
//				}
//			}
//		}
//	}
//	Programs* SearchProgramByID(const char* ID)
//	{
//		List<Programs>::Iterator it;
//		for (it = progs->Begin(); it.GetCurrent() != 0; ++it)
//		{
//			if (*(*it) == ID)
//			{
//				return *(it);
//			}
//		}
//	}
//	Block* SearchForBestFit(int size)
//	{
//		//return the block with minimum diff between Req mem and byte size
//		Block* tempo = 0;
//		List<Block>::Iterator it = pool->Begin();
//		int minDiff = sizeOfMemory;
//		for (it = pool->Begin(); it.GetCurrent() != 0; ++it)
//		{
//			if (size <= (*(*it)).GetTotalBytes() && (*(*it)).GetTotalBytes() - size < minDiff)
//			{
//				minDiff = (*(*it)).GetTotalBytes() - size;
//				tempo = (*it);
//			}
//		}
//
//		return tempo;
//	}
//	Block* SearchForFirstFit(int size)
//	{
//		//returns first block whose byte size is greater than or equal to required memory
//		Block* tempo = 0;
//		List<Block>::Iterator it = pool->Begin();
//		for (it = pool->Begin(); it.GetCurrent() != 0; ++it)
//		{
//			if (size <= (*(*it)).GetTotalBytes())
//			{
//				tempo = *it;
//				return tempo;
//			}
//		}
//		return tempo;
//	}
//	void GetMem(const char* ID, int size)
//	{
//		Block* tempo = 0;
//		//if the prog pointer is empty then a list is created
//		if (progs == 0)
//		{
//			progs = new List<Programs>;
//		}
//
//		if (strategy == 0)
//		{
//			tempo = SearchForBestFit(size);
//		}
//		if (strategy == 1)
//		{
//			tempo = SearchForFirstFit(size);
//		}
//		if (tempo != 0)
//		{
//			//if tempo is not 0 it means some block has been found that can give the required memory to program
//			if (progs != 0)
//			{
//				//The id of proram will be compared with the ids of available programs in progList
//				Programs* temp = SearchProgramByID(ID);
//				//if program is found
//				if (temp != 0)
//				{
//					temp->AllocateMemory(tempo->GetByteID(), size);
//					//if the block offering memory has byte size greater than the ReqMemory then
//					//the block's byte size will be altered
//					//the block's start ID will be altered
//					if (tempo->GetTotalBytes() > size)
//					{
//						tempo->SetByteID(tempo->GetByteID() + size);
//						tempo->SetTotalBytes(tempo->GetTotalBytes() - size);
//					}
//					//if the block offering memory has byte size equal to the ReqMemory
//					//then the block will be delete from the pool
//					else
//					{
//						pool->DeleteElement(tempo);
//					}
//				}
//				//if program is not found
//				else
//				{
//					Programs* temp = new Programs(ID);
//					progs->insertAtEnd(*temp);
//					temp = SearchProgramByID(ID);
//					temp->AllocateMemory(tempo->GetByteID(), size);
//					if (tempo->GetTotalBytes() > size)
//					{
//						tempo->SetByteID(tempo->GetByteID() + size);
//						tempo->SetTotalBytes(tempo->GetTotalBytes() - size);
//					}
//					else
//					{
//						pool->DeleteElement(tempo);
//					}
//				}
//			}
//		}
//		//if there's no block available to offer required memory
//		else
//		{
//			cout << "Memory for " << ID << " program not available " << endl;
//		}
//	}
//	void DeleteProgram(const char* ID)
//	{
//		//this function deletes the program whos Id is mentioned (if it is found)
//		Programs* temp = SearchProgramByID(ID);
//		if (temp != 0)
//		{
//			//once a program is deleted the allocated memory should be returned to the pool
//			List<Block>* temp1 = temp->GetBlocks();
//			MergeBlocks(pool, temp1);
//			progs->DeleteElement(temp);
//		}
//		else
//		{
//			cout << ID << " cannot be deleted as it doesn't exist in programs list " << endl;
//		}
//	}
//	void run()
//	{
//		//you can hard code operations here
//		GetMem("P1", 40);
//		GetMem("P2", 30);
//		GetMem("P1", 20);
//		GetMem("P3", 30);
//		GetMem("P1", 200);
//		GetMem("P2", 100);
//		GetMem("P4", 30);
//		GetMem("P3", 50);
//		GetMem("P4", 100);
//		GetMem("P3", 200);
//		GetMem("P4", 150);
//		GetMem("P3", 30);
//		GetMem("P4", 400);
//		GetMem("Some Dummy Program not mentioned in prog list", 2180);
//		GetMem("P4", 250);
//		GetMem("Some Dummy Program not mentioned in prog list", 190);
//		DeleteProgram("P4");
//		/*GetMem("P4", 200);*/
//		/*DeleteProgram("P3");*/
//		pool->Print();
//		progs->Print();
//	}
//	~MemoryManagement()
//	{
//		delete pool;
//		delete progs;
//		pool = 0;
//		progs = 0;
//	}
//};
//int main()
//
//{
//	cout << "                                              Memory Management System                    " << endl << endl;
//	int size;
//	bool opt;
//	cout << "Enter the amount of memory required (in bytes) ";
//	cin >> size;
//	cout << "Enter the method you want to use in system BestFit(0) or FirstFit(1) ";
//	cin >> opt;
//	MemoryManagement memory(size, opt);
//	memory.run();
//}