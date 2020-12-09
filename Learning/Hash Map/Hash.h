#include <list>
class Hash
{
private:
	int buckets;
	std::list<int>* table;	//table is a list of lists (list at key 1 , list at key 2, etc.

public:
	Hash(int b);		//Constructor
	void displayHash();		//display the has map
	int hashFunction(int x);		//calculate hash value for value
	void hInsert(int x);			//add value to hash map
	void hDelete(int x);			//remove a value from the hash map
};