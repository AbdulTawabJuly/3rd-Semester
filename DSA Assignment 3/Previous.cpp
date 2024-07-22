//#include<iostream>
//#include<string>
//using namespace std;
//int abs(int x)
//{
//	return (x < 0) ? -x : x;
//}
//int max(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//class BookData;
//class Index;
//
//template<class T>
//class DList
//{
//private:
//
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
//
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
//		Iterator& operator++(int) //post increment
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
//
//			else { return false; }
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
//		Iterator& AddAuthors(char** newlist)
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
//
//		Iterator& operator=(DNode* temp)
//		{
//			curr = temp;
//			return *this;
//		}
//
//		void SetIterator(Iterator obj)
//		{
//			curr = obj.curr;
//		}
//		void SetIteratorwithNode(DNode* temp)
//		{
//			curr = temp;
//		}
//		/*void SetIteratorWithindex(T& obj)
//		{
//			curr = obj;
//		}*/
//
//		/*Iterator GetIterator()
//		{
//
//		}*/
//		friend ostream &operator<<(ostream &out,Iterator&it)
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
//
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
//	Iterator& InsertBefore(Iterator it, T d)
//	{
//		DList<BookData>::Iterator temporary;
//
//		DNode* t = it.curr;
//		DNode* temp = new DNode;
//		temp->data = d;
//		temp->next = t;
//		temp->prev = t->prev;
//		t->prev->next = temp;
//		t->prev = temp;
//		temporary.curr = temp;
//		return temporary;
//		//*(temporary) = temp;
//
//		//*(obj) = temp;
//
//	}
//	Iterator& InsertAfter(Iterator it, T d)
//	{
//		DList<BookData>::Iterator temporary;
//
//		DNode* t = it.curr;
//		DNode* temp = new DNode;
//		temp->data = d;
//		temp->next = t->next;
//		temp->prev = t;
//		t->next->prev = temp;
//		t->next = temp;
//		temporary.curr = temp;
//		return temporary;
//		//*(temporary) 
//		//*(obj) = temp;
//	}
//
//	Iterator& CheckandInsert(T d, Iterator it)
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
//	Iterator Remove(Iterator it)
//	{
//		DNode* t = it.curr;
//		t->prev->next = t->next;
//		t->next->prev = t->prev;
//		Iterator ite(t->next);
//		delete t;
//		return ite;
//	}
//	//Iterator RemoveFromLL(T d)
//	//{
//	//	if(d)
//	//}
//
//	/*Iterator ReturnPointer(int No, DList<BookData>Rec)
//	{
//		Iterator it = Rec.Begin();
//		for (; it != Rec.End(); it++)
//		{
//			if(it.)
//		}
//		while (it != Rec.End())
//		{
//			if ((*it).)
//			{
//
//			}
//			it++
//		}
//	}*/
//
//	
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
//
//
//
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
//
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
//
//	/*void InsertAll(Dnode*head)
//	{
//
//	}*/
//
//	//void InsertSorted(T d)
//	//{
//	//	size++;
//	//	if (head->next == tail)  // No Element
//	//	{
//	//		InsertatStart(d);
//	//	}
//	//	else if (head->next->next == tail)  // Only 1 element
//	//	{
//	//		DNode* temp = head->next;
//	//		if (temp->data >= d)
//	//		{
//	//			InsertatStart(d);
//	//		}
//	//		else
//	//		{
//	//			InsertatEnd(d);
//	//		}
//	//	}
//	//	else
//	//	{
//	//		DNode* Curr = new DNode;
//	//		Curr->data = d;
//	//		DNode* temp = head->next;
//	//		while (temp != tail)
//	//		{
//	//			if (temp->data <= Curr->data && temp->next->data >= Curr->data)
//	//			{
//	//				Curr->next = temp->next;
//	//				temp->next->prev = Curr;
//	//				temp->next = Curr;
//	//				Curr->prev = temp;
//	//				return;
//	//			}
//	//			temp = temp->next;
//	//		}
//	//	}
//
//	//}
//
//	DList& operator=(DList& obj)
//	{
//		this->size = obj.size;
//		/*this->head = obj.head;
//		this->tail = obj.tail;*/
//		DNode* temp = obj.head->next;
//		while (temp->next!= nullptr)
//		{
//			InsertatEnd(temp->data);
//			temp = temp->next;
//		}
//		return *this;
//	}
//	
//	void Print()
//	{
//		if (head == nullptr)
//		{
//			cout << "Linked List is Empty" << endl;
//		}
//		else
//		{
//			DNode* temp;
//			temp = head->next;
//			while (temp != tail)
//			{
//				cout << temp->data << " ";
//				cout << endl;
//				temp = temp->next;
//			}
//		}
//	}
//
//	void DeleteatStart()
//	{
//		DNode* temp = head->next;
//		head->next->prev = head;
//		head->next = temp->next;
//		delete temp;
//	}
//
//	/*void DeleteByISSN(int ISSN)
//	{
//		DNode* temp = head->next;
//		while (temp->next != tail)
//		{
//			if (temp->data == ISSN)
//			{
//				temp->prev->next = temp->next;
//				temp->next->prev = temp->prev;
//				delete temp;
//				return;
//			}
//			temp = temp->next;
//		}
//	}*/
//	void DeleteatEnd()
//	{
//		DNode* temp = tail->prev;
//		temp->prev->next = tail;
//		tail->prev = temp->prev;
//		delete temp;
//	}
//
//	int GetLLSize()
//	{
//		return size;
//	}
//	Iterator GetOnlyElement()
//	{
//		Iterator temp = this->Begin();
//		//temp.curr->data = head->next->data;
//		return temp;
//	}
//	void Update(int Choice )
//	{
//
//	}
//	/*~DList()
//	{
//		while (head->next != tail)
//		{
//			DeleteatStart();
//		}
//	}*/
//};
//
//class Iterator;
//
//class BookData
//{
//private:
//	int ISSN;
//	string Title;
//	int RefBooks;
//	int Available;
//	DList<char*>Authors;
//
//public:
//	BookData()
//	{
//		ISSN = 0;
//		Title.clear();
//		RefBooks = 0;
//		Available = 0;		
//	}
//
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
//
//	BookData& operator=(BookData& obj)
//	{
//		ISSN = obj.ISSN;
//		Title = obj.Title;
//		RefBooks = obj.RefBooks;
//		Available = obj.Available;
//		Authors = obj.Authors;
//		return *this;
//	}
//
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
//	BookData& operator= (char** AddAuthors)
//	{
//		Authors.InsertatEnd(AddAuthors[0]);
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
//
//
//	bool operator==(BookData& d)
//	{
//		if (this->ISSN == d.ISSN)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	bool operator>=(BookData& d)
//	{
//		if (this->ISSN >= d.ISSN)
//		{
//			return true;
//		}
//		return false;
//	}
//	/*bool operator>(Iterator& it)
//	{
//		if (ISSN > it.curr->data)
//		{
//
//		}
//	}*/
//
//	bool operator<=(BookData& d)
//	{
//		if (this->ISSN <= d.ISSN)
//		{
//			return true;
//		}
//		return false;
//	}
//	
//	friend ostream& operator<<(ostream&out,BookData&obj)
//	{
//		out << "Book's ISSN : " << obj.ISSN << endl;
//		out << "Book's Tittle : " << obj.Title << endl;
//		out << "No of Reference Books : " << obj.RefBooks << endl;
//		out << "No of Available Books : " << obj.Available << endl;
//		out << "Authors Name's : ";
//		obj.Authors.Print();
//		cout << endl;
//		return out;
//	}
//
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
//	/*Index(int no, BookData obj)
//	{
//		ISSN = no;
//		Data = obj;
//	}*/
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
//	/*Iterator& operator=(Index& obj)
//	{
//		ISSN = obj.ISSN;
//		Data = obj.Data;
//		return *this;
//	}*/
//	DList<BookData>::Iterator GetIteratorWI()
//	{
//		return Data;
//	}
//
//	DList<BookData>::Iterator GetIteratorI(Index& obj)
//	{
//		return obj.Data;
//	}
//
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
//
//	/*DList<BookData>::Iterator GetPointer(int no, DList<BookData>Rec)
//	{
//		ISSN = no;
//		Data = Rec.Begin();
//		while (Data.GetCurrent() != Rec.End().GetCurrent())
//		{
//			if (Data.GetCurrent()->data == no)
//			{
//				return Data;
//			}
//
//			Data++;
//		}
//	}*/
//
//};
//
//
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
//	void printInorder(Anode* r)
//	{
//		if (r == nullptr)
//			return;
//		printInorder(r->l);
//		cout << r->val << endl;
//		printInorder(r->r);
//	}
//	void printPreorder(Anode* r)
//	{
//		if (r == nullptr)
//			return;
//		cout << r->val << endl;
//		printPreorder(r->l);
//		printPreorder(r->r);
//	}
//	void printPostorder(Anode* r)
//	{
//		if (r == nullptr)
//			return;
//		printPostorder(r->l);
//		printPostorder(r->r);
//		cout << r->val << endl;
//	}
//	
//	int getHeight(Anode* r)
//	{
//		if (r == nullptr)
//			return -1;
//		return r->height;
//	}
//	void Delete(Anode*& r, int val)
//	{
//		if (r->val == val)
//		{
//			//delete node based on 3 conditions
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
//				//find max from r->l and replace it with r
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
//		r->height = 1 + max(getHeight(r->l), getHeight(r->r));
//		int factor = getBalance(r);
//		if (factor < -1) // right subtree is getting heavy deletion was done in left subtree
//		{
//			int k = getBalance(r->r);
//			if (k <= -1) // RR case
//			{
//				rotateL(r);
//			}
//			else //RL
//			{
//				rotateR(r->r);
//				rotateL(r);
//			}
//		}
//		else if (factor > 1)
//		{
//			int k = getBalance(r->l);
//			if (k >= 1) // LL case
//			{
//				rotateR(r);
//			}
//			else //LR
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
//		prevR->height = 1 + max(getHeight(prevR->l), getHeight(prevR->r));
//		r->height = 1 + max(getHeight(r->l), getHeight(r->r));
//	}
//	void rotateR(Anode*& r)
//	{
//		Anode* t = r->l;
//		r->l = t->r;
//		t->r = r;
//		Anode* prevR = r;
//		r = t;
//		prevR->height = 1 + max(getHeight(prevR->l), getHeight(prevR->r));
//		r->height = 1 + max(getHeight(r->l), getHeight(r->r));
//	}
//	void balance(Anode*& r, T val)
//	{
//		int factor = getHeight(r->l) - getHeight(r->r);
//		if (factor < -1) // right subtree is getting heavy
//		{
//			if (val < r->r->val) //RL insertion
//			{
//				rotateR(r->r);
//				rotateL(r);
//			}
//			else if (val > r->r->val) //RR insertion
//			{
//				rotateL(r);
//			}
//		}
//		else if (factor > 1)
//		{
//			if (val < r->l->val)//LL insertion
//			{
//				rotateR(r);
//			}
//			else if (val > r->l->val)//LR insertion
//			{
//				//cout<<"rotat"
//				rotateL(r->l);
//				rotateR(r);
//			}
//		}
//	}
//	bool insert(Anode*& r, T d)
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
//				bool b = insert(r->l, d);
//				if (b)//balance only if insertion was successful
//				{
//					r->height = 1 + max(getHeight(r->l), getHeight(r->r));
//					balance(r, d);
//				}
//				return b;
//			}
//			else if (d > r->val)
//			{
//				bool b = insert(r->r, d);
//				if (b)
//				{
//					r->height = 1 + max(getHeight(r->l), getHeight(r->r));
//					balance(r, d);
//				}
//				return b;
//			}
//		}
//		return false;
//	}
//	void insertAllOf(Anode* r)
//	{
//		if (r == nullptr)
//			return;
//		insert(r->val);
//		insertAllOf(r->l);
//		insertAllOf(r->r);
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
//	Index& GetParentNodeForInsert(Anode* r, BookData& Child, T Parent)
//	{
//		if (r == nullptr)
//		{
//			return Parent;
//		}
//		else if (r->val > Child)
//		{
//			Parent = r->val;
//			//cout << Parent;
//			GetParentNodeForInsert(r->l, Child, Parent);
//		}
//		else if(r->val<=Child)
//		{
//			Parent = r->val;
//			//cout << Parent;
//			GetParentNodeForInsert(r->r, Child, Parent);
//		}
//	}
//	Index& GetParentNodeForDelete(Anode* r, int Key, T Parent)
//	{
//		if (r->val==Key)
//		{
//			return r->val;
//		}
//		else if (r->val > Key)
//		{
//			Parent = r->val;
//			//cout << Parent;
//			GetParentNodeForDelete(r->l, Key, Parent);
//		}
//		else if (r->val <= Key)
//		{
//			Parent = r->val;
//			//cout << Parent;
//			GetParentNodeForDelete(r->r, Key, Parent);
//		}
//	}
//public:
//	AVL()
//	{
//		root = nullptr;
//	}
//	AVL(const AVL& rhs)
//	{
//		root = nullptr;
//		insertAllOf(rhs.root);
//	}
//	bool insert(T d)
//	{
//		return insert(root, d);
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
//	void freeNode(Anode* r)
//	{
//		if (r == nullptr)
//			return;
//		freeNode(r->l);
//		freeNode(r->r);
//		delete r;
//	}
//	void printInorder()
//	{
//		printInorder(root);
//	}
//	void printPreOrder()
//	{
//		printPreorder(root);
//	}
//	void printPostOrder()
//	{
//		printPostorder(root);
//	}
//
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
//		freeNode(root);
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
//		//getline(cin, tit);
//		cin >> tit;
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
//	
//		if (RecordLL.GetLLSize() == 0)
//		{
//			DList<BookData>::Iterator temp;
//			RecordLL.InsertatStart(tobeInsertedLL);
//			temp.SetIterator(RecordLL.GetOnlyElement());
//			Index tobeInsertedT(issn, temp);
//			Tree.insert(tobeInsertedT);
//			return;
//		}
//		else
//		{
//			Index temp2;
//			//DList<BookData>::Iterator tempit;
//			
//			temp2.SetIterator(Tree.GetParentNodeForInsert(tobeInsertedLL));
//			temp2.SetISSN(issn);
//
//			//tempit.SetIterator(temp2.GetIteratorWI());
//
//			//Index tobeInsertedT2(issn, tempit);
//			Index tobeInsertedTree;
//
//			tobeInsertedTree.SetIter(RecordLL.CheckandInsert(tobeInsertedLL, temp2.GetIteratorWI()));
//			tobeInsertedTree.SetISSN(issn);
//			Tree.insert(tobeInsertedTree);
//			// Make a function in DList class of Insert(Inseert Before and Insert After ) which take iterator (tempit)
//			// After this Insert the obj in tree
//
//
//			//temp.SetIterator(temp2.GetIterator2());
//
//		}
//	}
//	void Delete(int No)
//	{
//		Index toDeleteLL;
//		toDeleteLL.SetIterator(Tree.GetParentNodeForDelete(No));
//		toDeleteLL.SetISSN(No);
//		RecordLL.Remove(toDeleteLL.GetIteratorWI());
//
//		Tree.Delete(50);
//	}
//	void PrintSpecific(int No)
//	{
//		system("cls");
//		Tree.PrintNode(Tree.search(55));
//	}
//	void Print()
//	{
//		Tree.printInorder();
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
//
//		Index toUpdate;
//		toUpdate.SetIterator(Tree.GetParentNodeForDelete(issn));
//		toUpdate.SetISSN(issn);
//
//		DList<BookData>:: Iterator it;
//
//		//it.SetIteratorWithindex(toUpdate);
//		//it.SetIterator(toUpdate);
//		it = toUpdate.GetIteratorWI();
//
//		cout << "Press 1 -> To Change Title \nPress 2 -> To Change No of Reference Books \nPress 3 -> To Change No of Available Books \nPress 4 -> To Change Authors Details \n";
//		cin >> choice;
//		system("cls");
//
//
//		if (choice == 1)
//		{
//			cout << "Enter New Title : ";
//
//			cin >> newtit;
//			
//			*(it).SetTitle(newtit);
//		}
//		else if (choice == 2)
//		{
//			cout << "Enter New Number of Reference Books : ";
//			cin >> ref;
//			*(it).SetRefNo(ref);
//		}
//		else if (choice == 3)
//		{
//			cout << "Enter New Number of Available Books : ";
//			cin >> avail;
//			*(it).SetAvailNo(avail);
//		}
//		else if (choice == 4)
//		{
//			cout << " Press 1 -> Add New Author \n Press 2 -> Delete Previous Author : ";
//			cin >> choice;
//			if (choice == 1)
//			{
//				cout << "Enter No of Authors you Want to Add : ";
//				cin >> noofaut;
//				authors = new char* [noofaut];
//
//				for (int j = 0; j < noofaut; j++)
//				{
//					authors[j] = new char[50];
//				}
//				cout << "Enter Names of Authors : ";
//				for (int j = 0; j < noofaut; j++)
//				{
//					cin >> authors[j];
//				}
//				*(it).AddAuthors(authors);
//			}
//			else if (choice == 2)
//			{
//				*(it).DeleteAuthors(1);
//			}
//		}
//	}
//};
//
//void Run()
//{
//	Library LMS;
//	LMS.InputData();
//	LMS.InputData();
//	LMS.InputData();
//	/*LMS.InputData();
//	LMS.InputData();
//	LMS.InputData();*/
//	//LMS.PrintSpecific(100);
//	//LMS.Print();
//	LMS.PrintLL();
//	system("pause");
//	system("cls");
//	LMS.Update();
//	LMS.PrintLL();
//	system("pause");
//	system("cls");
//	LMS.Print();
//	system("cls");
//	system("pause");
//	LMS.PrintSpecific(100);
//	//LMS.Delete(55);
//	//LMS.Print();
//	//LMS.PrintLL();
//
//}
//
//int main()
//{
//	Run();
//}
//
