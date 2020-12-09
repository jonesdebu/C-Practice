#pragma once
#include <iostream>

template <class T>
class myVector
{

private:
	int size;						//current size of the array
	int maxSize;					//max size of the array
	T* data;						//array holding the data

	void allocNew()					//allocates new mem for dynamic array
	{
		maxSize *= 2;
		T* tmp = new T[maxSize];		//tmp array with new maxSize
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
	}

public:
	myVector()						//default constructor
	{
		size = 0;
		maxSize = 3;
		data = new T[maxSize];
	}

	myVector(int n)		  				//constructor where user specifies size
	{
		size = n;
		maxSize = n * 2;
		data = new T[maxSize];
	}

	myVector(const myVector&);				//copy constructor

	void push_back(const T item)			//append an item to the end of the array
	{
		if (size + 1 > maxSize) {
			allocNew();
		}

		data[size] = item;
		size++;
	}

	void pop_back()
	{
		data[size - 1] = NULL;
		size--;
		return;
	}

	bool empty()
	{
		if (size == 0)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	~myVector()						//destructor | don't really need it with this set up
	{
		delete[] data;
	}

	int getSize()					//returns the size of the array
	{
		return size;
	}

	int getMaxSize()
	{
		return maxSize;
	}

	int getCapacity()
	{
		return sizeof(myVector::data);
	}

	T& operator[](int i)			//indexing operator overload 
	{
		return data[i];
	}

	friend std::ostream& operator<<(std::ostream& output, myVector<T>& v)
	{
		output << '[';
		for (int i = 0; i < v.getSize()-1; i++)
		{
			output << v[i] << ", ";
		}
		output << v[v.getSize() - 1];
		output << ']';
		return output;
	}

};



int main()
{
	myVector<int> testVec;

	std::cout << testVec.getSize() << std::endl;

	testVec.push_back(4);
	testVec.push_back(5);
	testVec.push_back(6);
	testVec.pop_back();

	std::cout << testVec.getSize() << std::endl;

	std::cout << testVec << std::endl;

	myVector<int> vec2;

	std::cout << "testVec isEmpty: " << testVec.empty() << std::endl;

	std::cout << "vec2 isEmpty: " << vec2.empty() << std::endl;

	std::cout << testVec.getCapacity() << std::endl;

	std::cout << testVec.getMaxSize() << std::endl;

	//testVec.~myVector(); //only used if instansiated with new keyword | testVec is a stack local object not a heap object

	return 0;
}