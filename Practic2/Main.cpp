#include <iostream>

#include "MySortedArray.hpp"

void PrintArray(MyArrayParent array)
{
	int capacity = array.GetCapacity();
	int size = array.GetSize();

	for(int i = 0;i < capacity;i++)
		if(i < size)
			std::cout << '[' << i << "]\t" << array.GetComponent(i) << std::endl;
		else
			std::cout << '[' << i << "]\t[_]" << std::endl;
}

int main()
{
	// Задание 2.1
	MyArrayParent parent(5);
	parent.Push(3.5);
	parent.Push(2.0);
	parent[2] = 1.0;

	std::cout << "MyArrayParent: " << std::endl;
	PrintArray(parent);

	std::cout << "Index of 1.0 is " << parent.IndexOf(1.0) << std::endl;

	MyArrayParent copy(parent);
	std::cout << "MyArrayParent (Copy): " << std::endl;
	PrintArray(copy);
 
	std::cout << "MySortedArray: " << std::endl;
	MySortedArray sorted(7);
	sorted.Push(4.0);
	sorted.Push(2.0);
	sorted.Push(3.0);
	sorted.Push(2.0);
	sorted.Push(19.0);
	sorted.Push(-2.5);
	PrintArray(sorted);

	std::cout << "Index of 4 is " << sorted.IndexOf(4.0) << std::endl;

	return 0;
}