#include<iostream>
#include<queue>
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

	int CountLeafNodes(BSTNode* temp)
	{
		if (temp == nullptr)
		{
			return 0;
		}
		else if (temp->left == nullptr && temp->right == nullptr)
		{
			return 1;
		}
		else
		{
			return CountLeafNodes(temp->left) + CountLeafNodes(temp->right);
		}
	}
	int CountLeafNodes()
	{
		return CountLeafNodes(root);
	}

	void PrintSorted(BSTNode* temp)
	{
		if (temp != nullptr)
		{
			PrintSorted(temp->left);
			cout << temp->data << " ";
			PrintSorted(temp->right);
		}

	}
	void PrintSorted()
	{
		PrintSorted(root);
	}
};

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data)
{
	Node* newNode = new Node();
	if (!newNode) {
		cout << "Memory error\n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* InsertNode(Node* root, int data)
{
	if (root == NULL) {
		root = CreateNode(data);
		return root;
	}
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		else {
			temp->left = CreateNode(data);
			return root;
		}

		if (temp->right != NULL)
			q.push(temp->right);
		else {
			temp->right = CreateNode(data);
			return root;
		}
	}
}

void inorder(Node* temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << ' ';
	inorder(temp->right);
}

void Converting(Node* tree1, Node* tree2)
{
	if (tree1 == NULL)
		return;
	if (tree1->left == nullptr && tree1->right == nullptr)
	{
		return;
	}
		
	if (tree1->left->data == tree2->right->data || tree1->right->data == tree2->left->data)
	{
		Node*temp = tree1->left;
		tree1->left= tree1->right;
		tree1->right = temp;

	}
	Converting(tree1->left, tree2->left);
	Converting(tree1->right, tree2->right);
	return;
}

void main()
{
	BST<int> tree;
	// Task 3
	cout << "Binary Tree No 1 for Task No 3 " << endl;

	Node* root1 = CreateNode(1);
	root1->left = CreateNode(2);
	root1->left->left = CreateNode(4);
	root1->left->right = CreateNode(5);
	root1->left->right->left = CreateNode(7);
	root1->left->right->right = CreateNode(8);
	root1->right = CreateNode(3);
	root1->right->left = CreateNode(6);

	inorder(root1);
	cout << endl << endl;

	cout << "Binary Tree No 2 for Task No 3 " << endl;

	Node* root2 = CreateNode(1);
	root2->left = CreateNode(3);
	root2->left->right = CreateNode(6);

	root2->right = CreateNode(2);
	root2->right->left = CreateNode(4);
	root2->right->right = CreateNode(5);
	root2->right->right->left = CreateNode(8);
	root2->right->right->right = CreateNode(7);

	inorder(root2);
	cout << endl << endl;

	cout << "Converting the Binary tree 1 into Binary Tree 2 by Flipping the Nodes" << endl;
	Converting(root1, root2);
	inorder(root1);
	system("pause");
}