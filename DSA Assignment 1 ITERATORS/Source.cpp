//#include<iostream>
//using namespace std;
//
//template<class t>
//class DList
//{
//private:
//	class Dnode
//	{
//	public:
//		t data;
//		Dnode* next;
//		Dnode* prev;
//		Dnode()
//		{
//			next = prev = nullptr;
//		}
//	};
//	Dnode* head;
//	Dnode* tail;
//public:
//	class Iterator
//	{
//		friend class DList;
//	private:
//		Dnode* curr;
//	public:
//		Iterator()
//		{
//			curr = nullptr;
//		}
//		Iterator(Dnode* c)
//		{
//			curr = c;
//		}
//
//		Iterator& operator++(int)
//		{
//			Iterator it = curr;
//			curr = curr->next;
//			return it;
//		}
//
//		t& operator*()
//		{
//			return curr->data;
//		}
//
//		bool operator!=(Iterator it)
//		{
//			if (curr != it.curr)
//				return true;
//			else
//				return false;
//		}
//
//	};
//
//	DList()
//	{
//		head = tail = nullptr;
//	}
//
//	Iterator begin()
//	{
//		Iterator it;
//		it.curr = head;
//		return it;
//	}
//
//	Iterator end()
//	{
//		Iterator it;
//		it.curr = tail;
//		return it;
//	}
//
//	
//
//	void Insert(Iterator it, t d)
//	{
//		if (it.curr == nullptr)
//		{
//			Dnode* temp = new Dnode;;
//			temp->data = d;
//			head = tail = temp;
//
//		}
//		else
//		{
//			Dnode* t1 = it.curr;
//			Dnode* temp = new Dnode;;
//			temp->data = d;
//			temp->next = t1;
//			temp->prev = t1->prev;
//			t1->prev->next = temp;
//			t1->prev = temp;
//		}
//		
//	}
//
//	void InsertatStart(t d)
//	{
//		Insert(begin(), d);
//	}
//	void InsertatEnd(t d)
//	{
//		Insert(end(), d);
//	}
//
//	Iterator Remove(Iterator it)
//	{
//		Dnode* t1 = it.curr;
//		t1->prev->next = t1->next;
//		t1->next->prev = t1->prev;
//		Iterator ite(t1->next);
//		delete t1;
//		return ite;
//	}
//
//	void RemoveatStart()
//	{
//		Remove(begin());
//	}
//	void RemoveatEnd()
//	{
//		Remove(end());
//	}
//
//	~DList()
//	{
//		for (Iterator it = begin(); it != end();)
//		{
//			it = Remove(it);
//			it++;
//		}
//	}
//};
//
//int main()
//{
//	DList<int>L1;
//	L1.InsertatStart(3);
//	L1.InsertatStart(2);
//	L1.InsertatStart(1);
//	L1.InsertatEnd(4);
//	L1.InsertatEnd(5);
//	L1.InsertatEnd(6);
//
//	//DList<int>::Iterator iter;
//	//iter = L1.begin();
//	DList<int>::Iterator iter = L1.begin();
//	for (; iter!=L1.end(); )
//	{
//		cout << *iter;
//		iter++;
//	}
//}