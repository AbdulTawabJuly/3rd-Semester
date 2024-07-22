#pragma once
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
	node* parent;
	node(int a, node* pa, node* rt, node* lf)
	{
		data = a;
		parent = pa;
		right = rt;
		left = lf;
	}
};
struct nod
{
	node* data;
	nod* next;
	nod* priv;
	nod(node* i, nod* s, nod* p)
	{
		data = i;
		next = s;
		priv = p;
	}
};
class stack
{
	int size;
public:
	nod* head;
	nod* tail;
	stack()
	{
		size = -1;
		head = nullptr;
		tail = nullptr;
	}
	bool push(node* k)
	{
		if (head == nullptr)
		{
			nod* a = new nod(k, nullptr, this->tail);
			head = a;
			tail = a;
			size++;
		}
		else
		{
			nod* a = new nod(k, nullptr, tail);
			tail->next = a;
			tail = a;
			size++;
		}
		return true;
	}
	bool pop()
	{
		if (size > -1)
		{
			if (size == 0)
			{
				nod* a = tail;
				this->tail = nullptr;
				this->head = nullptr;
				size--;
				delete a;
			}
			else
			{
				nod* a = tail;
				this->tail = tail->priv;
				size--;
				delete a;
			}
			return true;
		}
		return false;
	}
	bool top(node*& a)
	{
		if (size > -1) {
			a = this->tail->data;
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (size == -1)
		{
			return true;
		}
		return false;
	}
};
class Queue
{
	int currsize;
public:
	nod* head;
	nod* tail;
	Queue()
	{
		currsize = -1;
		head = nullptr;
		tail = nullptr;
	}
	bool Enqueue(node* k)
	{
		if (head == nullptr)
		{
			nod* a = new nod(k, nullptr, this->tail);
			head = a;
			tail = a;
			currsize++;
		}
		else
		{
			nod* a = new nod(k, nullptr, tail);
			tail->next = a;
			tail = a;
			currsize++;
		}
		return true;
	}
	bool Dequeue()
	{
		if (currsize > -1)
		{
			if (currsize == 0)
			{
				nod* a = head;
				this->tail = nullptr;
				this->head = nullptr;
				currsize--;
				delete a;
			}
			else
			{
				nod* a = head;
				this->head = head->next;
				currsize--;
				delete a;
				return true;
			}
			return false;
		}
	}
	bool top(node*& a)
	{
		if (currsize > -1) {
			a = this->head->data;
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (currsize == -1)
		{
			return true;
		}
		return false;
	}
};