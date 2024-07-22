#ifndef EDITOR_H
#define EDOTOR_H
const int MAX_X = 100;
const int MAX_Y = 50;

//-------------------------------Color Codes------------------------------//
// Color Codes Hexadecimal values for both Fore Ground and Back Ground //ForeGround|BackGround
int B_BLACK = 0x00;	int B_Royal_Blue = 0x10;	int B_Dark_Green = 0x20;
int B_Tale_Blue = 0x30;	int B_Dark_Red = 0x40;	int B_Purple = 0x50;
int B_Tale_Green = 0x60;	int B_Light_Grey = 0x70; int B_Dark_Gray = 0x80;
int B_Light_Blue = 0x90; int B_Light_Green = 0xA0;	int B_Sky_Blue = 0xB0;
int B_Red = 0xC0;	int B_Pink = 0xD0;	int B_Yellow = 0xE0;
int B_White = 0xF0;

int F_BLACK = 0x00;	int F_Royal_Blue = 0x01; int F_Dark_Green = 0x02;
int F_Tale_Blue = 0x03;	int F_Dark_Red = 0x04;	int F_Purple = 0x05;
int F_Tale_Green = 0x06;	int F_Light_Grey = 0x07; int F_Dark_Gray = 0x08;
int F_Light_Blue = 0x09; int F_Light_Green = 0x0A;	int F_Sky_Blue = 0x0B;
int F_Red = 0x0C;	int F_Pink = 0x0D;	int F_Yellow = 0x0E;
int F_White = 0x0F;

