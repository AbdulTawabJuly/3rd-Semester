#include<iostream>
using namespace std;

template<class T>
class DList
{
private:
	class DNode
	{
	public:
		T data;
		DNode* next;
		DNode* prev;
	};
	DNode* head;
	DNode* tail;
public:
	class Iterator
	{
		friend class DList<T>;
	private:
		DNode* curr;
		Iterator(DNode* c)
		{
			curr = c;
		}
	public:
		friend class DList<T>;
		Iterator()
		{
			curr = nullptr;
		}
		T& operator*()
		{
			return curr->data;
		}
		bool operator!=(Iterator& it)
		{
			if (curr != it.curr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		Iterator& begin()
		{
			Iterator it(head->next);
			return it;
		}
		Iterator end()
		{
			Iterator it(tail);
			return it;
		}
		Iterator& operator++()
		{
			curr = curr->next;
			return *this;
		}
		Iterator& operator++(int)
		{
			Iterator old = *this;
			curr = curr->next;
			return old;
		}
		Iterator& operator--()
		{
			curr = curr->prev;
			return *this;
		}

		void Insert(Iterator it, T d)
		{
			DNode* temp = new DNode;
			temp->data = d;
			DNode* t = it.curr;
			temp->next = t;
			temp->prev = t->prev;
			t->prev->next = temp;
			t->prev = temp;
		}
		Iterator Remove(Iterator it)
		{
			DNode* t = it.curr;
			t->prev->next = t->next;
			t->next->prev = t->prev;
			Iterator ite(t->next);
			delete t;
			return ite;
		}

	};
	void InsertatStart(T d)
	{
		Insert(this->begin(), d);
	}
	void InsertatEnd(T d)
	{
		Insert(this->end(), d);
	}
	void RemoveatStart(T d)
	{
		Remove(this->begin());
	}
	void RemoveatEnd(T d)
	{
		Remove(this->end());
	}

	void Print()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			DNode* temp;
			temp = head->next;
			while (temp != tail)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
	}

	/*~DList()
	{
		for (Iterator it = begin(); it != end(); it--)
		{
			it = Remove(it);
		}
		delete head;
		delete tail;
	}*/
};
int main()
{
	DList<int> L1;
	L1.InsertatStart(1);
	L1.InsertatStart(2);
	L1.InsertatStart(3);
	L1.InsertatStart(4);
	L1.InsertatStart(5);
	L1.Print();
//	DList<int>::Iterator iter;
	//iter = iter.begin();


}