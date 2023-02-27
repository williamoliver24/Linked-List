#include <iostream>
#include <vector>
#include "LinkedList.h"

int main()
{
	std::vector entries{ 1, 2, 3, 2, 4, 34, 2, 45, 2, 3, 1, 0, 100 };

	LinkedList List;	

	List.addNodes(entries);

	List.printList();

	List.deleteNode(1);

	List.printList();

	return 0;
}