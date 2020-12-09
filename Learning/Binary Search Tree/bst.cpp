#include "bst.h"
#include <iostream>
#include <iomanip>

BST::BST(int x)
{
	root = new Node;
	root->value = x;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
}

int BST::getRootValue()
{
	return root->value;
}

Node* BST::getRoot()
{
	return root;
}

void BST::insert(int x)		//insert
{
	Node* traverse = root;
	Node* newNode = new Node;
	newNode->value = x;
	newNode->left = NULL;
	newNode->right = NULL;


	while (traverse) {
		
		if (traverse->value > x)
		{
			if (traverse->left)
			{
				traverse = traverse->left;
			}
			else
			{
				traverse->left = newNode;
				newNode->parent = traverse;
				break;
			}
		}
		
		else                                         //current node value < x then move right
		{
			if (traverse->right)
			{
				traverse = traverse->right;
			}
			else
			{
				traverse->right = newNode;
				newNode->parent = traverse;
				break;
			}
		}			
	}
	return;
}

void BST::remove(int x)
{
	Node* traverse = root;
	if (traverse == NULL) return;

	if (traverse->value == x)
	{
		delete traverse;
		return;
	}
	else
	{
		if(traverse->left) remove_helper(traverse->left, x);
		if(traverse->right) remove_helper(traverse->right, x);
	}
	return;
}
void BST::remove_helper(Node* current, int x)
{
	if (current == NULL) return;

	if (current->value == x)
	{
		delete current;
		return;
	}
}

bool BST::DFS(int x)
{
	return DFS_helper(root, x);
}

bool BST::DFS_helper(Node* current, int x)
{
	if(current)					//Base case for Recursion
	{
		if (current->value == x) return true;
		else if (current->value > x) return DFS_helper(current->left, x);
		else if (current->value < x) return DFS_helper(current->right, x);
		
	}
	return false;
}


void BST::displayTree(Node* traverse, int indent = 0)	//postorder
{
	if (traverse != NULL) {
		if (traverse->right) {
			displayTree(traverse->right, indent + 4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (traverse->right) std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout << traverse->value << "\n ";
		if (traverse->left) {
			std::cout << std::setw(indent) << ' ' << " \\\n";
			displayTree(traverse->left, indent + 4);
		}
	}
}

