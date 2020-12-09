struct Node
{
	int value;
	Node* left;		//pointer to left child
	Node* right;	//pointer to right child
	Node* parent;	//pointer to the parent
};

class BST
{
private:
	Node* root;

public:
	BST(int x);
	Node* getRoot();
	int getRootValue();
	void insert(int x);
	void remove(int x);
	void remove_helper(Node*, int);
	bool DFS(int x);
	bool DFS_helper(Node* current, int);
	void displayTree(Node*, int);
	void displayTreeHelper(Node* current);
};