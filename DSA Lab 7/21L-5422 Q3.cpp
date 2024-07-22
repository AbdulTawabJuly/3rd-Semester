#include<iostream>
using namespace std;
template<class T>
class BST
{
private:
	class BSTNode
	{
	public:
		T data;
		BSTNode* left;
		BSTNode* right;

	};
	BSTNode* root;

public:
	BST()
	{
		root = nullptr;
	}
	void Insert(BSTNode*& r, T d)
	{
		if (r == nullptr)
		{
			r = new BSTNode;
			r->data = d;
			r->left = r->right = nullptr;
		}
		else
		{
			if (d < r->data)
			{
				Insert(r->left, d);
			}
			else if (d > r->data)
			{
				Insert(r->right, d);
			}
		}
	}
	void Insert(T d)
	{
		Insert(root, d);
	}

	BST(BST const& tree)
	{
		Copy(tree.root);
	}
	void Copy(BSTNode* obj)
	{
		if (obj != nullptr)
		{
			Insert(obj->data);
			Copy(obj->left);
			Copy(obj->right);
		}
	}

	
	int Length(BSTNode*& r)
	{
		if (r == nullptr)
		{
			return 0;
		}
		else
		{
			return 1 + Length(r->left) + Length(r->right);
		}
	}

	int Length()
	{
		return Length(root);
	}
	
	BSTNode* S(BSTNode* r, T d)
	{
		if (r == nullptr)
		{
			return 0;
		}
		if(r->data==d)
		{
			return r;
		}
	     if (d < r->data)
		{
			r = r->left;
			S(r, d);
		}
		else if (d > r->data)
		{
			r = r->right;
			S(r, d);
		}
	}
	BSTNode* Search(int d)
	{
		return S(root,d);
	}

	void MINMAX(int &min,int&max)
	{
		BSTNode* curr = root;
		while (curr->right != nullptr)
		{
			curr = curr->right;
		}
		max = curr->data;
		curr = root;
		while (curr->left != nullptr)
		{
			curr = curr->left;
		}
		min = curr->data;
	}
};

void main()
{
	BST<int> tree;

	tree.Insert(500);
	tree.Insert(1000);
	tree.Insert(1);
	tree.Insert(600);
	tree.Insert(700);
	tree.Insert(10);
	tree.Insert(30);
	tree.Insert(9000);
	tree.Insert(50000);
	tree.Insert(20);
	
	cout << "\nCOPY CONSTRUCTOR\n";
	BST<int> tree1(tree);

	cout << endl << endl << "Tree Length: " << tree.Length() << endl << endl;
	
		cout << "\nSEARCH:";
	if (tree.Search(1))
	{
		cout << "\nFound" << endl;
	}
	else
		cout << "NOT FOUND\n";
	if (tree.Search(123))
	{
		cout << "Found" << endl;
	}
	else
		cout << "NOT FOUND\n";
	cout << "Length of Tree: " << tree1.Length() << "\n";
	cout << endl;
	int min = 0, max = 0;
	 tree.MINMAX(min, max);
	 cout << "Min of tree is : " << min << endl;
	 cout << "Max of tree is : " << max << endl;
	system("pause");
}
