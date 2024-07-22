//#include<iostream>
//using namespace std;
//
//template<typename T>
//class List
//{
//private:
//	class Node
//	{
//	public:
//		T data;
//		Node* next;
//		Node()
//		{
//			next = nullptr;
//		}
//		Node(const T& obj, Node* nptr = nullptr) // parameterized constructor
//		{
//			data = obj;
//			next = nptr;
//		}
//	};
//	Node* head;
//	Node* tail;
//	int size;
//public:
//	List()
//	{
//		head = tail = nullptr;
//		size = 0;
//	}
//
//	void print()
//	{
//		Node* curr = head;
//		while (curr != nullptr)
//		{
//			cout << curr->data;
//			curr = curr->next;
//		}
//	}
//
//	bool isEmpty()
//	{
//		return size == 0;
//	}
//
//	class Iterator
//	{
//		friend class List<T>;
//	private:
//		Node* curr;
//	public:
//		Iterator()
//		{
//			curr = nullptr;
//		}
//
//		T& operator*()
//		{
//			return curr->data;
//		}
//
//		Iterator& operator++(int) //post increment
//		{
//			Iterator temp = *this;
//			curr = curr->next;
//			return temp;
//		}
//
//		bool operator!=(Iterator obj)
//		{
//			return curr != obj.curr;
//		}
//
//		bool operator==(Iterator obj)
//		{
//			return curr == obj.curr;
//		}
//	};
//
//	Iterator& begin() // returns Iterator pointing to head 
//	{
//		Iterator temp;
//		temp.curr = head;
//		return temp;
//	}
//
//	Iterator& end() // returns iterator pointing to null
//	{
//		Iterator temp;
//		temp.curr = tail->next;
//		return temp;
//	}
//
//	void insertAtTail(const T& element)
//	{
//		if (!isEmpty())
//		{
//			tail->next = new Node(element);
//			tail = tail->next;
//			size++;
//		}
//		else
//		{
//			head = new Node(element);
//			tail = head;
//			size++;
//		}
//	}
//
//	void insertInOrder(const T& element) //sorted insertion
//	{
//		if (isEmpty())
//		{
//			head = new Node(element);
//			tail = head;
//			size++;
//		}
//		else
//		{
//			Node* nNode = new Node(element); //creating the node to be inserted
//			Node* curr = head;
//			Node* prev = nullptr;
//			bool insert = false;
//			while (curr != nullptr)
//			{
//				if (curr->data >= element)
//				{
//					nNode->next = curr;
//					if (prev != nullptr)  // multiple nodes in the list
//						prev->next = nNode;
//					else // 1 element in the list
//						head = nNode;
//					insert = true;
//					size++;
//					break;
//				}
//				prev = curr;
//				curr = curr->next;
//			}
//			if (insert == false) //Element is largest so its inserted at end
//			{
//				tail->next = nNode;
//				tail = tail->next;
//				size++;
//			}
//		}
//	}
//
//	void deleteAtStart()
//	{
//		if (isEmpty())
//		{
//			return;
//		}
//		else
//		{
//			Node* temp = head->next;
//			delete head;
//			head = temp;
//			if (temp == nullptr)
//				tail = head;
//			size--;
//		}
//	}
//
//	void deleteInMiddle(const T& element)
//	{
//		Node* curr = head;
//		Node* prev = nullptr;
//		int i = 0;
//		while (curr->data != element && curr != nullptr)
//		{
//			prev = curr;
//			curr = curr->next;
//		}
//		if (curr == nullptr) // list completely traversed
//		{
//			if (head == nullptr)
//			{
//				cout << "List is empty" << endl;
//			}
//			else
//			{
//				cout << "Element is not present in the list" << endl;
//			}
//		}
//		else
//		{
//			if (curr == head)
//			{
//				deleteAtStart();
//			}
//			else
//			{
//				prev->next = curr->next;
//				if (curr == tail)
//					tail = prev;
//				delete curr;
//				size--;
//			}
//		}
//	}
//
//	int getSize()
//	{
//		return size;
//	}
//};
//
//class Block
//{
//private:
//	int start_byte_id;
//	int total_bytes;
//public:
//	Block(int id = 0, int total = 0)
//	{
//		start_byte_id = id;
//		total_bytes = total;
//	}
//
//	friend ostream& operator<<(ostream& out, const Block& obj)
//	{
//		cout << "[" << obj.start_byte_id << " ";
//		cout << obj.total_bytes << "] ";
//		return out;
//	}
//
//	bool operator>=(int memory)
//	{
//		if (total_bytes >= memory)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	bool operator<=(const Block& obj)
//	{
//		return total_bytes <= obj.total_bytes;
//	}
//
//	bool operator>=(const Block& obj)
//	{
//		return start_byte_id >= obj.start_byte_id;
//	}
//
//	bool operator!=(const Block& obj)
//	{
//		return start_byte_id != obj.start_byte_id;
//	}
//
//	int getId()
//	{
//		return start_byte_id;
//	}
//
//	int getBytes()
//	{
//		return total_bytes;
//	}
//
//	void setStartByte(int value)
//	{
//		start_byte_id = value;
//	}
//
//	void setBytes(int value)
//	{
//		total_bytes = value;
//	}
//};
//
//class Program
//{
//	friend class MemoryManagementSystem;
//private:
//	int id;
//	int size;
//	List<Block>blocks;
//public:
//	Program(int i = 0, int s = 0)
//	{
//		id = i;
//		size = s;
//	}
//
//	bool operator==(int ID)
//	{
//		return id == ID;
//	}
//
//	bool operator!=(const Program& obj)
//	{
//		return id != obj.id;
//	}
//
//	friend ostream& operator<<(ostream& out, const Program& obj)
//	{
//		cout << "P" << obj.id << " " << obj.size;
//		return out;
//	}
//
//	void setSize(int s)
//	{
//		size += s;
//	}
//};
//
//class MemoryManagementSystem
//{
//private:
//	List<Block>pool;
//	List<Program>Progs;
//	int sizeOfMemory;
//	bool strategy;
//public:
//	MemoryManagementSystem(int s = 0, bool choice = 0)
//	{
//		sizeOfMemory = s;
//		strategy = choice;
//		Block b1(0, s); // initiallizing pool with 1 node
//		pool.insertAtTail(b1);
//	}
//
//	void merge() // To merge blocks in pool
//	{
//		List<Block>::Iterator poolIter = pool.begin(), tempIter;
//		tempIter = poolIter;
//		while (tempIter != pool.end())
//		{
//			int prev = 0;
//			int next = 0;
//			prev = (*poolIter).getId() + (*poolIter).getBytes(); //startingID + totalBytes
//			tempIter++;
//			if (tempIter != pool.end())
//			{
//				next = (*tempIter).getId();
//				if (prev == next) //Two contiguous blocks found
//				{
//					(*tempIter).setStartByte((*poolIter).getId());
//					(*tempIter).setBytes((*tempIter).getBytes() + (*poolIter).getBytes());
//					pool.deleteInMiddle(*poolIter);
//				}
//			}
//			poolIter = tempIter;
//		}
//	}
//
//	void createProgram(int pID, int som, List<Block>::Iterator it2)
//	{
//		Block b1((*it2).getId(), som);
//		Program newP(pID, som);
//		newP.blocks.insertAtTail(b1); // adding the new program to Progs
//		Progs.insertAtTail(newP);
//		(*it2).setStartByte((*it2).getId() + som); // updating pool 
//		(*it2).setBytes((*it2).getBytes() - som);
//	}
//
//	void updateProgram(int mem, List<Program>::Iterator it1, List<Block>::Iterator it2)
//	{
//		Block b1((*it2).getId(), mem); // inserting new block in blocks list of program
//		(*it1).blocks.insertAtTail(b1);
//		(*it1).size += mem;
//		(*it2).setStartByte((*it2).getId() + mem);
//		(*it2).setBytes((*it2).getBytes() - mem);
//	}
//
//	bool findProgram(List<Program>::Iterator& it, int id)
//	{
//		for (; it != Progs.end(); it++) //traversing progs list
//		{
//			if (*it == id) // comparing ids
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//
//	void firstFit(int pID, int som)
//	{
//		List<Block>::Iterator pIter = pool.begin(); //to iterate pool list
//		List<Program>::Iterator bIter = Progs.begin(); // to iterate Progs list
//		for (; pIter != pool.end(); pIter++)
//		{
//			if (*pIter >= som) // memory avaliable
//			{
//				if (Progs.isEmpty())
//				{
//					createProgram(pID, som, pIter); // insert new program in progs
//				}
//				else // checking if required program is avaliable in Progs or not
//				{
//					bool found = findProgram(bIter, pID);
//					if (found == true)
//					{
//						updateProgram(som, bIter, pIter);
//					}
//					else
//					{
//						createProgram(pID, som, pIter);
//					}
//					break;
//				}
//			}
//
//		}
//	}
//
//	void bestFit(int pID, int som)
//	{
//		List<Block>::Iterator pIter = pool.begin(); // pool iterator
//		List<Program>::Iterator bIter = Progs.begin(); // to iterate Progs List
//		List<Block>::Iterator temp; // to store iterator pointing to block with minimum bytes
//		int min = som;
//		temp = pIter;
//		for (; pIter != pool.end(); pIter++)
//		{
//			if ((*pIter).getBytes() <= min && (*pIter).getBytes() >= som)
//			{
//				min = (*pIter).getBytes();
//				temp = pIter;
//			}
//		}
//		if (*temp >= som)
//		{
//			Block b1((*temp).getId(), som);
//			if (Progs.isEmpty())
//			{
//				createProgram(pID, som, temp);
//			}
//			else
//			{
//				bool found = findProgram(bIter, pID);
//				if (found == true)
//				{
//					updateProgram(som, bIter, temp);
//				}
//				else
//				{
//					createProgram(pID, som, temp);
//				}
//			}
//		}
//	}
//
//	void getMem(int pID, int som)
//	{
//		List<Block>::Iterator pIter = pool.begin(); //to iterate pool list
//		List<Program>::Iterator bIter = Progs.begin();	// to iterate Progs list
//		if (strategy == 0)
//		{
//			firstFit(pID, som);
//		}
//		else if (strategy == 1)
//		{
//			bestFit(pID, som);
//		}
//	}
//
//	void deleteProgram(int Pid)
//	{
//		List<Program>::Iterator pIter = Progs.begin();
//		bool found = findProgram(pIter, Pid);
//		if (found == true)
//		{
//			List<Block>::Iterator bIter = (*pIter).blocks.begin(); //bIter pointing to list
//			while (bIter != (*pIter).blocks.end())                 //of blocks in the found
//			{                                                      //program
//				pool.insertInOrder(*bIter);
//				bIter++;
//			}
//			bIter = (*pIter).blocks.begin();
//			int size = (*pIter).blocks.getSize();
//			for (int i = 0; i < size; i++)
//				(*pIter).blocks.deleteAtStart();
//			Progs.deleteInMiddle(*pIter);
//		}
//		else
//		{
//			cout << "Program not found" << endl;
//		}
//		merge(); // to merge contiguous blocks in pool
//	}
//
//	void printProgram()
//	{
//		List<Program>::Iterator iter = Progs.begin();
//		if (!Progs.isEmpty())
//		{
//			while (iter != Progs.end())
//			{
//				cout << *iter << " : ";
//				(*iter).blocks.print();
//				cout << endl;
//				iter++;
//			}
//		}
//	}
//
//	void printPool()
//	{
//		List<Block>::Iterator it = pool.begin();
//		while (it != pool.end())
//		{
//			cout << *it;
//			it++;
//		}
//	}
//};
//
//int main()
//{
//	MemoryManagementSystem m1(100000, 0);
//	cout << "Pool : ";
//	m1.printPool();
//	cout << endl;
//	m1.getMem(1, 40);
//	m1.getMem(2, 30);
//	m1.getMem(1, 20);
//	m1.getMem(3, 40);
//	m1.getMem(4, 30);
//	m1.getMem(5, 20);
//	m1.getMem(6, 40);
//	m1.getMem(5, 30);
//	m1.getMem(4, 20);
//	m1.deleteProgram(2);
//	m1.deleteProgram(5);
//	m1.getMem(1, 20);
//	m1.deleteProgram(1);
//	m1.printProgram();
//	cout << endl;
//	cout << "Pool : ";
//	m1.printPool();
//	system("pause");
//	//cout << endl;
//}