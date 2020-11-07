#include<iostream>
#include<queue>

using namespace std;

//Binary Serach Tree Node declaration
struct BSTreeNode
{
	int data;
	BSTreeNode* leftBSTree;
	BSTreeNode* rightBSTree;
};

BSTreeNode* bstreeRoot;

//Class declaration for all BST operations
class BSTOperations
{
public:
	BSTOperations()
	{
		bstreeRoot = nullptr;
	}
	BSTreeNode* insertNode(BSTreeNode* , int);
	void InOrder(BSTreeNode*);
	BSTreeNode* deleteNode(BSTreeNode*, int);
	BSTreeNode* createNode(int);
	BSTreeNode* insertNodeNonRecursive(BSTreeNode*, int);
	BSTreeNode* SearchKey(BSTreeNode*, int, BSTreeNode*&);
	BSTreeNode* minimumKey(BSTreeNode*);
	BSTreeNode* maximumKey(BSTreeNode*);
	bool isValidBST(BSTreeNode*);
};

//Function to check whether a tree is valid BST
bool BSTOperations::isValidBST(BSTreeNode* bstreeRoot)
{
	if (bstreeRoot == nullptr)
	{
		return true;
	}
	queue< BSTreeNode*> qBST;
	qBST.push(bstreeRoot);
	while (!qBST.empty())
	{
		BSTreeNode *temp = qBST.front();
		qBST.pop();

	}
}

//Function to create Binary Search Tree Node
BSTreeNode* BSTOperations::createNode(int data)
{
	BSTreeNode* node = new BSTreeNode();
	node->data = data;
	node->leftBSTree = nullptr;
	node->rightBSTree = nullptr;
	return(node);
}

//Function to insert a node iteratively
BSTreeNode* BSTOperations::insertNodeNonRecursive(BSTreeNode *bstreeRoot, int d)
{
	BSTreeNode* current = bstreeRoot;
	BSTreeNode* parent = nullptr;

	if (bstreeRoot == nullptr)
	{
		bstreeRoot = createNode(d);
		return(bstreeRoot);
	}

	while (current != nullptr)
	{
		parent = current;
		if (d < current->data)
		{
			current = current->leftBSTree;
		}
		else
		{
			current = current->rightBSTree;
		}
	}

	if (d < parent->data)
	{
		parent->leftBSTree = createNode(d);
	}
	else
	{
		parent->rightBSTree = createNode(d);
	}
	return(bstreeRoot);
}

//Function to insert a node recursively
BSTreeNode* BSTOperations::insertNode(BSTreeNode* bstreeRoot, int d)
{
	if (bstreeRoot == nullptr)
	{
		return(createNode(d));
	}
	else
	{
		if (d <= bstreeRoot->data)
		{
			bstreeRoot->leftBSTree = insertNode(bstreeRoot->leftBSTree, d);
		}
		else
		{
			bstreeRoot->rightBSTree = insertNode(bstreeRoot->rightBSTree, d);
		}
	}
	return(bstreeRoot);
}

//Function for inorder travesal of tree
void BSTOperations::InOrder(BSTreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	InOrder(root->leftBSTree);
	std::cout << " " << root->data;
	InOrder(root->rightBSTree);
}

//Search for a particular key node
BSTreeNode* BSTOperations::SearchKey(BSTreeNode* root, int d, BSTreeNode* &parent)
{
	parent = nullptr;
	if (root == nullptr)
	{
		return(nullptr);
	}
	while ((root != nullptr) && (root->data != d))
	{
		parent = root;
		if (d < root->data)
		{
			root = root->leftBSTree;
		}
		else
		{
			root = root->rightBSTree;
		}
	}
	return(root);
}

//Minimum key in the subtree rooted at current
BSTreeNode* BSTOperations::minimumKey(BSTreeNode* current)
{
	if (current == nullptr)
	{
		return(nullptr);
	}
	while (current->leftBSTree != nullptr)
	{
		current = current->leftBSTree;
	}
	return(current);
}

//Maximum key in the subtree rooted at current
BSTreeNode* BSTOperations::maximumKey(BSTreeNode* current)
{
	if (current == nullptr)
	{
		return(nullptr);
	}
	while (current->rightBSTree != nullptr)
	{
		current = current->rightBSTree;
	}
	return(current);
}


//Function for node deletion
BSTreeNode* BSTOperations::deleteNode(BSTreeNode* root, int d)
{
	BSTreeNode* rootTemp = root;
	BSTreeNode* parent = nullptr;

	if (rootTemp == nullptr)
	{
		return(nullptr);
	}
	BSTreeNode* current = SearchKey(rootTemp, d, parent);

	//Search key is not present in tree
	if (current == nullptr)
	{
		return(nullptr);
	}

	//Key node has no children
	if (current->leftBSTree == nullptr && current->rightBSTree == nullptr)
	{
		if (current == root)
		{
			root = nullptr;
		}
		else
		{
			if (parent->leftBSTree == current)
			{
				parent->leftBSTree = nullptr;
			}
			else
			{
				parent->rightBSTree = nullptr;
			}
		}
		free(current);
	}
	//Key node has two children
	else if (current->leftBSTree && current->rightBSTree)
	{
		//Two ways: 1) either replace with in-order predecssor
		//find in-order predecessor
		//BSTreeNode* predecessor = maximumKey(current->leftBSTree);
		//int valPre = predecessor->data;

		//Two ways: 2) or replace with in-order successor
		//find in-order predecessor
		BSTreeNode* successor = minimumKey(current->rightBSTree);
		int valPre = successor->data;

		//delete predecessor node iteratively which may have atmost one right child
		root = deleteNode(root, successor->data);
		current->data = valPre;
	}
	//Key node has only one right child
	else
	{
		BSTreeNode* branchKey = (current->leftBSTree) ? current->leftBSTree : current->rightBSTree;
		if (current == root)
		{
			root = branchKey;
		}
		else
		{
			if (current == parent->leftBSTree)
			{
				parent->leftBSTree = branchKey;
			}
			else
			{
				parent->rightBSTree = branchKey;
			}
		}
	}
	return(root);
}

void main()
{
	BSTOperations BSTreeNew;
	bstreeRoot = BSTreeNew.insertNodeNonRecursive(bstreeRoot, 10);
	bstreeRoot = BSTreeNew.insertNodeNonRecursive(bstreeRoot, 15);
	bstreeRoot = BSTreeNew.insertNodeNonRecursive(bstreeRoot, 5);
	bstreeRoot = BSTreeNew.insertNodeNonRecursive(bstreeRoot, 2);
	bstreeRoot = BSTreeNew.insertNodeNonRecursive(bstreeRoot, 7);
	bstreeRoot = BSTreeNew.insertNodeNonRecursive(bstreeRoot, 12);
	bstreeRoot = BSTreeNew.insertNodeNonRecursive(bstreeRoot, 25);
	BSTreeNew.InOrder(bstreeRoot);
	BSTreeNew.deleteNode(bstreeRoot, 10);
	cout << "\n";
	BSTreeNew.InOrder(bstreeRoot);
	getchar();
}