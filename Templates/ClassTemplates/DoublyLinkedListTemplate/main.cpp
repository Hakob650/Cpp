#include <iostream>
#include "DoublyLinkedList.hpp"

int main()
{
	std::cout << "Constructing the list\n";
	DoublyLinkedList<int> list = {10, 20, 30};
	std::cout << "Initial List: " << list << std::endl;

	std::cout << "Inserting\n";
	list.push_front(5);
	list.push_back(40);
	std::cout << "After push_front(5) and push_bacK(40): " << list << std::endl;

	std::cout << "Accessing\n";
	std::cout << "Front: " << list.front() << " ,Back: " << list.back() << "\n";

	std::cout << "Searching\n";
	auto found = list.find(20);
	if(found)
	{
		std::cout << "Found: " << found->data << "\n"; 
	}
	else
	{
		std::cout << "Not Found\n";
	}


	std::cout << "\nMerging lists\n";
	DoublyLinkedList<int> other = {100, 200};
	std::cout << "other list: " << other << "\n";
	list.merge(other);
	std::cout << "After Merge: " << list << "\n";
	std::cout << "Other should now be empty: " << other << "\n";

	std::cout << "\nClearing\n";
	list.clear();
	std::cout << "After clear(): " << list << "(size: " << list.size() << ")\n";

	return 0;
}