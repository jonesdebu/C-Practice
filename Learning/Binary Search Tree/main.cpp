#include "bst.h"
#include <iostream>

int main()
{
	BST myTree(5);
	myTree.insert(1);
	myTree.insert(3);
	myTree.insert(8);
	myTree.displayTree(myTree.getRoot(), 0);
	std::cout << "Result: " << myTree.DFS(8) << std::endl;
	std::cout << "Result: " << myTree.DFS(3) << std::endl;
	return 0;
}