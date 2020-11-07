//Author: Akshara P K
//Date: 05-Nov-2020

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

//Node definition
struct Node
{
	int data;
	Node *next;
};

//List Class declaration 
class List
{
public:
	List()
	{
		head = nullptr;
	}
	void Insert(int);
	void Delete(int);
	int Size();
	std::vector<int> Print();
	void Reverse();
	void DeleteMiddle();
private:
	Node *head;
};

//Function to insert a node
void List::Insert(int num)
{
	Node *list = head;
	if (head != nullptr)
	{
		while (list->next != nullptr)
		{
			list = list->next;
		}
		list->next = new Node();
		list->next->data = num;
		list->next->next = nullptr;
	}
	else
	{
		head = new Node();
		head->data = num;
		head->next = nullptr;
	}
}

//Function to delete a particular key
void List::Delete(int num)
{
	Node *list = head;
	Node *PrevList = head;
	Node *temp;

	while (list != nullptr)
	{
		if((head == list) && (list->data == num))
		{
				temp = list->next;
				delete(list);
				list = temp;
				head = list;
		}
		else if (list->data == num)
		{
			temp = list->next;
			delete(list);
			list = temp;
			PrevList->next = list;
		}
		else
		{
			PrevList = list;
			list = list->next;
		}
	}
}

//Function to delete middle node
void List::DeleteMiddle()
{
	int toDelete = Size()/2;
	Node *list = head;
	Node* temp;
	int countList = 0;
	while (countList < toDelete-1)
	{
		list = list->next;
		countList++;
	}
	temp = list->next;
	list->next = list->next->next;
	delete(temp);
}

//Function to return size of list
int List::Size()
{
	Node *list = head;
	int countList = 0;
	while (list != nullptr)
	{
		list = list->next;
		countList++;
	}
	return(countList);
}

//Function to print all elements in list
std::vector<int> List::Print()
{
	Node *list = head;
	std::vector<int> vecList;
	while (list != nullptr)
	{
		vecList.push_back(list->data);
		list = list->next;
	}
	return(vecList);
}

//Function to reverse list
void List::Reverse()
{
	Node *list = head;
	Node *PrevList = nullptr;
	Node *NextList = nullptr;
	std::vector<int> vecList;
	while (list != nullptr)
	{
		NextList = list->next;
		list->next = PrevList;
		PrevList = list;
		list = NextList;
	}
	head = PrevList;
}

int main()
{
	List list;

	list.Insert(10);
	list.Insert(10);
	list.Insert(20);
	list.Insert(25);
	list.Insert(10);
	list.Insert(35);
	list.Insert(5);
	list.Insert(0);
	auto nodes = list.Print();
	std::cout << "Nodes: ";
	std::copy(std::begin(nodes), std::end(nodes), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	//assert((nodes == std::vector<int>{10, 15, 20, 25, 10, 35, 5, 0}));
	//std::cout << "List size: " << list.Size() << "\n";
	//assert(list.Size() == 8);

	 list.Delete(10);
	 list.Delete(15);
	// list.Delete(20);
	// list.Delete(25);
	 list.Delete(35);
	// list.Delete(5);
	 list.Delete(0);
	 nodes = list.Print();
	 std::cout << "Nodes after deletion: ";
	 std::copy(std::begin(nodes), std::end(nodes), std::ostream_iterator<int>(std::cout, " "));
	 std::cout << "\n";
	 //assert(list.Size() == 6);
	 
	 list.Reverse();
	 nodes = list.Print();
	 std::cout << "Reversed Nodes: ";
	 std::copy(std::begin(nodes), std::end(nodes), std::ostream_iterator<int>(std::cout, " "));
	 std::cout << "\n";

	 list.DeleteMiddle();
	 nodes = list.Print();
	 std::cout << "Middle deleted Nodes: ";
	 std::copy(std::begin(nodes), std::end(nodes), std::ostream_iterator<int>(std::cout, " "));
	 std::cout << "\n";
	// assert(list.Print() == std::vector<int>{10, 15, 20, 25, 30, 35, 0});
	 std::cin.get();
}