//Author: Akshara P K
//Date: 05-Nov-2020

#include<iostream>
#include <queue>

//Node declaration
struct Node
{
	int data;
	Node *leftNode;
	Node *rightNode;
};
Node *root;

//Class declaration of Binary Tree
class BTree
{
public:
	BTree()
	{
		root = nullptr;
	}
	Node* createNode(int);
	void insertNode(int);
	void InOrder(Node *root);
	void PreOrder(Node *root);
	void PostOrder(Node *root);
};

//Function to create node
Node* BTree::createNode(int data)
{
	Node *node = new Node();
	node->data = data;
	node->leftNode = nullptr;
	node->rightNode = nullptr;
	return(node);
}

//Function to insert node
void BTree::insertNode(int data)
{
	if (root == nullptr)
	{
		root = new Node();
		root->data = data;
		root->leftNode = nullptr;
		root->rightNode = nullptr;
	}
	else
	{
		//Used queue for creating balanced tree
		std::queue <Node*> queueNodes;
		queueNodes.push(root);
		while (!queueNodes.empty())
		{
			Node *temp = queueNodes.front();
			queueNodes.pop();
			if (temp->leftNode == nullptr)
			{
				temp->leftNode = createNode(data);
				return;
			}
			else
			{
				queueNodes.push(temp->leftNode);
			}
			if (temp->rightNode == nullptr)
			{
				temp->rightNode = createNode(data); 
				return;
			}
			else
			{
				queueNodes.push(temp->rightNode);
			}
		}
	}
}

//Inorder traversal
void BTree::InOrder(Node *root)
{
	if (root == nullptr)
	{
		return;
	}
	InOrder(root->leftNode);
	std::cout << " " << root->data;
	InOrder(root->rightNode);
}

//Preorder traversal
void BTree::PreOrder(Node *root)
{
	if (root == nullptr)
	{
		return;
	}
	std::cout << " " << root->data;
	PreOrder(root->leftNode);
	PreOrder(root->rightNode);
}

//Postorder traversal
void BTree::PostOrder(Node *root)
{
	if (root == nullptr)
	{
		return;
	}
	PostOrder(root->leftNode);
	PostOrder(root->rightNode);
	std::cout << " " << root->data;
}

void main()
{
	BTree btreeFirst;
	btreeFirst.insertNode(10);
	btreeFirst.insertNode(11);
	btreeFirst.insertNode(12);
	btreeFirst.insertNode(5);
	btreeFirst.insertNode(23);
	std::cout << "\n Pre-order: ";
	btreeFirst.PreOrder(root);
	std::cout << "\n In-order: ";
	btreeFirst.InOrder(root);
	std::cout << "\n Post-order: ";
	btreeFirst.PostOrder(root);
	getchar();
}