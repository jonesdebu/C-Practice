#include <iostream>
#include "Hash.h"

int main()
{
	Hash myHash(7);
	int myArray[] = {15, 11, 27, 8, 12};
	int len = sizeof(myArray) / sizeof(myArray[0]);	//size of integer array / size of 1 integer = length of integer array (or number of integers in the array)
	std::cout << len << std::endl;
	/*for (int i = 0; i < len; i++) {
		myHash.hInsert(myArray[i]);
	}*/
	for (int x : myArray) {
		myHash.hInsert(x);
	}
	myHash.hDelete(12);
	myHash.displayHash();
	return 0;
}