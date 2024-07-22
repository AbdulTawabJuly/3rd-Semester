#include<iostream>
#include<string>
using namespace std;

class Helper
{
public:
	static int stringLength(char* str)
	{
		int i = 0;                               // This function  return lenght of str
		while (str[i] != '\0')
		{
			i++;
		}
		return i;
	}
	static void stringCopy(char*& str1, char*& str2)
	{
		int L = stringLength(str2);
		int i = 0;
		for (i = 0; i < L; i++)
		{
			str1[i] = str2[i];                     //Deep Copies srtr2 into str1.
		}
	}


	static char* GetStringFromBuffer(char* str)
	{
		int L = stringLength(str);//This function  allocate required memory on heap
		L = L + 1;
		char* string = new char[L];
		for (int i = 0; i < L; i++)
		{
			string[i] = '\0';
		}
		stringCopy(string, str);
		return string;
	}
	static int compareString(char* string1, char* string2)
	{

		int size = stringLength(string1);
		int size2 = stringLength(string2);
		int max = 0;
		if (size > size2)
		{
			max = size;
		}
		else
		{
			max = size2;
		}
		int a = 0;
		while (a < max)
		{

			if (string1[a] != string2[a])
			{
				return 0;
			}
			else
			{
				a++;
			}
		}
		return 1;
	}

};
class Program;
class Block
{
	friend ostream& operator<<(ostream&, Block);

	int start_byte_ID;
	int total_bytes;
public:
	Block()
	{

	}
	Block(int ID, int t_bytes)
	{
		start_byte_ID = ID;
		total_bytes = t_bytes;
	}
	void setstartID(int i)                      //set id and total bytes according to given requirment. 
	{
		start_byte_ID = i;
	}
	void settotalbytes(int b)
	{
		total_bytes = b;
	}
	int getstartID()
	{
		return start_byte_ID;
	}
	int gettotalbytes()
	{
		return total_bytes;
	}
	bool operator >=(int size)
	{                               //check total bytes and size and return true if tota bytes greater than size. 
		if (total_bytes >= size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};
ostream& operator<<(ostream& out, Block b)
{//overload operator of cout.
	cout << "Start Byte ID : ";
	out << b.start_byte_ID;
	cout << endl;
	cout << "  Total Bytes : ";
	out << b.total_bytes;
	cout << endl;
	return out;
}
template<class T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node()
		{

		}
	};

