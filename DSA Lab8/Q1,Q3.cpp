//#include<iostream>
//#include<queue>
//using namespace std;
//template<class T>
//class BST
//{
//private:
//	class BSTNode
//	{
//	public:
//		T data;
//		BSTNode* left;
//		BSTNode* right;
//
//	};
//	BSTNode* root;
//
//public:
//	BST()
//	{
//		root = nullptr;
//	}
//	void Insert(BSTNode*& r, T d)
//	{
//		if (r == nullptr)
//		{
//			r = new BSTNode;
//			r->data = d;
//			r->left = r->right = nullptr;
//		}
//		else
//		{
//			if (d < r->data)
//			{
//				Insert(r->left, d);
//			}
//			else if (d > r->data)
//			{
//				Insert(r->right, d);
//			}
//		}
//	}
//	void Insert(T d)
//	{
//		Insert(root, d);
//	}
//
//	/*void InsertBinaryTree(BSTNode*&btroot,T d)
//	{
//		if(btroot==nullptr)
//		{
//			btroot = new BSTNode;
//			btroot->data = d;
//			btroot->left = btroot->right = nullptr;
//		}
//		else
//		{
//			if(btroot->left==nullptr)
//			{
//				Insert(btroot->left, d);
//			}
//			else if()
//		}
//	}
//
//	void InsertBinaryTree(T d)
//	{
//		Insert(root, d);
//	}*/
//
//	/*void InsertLeft(BSTNode*&btroot,T d)
//	{
//		if(btroot==nullptr)
//		{
//			btroot = new BSTNode;
//			btroot->data = d;
//			btroot->left = btroot->right = nullptr;
//		}
//		else
//		{
//			btroot->left = new BSTNode;
//			btroot->left->->data = d;
//			btroot->left->left = btroot->left->right = nullptr;
//		}
//	}*/
//
//	int Length(BSTNode*& r)
//	{
//		if (r == nullptr)
//		{
//			return 0;
//		}
//		else
//		{
//			return 1 + Length(r->left) + Length(r->right);
//		}
//	}
//
//	int Length()
//	{
//		return Length(root);
//	}
//
//	int CountLeafNodes(BSTNode* temp)
//	{
//		if (temp == nullptr)
//		{
//			return 0;
//		}
//		else if (temp->left == nullptr && temp->right == nullptr)
//		{
//			return 1;
//		}
//		else
//		{
//			return CountLeafNodes(temp->left) + CountLeafNodes(temp->right);
//		}
//	}
//	int CountLeafNodes()
//	{
//		return CountLeafNodes(root);
//	}
//
//	void PrintSorted(BSTNode* temp)
//	{
//		if (temp != nullptr)
//		{
//			PrintSorted(temp->left);
//			cout << temp->data << " ";
//			PrintSorted(temp->right);
//		}
//
//	}
//	void PrintSorted()
//	{
//		PrintSorted(root);
//	}
//
//	/*void SwapTree(BSTNode*temp)
//	{
//		if(temp!=nullptr)
//		{
//
//		}
//	}*/
//	//void SwapTree(root);
//
//};
//
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//};
//
//Node* CreateNode(int data)
//{
//	Node* newNode = new Node();
//	if (!newNode) {
//		cout << "Memory error\n";
//		return NULL;
//	}
//	newNode->data = data;
//	newNode->left = newNode->right = NULL;
//	return newNode;
//}
//
//Node* InsertNode(Node* root, int data)
//{
//	if (root == NULL) {
//		root = CreateNode(data);
//		return root;
//	}
//	queue<Node*> q;
//	q.push(root);
//
//	while (!q.empty()) {
//		Node* temp = q.front();
//		q.pop();
//
//		if (temp->left != NULL)
//			q.push(temp->left);
//		else {
//			temp->left = CreateNode(data);
//			return root;
//		}
//
//		if (temp->right != NULL)
//			q.push(temp->right);
//		else {
//			temp->right = CreateNode(data);
//			return root;
//		}
//	}
//}
//
//void inorder(Node* temp)
//{
//	if (temp == NULL)
//		return;
//
//	inorder(temp->left);
//	cout << temp->data << ' ';
//	inorder(temp->right);
//}
//
//void Check(Node* tree1)
//{
//	if (tree1 == NULL)
//		return;
//	if (tree1->left == nullptr || tree1->right == nullptr)
//		return;
//	if (tree1->left->data > tree1->right->data)
//	{
//		int temp = tree1->left->data;
//		tree1->left->data = tree1->right->data;
//		tree1->right->data = temp;
//
//	}
//	Check(tree1->left);
//	Check(tree1->right);
//	return;
//}
//
//void main()
//{
//	BST<int> tree;
//	// Task 1
//	cout << "Binary Search Tree for Task No 1 " << endl;
//	tree.Insert(500);
//	tree.Insert(1000);
//	tree.Insert(1);
//	tree.Insert(600);
//	tree.Insert(700);
//	tree.Insert(10);
//	tree.Insert(30);
//	tree.Insert(9000);
//	tree.Insert(50000);
//	tree.Insert(20);
//	tree.PrintSorted();
//	cout << endl << "No of Leaf Nodes in the Tree : " << tree.CountLeafNodes() << endl << endl << endl;
//	system("pause");
//	system("cls");
//
//	// Task 2
//	cout << "Task No 2" << endl;
//	Node* root1 = CreateNode(5);
//	root1->left = CreateNode(3);
//	root1->left->left = CreateNode(4);
//	root1->left->right = CreateNode(2);
//	root1->right = CreateNode(8);
//	root1->right->left = CreateNode(6);
//	root1->right->right = CreateNode(10);
//
//	cout << "Binary Tree  : ";
//	inorder(root1);
//	cout << endl << endl;
//
//	cout << "Converting the tree into BSTree" << endl;
//	Check(root1);
//	inorder(root1);
//	system("pause");
//
//	/* int swap=tree1->left->data;
//			  tree1->left->data=tree1->right->data;
//			  tree1->right->data=swap;*/
//}