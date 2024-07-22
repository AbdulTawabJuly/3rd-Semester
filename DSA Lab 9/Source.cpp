//#include<iostream>
//using namespace std;
//template <class T>
//class Atree
//{
//private:
//	class Anode
//	{
//	public:
//		T data;
//		Anode* left;
//		Anode* right;
//		int height;
//		Anode()
//		{
//			left = nullptr;
//			right = nullptr;
//			height = 0;
//		}
//		Anode(T d, Anode* l, Anode* r, int h)
//		{
//			data = d;
//			left = l;
//			right = r;
//			height = h;
//		}
//	};
//	Anode* root;
//public:
//
//	Atree()
//	{
//		root = nullptr;
//	}
//
//	int getH(Anode* r)
//	{
//		if (r == nullptr)
//		{
//			return -1;
//		}
//		else
//		{
//			return r->height;
//		}
//	}
//
//	int max(int l, int r)
//	{
//		if (r > l)
//			return r;
//		else
//			return l;
//	}
//
//	void rotateleft(Anode*& x)
//	{
//		Anode* y = x->right;
//		x->right = y->left;
//		y->left = x;
//		x->height = 1 + max(getH(x->left), getH(x->right));
//		y->height = 1 + max(getH(y->left), getH(y->right));
//		x = y;
//	}
//
//	void rotateright(Anode*& x)
//	{
//		Anode* y = x->left;
//		x->left = y->right;
//		y->right = x;
//		x->height = 1 + max(getH(x->left), getH(x->right));
//		y->height = 1 + max(getH(y->left), getH(y->right));
//		x = y;
//	}
//
//
//	void doublerotateleft(Anode*& x)
//	{
//		rotateright(x->right);
//		rotateleft(x);
//	}
//
//
//	void doublerotateright(Anode*& x)
//	{
//		rotateleft(x->left);
//		rotateright(x);
//	}
//
//	/*void Insert(Anode*& r, T d)
//	{
//		if (r == nullptr)
//		{
//			r = new Anode(d, nullptr, nullptr, 0);
//		}
//		else
//		{
//			if (d < r->data)
//			{
//				Insert(r->left, d);
//				if (getH(r->left) - getH(r->right) == -2)
//				{
//					if (d > r->left->data)
//					{
//						rotateright(r);
//					}
//					else
//					{
//						doublerotateright(r);
//					}
//				}
//			}
//			else if (d > r->data)
//			{
//				Insert(r->right, d);
//				if (getH(r->left) - getH(r->right) == -2)
//				{
//					if (d > r->right->data)
//					{
//						rotateleft(r);
//					}
//					else
//					{
//						doublerotateleft(r);
//					}
//				}
//			}
//			r->height = 1 + max(getH(r->right), getH(r->left));
//		}
//	}
//
//	void Insert(T d)
//	{
//		Insert(root, d);
//	}*/
//
//
//	void InsertRec(T d, Anode*& r)
//	{
//		if (r == 0)
//		{
//			r = new Anode;
//			r->data = d;
//			r->left = 0;
//			r->right = 0;
//			r->height = 0;
//		}
//		
//		if (d > r->data)
//		{
//			InsertRec(d, r->right);
//		}
//		else if (d < r->data)
//		{
//			InsertRec(d, r->left);
//		}
//		int HeightDifference = getH(r->left) - getH(r->right);
//		
//		if (HeightDifference > 1 && d < r->left->data)
//		{
//			rotateright(r);
//		}
//		if (HeightDifference < -1 && d > r->right->data)
//		{
//			rotateleft(r);
//		}
//		if (HeightDifference > 1 && d > r->left->data)
//		{
//			rotateleft(r->left);
//			rotateright(r);
//		}
//		if (HeightDifference < -1 && d < r->right->data)
//		{
//			rotateright(r->right);
//			rotateleft(r);
//		}
//		r->height = 1 + max(getH(r->left), getH(r->right));
//	}
//
//	void InsertRec(T d)
//	{
//		InsertRec(d, root);
//	}
//
//	void Inorder(Anode* r)
//	{
//		if (r)
//		{
//			Inorder(r->left);
//			cout << r->data << " ";
//			Inorder(r->right);
//		}
//		else
//			return;
//	}
//	void Inorder()
//	{
//		Inorder(root);
//	}
//
//	void Postorder(Anode* r)
//	{
//		if (r)
//		{
//			Postorder(r->left);
//			Postorder(r->right);
//			cout << r->data << " ";
//		}
//		else
//			return;
//	}
//	void Postorder()
//	{
//		Postorder(root);
//	}
//
//	void Preorder(Anode* r)
//	{
//		if (r)
//		{
//			cout << r->data << " ";
//			Preorder(r->left);
//			Preorder(r->right);
//		}
//	}
//	void Preorder()
//	{
//		Postorder(root);
//	}
//
//};
//int main()
//{
//	Atree<int>AVL;
//	AVL.InsertRec(7);
//	AVL.InsertRec(6);
//	AVL.InsertRec(5);
//	AVL.InsertRec(4);
//	AVL.InsertRec(3);
//	AVL.InsertRec(2);
//	AVL.InsertRec(1);
//
//	AVL.Postorder();
//	cout << endl;
//
//	AVL.Inorder();
//	cout << endl;
//
//	AVL.Preorder();
//	cout << endl;
//
// 
// 
//}
