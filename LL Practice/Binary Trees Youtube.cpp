//#include<iostream>
//#include<string>
//using namespace std;
//
//static int idx = -1;
//
//class Node {
//
//	friend class BinaryTree;
//public:
//
//	int data;
//	Node *left;
//	Node *right;
//
//	Node(int Data)
//	{
//		this->data = Data;
//		this->left = NULL;
//		this->right = NULL;
//	}
//};
//
//class BinaryTree
//{
//
//public:
//	Node* BuildTree(int nodes[])
//	{
//		idx++;
//		if (nodes[idx] == -1)
//		{
//			return NULL;
//		}
//
//		Node* newNode = new Node(nodes[idx]);
//		newNode->left = BuildTree(nodes);
//		newNode->right = BuildTree(nodes);
//
//		return newNode;
//	}
//};
//
//static void Preorder(Node *root)
//{
//	if (root == NULL)
//	{
//		//cout << " -1 ";
//		return;
//	}
//
//	cout << root->data<<" ";
//	Preorder(root->left);
//	Preorder(root->right);
//
//}
//
//void Inorder(Node* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	Inorder(root->left);
//	cout << root->data << " ";
//	Inorder(root->right); 
//}
//
//void PostOrder(Node* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	PostOrder(root->left);
//	PostOrder(root->right);
//	cout << root->data << " ";
//
//}
//
//int CountofNodes(Node* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	int LeftNodes = CountofNodes(root->left);
//	int RightNodes = CountofNodes(root->right);
//	
//	return LeftNodes + RightNodes + 1; 
//}
//
//int SumofNodes(Node* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	int LeftSum = SumofNodes(root->left);
//	int RightSum = SumofNodes(root->right);
//
//	return LeftSum + RightSum + root->data;
//}
//
//int Height(Node* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	int leftHeight = Height(root->left);
//	int rightHeight = Height(root->right);
//
//	int MyHeight = 0;
//	if (leftHeight > rightHeight)
//	{
//		MyHeight = leftHeight + 1;
//	}
//	else
//	{
//		MyHeight = rightHeight + 1;
//	}
//	return MyHeight;
//}
//
//int Diameter(Node* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int dia1 = Diameter(root->left);
//	int dia2 = Diameter(root->right);
//	int dia3 = Height(root->left) + Height(root->right) + 1;
//
//	if (dia1 > dia2 && dia1 > dia3)
//	{
//		return dia1;
//	}
//	else if (dia2 > dia1 && dia2 > dia3)
//	{
//		return dia2;
//	}
//	else
//	{
//		return dia3;
//	}
//}
//int main()
//{
//	int nodes[] = { 1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1 };
//
//	BinaryTree* tree = new BinaryTree();
//	Node* root = tree->BuildTree(nodes);
//	//cout << root->data;
//
//	//Preorder(root);  // Time Complexity O(n)
//
//	//Inorder(root);
//
//	// PostOrder(root);
//	
//
//	//cout<<CountofNodes(root); // TC -> O(n)
//
//	//cout << SumofNodes(root);  // TC -> O(n)
//
//	//cout << Height(root);  // TC -> O(n)
//
//	//cout << Diameter(root);  // TC -> O(n^2)
//}