//Author:Akshara P K
//Date: 06-Nov-2020

#include<iostream>
#include<stack>
#include<vector>
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
	vector<int> inorderIterative(BSTreeNode*);
	vector<int> preorderIterative(BSTreeNode*);
	vector<int> postorderIterative(BSTreeNode*);
	vector<vector< BSTreeNode*>> levelOrderIterative(BSTreeNode*);
};

//Function to perform inorder traversal iteratively
vector<int> BSTOperations::inorderIterative(BSTreeNode* bstreeRoot)
{
	std::stack< BSTreeNode*> stackNodes;
	vector<int> vecNodes;
	BSTreeNode* current = bstreeRoot;

	//If current pointer is null and stack is empty, lets return
	while ((current != nullptr) || (!stackNodes.empty()))
	{
		if (current != nullptr)
		{
			stackNodes.push(current);
			current = current->leftBSTree;
		}
		else
		{
			current = stackNodes.top();
			stackNodes.pop();
			vecNodes.push_back(current->data);
			current = current->rightBSTree;
		}
	}
	return(vecNodes);
}

//Function to perform preorder traversal iteratively
vector<int> BSTOperations::preorderIterative(BSTreeNode* bstreeRoot)
{
	std::stack< BSTreeNode*> stackNodes;
	vector<int> vecNodes;
	BSTreeNode* current = bstreeRoot;

	//If current pointer is null and stack is empty, lets return
	while ((current != nullptr) || (!stackNodes.empty()))
	{
		if (current != nullptr)
		{
			stackNodes.push(current);
			vecNodes.push_back(current->data);
			current = current->leftBSTree;
		}
		else
		{
			current = stackNodes.top();
			stackNodes.pop();
			current = current->rightBSTree;
		}
	}
	return(vecNodes);
}

//Function to perform postorder traversal iteratively
vector<int> BSTOperations::postorderIterative(BSTreeNode* bstreeRoot)
{
	std::stack< BSTreeNode*> stackNodes;
	stackNodes.push(bstreeRoot);

	std::stack< BSTreeNode*> stackOut;
	vector<int> vecNodes;
	BSTreeNode* current = bstreeRoot;

	//If current pointer is null and stack is empty, lets return
	while (!stackNodes.empty())
	{
		current = stackNodes.top();
		stackOut.push(current);
		stackNodes.pop();

		if (current->leftBSTree != nullptr)
		{
			stackNodes.push(current->leftBSTree);
		}
		if (current->rightBSTree != nullptr)
		{
			stackNodes.push(current->rightBSTree);
		}
	}

	while (!stackOut.empty())
	{
		vecNodes.push_back(stackOut.top()->data);
		stackOut.pop();
	}
	return(vecNodes);
}

//Function to check whether a tree is valid BST
bool BSTOperations::isValidBST(BSTreeNode* bstreeRoot)
{
	std::stack< BSTreeNode*> stackNodes;
	vector<int> vecNodes;

	if ((bstreeRoot == nullptr) || (bstreeRoot->leftBSTree == nullptr && bstreeRoot->rightBSTree == nullptr))
	{
		return true;
	}
	vecNodes = inorderIterative(bstreeRoot);

	int temp = vecNodes[0];
	for (int i =1; i < vecNodes.size(); i++)
	{
		if (temp >= vecNodes[i])
		{
			return false;
		}
		temp = vecNodes[i];
	}

	return(true);
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
		//find in-order successor
		BSTreeNode* successor = minimumKey(current->rightBSTree);
		int valPre = successor->data;

		//delete successor node iteratively which may have atmost one right child
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

//Function to return all nodes in each level as a collection of vectors
vector<vector< BSTreeNode*>> levelOrderIterative(BSTreeNode* root)
{
	vector<vector< BSTreeNode*>> vecAllLevels;
	if(root == nullptr)
	{
		return vecAllLevels;
	}

	BSTreeNode* current;
	queue< BSTreeNode*> queueNodes;
	//Insert root in to queue
	queueNodes.push(root);
	
	int count = 1;
	vector< BSTreeNode*> levelNodes;
	while (!queueNodes.empty() && count != 0)
	{
		//CountTemp is to count nodes in each level
		int countTemp = 0;
		while (count)
		{
			current = queueNodes.front();
			levelNodes.push_back(current);
			queueNodes.pop();
			count--;
			if (count == 0) //means levelNodes has all nodes inserted in the particular level
			{
				vecAllLevels.push_back(levelNodes);
				levelNodes.clear();
			}
			//if current has left sub tree, push that one to queue
			if (current->leftBSTree != nullptr)
			{
				queueNodes.push(current->leftBSTree);
				countTemp++;
			}
			//if current has right sub tree, push that one to queue
			if (current->rightBSTree != nullptr)
			{
				queueNodes.push(current->rightBSTree);
				countTemp++;
			}
		}
		//copy count of nodes to count for the other loop
		count = countTemp;
	}
	return vecAllLevels;
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
	bstreeRoot = BSTreeNew.insertNodeNonRecursive(bstreeRoot, 35);

	vector<int> vecNodes = BSTreeNew.postorderIterative(bstreeRoot);
	// Declaring iterator to the vector 
	vector<int>::iterator nodesPtr;

	// Displaying vector elements using begin() and end() 
	cout << "Post-Order Nodes : ";
	for (nodesPtr = vecNodes.begin(); nodesPtr < vecNodes.end(); nodesPtr++)
	{
		cout << *(nodesPtr) << " ";
	}
	
	BSTreeNew.deleteNode(bstreeRoot, 10);
	cout << "\nAfter Deletion: ";
	BSTreeNew.InOrder(bstreeRoot);

	cout << "\n Valid: " << BSTreeNew.isValidBST(bstreeRoot);

	vector<vector< BSTreeNode*>> vecAllLevels = levelOrderIterative(bstreeRoot);
	vector<vector< BSTreeNode*>>::iterator levelNodesIterator;
	vector< BSTreeNode*>::iterator nodesIterator;
	for (levelNodesIterator = vecAllLevels.begin(); levelNodesIterator < vecAllLevels.end(); levelNodesIterator++)
	{
		cout << "\n[";
		for (nodesIterator = (*levelNodesIterator).begin(); nodesIterator < (*levelNodesIterator).end(); nodesIterator++)
		{
			cout << (*nodesIterator)->data << ",";
		}
		cout << "]";
	}

	getchar();
}
