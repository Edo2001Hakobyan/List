#include <iostream>
#include <cassert>
#include "list.hpp"

int main()
{
	List list;
	//Check that size is 0 and list is empty
	assert(list.get_size() == 0);
	assert(list.is_empty() == true);

	//Add nodes to the list
	list.push_back(1);
        list.push_back(2);
        list.push_back(3);

	//Check that the size is 3 and list is not empty
	assert(list.get_size() == 3);
	assert(list.is_empty() == false);

	list.print();
	return 0;
}