	Node* head;
	Node* tail;

public:


	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	void insertatstart(T d)
	{
		Node* temp = new Node;
		temp->data = d;
		temp->next = head;

		if (head == NULL)
		{
			head = tail = temp;
		}
		else
			head = temp;
	}
	void insertatend(T d)
	{
		if (head == NULL)
		{//if there is noi element in list then same logic of insertatstart.
			insertatstart(d);
		}
		else
		{
			Node* temp = new Node;
			temp->data = d;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}
	}
	void Print()
	{
		Node* current = head;      //make a temporay node and traverse the whole list and print tha data of the node.
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	bool Search(T d)
	{//traverse the list and if given data is present at node then give true.
		Node* curr = head;
		while (curr != NULL)
		{
			if (curr->data = d)
			{

				return true;
			}
			curr = curr->next;
		}

		return false;
	}
	void DeleteAtStart()
	{
		if (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		if (head == NULL)
		{
			tail = NULL;
		}

	}
	void deleteAtEnd()
	{
		if (head != nullptr)
		{
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
	}
	bool isEmpty()
	{
		if (head == NULL)
		{
			return 1;
		}
		else
			return 0;
	}
	Program* seachProgramById(char* id)
	{                    //traverse the list and compare the current id with given id and if program id is present then return true.
		Node* current = head;
		while (current != NULL)
		{
			if (Helper::compareString((current->data).getID(), id))
			{
				return &(current->data);
			}
			current = current->next;
		}
		return 0;
	}
	Block* searchFirstFit(int s)
	{          //made the node and put that on the start of list of block and put untill
		//null is not come.
		Node* current = head;
		while (current != NULL)
		{
			if (current->data >= s)
			{
				return &(current->data);
			}
			current = current->next;
		}
		return 0;
	}
	//Block* SearchBestFit(int s)
	//{                     //made the node and search for the minimum space in the list if there is minimum space sccording to the requirement then return thata space.
	//	Node* current = head;
	//	int temp=10000000;
	//	Block* ptr = 0;
	//	while (current != NULL)
	//	{
	//		if (((current->data).gettotalbytes() - s) < temp)
	//		{
	//			temp =  current->data - s;
	//			 ptr = &current->data;
	//		}
	//		current = current->next;

	//	}
	//	return ptr;
	//}
};

class Program
{
	friend ostream& operator<<(ostream&, Program);
	char* ID;
	int Size;
	List<Block> block;
public:
	Program()
	{
		ID = NULL;
		Size = 0;
	}
	Program(char* i)//setter and getters of program id and size.
	{
		ID = Helper::GetStringFromBuffer(i);
	}
	char setID(char* i)
	{
		ID = Helper::GetStringFromBuffer(i);
	}
	int setSize(int s)
	{
		Size = s;
	}
	char* getID()
	{
		return ID;
	}
	int getSize()
	{
		return Size;
	}
	void allocateBlocks(Block& bl, int s)
	{
		block.insertatend(bl);       //insert block accoridng at the end of the list of block.and increase the size of list when block insert.
		Size = Size + s;
	}

};
ostream& operator<<(ostream& out, Program p)
{      //overload operator of cout.
	cout << "program id : ";
	out << p.ID;
	cout << endl;
	cout << " P Size : ";
	out << p.Size;
	cout << endl;

	p.block.Print();
	return out;
}
class MemoryManagementSystem
{
private:
	List<Block> pool;
	List<Program> progs;
	int sizeOfMemory;
	bool strategy;
public:
	MemoryManagementSystem(int s, bool str)
	{
		sizeOfMemory = s;
		strategy = str;
		Block pl(0, sizeOfMemory);
		pool.insertatend(pl);
	}
	void GetMem(char* ID, int size)
	{
		Program* ptr = progs.seachProgramById(ID);
		Block* ptr1 = 0;
		if (strategy == 0)
		{//if strategy is zero then serach pool of first  fit in the list .
			ptr1 = pool.searchFirstFit(size);

		}
		//if (strategy == 1)
		//{//if strategy is one then  search pool best fit.
		//	 ptr1 = pool.SearchBestFit(size);
		//}
		if (ptr == NULL)
		{

			int t_bytes = ptr1->gettotalbytes();//total bytes of block
			int startID = ptr1->getstartID();//starting id of block.
			Program temp(ID);
			progs.insertatend(temp);//insert id at the end .
			Program* ptr2 = progs.seachProgramById(ID);//
			Block temp1(startID, size);
			if (t_bytes > size)
			{
				ptr1->setstartID(startID + size);//when total bytes grater then size then set id with adding the size.
				ptr1->settotalbytes(t_bytes - size);//and same with as with total bytes.
			}

			ptr2->allocateBlocks(temp1, size);//allocate memory of block to the program.

		}
		else
		{
			int t_bytes = ptr1->gettotalbytes();
			int startID = ptr1->getstartID();

			Block temp1(startID, size);
			if (t_bytes > size)
			{
				ptr1->setstartID(startID + size);
				ptr1->settotalbytes(t_bytes - size);
			}

			ptr->allocateBlocks(temp1, size);

		}

	}
	void menu()
	{
		char arr[10] = "P1";
		char arr1[10] = "P2";
		char arr2[10] = "P3";
		char arr3[10] = "P4";
		GetMem(arr, 40);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr1, 30);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr, 20);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr2, 30);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr, 200);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr3, 30);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr2, 50);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr3, 100);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr2, 200);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr3, 150);
		pool.Print();
		progs.Print();
		cout << endl;


		GetMem(arr2, 30);
		pool.Print();
		progs.Print();
		cout << endl;

		GetMem(arr3, 400);
		pool.Print();
		progs.Print();
		cout << endl;
	}
};

int main()
{
	cout << "-------------------Memory Management System-----------------------------" << endl;
	MemoryManagementSystem M(10000, 0);//0 for first fit and 1 for best fit.

	M.menu();
	system("pause");
	return 0;
}