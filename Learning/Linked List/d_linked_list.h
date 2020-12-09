struct node
{
	int data;
	node* next;
	node* previous;
};


class d_linked_list
{
private:
	node* head;
	node* tail;
public:
	d_linked_list();	
	void append_node(int value);			//appends a node to the end of the linked list
	void add_node(int position, int value);	//add a node to a position in the linked list moves existing node one position over
	int remove_node(int value);				//removes first node with date == value
	void get_head();							//returns the head of the list
	void get_tail();							//returns the tail of the list
	void pop_node();						//pops a node off the end of the list	
	void display();
};
