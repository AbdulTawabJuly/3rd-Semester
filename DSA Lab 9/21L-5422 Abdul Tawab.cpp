#include<iostream>
using namespace std;
template <class T>
class Atree
{
private:
	class Anode
	{
	public:
		T data;
		Anode* left;
		Anode* right;
		int height;
		Anode()
		{
			left = nullptr;
			right = nullptr;
			height = 0;
		}
		Anode(T d, Anode* l, Anode* r, int h)
		{
			data = d;
			left = l;
			right = r;
			height = h;
		}
	};
	Anode* root;
public:

	Atree()
	{
		root = nullptr;
	}

	int getH(Anode* r)
	{
		if (r == nullptr)
		{
			return -1;
		}
		else
		{
			return r->height;
		}
	}

	int max(int l, int r)
	{
		if (r > l)
			return r;
		else
			return l;
	}

	void rotateleft(Anode*& x)
	{
		Anode* y = x->right;
		x->right = y->left;
		y->left = x;
		x->height = 1 + max(getH(x->left), getH(x->right));
		y->height = 1 + max(getH(y->left), getH(y->right));
		x = y;
	}

	void rotateright(Anode*& x)
	{
		Anode* y = x->left;
		x->left = y->right;
		y->right = x;
		x->height = 1 + max(getH(x->left), getH(x->right));
		y->height = 1 + max(getH(y->left), getH(y->right));
		x = y;
	}


	void doublerotateleft(Anode*& x)
	{
		rotateright(x->right);
		rotateleft(x);
	}


	void doublerotateright(Anode*& x)
	{
		rotateleft(x->left);
		rotateright(x);
	}

	int BalanceFactor()
	{
		int BF = getH(root->left) - getH(root->right);
		return BF;
	}

	void InsertRec(T d, Anode*& r)
	{
		if (r == 0)
		{
			r = new Anode;
			r->data = d;
			r->left = 0;
			r->right = 0;
			r->height = 0;
		}
		if (d > r->data)
		{
			InsertRec(d, r->right);
		}
		else if (d < r->data)
		{
			InsertRec(d, r->left);
		}
		int HeightDifference = getH(r->left) - getH(r->right);
		if (HeightDifference > 1 && d < r->left->data)
		{
			rotateright(r);
		}
		if (HeightDifference < -1 && d > r->right->data)
		{
			rotateleft(r);
		}
		if (HeightDifference > 1 && d > r->left->data)
		{
			rotateleft(r->left);
			rotateright(r);
		}
		if (HeightDifference < -1 && d < r->right->data)
		{
			rotateright(r->right);
			rotateleft(r);
		}
		r->height = 1 + max(getH(r->left), getH(r->right));
	}
	void Insert(T d)
	{
		InsertRec(d, root);
	}

	void InOrder(Anode* r)
	{
		if (r)
		{
			InOrder(r->left);
			cout << r->data<<" ";
			InOrder(r->right);
		}

	}

	void InOrder()
	{
		InOrder(root);
	}

	bool Search(Anode* root, int key)
	{
		if (root) {
			if (key == root->data)
			{
				return true;
			}
				
			else if (key < root->data)
			{
				return Search(root->left, key);
			}
			else if (key > root->data)
			{
				return Search(root->right, key);
			}
			if (key != root->data)
			{
				return false;
			}
		}
		else if (root == nullptr)
		{
			return false;
		}
	}

	bool Search(int key) 
	{
		return Search(root, key);
	}

	void PostOrder(Anode* r)
	{
		if (r)
		{
			PostOrder(r->left);
			PostOrder(r->right);
			cout << r->data<<" ";

		}
		else
			return;
	}

	void PostOrder()
	{
		PostOrder(root);
	}

	void PreOrder(Anode* r)
	{
		if (r)
		{

			cout << r->data<<" ";
			PreOrder(r->left);
			PreOrder(r->right);

		}
	}

	void PreOrder()
	{
		PreOrder(root);
	}

	bool isAVL(Anode* r)
	{
		if (r)
		{

			static bool flag = true;
			isAVL(r->left);
			isAVL(r->right);
			if (getH(r->left) - getH(r->right) > 1 || getH(r->left) - getH(r->right) < (-1))
			{
				if (flag)
				{
					flag = false;
				}
			}
			return flag;
		}
		else {
			return true;
		}
	}
	bool isAVL()
	{
		return isAVL(root);
	}

	int FindMin(Anode*r)
	{
		if (r->left == 0)
		{
			return r->data;
		}
		else
		{
			FindMin(r->left);
		}
	}
	int FindMin()
	{
		return FindMin(root);
	}

	int Find2ndMin(Anode* r)
	{
		if (r->left->left == 0)
		{
			return r->data;
		}
		else
		{
			Find2ndMin(r->left);
		}
	}
	int Find2ndMin()
	{
		return Find2ndMin(root);
	}
};
int main()
{
	Atree<int>AVL;
	AVL.Insert(7);
	AVL.Insert(6);
	AVL.Insert(5);
	AVL.Insert(4);
	AVL.Insert(3);
	AVL.Insert(2);
	AVL.Insert(1);

	cout << endl;
	cout << "PostOrder Traversal : ";
	AVL.PostOrder();
	cout << endl;

	cout << endl;
	cout << "InOrder Traversal : ";
	AVL.InOrder();
	cout << endl;

	cout << endl;
	cout << "PreOrder Traversal : ";
	AVL.PreOrder();
	cout << endl;
	cout<<endl;

	cout << "Checking if the Tree is AVL or Not" << endl;
	cout << "1 if AVL and 0 if Not AVL : ";
	cout<<AVL.isAVL();
	cout << endl<<endl;

	cout << "Minimum Element in the Tree: ";
	cout << AVL.FindMin();
	cout << endl<<endl;


	cout << "2nd Minimum Element in the Tree: ";
	cout << AVL.Find2ndMin() << endl;
	cout << endl;

	cout << "Search 5 int Tree: ";
	cout << AVL.Search(5);
	cout << endl << endl;

}