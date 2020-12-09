
#include <iostream>
#include "d_linked_list.h"

d_linked_list::d_linked_list()
{
	head = NULL;
	tail = NULL;
}

void d_linked_list::append_node(int value)
{
	node* tmp = new node;
	tmp->data = value;
	tmp->next = NULL;
	tmp->previous = tail;

	if(head == NULL)
	{
		head = tmp;
		tail = tmp;
	}

	else //add node normal way
	{
		tail->next = tmp;	//put new node on the end
		tail = tail->next;	//move tail to the end
		
	}

}

void d_linked_list::add_node(int position, int value)
{
	// A C to A B C
	node* new_node = new node;
	new_node->data = value;
	new_node->next = NULL;
	
	if (head == NULL)
	{
		head = new_node;
		std::cout << "New node is now the head" << std::endl;
		return;
	}

	int count = 1;
	node* traverse = head;
	
	while (traverse != NULL)
	{
		if (traverse->next == NULL)	//at the end of the list
		{
			traverse->next = new_node;
			new_node->previous = traverse;
			tail = new_node;
			
			std:: cout << "insert position is at or past end of list node is now at tail of list" << std::endl;
			std::cout << "Node: " << value << " inserted..." << std::endl;
			std::cout << "previous node data: " << new_node->previous->data << std::endl <<std::endl;							//print new node's previous node
			return;
		}

		else if (count != position)
		{
			count++;
			traverse = traverse->next;
		}

		else if(count == position)
		{

			if (traverse == head)
			{
				new_node->next = traverse;
				traverse->previous = new_node;
				head = new_node;

				std::cout << new_node->data << " is now the head of the list" << std::endl;
				return;
			}

			else
			{
				//once reach position insert node inbetween position and next
				new_node->next = traverse;					//new node is put in place
				new_node->previous = traverse->previous;	//new node next is existing node
				traverse->previous->next = new_node;		//next of the previous node to position is now new node
				traverse->previous = new_node;				//existing node previous is now new node
				

				std::cout << "Node: " << value << " inserted" << std::endl;
				std::cout << "previous node data: " << new_node->previous->data << std::endl;	//print previous of new node
				std::cout << "next node data: " << new_node->next->data << std::endl;			//print next of new node

				return;
			}
		}
	
	}
}

int d_linked_list::remove_node(int value)
{

	if (head->data == value)
	{
		node* tmp = head;
		head = head->next;
		std::cout << "Node: " << value << " removed" << std::endl << std::endl;
		delete tmp;
		return 1;
	}

	node* traverse;
	traverse = head;
	while (traverse->next != NULL)
	{
		if (traverse->next->data == value)
		{
			//remove the node
			node* tmp = traverse->next->next;	//	set tmp to the node after the remove node 
			delete traverse->next;				//	remove the remove node
			traverse->next = tmp;				//	set the before node's next to the after node
			tmp->previous = traverse;			//	set the after node's previous to the before node
			std::cout << "Node: " << value << " removed" << std::endl << std::endl;
			return 1;
		}

		else
		{
			traverse = traverse->next;
		}
	}

	std::cout << "No node with value: " << value << " found" << std::endl;
	return 0;
}

void d_linked_list::display()
{
	node* traverse;
	traverse = head;
	std::cout << "Current list: ";
	while (traverse != NULL)
	{
		std::cout << traverse->data << " ";
		traverse = traverse->next;
	}
	std::cout << std::endl << std::endl;
}

void d_linked_list::get_head()
{
	std::cout << "Head of the list is: " << head->data << std::endl;
}

void d_linked_list::get_tail()
{
	std::cout << "Tail of the list is: " << tail->data << std::endl;
}
