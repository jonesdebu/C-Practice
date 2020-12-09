// This file contains the 'main' function. Program execution begins and ends there.
// Driver Code to test Linked List.

#include <iostream>
#include "d_linked_list.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
    d_linked_list my_list;
    my_list.append_node(5);
    my_list.append_node(6);
    my_list.append_node(4);
    my_list.display();
    my_list.remove_node(6);

    my_list.add_node(4, 7);
    my_list.display();
    my_list.add_node(3, 2);
    my_list.display();
    my_list.add_node(1, 1);
    my_list.display();
    my_list.get_head();
    my_list.get_tail();
    my_list.remove_node(1);
    my_list.get_head();
    my_list.display();
    my_list.add_node(3, 9);
    my_list.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
