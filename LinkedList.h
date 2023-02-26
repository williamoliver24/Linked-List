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

	LinkedList() // Constructor. Gives us an empty list
	{
		l_start = nullptr;
	}

	~LinkedList() // Destructor. Sequentially deletes each node in the list
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

	void deleteNode(int targetData) // This function runs through the list and deletes all nodes with the value given as argument.
	{
		if (!l_start) // We ensure that the list is not empty
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
		std::cout << "Deleted " << counter << " node(s)" << ".\n";
	}

	int nodeCount() // This function returns the number of nodes in a list.
	{
		Node* current{ l_start };
		
		int i{};
		while (current)
		{
			++i;
			current = current->n_next;
		}
		return i;
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
	}
};

#endif