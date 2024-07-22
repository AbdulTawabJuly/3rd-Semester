//#include<iostream>
//#include<Windows.h>
//#include<string>
//using namespace std;
//int MaxofTwo(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//class BookData;
//class Index;
//template<class T>
//class DList
//{
//private:
//	class DNode
//	{
//	public:
//		T data;
//		DNode* next;
//		DNode* prev;
//		DNode()
//		{
//			next = prev = nullptr;
//		}
//	};
//	DNode* head;
//	DNode* tail;
//	int size;
//public:
//	class Iterator
//	{
//		friend class DList<T>;
//	private:
//
//		DNode* curr;
//	public:
//		Iterator()
//		{
//			curr = nullptr;
//		}
//		Iterator(DNode* t)
//		{
//			curr = t;
//		}
//		Iterator& operator++(int) 
//		{
//			Iterator temp = *this;
//			curr = curr->next;
//			return temp;
//		}
//		Iterator& operator++()
//		{
//			curr = curr->next;
//			return *this;
//		}
//		Iterator& operator--()
//		{
//			curr = curr->prev;
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
//			else 
//			{ 
//				return false; 
//			}
//		}
//		Iterator& operator=(Iterator temp)
//		{
//			curr = temp.curr;
//			return *this;
//		}
//		Iterator& SetTitle(string tit)
//		{
//			curr->data = tit;
//			return *this;
//		}
//		Iterator& SetRefNo(int Ref)
//		{
//			curr->data = Ref;
//			return *this;
//		}
//		Iterator& SetAvailNo(int Avail)
//		{
//			curr->data /= Avail;
//			return *this;
//		}
//		Iterator& AddAuthors(char* newlist)
//		{
//			curr->data = newlist;
//			return *this;
//		}
//		Iterator& DeleteAuthors(int i)
//		{
//			curr->data - i;
//			return *this;
//
//		}
//		Iterator& operator=(DNode* temp)
//		{
//			curr = temp;
//			return *this;
//		}
//		void SetIterator(Iterator obj)
//		{
//			curr = obj.curr;
//		}
//		void SetIteratorwithNode(DNode* temp)
//		{
//			curr = temp;
//		}
//		friend ostream& operator<<(ostream& out, Iterator& it)
//		{
//			out << it.curr->data;
//			return out;
//		}
//		DNode* GetCurrent()
//		{
//			return curr;
//		}
//		DNode* GetNext()
//		{
//			return curr->next;
//		}
//	};
//	Iterator Begin()
//	{
//		Iterator it;
//		it.curr = head->next;
//		return it;
//	}
//	Iterator End()
//	{
//		Iterator it;
//		it.curr = tail->prev;
//		return it;
//	}
//	Iterator& InsertBefore(Iterator it, T d)  // Insertion Before with the help of iterator
//	{
//		DList<BookData>::Iterator temporary;
//		DNode* t = it.curr;
//		DNode* temp = new DNode;
//		temp->data = d;
//		temp->next = t;
//		temp->prev = t->prev;
//		t->prev->next = temp;
//		t->prev = temp;
//		temporary.curr = temp;
//		return temporary;
//	}
//	Iterator& InsertAfter(Iterator it, T d)  // Insertion After with the help of iterator
//	{
//		DList<BookData>::Iterator temporary;
//		DNode* t = it.curr;
//		DNode* temp = new DNode;
//		temp->data = d;
//		temp->next = t->next;
//		temp->prev = t;
//		t->next->prev = temp;
//		t->next = temp;
//		temporary.curr = temp;
//		return temporary;
//	}
//	Iterator& CheckandInsert(T d, Iterator it)  // This Checks wheather to Insert before or after the given Iterator
//	{
//		if (d >= it.curr->data)
//		{
//			return InsertAfter(it, d);
//		}
//		else
//		{
//			return InsertBefore(it, d);
//		}
//	}
//	Iterator Remove(Iterator it)  // This Removes the Node with the help of the given iterator
//	{
//		DNode* t = it.curr;
//		t->prev->next = t->next;
//		t->next->prev = t->prev;
//		Iterator ite(t->next);
//		delete t;
//		return ite;
//	}
//	DList()
//	{
//		head = new DNode;
//		tail = new DNode;
//		size = 0;
//		head->next = tail;
//		head->prev = nullptr;
//		tail->next = nullptr;
//		tail->prev = head;
//	}
//	void InsertatStart(T d)
//	{
//		DNode* temp = new DNode;
//		temp->data = d;
//		temp->prev = head;
//		temp->next = head->next;
//		head->next->prev = temp;
//		head->next = temp;
//		size++;
//	}
//	void InsertatEnd(T d)
//	{
//		DNode* temp = new DNode;
//		temp->data = d;
//		temp->next = tail;
//		temp->prev = tail->prev;
//		tail->prev->next = temp;
//		tail->prev = temp;
//		size++;
//	}
//	DList& operator=(DList& obj)   // Assignment operator of DList
//	{
//		this->size = obj.size;
//		DNode* temp = obj.head->next;
//		while (temp->next != nullptr)
//		{
//			InsertatEnd(temp->data);
//			temp = temp->next;
//		}
//		return *this;
//	}
//	void Print()
//	{
//		if (head == nullptr)
//		{
//			cout << " There is No Author of the Book" << endl;
//		}
//		else
//		{
//			DNode* temp;
//			temp = head->next;
//			while (temp != tail)
//			{
//				cout << temp->data << " ";
//				temp = temp->next;
//			}
//		}
//	}
//	void DeleteatStart()
//	{
//		DNode* temp = head->next;
//		head->next->prev = head;
//		head->next = temp->next;
//		delete temp;
//	}
//	void DeleteatEnd()
//	{
//		DNode* temp = tail->prev;
//		temp->prev->next = tail;
//		tail->prev = temp->prev;
//		delete temp;
//	}
//	int GetLLSize()
//	{
//		return size;
//	}
//	Iterator GetOnlyElement()
//	{
//		Iterator temp = this->Begin();
//		return temp;
//	}
//	/*~DList()
//	{
//		while (head->next != tail)
//		{
//			DeleteatStart();
//		}
//	}*/
//};
//class Iterator;
//class BookData
//{ 
//	// Most of the Functions of this class is either getter or setter or overloaded operator
//	// These operators dont need to be explained as they are very small
//	// User can Differentiate between them easily
//private:
//	int ISSN;
//	string Title;
//	int RefBooks;
//	int Available;
//	DList<char*>Authors;
//public:
//	BookData()
//	{
//		ISSN = 0;
//		Title.clear();
//		RefBooks = 0;
//		Available = 0;
//	}
//	BookData(int issn, string title, int ref, int avail, int noofaut, char** arr)
//	{
//		ISSN = issn;
//		Title = title;
//		RefBooks = ref;
//		Available = avail;
//		for (int i = 0; i < noofaut; i++)
//		{
//			Authors.InsertatEnd(arr[i]);
//		}
//
//	}
//	BookData& operator=(BookData& obj)
//	{
//		ISSN = obj.ISSN;
//		Title = obj.Title;
//		RefBooks = obj.RefBooks;
//		Available = obj.Available;
//		Authors = obj.Authors;
//		return *this;
//	}
//	BookData& operator=(string tit)
//	{
//		Title = tit;
//		return *this;
//	}
//	BookData& operator=(int Ref)
//	{
//		RefBooks = Ref;
//		return *this;
//	}
//	BookData& operator/=(int Avail)
//	{
//		Available = Avail;
//		return *this;
//	}
//	BookData& operator= (char* AddAuthors)
//	{
//		Authors.InsertatEnd(AddAuthors);
//		return *this;
//	}
//	BookData& operator-(int entries)
//	{
//		while (entries != 0)
//		{
//			Authors.DeleteatEnd();
//			entries--;
//		}
//		return *this;
//	}
//	int GetISSN()
//	{
//		return ISSN;
//	}
//	bool operator==(int No)
//	{
//		if (this->ISSN == No)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool operator==(BookData& d)
//	{
//		if (this->ISSN == d.ISSN)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool operator>=(BookData& d)
//	{
//		if (this->ISSN >= d.ISSN)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool operator<=(BookData& d)
//	{
//		if (this->ISSN <= d.ISSN)
//		{
//			return true;
//		}
//		return false;
//	}
//	friend ostream& operator<<(ostream& out, BookData& obj)
//	{
//		out << "Book's ISSN : " << obj.ISSN << endl;
//		out << "Book's Tittle : " << obj.Title << endl;
//		out << "No of Reference Books : " << obj.RefBooks << endl;
//		out << "No of Available Books : " << obj.Available << endl;
//		out << "Authors Name's :  ";
//		obj.Authors.Print();
//		cout << endl;
//		return out;
//	}
//	void Print()
//	{
//		cout << "Book's ISSN : " << ISSN << endl;
//		cout << "Book's Tittle : " << Title << endl;
//		cout << "No of Reference Books : " << RefBooks << endl;
//		cout << "No of Available Books : " << Available << endl;
//		cout << "Authors Name's : ";
//		Authors.Print();
//		cout << endl;
//	}
//};
//
//class Index
//{
//	// Most of the Functions of this class is either getter or setter or overloaded operator
//	// These operators dont need to be explained as they are very small
//	// User can Differentiate between them easily
//private:
//	int ISSN;
//	DList<BookData>::Iterator Data;
//public:
//	Index()
//	{
//		ISSN = 0;
//	}
//	Index(int no, DList<BookData>::Iterator temp)
//	{
//		ISSN = no;
//		Data = temp;
//	}
//	bool operator>(Index obj)
//	{
//		if (ISSN > obj.ISSN)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	bool operator>(int Key)
//	{
//		if (ISSN > Key)
//			return true;
//		else
//			return false;
//	}
//	bool operator > (BookData obj)
//	{
//		if (ISSN > obj.GetISSN())
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	bool operator<=(BookData obj)
//	{
//		if (ISSN <= obj.GetISSN())
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	bool operator<=(int Key)
//	{
//		if (ISSN <= Key)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	bool operator<(Index obj)
//	{
//		if (ISSN < obj.ISSN)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	bool operator<(int Key)
//	{
//		if (ISSN < Key)
//			return true;
//		else
//			return false;
//	}
//	bool operator==(BookData obj)
//	{
//		if (ISSN == obj.GetISSN())
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	bool operator==(int Key)
//	{
//		if (ISSN == Key)
//			return true;
//		else
//			return false;
//	}
//	Index& operator=(Index& obj)
//	{
//		ISSN = obj.ISSN;
//		Data = obj.Data;
//		return *this;
//	}
//	DList<BookData>::Iterator GetIteratorWI()
//	{
//		return Data;
//	}
//	DList<BookData>::Iterator GetIteratorI(Index& obj)
//	{
//		return obj.Data;
//	}
//	void SetIterator(Index& obj)
//	{
//		Data = obj.Data;
//	}
//	void SetIter(DList<BookData>::Iterator obj)
//	{
//		Data = obj;
//	}
//	void SetISSN(int no)
//	{
//		ISSN = no;
//	}
//	friend ostream& operator<<(ostream& out, Index& obj)
//	{
//		out << obj.Data;
//		return out;
//	}
//};
//template<class T>
//class AVL
//{
//private:
//	class Anode
//	{
//	public:
//		T val;
//		Anode* l;
//		Anode* r;
//		int height;
//		Anode()
//		{
//			height = 0;
//			l = r = nullptr;
//		}
//	};
//	Anode* root;
//	void PrintInorder(Anode* r)  // Inoreder Treaversal (Sequential Traversal)
//	{
//		if (r == nullptr)
//			return;
//		PrintInorder(r->l);
//		cout << r->val << endl;
//		PrintInorder(r->r);
//	}
//	int getHeight(Anode* r) 
//	{
//		if (r == nullptr)
//			return -1;
//		return r->height;
//	}
//	void Delete(Anode*& r, int val)  // Delete a Node
//	{
//		if (r->val == val)
//		{
//			//Delete node based on 3 conditions
//			if (r->l == nullptr && r->r == nullptr)
//			{
//				Anode* tmp = r;
//				r = nullptr;
//				delete tmp;
//
//			}
//			else if (r->l == nullptr)
//			{
//				Anode* tmp = r;
//				r = r->r;
//				delete tmp;
//			}
//			else if (r->r == nullptr)
//			{
//				Anode* tmp = r;
//				r = r->l;
//				delete tmp;
//			}
//			else //r has two childs
//			{
//				Anode* k = r->l;
//				Anode* prev = nullptr;
//				while (k->r != nullptr)
//				{
//					prev = k;
//					k = k->r;
//				}
//				if (prev == nullptr)
//				{
//					r->l = nullptr;
//					r->val = k->val;
//					delete k;
//				}
//				else
//				{
//					r->val = k->val;
//					prev->r = nullptr;
//					delete k;
//				}
//			}
//			return;
//		}
//
//		else if (r->val < val)
//		{
//			Delete(r->r, val);
//		}
//
//		else if (r->val > val)
//		{
//			Delete(r->l, val);
//		}
//
//		r->height = 1 + MaxofTwo(getHeight(r->l), getHeight(r->r));
//		int factor = getBalance(r);
//		if (factor < -1) // right subtree is getting heavy deletion was done in left subtree
//		{
//			int k = getBalance(r->r);
//			if (k <= -1) // R->R 
//			{
//				rotateL(r);
//			}
//			else //R->L
//			{
//				rotateR(r->r);
//				rotateL(r);
//			}
//		}
//		else if (factor > 1)
//		{
//			int k = getBalance(r->l);
//			if (k >= 1) // L->L 
//			{
//				rotateR(r);
//			}
//			else //L->R
//			{
//				rotateL(r->l);
//				rotateR(r);
//			}
//		}
//	}
//	inline int getBalance(Anode* r)//r must not be null
//	{
//		int factor = getHeight(r->l) - getHeight(r->r);
//		return factor;
//	}
//	void rotateL(Anode*& r)
//	{
//		Anode* t = r->r;
//		r->r = t->l;
//		t->l = r;
//		Anode* prevR = r;
//		r = t;
//		prevR->height = 1 + MaxofTwo(getHeight(prevR->l), getHeight(prevR->r));
//		r->height = 1 + MaxofTwo(getHeight(r->l), getHeight(r->r));
//	}
//	void rotateR(Anode*& r)
//	{
//		Anode* t = r->l;
//		r->l = t->r;
//		t->r = r;
//		Anode* prevR = r;
//		r = t;
//		prevR->height = 1 + MaxofTwo(getHeight(prevR->l), getHeight(prevR->r));
//		r->height = 1 + MaxofTwo(getHeight(r->l), getHeight(r->r));
//	}
//	void balance(Anode*& r, T val)
//	{
//		int factor = getHeight(r->l) - getHeight(r->r);
//		if (factor < -1) // right subtree is getting heavy
//		{
//			if (val < r->r->val) //R->L insertion
//			{
//				rotateR(r->r);
//				rotateL(r);
//			}
//			else if (val > r->r->val) //R->R insertion
//			{
//				rotateL(r);
//			}
//		}
//		else if (factor > 1) // Left subtree is getting heavy
//		{
//			if (val < r->l->val)//L->L insertion
//			{
//				rotateR(r);
//			}
//			else if (val > r->l->val)//L->R insertion
//			{
//				rotateL(r->l);
//				rotateR(r);
//			}
//		}
//	}
//	bool Insert(Anode*& r, T d)
//	{
//		if (r == nullptr)
//		{
//			r = new Anode;
//			r->val = d;
//			r->l = nullptr;
//			r->r = nullptr;
//			return true;
//		}
//		else
//		{
//			if (d < r->val)
//			{
//				bool b = Insert(r->l, d);
//				if (b)//Balance if Insertion was Successful
//				{
//					r->height = 1 + MaxofTwo(getHeight(r->l), getHeight(r->r));
//					balance(r, d);
//				}
//				return b;
//			}
//			else if (d > r->val)
//			{
//				bool b = Insert(r->r, d);
//				if (b)
//				{
//					r->height = 1 + MaxofTwo(getHeight(r->l), getHeight(r->r));
//					balance(r, d);
//				}
//				return b;
//			}
//		}
//		return false;
//	}
//	void InsertAll(Anode* r)  // Used in Copy Constructor to Copy the whole Tree
//	{
//		if (r == nullptr)
//			return;
//		Insert(r->val);
//		InsertAll(r->l);
//		InsertAll(r->r);
//	}
//	Anode* search(Anode* r, int d)
//	{
//		if (r == nullptr)
//			return nullptr;
//		if (r->val == d)
//			return r;
//		if (r->val < d)
//			return search(r->r, d);
//		else if (r->val > d)
//			return search(r->l, d);
//		return nullptr;
//	}
//	Index& GetParentNodeForInsert(Anode* r, BookData& Child, T Parent)  // Returns Future Parent Node
//	{
//		if (r == nullptr)
//		{
//			return Parent;
//		}
//		else if (r->val > Child)
//		{
//			Parent = r->val;
//			GetParentNodeForInsert(r->l, Child, Parent);
//		}
//		else if (r->val <= Child)
//		{
//			Parent = r->val;
//			GetParentNodeForInsert(r->r, Child, Parent);
//		}
//	}
//	Index& GetParentNodeForDelete(Anode* r, int Key, T Parent)  // This Function actually returns the node given by No and not the parent Node
//	{
//		if (r->val == Key)
//		{
//			return r->val;
//		}
//		else if (r->val > Key)
//		{
//			Parent = r->val;
//			GetParentNodeForDelete(r->l, Key, Parent);
//		}
//		else if (r->val <= Key)
//		{
//			Parent = r->val;
//			GetParentNodeForDelete(r->r, Key, Parent);
//		}
//	}
//public:
//	// In Public there are only Wrapper Functions of the Original Functions
//	AVL()
//	{
//		root = nullptr;
//	}
//	AVL(const AVL& rhs)
//	{
//		root = nullptr;
//		InsertAll(rhs.root);
//	}
//	bool Insert(T d)
//	{
//		return Insert(root, d);
//	}
//	Anode* search(int key)
//	{
//		return search(root, key);
//
//	}
//	Index& GetParentNodeForInsert(BookData& d)
//	{
//		Index temp = root->val;
//		return GetParentNodeForInsert(root, d, temp);
//	}
//	Index& GetParentNodeForDelete(int Key)
//	{
//		Index temp = root->val;
//		return GetParentNodeForDelete(root, Key, temp);
//	}
//	void FreeNode(Anode* r)
//	{
//		if (r == nullptr)
//			return;
//		FreeNode(r->l);
//		FreeNode(r->r);
//		delete r;
//	}
//	void PrintInorder()
//	{
//		PrintInorder(root);
//	}
//	void Delete(int val)
//	{
//		if (root != nullptr)
//			Delete(root, val);
//	}
//	bool IsEmpty()
//	{
//		if (root == nullptr)
//			return true;
//		else
//			return false;
//	}
//	void PrintNode(Anode* Node)
//	{
//		cout << Node->val;
//	}
//	~AVL()
//	{
//		FreeNode(root);
//	}
//};
//
//class Library
//{
//private:
//	AVL<Index>Tree;
//	DList<BookData>RecordLL;
//public:
//	Library()
//	{
//
//	}
//	void InputData()
//	{
//		int it = 0;
//		int issn, ref, avail, noofaut = 0;
//		string tit;
//		char** authors;
//		cout << "Enter Book's ISSN : ";
//		cin >> issn;
//		cout << "Enter Title of the Book : ";
//		cin.ignore();
//		getline(cin, tit);
//		//cin >> tit;
//		cout << "Enter No of Reference Books : ";
//		cin >> ref;
//		cout << "Enter No of Available Books : ";
//		cin >> avail;
//		cout << "Enter No of Authors : ";
//		cin >> noofaut;
//		authors = new char* [noofaut];
//		for (int j = 0; j < noofaut; j++)
//		{
//			authors[j] = new char[50];
//		}
//		cout << "Enter Names of Authors : ";
//		for (int j = 0; j < noofaut; j++)
//		{
//			cin >> authors[j];
//		}
//		cout << endl << endl;
//		BookData tobeInsertedLL(issn, tit, ref, avail, noofaut, authors);
//		if (RecordLL.GetLLSize() == 0)
//		{ 
//			// If there is no element in the system
//			// You can First Input it in the list
//			// And Then Its Iterator in the Tree
//			DList<BookData>::Iterator temp;
//			RecordLL.InsertatStart(tobeInsertedLL);
//			temp.SetIterator(RecordLL.GetOnlyElement());
//			Index tobeInsertedT(issn, temp);
//			Tree.Insert(tobeInsertedT);
//			return;
//		}
//		else
//		{
//			// If the Tree/List is not empty First Take the Iterator of Future Parent Node from Tree
//			// Insert According to it in the List
//			// And then Insert its Iterator in the Tree
//			Index temp2;
//			temp2.SetIterator(Tree.GetParentNodeForInsert(tobeInsertedLL));
//			temp2.SetISSN(issn);
//			Index tobeInsertedTree;
//			tobeInsertedTree.SetIter(RecordLL.CheckandInsert(tobeInsertedLL, temp2.GetIteratorWI()));
//			tobeInsertedTree.SetISSN(issn);
//			Tree.Insert(tobeInsertedTree);
//		}
//	}
//	void Delete(int No) 
//	{ 
//		system("cls");
//		if (Tree.search(No))
//		{
//			Index toDeleteLL;   // As Explained above GetParentNodeForDelete -> gives the paticular node and not the parent node
//			toDeleteLL.SetIterator(Tree.GetParentNodeForDelete(No));  // Get the Node Iterator From Tree
//			toDeleteLL.SetISSN(No);
//			RecordLL.Remove(toDeleteLL.GetIteratorWI());  // First Delete it from List
//			Tree.Delete(No); // And then from tree
//			cout << "Book's Data has been Deleted " << endl;
//			cout << endl;
//			system("pause");
//		}
//		else
//		{
//			cout << "The Data of the Given ISSN Does Not Exist " << endl;
//			cout << endl;
//			system("pause");
//		}
//	}
//	void PrintSpecific(int No)
//	{
//		system("cls");
//		if (Tree.search(No))
//		{
//			Tree.PrintNode(Tree.search(No));
//		}
//		else
//		{
//			cout << "The Data of the Given ISSN Does Not Exist " << endl;
//		}
//	}
//	void Print()
//	{
//		Tree.PrintInorder();
//	}
//	void PrintLL()
//	{
//		RecordLL.Print();
//	}
//	void Update()
//	{
//		int choice = 0;
//		int issn, ref, avail, noofaut = 0;
//		string newtit;
//		char** authors;
//		cout << "Enter ISSN of The Book You Want to Update : ";
//		cin >> issn;
//		system("cls");
//		if (!Tree.search(issn))
//		{
//			cout << "The Given Book's Data Does Not Exists ";
//			system("pause");
//		}
//		else
//		{
//			Index toUpdate;
//			toUpdate.SetIterator(Tree.GetParentNodeForDelete(issn));
//			toUpdate.SetISSN(issn);
//			DList<BookData>::Iterator it;
//			it = toUpdate.GetIteratorWI();
//			cout << "Press 1 -> To Change Title \nPress 2 -> To Change No of Reference Books \nPress 3 -> To Change No of Available Books \nPress 4 -> To Change Authors Details \n";
//			cin >> choice;
//			system("cls");
//			if (choice == 1)
//			{
//				cout << "Enter New Title : ";
//				//cin >> newtit;
//				cin.ignore();
//				getline(cin, newtit);
//				*(it).SetTitle(newtit);
//			}
//			else if (choice == 2)
//			{
//				cout << "Enter New Number of Reference Books : ";
//				cin >> ref;
//				*(it).SetRefNo(ref);
//			}
//			else if (choice == 3)
//			{
//				cout << "Enter New Number of Available Books : ";
//				cin >> avail;
//				*(it).SetAvailNo(avail);
//			}
//			else if (choice == 4)
//			{
//				cout << " Press 1 -> Add New Author \n Press 2 -> Delete Previous Author : ";
//				cin >> choice;
//				if (choice == 1)
//				{
//					cout << "Enter No of Authors you Want to Add : ";
//					cin >> noofaut;
//					authors = new char* [noofaut];
//
//					for (int j = 0; j < noofaut; j++)
//					{
//						authors[j] = new char[50];
//					}
//					cout << "Enter Names of Authors : ";
//					for (int j = 0; j < noofaut; j++)
//					{
//						cin >> authors[j];
//						*(it).AddAuthors(authors[j]);
//					}
//					
//				}
//				else if (choice == 2)
//				{
//					int no = 0;
//					cout << "Enter Number of Authors you want to delete : ";
//					cin >> no;
//					for (int i = 0; i < no; i++)
//					{
//						*(it).DeleteAuthors(1);
//					}
//				}
//			}
//
//			cout << "Data has been Updated " << endl;
//			cout << endl;
//			system("pause");
//		}
//	}
//};
//void Run()
//{
//	int choice = 0, choice1 = 0, choice2 = 0;
//	Library LMS;
//	while (true)
//	{
//		system("cls");
//		cout << "							Welcome to Library Management System " << endl;
//		cout << "							By: Abdul Tawab (21L-5422) " << endl;
//		cout << endl << endl;
//		cout << "Press 1 -> To Input Book's Data \nPress 2 -> To Review a Book's Data \nPress 3 -> To Update a Book's Data \nPress 4 -> To Delete a Book's Data \nPress 5 -> To Exit " << endl;
//		cin >> choice;
//		if (choice == 1)
//		{
//			system("cls");
//			LMS.InputData();
//		}
//		else if (choice == 2)
//		{
//			system("cls");
//			cout << "Enter ISSN of the Book you want To Review : ";
//			cin >> choice1;
//			LMS.PrintSpecific(choice1);
//			cout << endl;
//			system("pause");
//		}
//		else if (choice == 3)
//		{
//			system("cls");
//			LMS.Update();
//			system("cls");
//			
//		}
//		else if (choice == 4)
//		{
//			system("cls");
//			cout << "Enter ISSN of the Book you want To Delete : ";
//			cin >> choice2;
//			LMS.Delete(choice2);
//			system("cls");
//		}
//		else if (choice == 5)
//		{
//			system("cls");
//			cout << endl;
//			cout << "Thank You for your coorporation  ";
//			cout << endl;
//			cout << endl;
//			break;
//		}
//	}
//}
//int main()
//{
//	system("color 74");
//	Run();
//}