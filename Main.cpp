#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList List;

	List.addNode(0);

	for (int i{}; i < 6; ++i)
	{
		List.addNode(i);
	}

	List.printList();

	List.deleteNode(0);

	List.printList();

	return 0;
}