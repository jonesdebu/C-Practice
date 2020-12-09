#include <iostream>

bool binarySearch(int arr[], int low, int high, int value) 
{
	if (high >= low)	//Base Case for Recursion
	{
		int mid = low + high / 2;

		if (arr[mid] == value) { return true; }

		if (value < arr[mid])	//search left half of array
		{
			return binarySearch(arr, low, mid - 1, value);
		}

		if (value > arr[mid])
		{
			return binarySearch(arr, mid + 1, high, value);
		}

	}
	return false;
}

int main()
{
	int array[] = { 2, 4, 6, 7, 8, 12, 15 };
	int length = sizeof(array) / sizeof(array[0]);
	
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << '\n';
	}

	std::cout << '\n';
	
	std::cout << binarySearch(array, 0, length - 1, 4) << '\n';
	std::cout << binarySearch(array, 0, length - 1, 3) << '\n';
	return 0;
}