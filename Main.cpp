#include <iostream>
#include <vector>
#include <cassert>
#include "LinkedList.h"

int main()
{
	std::vector entriesA{ 1, 2, 3, 2, 4, 34, 2};

	std::vector entriesB{ 9, 2, 3, 4, 5 };

	LinkedList ListA;
	ListA.addNodes(entriesA);

	LinkedList ListB;
	ListB.addNodes(entriesB);

	ListA += ListB;

	ListA.printList();

	std::cout << "The sixth entry in ListA is: " << ListA[5] << '\n';

	return 0;
}