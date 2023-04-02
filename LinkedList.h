#ifndef Classes
#define Classes

class Node // These nodes are the elements of our linked list. Each contains a piece of data (an integer here but we could use any type) and a pointer to the next node in the linked list (a null pointer by default).
{
public:
	int n_value;
	Node* n_next;

	Node(int data) //Constructor
	{
		n_value = data;
		n_next = nullptr;
	}
};

class LinkedList // Linked lists are strings of nodes, each of which contains a pointer to the next in the list.
{
public:
	Node* l_start;

	LinkedList() // Constructor: gives us an empty list.
	{
		l_start = nullptr;
	}

	LinkedList(const LinkedList& L) // Copy constructor which does a deep copy
	{
		LinkedList final;

		Node* current{ L.l_start };

		while (current)
		{
			final.addNode(current->n_value);
			current = current->n_next;
		}
	}

	~LinkedList() // Destructor: sequentially deletes each node in the list.
	{
		Node* current{ l_start };
		while (current)
		{
			Node* next{ current->n_next };
			delete current;
			current = next;
		}
	}

	void addNode(int data) // This function adds a node with a value given as argument to the end of the list.
	{
		Node* newNode{ new Node(data) };

		if (!l_start)
			l_start = newNode;
		else
		{
			Node* current{ l_start };

			while (current->n_next)
			{
				current = current->n_next;
			}
			current->n_next = newNode;
		}
	}

	void addNodes(std::vector<int>& vector) // This function adds every element of a vector to our list as a node.
	{
		for (int elet: vector)
		{
			this->addNode(elet);
		}
	}

	void clearList()
	{
		Node* temp{ nullptr };

		while (l_start)
		{
			temp = l_start;
			l_start = l_start->n_next;
			delete temp;
		}
	}

	void deleteNode(int targetData) // This function runs through the list and deletes all nodes with the value given as argument.
	{
		if (!l_start) // We ensure that the list is not empty.
		{
			std::cout << "List is empty.\n";
			return;
		}

		int counter{};

		if (l_start->n_value == targetData) // We delete strings of nodes at the start of the list with the target value.
		{
			while (l_start->n_value == targetData)
			{
				Node* temp{ l_start };
				l_start = l_start->n_next;
				delete temp;
				++counter;
			}
		}

		Node* current{ l_start };

		while (current->n_next) // We delete the rest of the nodes with the target value.
		{
			if (current->n_next->n_value == targetData)
			{
				Node* target{ current->n_next };
				current->n_next = target->n_next;
				delete target;
				++counter;
			}
			else
				current = current->n_next;
		}
		std::cout << "Deleted " << counter << " node(s)" << ".\n\n";
	}

	int nodeCount() // This function returns the number of nodes in a list.
	{
		Node* current{ l_start };
		
		int counter{};
		while (current)
		{
			++counter;
			current = current->n_next;
		}
		return counter;
	}

	int targetCount(int target) // This function returns the number of times the target data value occurs in the list.
	{
		int counter{};
		Node* current{ l_start };

		while (current)
		{
			if (current->n_value == target)
				++counter;

			current = current->n_next;
		}
		return counter;
	}

	void printList() // This function prints every value in the list along with its adress to the console.
	{
		if (!l_start)
		{
			std::cout << "No nodes in list\n";
			return;
		}

		Node* current{ l_start };
		while (current)
		{
			std::cout << "Value: " << current->n_value << ", Adress: " << current << '\n';
			current = current->n_next;
		}
		std::cout << '\n';
	}

	// Operator Overloads //
	friend LinkedList operator+(const LinkedList& a, const LinkedList& b);
	LinkedList& operator+=(const LinkedList& b);
	int& operator[](int index);
	LinkedList& operator=(LinkedList& a);
};

LinkedList operator+(const LinkedList& a, const LinkedList& b) // This operator overload allows us to concatenate lists using the binary + operator.
{
	LinkedList list{};

	Node* current{ a.l_start };

	while(current) // We add every value in the first list to our new list.
	{
		list.addNode(current->n_value);
		current = current->n_next;
	}

	current = b.l_start;

	while (current) // We add every value in the second list to our new list.
	{
		list.addNode(current->n_value);
		current = current->n_next;
	}

	return list;
}

LinkedList& LinkedList::operator+=(const LinkedList& b)
{
	Node* current{ b.l_start };

	while(current)
	{
		this->addNode(current->n_value);
		current = current->n_next;
	}

	return *this;
}

int& LinkedList::operator[](int index)
{
	assert(index >= 0 && index < this->nodeCount());

	int i{};
	Node* current{ this->l_start };
	while (current)
	{
		if (i == index)
			return current->n_value;

		current = current->n_next;
		++i;
	}

	return current->n_value; // We shouldn't ever reach this point.
}

LinkedList& LinkedList::operator=(LinkedList& a)
{
	if (this == &a) // Ensures that we can't break anything by setting a list equal to itself
		return *this;

	this->clearList();

	Node* current{ a.l_start };

	while (current)
	{
		this->addNode(current->n_value);
		current = current->n_next;
	}

	return *this;
}

#endif
