//#include<iostream>
//using namespace std;
//
//template<class t>
//class BST
//{
//private:
//	class BNode
//	{
//	public:
//		t data;
//		BNode* left;
//		BNode* right;
//		BNode()
//		{
//			left = right = nullptr;
//			data = 0;
//		}
//		BNode(t d, BNode* l, BNode* r)
//		{
//			data = d;
//			left = l;
//			right = r;
//		}
//	};
//	BNode* root;
//public:
//	BST()
//	{
//		root = nullptr;
//	}
//
//	void InsertR(BNode*& r, t d)
//	{
//		if (r == nullptr)
//		{
//			r = new BNode;
//			r->data = d;
//			r->right = r->left = nullptr;
//		}
//		else
//		{
//			if (d < r->data)
//			{
//				InsertR(r->left, d);
//			}
//			else if (d > r->data)
//			{
//				InsertR(r->right, d);
//			}
//		}
//	}
//
//	void InsertR(t d)
//	{
//		InsertR(root, d);
//	}
//
//	void InsertI(t d)
//	{
//		BNode* curr = root;
//		BNode* P = curr;
//		while (curr != nullptr)
//		{
//			P = curr;
//			if (d > curr->data)
//			{
//				curr = curr->right;
//			}
//			else if (d < curr->data)
//			{
//				curr = curr->left;
//			}
//			else if (d == curr->data)
//			{
//				return;
//			}
//		}
//		if (root == nullptr)
//		{
//			root = new BNode(d, nullptr, nullptr);
//		}
//		else
//		{
//			curr = new BNode(d, nullptr, nullptr);
//			if (d < P->data)
//			{
//				P->left = curr;
//			}
//			else
//			{
//				P->right = curr;
//			}
//		}
//	}
//
//	void InOrderPrint(BNode* r)
//	{
//		if (r != nullptr)
//		{
//			InOrderPrint(r->left);
//			cout << r->data << " ";
//			InOrderPrint(r->right);
//		}
//	}
//	void InOrderI()
//	{
//		BNode* curr = root;
//
//	}
//	void InOrderPrint()
//	{
//		InOrderPrint(root);
//	}
//	void PostOrderPrint(BNode* r)
//	{
//		if (r != nullptr)
//		{
//			PostOrderPrint(r->left);
//			PostOrderPrint(r->right);
//			cout << r->data << " ";
//		}
//	}
//	void PostOrderPrint()
//	{
//		PostOrderPrint(root);
//	}
//
//	void PreOrderPrint(BNode* r)
//	{
//		if (r != nullptr)
//		{
//			cout << r->data << " ";
//			PreOrderPrint(r->left);
//			PreOrderPrint(r->right);
//		}
//	}
//
//	void PreOrderPrint()
//	{
//		PreOrderPrint(root);
//	}
//
//	int NoofNodes(BNode*& r)
//	{
//		if (r == nullptr)
//			return 0;
//		else
//			return 1 + NoofNodes(r->left) + NoofNodes(r->right);
//	}
//	int NoOfNodes()
//	{
//		return NoofNodes(root);
//	}
//
//	int Height(BNode*& r)
//	{
//		if (r == nullptr)
//			return 0;
//		else
//		{
//			int lH = Height(r->left);
//			int rH = Height(r->right);
//
//			if (lH > rH)
//				return (1 + lH);
//			else
//				return (1 + rH);
//		}
//	}
//	int GetHeight(BNode*& r)
//	{
//		if (r == nullptr)
//			return -1;
//		else if (r->left == nullptr && r->right == nullptr)
//			return 0;
//		else
//		{
//			int lH = Height(r->left);
//			int rH = Height(r->right);
//
//			if (lH > rH)
//				return (1 + lH);
//			else
//				return (1 + rH);
//		}
//	}
//	int GetH()
//	{
//		return GetHeight(root);
//	}
//
//	int CountLeafNodes(BNode*& head)
//	{
//		if (head == nullptr)
//			return 0;
//		else if (head->left == nullptr && head->right == nullptr)
//		{
//			return 1;
//		}
//		else
//			return  CountLeafNodes(head->left) + CountLeafNodes(head->right);
//	}
//	int CountLeafNodes()
//	{
//		return CountLeafNodes(root);
//	}
//	int Height()
//	{
//		return Height(root);
//	}
//
//	bool Search(BNode*& r, int key)
//	{
//		if (r == nullptr)
//			return false;
//		else if (r->data == key)
//			return true;
//		else
//		{
//			if (r->data > key)
//			{
//				Search(r->left, key);
//			}
//			else if (r->data < key)
//			{
//				Search(r->right, key);
//			}
//		}
//	}
//	bool Search(int key)
//	{
//		return Search(root, key);
//	}
//
//	/*void Update(BNode*& roo, int key1, int key2)
//	{
//		BNode* curr = root;
//		BNode* prev = curr;
//		while (curr != nullptr)
//		{
//			prev = curr;
//			if (key1 > curr->data)
//			{
//				curr = curr->right;
//				if (key1 == curr->data)
//				{
//					break;
//				}
//			}
//			else if (key1 < curr->data)
//			{
//				curr = curr->left;
//				if (key1 == curr->data)
//				{
//					break;
//				}
//			}
//		}
//
//		if (prev->data > key2)
//		{
//			curr->data = key2;
//			if (curr->left > curr->right && curr->right != nullptr && curr->left != nullptr)
//			{
//				int temp = curr->left->data;
//				curr->left->data = curr->right->data;
//				curr->right->data = temp;
//			}
//			else if (curr->right == nullptr&&curr->left!=nullptr && curr->data < curr->left->data)
//			{
//				int temp = curr->left->data;
//				curr->right = curr->left;
//				delete curr->left;
//			}
//		}
//		else if (prev->data < key2)
//		{
//			BNode* temp = prev->right;
//			prev->right = prev->left;
//			if (temp->data > prev->right->data)
//			{
//				prev->right->right = temp;
//			}
//			else if (temp->data < prev->right->data)
//			{
//				if(prev->right->left->data)
//			}
//		}
//	}*/
//
//	/*bool operator==(BST root1, BST root2)
//	{
//		if (r != nullptr)
//		{
//			if (root1->left == root2->left)
//			{
//				root1 = root1->left;
//				root2 = root2->left;
//			}
//			if (root1->data != root2->data)
//				return false;
//			root1->right == root2->right;
//		}
//		return true;
//	}*/
//	/*void DeleteNode(BNode*& r, int d)
//	{
//		if (r != nullptr)
//		{
//
//		}
//	}*/
//	void Destroy(BNode*r)
//	{
//		if (r != nullptr)
//		{
//			Destroy(r->left);
//			Destroy(r->right);
//			delete r;
//		}
//	}
//
//	~BST()
//	{
//		Destroy(root); 
//	}
//};
//int main()
//{
//	BST<int> treeR;
//	treeR.InsertR(9);
//	treeR.InsertR(20);
//	treeR.InsertR(1);
//	treeR.InsertR(19);
//	treeR.InsertR(31);
//	treeR.InsertR(6);
//	treeR.InsertR(22);
//	treeR.InsertR(18);
//	treeR.InsertR(23);
//
//	BST<int>treeI;
//	treeI.InsertI(9);
//	treeI.InsertI(20);
//	treeI.InsertI(1);
//	treeI.InsertI(19);
//	treeI.InsertI(31);
//	treeI.InsertI(6);
//	treeI.InsertI(22);
//	treeI.InsertI(18);
//	treeI.InsertI(23);
//
//	treeR.InOrderPrint();
//	cout << endl;
//	treeI.InOrderPrint();
//	cout << endl;
//	cout << endl;
//
//
//	treeR.PostOrderPrint();
//	cout << endl;
//	treeI.PostOrderPrint();
//	cout << endl;
//	cout << endl;
//
//	treeR.PreOrderPrint();
//	cout << endl;
//	treeI.PreOrderPrint();
//	cout << endl; cout << endl;
//
//	cout << treeI.NoOfNodes();
//	cout << endl;
//	cout << treeR.NoOfNodes();
//	cout << endl;
//	cout<<treeI.Height();
//	cout << endl;
//	cout << treeI.GetH() << endl;
//	cout<<treeR.CountLeafNodes();
//	cout << endl << endl;
//	cout<<treeI.Search(24);
//
//	cout << endl << endl << endl;
//	/*if (treeR == treeI)
//		cout<< true;
//	else
//		cout << false;*/
//}