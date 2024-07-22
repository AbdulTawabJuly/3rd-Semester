//#include<iostream>
//using namespace std;
//template <class t >
//class linklist
//{
//	class node
//	{
//	public:
//		t data;
//		node* next;
//		node* priv;
//		friend class linklist;
//		node()
//		{
//			next = nullptr;
//			priv = nullptr;
//		}
//		node(t as, node* ne = nullptr, node* pri = nullptr)
//		{
//			data = as;
//			next = ne;
//			priv = pri;
//		}
//		~node()
//		{
//
//		}
//	};
//	node head;
//	node tail;
//public:
//	linklist()
//	{
//		head.next = &tail;
//		tail.priv = &head;
//	}
//	class iterator
//	{
//		friend class linklist;
//		node* current;
//	public:
//		iterator()
//		{
//			current = nullptr;
//		}
//		iterator& operator ++()
//		{
//			current = current->next;
//			return *this;
//		}
//		iterator operator++(int a)
//		{
//			iterator old;
//			old.current = this->current;
//			this->current = this->current->next;
//			return old;
//		}
//		iterator& operator--()
//		{
//			current = current->priv;
//			return *this;
//		}
//		void setcurrent(node* as)
//		{
//			current = as;
//		}
//		node* getcurrent()
//		{
//			return current;
//		}
//		iterator operator--(int a)
//		{
//			iterator old;
//			old.current = this->current;
//			this->current = this->current->priv;
//			return old;
//		}
//		t operator* ()
//		{
//			return current->data;
//		}
//		bool operator==(const iterator as)
//		{
//			if (this->current == as.current)
//				return true;
//			else
//				return false;
//		}
//		bool operator!=(const iterator as)
//		{
//			if (this->current == as.current)
//				return false;
//			else
//				return true;
//		}
//	};
//	iterator bigen()
//	{
//		iterator as;
//		as.current = head.next;
//		return as;
//	}
//	iterator end()
//	{
//		iterator as;
//		as.current = &tail;
//		return as;
//	}
//	void insertion_at_head(t dat)
//	{
//		if (head.next == &tail)
//		{
//			node* as = new node(dat, &tail, &head);
//			head.next = as;
//			tail.priv = as;
//		}
//		else
//		{
//			node* as = new node(dat, head.next, &head);
//			head.next->priv = as;
//			head.next = as;
//		}
//	}
//	void insert(iterator i, t data)
//	{
//		if (i.current == &tail)
//		{
//			return;
//		}
//		else
//		{
//			node* ne = new node(data, i.current->next, i.current);
//			i.current->next->priv = ne;
//			i.current->next = ne;
//		}
//	}
//	void printforward()
//	{
//		iterator as = this->bigen();
//		for (; as.current != &tail; as++)
//		{
//			if (as.current->priv != &head)
//			{
//				cout << ',';
//			}
//			cout << *as;
//		}
//	}
//	void delete_from_head()
//	{
//		if (head.next != &tail)
//		{
//			node* as = head.next;
//			head.next = head.next->next;
//			head.next->priv = &head;
//			delete as;
//		}
//	}
//	~linklist()
//	{
//		iterator as = this->bigen();
//		for (; as.current != &tail; )
//		{
//			node* op = as.current;
//			as.current = as.current->next;
//			delete op;
//		}
//	}
//	bool searchword(t value, iterator& as)
//	{
//		iterator curr;
//		curr = as;
//		for (; curr.current != nullptr && curr.getcurrent()->next != nullptr; ++curr)
//		{
//			if (curr.getcurrent()->data == value)
//			{
//				as = curr;
//				return true;
//			}
//		}
//		return false;
//	}
//	iterator* searchfirst(t value)
//	{
//		iterator* curr;
//		curr = &this->bigen();
//		for (; curr.current != nullptr && curr.getcurrent()->next != nullptr; ++curr)
//		{
//			if (curr.getcurrent()->data == value)
//			{
//				return curr;
//			}
//		}
//		return nullptr;
//	}
//	iterator* searchlast(t value)
//	{
//		iterator curr;
//		curr = this->bigen();
//		int i = 0;
//		for (; curr.current != nullptr && curr.getcurrent()->next != nullptr; ++curr)
//		{
//			if (curr.getcurrent()->data == value)
//			{
//				i++;
//			}
//		}
//		if (i > 0)
//		{
//			iterator* list = new iterator[i + 1];
//			curr = this->bigen();
//			i = 0;
//			for (; curr.current != nullptr && curr.getcurrent()->next != nullptr; ++curr)
//			{
//				if (curr.getcurrent()->data == value)
//				{
//					list[i] = curr;
//					i++;
//				}
//			}
//			list[i] = this->end();
//			return list;
//		}
//		else
//			return nullptr;
//	}
//	void del(iterator& as)
//	{
//		if (as.current != &head && as.current != &tail)
//		{
//			node* s = as.current;
//			as++;
//			as.current->priv = s->priv;
//			s->priv->next = as.current;
//			delete s;
//		}
//	}
//	void del_all_entities(t val)
//	{
//		iterator as = this->bigen();
//		for (; as.current != &tail && as.current != nullptr;)
//		{
//			if (this->searchword(val, as))
//			{
//				this->del(as);
//			}
//			else
//				break;
//		}
//	}
//	void replace_all(t val1, t val2)
//	{
//		iterator as = this->bigen;
//		for (; as.current != &tail && as.current != nullptr; as++)
//		{
//			if (this->searchword(val1, as))
//			{
//				as.current->data = val2;
//			}
//		}
//	}
//	void insert_multiple(t* val, iterator& as, int siz)
//	{
//		if (as.current != &tail);
//		for (int i = 0; i < siz; i++)
//		{
//			this->insert(as, val[i]);
//			as++;
//		}
//	}
//	void swap(node*& a, node*& b)
//	{
//		node* priv1 = a->priv;
//		node* priv2 = b->priv;
//		node* net1 = a->next;
//		node* next = b->next;
//		a->priv = priv2;
//		b->priv = priv1;
//		a->next = next;
//		b->next = net1;
//		priv1->next = b;
//		priv2->next = a;
//		net1->priv = b;
//		next->priv = a;
//	}
//	void multipledel(iterator as, int num)// num is number of entries to b deleted
//	{
//		for (int i = 0; i < num; i++)
//		{
//			if (as.current != &tail)
//			{
//				this->del(as);
//			}
//		}
//	}
//};
//int main()
//{
//	linklist<int> list;
//	for (int i = 20; i >= 0; i--)
//		list.insertion_at_head(i);
//	list.insertion_at_head(20);
//	list.insertion_at_head(20);
//	list.insertion_at_head(78);
//	linklist<int>::iterator* as = list.searchlast(20);
//	for (int i = 0; as[i] != list.end(); i++)
//	{
//		list.insert(as[i], 30);
//	}
//	list.printforward();
//}