class point
{

public:
	point() { x = 0; y = 0; }
	point(int a, int b) { x = a; y = b; }
	int getX() { return x; }
	int getY() { return y; }
	void set(int a, int b) { x = a; y = b; }
	void setX(int a) { x = a; }
	void setY(int b) { y = b; }
	void setMaxPoint(int a, int b) { MaxPoint.x = a; MaxPoint.y = b; }
	int getMaxPointX() { return MaxPoint.x; }
	int getMaxPointY() { return MaxPoint.y; }
	//increment x-coordinate.  If max limit is reached then increment y and set x to zero
	//return false if max limit for x and y is reached
	bool incrementX();
	//increment y-coordinate.  If max limit is reached return false
	bool incrementY();
	//decrement x-coordinate.  If x is already at 0 then go to line above at last x (decrement y)
	//return false if both x and y are at 0
	bool decrementX();
	//decrement y-coordinate.  If y is already at 0 then return false
	bool decrementY();
private:
	static point MaxPoint;
	int x;
	int y;
};
using namespace std;
class linklist
{
	class node
	{
	public:
		char data;
		node* next;
		node* priv;
		point pos;
		friend class linklist;
		node()
		{
			next = nullptr;
			priv = nullptr;
		}
		node(char as, point curr, node* ne = nullptr, node* pri = nullptr)
		{
			data = as;
			next = ne;
			priv = pri;
			pos = curr;
		}
		~node()
		{

		}
	};
	node head;
	node tail;
public:
	class iterator
	{
		friend class linklist;
		node* current;
	public:
		iterator()
		{
			current = nullptr;
		}
		iterator& operator ++()
		{
			current = current->next;
			return *this;
		}
		iterator operator++(int a)
		{
			iterator old;
			old.current = this->current;
			this->current = this->current->next;
			return old;
		}
		iterator& operator--()
		{
			current = current->priv;
			return *this;
		}
		void setcurrent(node* as)
		{
			current = as;
		}
		node* getcurrent()
		{
			return current;
		}
		iterator operator--(int a)
		{
			iterator old;
			old.current = this->current;
			this->current = this->current->priv;
			return old;
		}
		char operator* ()
		{
			return current->data;
		}
		bool operator==(const iterator as)
		{
			if (this->current == as.current)
				return true;
			else
				return false;
		}
		bool operator!=(const iterator as)
		{
			if (this->current == as.current)
				return false;
			else
				return true;
		}
	};
	iterator bigen()
	{
		iterator as;
		as.current = head.next;
		return as;
	}
	iterator end()
	{
		iterator as;
		as.current = &tail;
		return as;
	}
	void incpoint(iterator i)
	{
		if (i.current->priv->data != '\n')
		{
			for (; i.current != nullptr; ++i)
			{
				if (i.current->pos.getX() < i.current->pos.getMaxPointX() - 1)
					i.current->pos.incrementX();
				else
				{
					i.current->pos.incrementY();
					i.current->pos.setX(0);
				}
				if ((i.current->data == '\n') && i.current->pos.getX() < MAX_X - 1)
				{
					break;
				}
			}
		}
		else
		{
			int k = 0;
			for (; i.current != nullptr; ++i, ++k)
			{
				i.current->pos.setX(k);
				i.current->pos.incrementY();
				if (i.current->data == '\n' || i.current->pos.getX() == MAX_X - 1)
				{
					k = -1;
				}
			}
		}
	}
	void decpoint(iterator i)
	{

		if (i.current->data != '\n')
			for (; i.current != nullptr && i.current->data != '\n'; i++)
			{
				if (i.current->pos.getX() != 0)
				{
					if (i.current->pos.getX() < i.current->pos.getMaxPointX())
						i.current->pos.decrementX();
				}
				else
				{
					for (; i.current != nullptr && i.current->pos.getX() != i.current->pos.getMaxPointX() - 1 && i.current->data != '\n'; i++)
					{
						if (i.current->priv->pos.getX() == MAX_X - 1)
						{
							i.current->pos.decrementX();
							break;
						}
						i.current->pos.decrementY();
						i.current->pos.setX(i.current->priv->pos.getX() + 1);
					}
				}
				if (i.current == nullptr)
					return;
				if (i.current->data == '\n')
				{
					i.current->pos.decrementY();
					i.current->pos.setX(i.current->priv->pos.getX() + 1);
					++i;
					int k = 0;
					for (; i.current != nullptr; i++, ++k)
					{
						i.current->pos.decrementY();
						i.current->pos.setX(k);
						if (i.current->data == '\n')
						{
							k = -1;
						}
					}
				}
				if (i.current == nullptr)
					return;
			}
		else if (i.current != nullptr && i.current->data == '\n' && i.current->pos.getX() == 0)
		{
			i.current->pos.decrementY();
			i.current->pos.setX(i.current->priv->pos.getX() + 1);
			++i;
			int k = 0;
			for (; i.current != nullptr; i++, ++k)
			{
				i.current->pos.decrementY();
				i.current->pos.setX(k);
				if (i.current->data == '\n')
				{
					k = -1;
				}
			}
			return;
		}
		else if (i.current->pos.getX() == 0 && i.current->data == '\n')
		{
			i.current->pos.decrementY();
			i.current->pos.setX(i.current->priv->pos.getX() + 1);
			++i;
			int k = 0;
			for (; i.current != nullptr; i++, ++k)
			{
				i.current->pos.decrementY();
				i.current->pos.setX(k);
				if (i.current->data == '\n')
				{
					k = -1;
				}
			}
			return;
		}
	}
	void insert(iterator i, char dat, point curr)
	{
		if (head.next == nullptr && tail.priv == nullptr)
		{
			node* as = new node(dat, curr, &tail, &head);
			head.next = as;
			tail.priv = as;
			if (dat != '/n')
			{
				tail.pos.set(1, 0);
			}
			else
			{
				tail.pos.set(0, 1);
			}
		}
		else if (i.current == &tail || (i.current->data == '\n' && dat != '\n'))
		{
			node* ak = new node(dat, curr, i.current, i.current->priv);
			node* as = i.current->priv;
			i.current->priv = ak;
			as->next = ak;
			if (i.current == &tail)
			{
				if (curr.getX() == curr.getMaxPointX())
					tail.pos.set(0, curr.getY() + 1);
				else
					tail.pos.set(curr.getX() + 1, curr.getY());
			}
			else
			{
				if (curr.getX() == curr.getMaxPointX())
					i.current->pos.set(0, curr.getY() + 1);
				else
					i.current->pos.set(curr.getX() + 1, curr.getY());
			}
		}
		else
		{
			node* ak = new node(dat, curr, i.current, i.current->priv);
			node* as = i.current->priv;
			i.current->priv = ak;
			as->next = ak;
			ClearScreen();
			this->incpoint(i);
			printforward();
		}
	}
	void printforward()
	{
		iterator as = this->bigen();
		PlaceCursor(0, 0);
		for (; as.current != nullptr; as++)
		{
			OutputString(as.current->pos.getX(), as.current->pos.getY(), &as.current->data);
		}
	}
	void erase(iterator i)
	{

		if (i.current->priv == &head)
		{
			return;
		}
		else
		{
			node* as = i.current->priv;
			i.current->priv = as->priv;
			as->priv->next = i.current;
			this->decpoint(i);
			if (i.current->data == '\n')
			{
				if (i.current->pos.getX() != 0)
					i.current->pos.decrementX();
			}
			ClearScreen();
			printforward();
			delete as;
		}
	}
	~linklist()
	{
		iterator as = this->bigen();
		for (; as.current != &tail; )
		{
			node* op = as.current;
			as.current = as.current->next;
			delete op;
		}
	}
	bool save_in_file()
	{
		PlaceCursor(this->tail.pos.getX(), this->tail.pos.getY());
		std::string buf;
		cout << "\nenter file name \n";
		cin >> buf;
		ofstream fil;
		fil.open(buf);
		if (!fil.is_open())
		{
			return false;
		}
		else
		{
			for (iterator a = this->bigen(); a.current != &tail; a++)
			{
				fil << *a;
			}
		}
	}
	point* searchword(char* value, iterator& as)
	{
		iterator curr;
		curr = as;
		int size = strlen(value);
		for (; curr.current != nullptr && curr.getcurrent()->next != nullptr; ++curr)
		{
			linklist::iterator j = curr;
			for (int i = 0; i < size; i++)
			{
				if (j.getcurrent()->next == nullptr || j.getcurrent()->data != value[i])
				{
					break;
				}
				else
				{
					if (i == size - 1)
					{
						if (j.getcurrent()->data == value[i])
						{
							j++;
							as = j;
							if (as.current->data == ' ' || as.current->data == '\n' || as.current->data == '\0')
								return &curr.current->pos;
							if (as.current == nullptr)
							{
								return nullptr;
							}
							break;
						}
					}
					j++;
				}
			}
		}
		return nullptr;
	}
	void searchhorizontal(bool tol, iterator& i)
	{
		iterator as = i;
		if (tol)
		{
			if (i.current->pos.getY() > 0)
			{
				for (; i.current->pos.getY() >= as.current->pos.getY() - 1; --i)
				{
					if (i.current->pos.getX() == (as.current->pos.getX()) && i.current->pos.getY() == (as.current->pos.getY() - 1))
					{
						return;
					}
					if (i.current->pos.getX() < as.current->pos.getX() && i.current->pos.getY() == (as.current->pos.getY() - 1))
					{
						break;
					}
				}
				for (; i.current->pos.getX() < MAX_X - 1 && i.current->data != '\n'; i++)
				{

				}
				if (i.current != &this->head && i.current->pos.getX() != MAX_X - 1)
					--i;
			}
			else
			{
				return;
			}
		}
		else
		{
			if (i.current->pos.getY() < this->tail.pos.getY())
			{
				for (; i.current != &this->tail && i.current->pos.getY() <= as.current->pos.getY() + 1; ++i)
				{
					if (i.current->pos.getX() == (as.current->pos.getX()) && i.current->pos.getY() == (as.current->pos.getY() + 1))
					{
						return;
					}
					if (i.current->pos.getX() > as.current->pos.getX() && i.current->pos.getY() == as.current->pos.getY() + 1)
					{
						break;
					}
				}
				if (i.current != &this->tail)
					--i;
			}
			else
			{
				return;
			}
		}
	}
	void multipledel(iterator& tail, char* val)
	{
		int size = strlen(val);
		for (int i = 0; i < size; i++)
		{
			this->erase(tail);
		}
	}
	void multipleinsertion(char* buf, iterator& tail)
	{
		for (int i = 0; i < strlen(buf); i++)
		{
			if (tail.current->data == '\0')
			{
				cout << buf[i];
			}
			this->insert(tail, buf[i], tail.current->pos);
		}
	}
	friend class stack;
};
class stack
{
	static int max;
	class node
	{
		linklist::iterator data;
		char* dai;
		char d;
		bool insert;
		node* next;
		node* priv;
	public:
		friend class stack;
		node(linklist::iterator dat, bool as, node* nxt, node* pri, char* a = nullptr, char p = '\0')
		{
			dai = a;
			data = dat;
			insert = as;
			next = nxt;
			priv = pri;
			d = p;
		}
		~node()
		{
		}
	};
	int siz;
	node* head;
	node* tail;
public:
	stack()
	{
		head = nullptr;
		tail = nullptr;
		siz = 0;
	}
	bool push(linklist::iterator as, bool in, char* a = nullptr, char p = '\0')
	{
		if (siz == 0)
		{
			node* bs;
			if (a != nullptr)
				bs = new node(as, in, nullptr, nullptr, a);
			else
				bs = new node(as, in, nullptr, nullptr, nullptr, p);
			head = tail = bs;
			siz++;
		}
		else if (siz < this->max)
		{
			node* ps = head;
			node* bs;
			if (a != nullptr)
				bs = new node(as, in, ps, nullptr, a);
			else
				bs = new node(as, in, ps, nullptr, nullptr, p);
			ps->priv = bs;
			head = bs;
			siz++;
		}
		else if (siz == this->max)
		{
			node* ds = tail;
			tail = tail->priv;
			tail->next == nullptr;
			node* ps = head;
			node* bs;
			if (a != nullptr)
				bs = new node(as, in, ps, nullptr, a);
			else
				bs = new node(as, in, ps, nullptr, nullptr, p);
			ps->priv = bs;
			head = bs;
			delete ds;
		}
		return true;
	}
	char* pop(linklist::iterator& as, bool& a, bool& s, char& p)
	{
		if (siz > 1)
		{
			if (!this->isempty())
			{
				as = this->head->data;
				node* bs = head;
				head = head->next;
				head->priv = nullptr;
				p = bs->d;
				char* op = bs->dai;
				s = bs->insert;
				delete bs;
				siz--;
				a = true;
				return op;
			}
		}
		else if (siz == 1)
		{
			as = this->head->data;
			a = true;
			s = head->insert;
			node* pa = head;
			p = this->head->d;
			head = nullptr;
			tail = nullptr;
			siz--;
			char* t = pa->dai;
			delete pa;
			return t;
		}
		else
		{
			a = false;
			return nullptr;
		}
	}
	bool isempty()
	{
		if (head == nullptr && tail == nullptr)
		{
			if (siz == 0)
				return true;
		}
		return false;
	}
	~stack()
	{
		linklist::iterator as;
		bool a;
		bool s;
		char p = '\0';
		while (!this->isempty())
		{
			this->pop(as, a, s, p);
		}
	}
};
int stack::max = 15;
#endif