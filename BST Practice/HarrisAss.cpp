//#include<iostream>
//#include<fstream>
//#include<vector>
//#include"help.h"
//using namespace std;
//class BST
//{
//	node* Root;
//public:
//	BST()
//	{
//		Root = nullptr;
//	}
//	~BST()
//	{
//		node* as = Root;
//		deleteNodes(as);
//	}
//	bool deleteNodes(node* as)
//	{
//		if (as == nullptr)
//		{
//			return false;
//		}
//		delete(as->left);
//		delete(as->right);
//		delete as;
//		return true;
//	}
//	bool insertion(int k)
//	{
//		node* a = Root;
//		if (a == nullptr)
//		{
//			node* as = new node(k, nullptr, nullptr, nullptr);
//			Root = as;
//			return true;
//		}
//		else
//		{
//			while (true)
//			{
//				if (k < a->data)
//				{
//					if (a->left == nullptr)
//					{
//						node* as = new node(k, a, nullptr, nullptr);
//						a->left = as;
//						return true;
//					}
//					else
//					{
//						a = a->left;
//						continue;
//					}
//				}
//				else if (k > a->data)
//				{
//					if (a->right == nullptr)
//					{
//						node* as = new node(k, a, nullptr, nullptr);
//						a->right = as;
//						return true;
//					}
//					else
//					{
//						a = a->right;
//						continue;
//					}
//				}
//				else
//				{
//					return false;
//				}
//			}
//		}
//	}
//	node* getRoot()
//	{
//		return this->Root;
//	}
//	bool search(int k, node* r)
//	{
//		if (r == nullptr)
//		{
//			return false;
//		}
//		if (k == r->data)
//		{
//			return true;
//		}
//		else if (k < r->data)
//		{
//			return search(k, r->left);
//		}
//		else if (k > r->data)
//		{
//			return search(k, r->right);
//		}
//
//	}
//	void Recprintpre(node* r)
//	{
//		if (r == nullptr)
//		{
//			return;
//		}
//		else
//		{
//			cout << r->data << ",";
//			Recprintpre(r->left);
//			Recprintpre(r->right);
//		}
//	}
//	void itratPrintpre()
//	{
//		node* a = this->Root;
//		stack s1;
//		s1.push(a);
//		while (!s1.isEmpty())
//		{
//			node* k;
//			s1.top(k);
//			cout << k->data << " , ";
//			s1.pop();
//			if (k->right != nullptr)
//			{
//				s1.push(k->right);
//
//			}
//			if (k->left != nullptr)
//			{
//				s1.push(k->left);
//
//			}
//		}
//	}
//	node* predices(node* as)
//	{
//		if (as->left == nullptr)
//		{
//			return as;
//		}
//		else
//		{
//			return predices(as->left);
//		}
//	}
//	node* successur(node* as)
//	{
//		if (as->right == nullptr)
//		{
//			return as;
//		}
//		else
//		{
//			return successur(as->right);
//		}
//	}
//	bool deleteNode(int key)
//	{
//		node* as = this->Root;
//		while (true)
//		{
//			if (as == nullptr)
//			{
//				return false;
//			}
//			if (key == as->data)
//			{
//				break;
//			}
//			else if (key < as->data)
//			{
//				as = as->left;
//			}
//			else if (key > as->data)
//			{
//				as = as->right;
//			}
//		}
//		node* p;
//		if (as->left != nullptr && as->right != nullptr) {
//			int temp;
//			p = this->predices(as->right);
//			if (p == as->right)
//			{
//				temp = p->data;
//				p->data = as->data;
//				as->data = temp;
//				p->parent->right = nullptr;
//			}
//			else
//			{
//				temp = p->data;
//				p->data = as->data;
//				as->data = temp;
//				p->parent->left = nullptr;
//			}
//		}
//		else if (as->left == nullptr && as->right != nullptr)
//		{
//			p = as;
//			if (as->data < as->parent->data)
//				as->parent->left = as->right;
//			if (as->data > as->parent->data)
//				as->parent->right = as->right;
//		}
//		else if (as->right == nullptr && as->left != nullptr)
//		{
//			p = as;
//			if (as->data < as->parent->data)
//				as->parent->left = as->left;
//			if (as->data > as->parent->data)
//				as->parent->right = as->left;
//		}
//		else
//		{
//			p = as;
//			if (as->data < as->parent->data)
//				as->parent->left = nullptr;
//			if (as->data > as->parent->data)
//				as->parent->right = nullptr;
//		}
//		delete p;
//	}
//	bool update(int key, int p)
//	{
//		if (search(key, this->Root))
//		{
//			if (this->insertion(p))
//			{
//				deleteNode(key);
//			}
//			else
//			{
//				return true;
//			}
//		}
//		else
//			return false;
//	}
//	int hight(node* Root)
//	{
//		if (Root == nullptr)
//		{
//			return 0;
//		}
//		else
//		{
//			int lh = hight(Root->left);
//			int rh = hight(Root->right);
//			if (lh > rh)
//			{
//				return (lh + 1);
//			}
//			else
//			{
//				return (rh + 1);
//			}
//
//		}
//	}
//	void loadcurrlevel(node* Root, int levl, BST& p)
//	{
//		if (Root == nullptr)
//		{
//			return;
//		}
//		if (levl == 1)
//		{
//			p.insertion(Root->data);
//		}
//		else
//		{
//			loadcurrlevel(Root->left, levl - 1, p);
//			loadcurrlevel(Root->right, levl - 1, p);
//		}
//	}
//	bool checkcurrlevel(node* Roota, node* Rootb, int levl)
//	{
//		if (Roota == nullptr || Rootb == nullptr)
//		{
//			return true;
//		}
//		if (levl == 1)
//		{
//			if (Roota->data != Rootb->data)
//			{
//				return false;
//			}
//		}
//		else
//		{
//			return checkcurrlevel(Roota->left, Rootb->left, levl - 1) && checkcurrlevel(Roota->right, Rootb->right, levl - 1);
//		}
//	}
//	int countinCurrlevel(node* Roo, int level)
//	{
//		if (Roo == nullptr)
//		{
//			return 0;
//		}
//		if (level == 1)
//		{
//			return 1;
//		}
//		else
//		{
//			return countinCurrlevel(Roo->left, level - 1) + countinCurrlevel(Roo->right, level - 1);
//		}
//	}
//	void operator=(BST& tree)
//	{
//		int hi = tree.hight(tree.Root);
//		for (int i = 0; i < hi; i++)
//		{
//			loadcurrlevel(tree.Root, i + 1, *this);
//		}
//	}
//	bool operator==(BST& tree)
//	{
//		int hia = this->hight(this->Root);
//		int hib = tree.hight(tree.Root);
//		if (hia == hib)
//		{
//			for (int i = 0; i < hia; i++)
//			{
//				if (!checkcurrlevel(this->Root, tree.Root, i + 1))
//				{
//					return false;
//				}
//			}
//			return true;
//		}
//		else
//			return false;
//	}
//	int countNodes()
//	{
//		node* no = this->Root;
//		if (no == nullptr)
//		{
//			return 0;
//		}
//		else
//		{
//			int a = this->hight(this->Root);
//			int sum = 0;
//			for (int i = 0; i < a; i++)
//			{
//				sum = sum + this->countinCurrlevel(this->Root, i + 1);
//			}
//			return sum;
//		}
//	}
//	bool swapNodes(node* Roo)
//	{
//		if (Roo == nullptr)
//		{
//			return true;
//		}
//		else
//		{
//			node* a = Roo->left;
//			Roo->left = Roo->right;
//			Roo->right = a;
//		}
//		swapNodes(Roo->left);
//		swapNodes(Roo->right);
//	}
//	BST* mirrorImage()
//	{
//		BST* tree = new BST;
//		*tree = *this;
//		tree->swapNodes(tree->Root);
//		return tree;
//	}
//	void levelPrinting()
//	{
//		Queue q1;
//		node* a = Root;
//		q1.Enqueue(a);
//		while (!q1.isEmpty())
//		{
//			q1.top(a);
//			cout << a->data << " , ";
//			q1.Dequeue();
//			if (a->left != nullptr)
//			{
//				q1.Enqueue(a->left);
//			}
//			if (a->right != nullptr)
//			{
//				q1.Enqueue(a->right);
//			}
//		}
//	}
//	/*void pathsum(vector<int> a)
//	{
//		a.
//	}*/
//};
//int main()
//{
//	BST tree;
//	int k = 0;
//	ifstream fin;
//	fin.open("tat.txt");
//	for (int i = 0; i < 15; i++)
//	{
//		fin >> k;
//		tree.insertion(k);
//	}
//	if (tree.search(12, tree.getRoot()))
//	{
//		cout << "Entity Exist\n";
//	}
//	else
//	{
//		cout << "dont exist\n";
//	}
//	tree.Recprintpre(tree.getRoot());
//	//tree.deleteNode(25);
//	cout << "\nprint after deleting \n";
//	tree.Recprintpre(tree.getRoot());
//	cout << "\nafter updating 2 in it\n";
//	////	if (!tree.update(22, 2))
//	//	{
//	//		cout << "\nvalue already exist or key is not present\n";
//	//	}
//	//	else
//	//	{
//	//		cout << "\nupdated\n";
//	//	}
//	//	tree.Recprintpre(tree.getRoot());
//	BST tree2;
//	tree2 = tree;
//	cout << "\n tree 2 after assigning iterativ \n";
//	tree.itratPrintpre();
//	tree2.insertion(100);
//	if (tree == tree2)
//	{
//		cout << "\n Trees are equal \n";
//	}
//	else
//	{
//		cout << "\ntrees are not equal \n";
//	}
//	cout << tree2.countNodes();
//	cout << tree2.countinCurrlevel(tree2.getRoot(), tree2.hight(tree2.getRoot()));
//	cout << "level order printing";
//	tree2.levelPrinting();
//}