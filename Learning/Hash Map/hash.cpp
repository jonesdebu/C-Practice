#include <iostream>
#include "Hash.h"

Hash::Hash(int b)
{
	buckets = b;
	table = new std::list<int>[buckets];
}

void Hash::displayHash()
{
	for (int i = 0; i < buckets; i++)		//for each bucket (in the lsit of buckets)
	{
		std::cout << i;
		for (auto x : table[i])				//print the values (in the list of values for each bucket)
		{
			std::cout << " ---> " << x;
		}
		std::cout << std::endl;
	}
}

int Hash::hashFunction(int x) {
	return x % buckets;
}

void Hash::hInsert(int value)
{
	int key_val = hashFunction(value);
	table[key_val].push_back(value);
}

void Hash::hDelete(int value)
{
	int index = hashFunction(value);
	std::list<int>::iterator i;
	for (i = table[index].begin(); i != table[index].end();)
	{
		if (*i == value)
		{
			if (i != table[index].end())
			{
				table[index].erase(i);
				return;
			}
		}
	}
}