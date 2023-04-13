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
        
	//Check thet 1 value is remove and list is not empty and 0 index equal is 2
	list.remove_value(1);
	assert(!list.is_empty());
	assert(list[0]==2);
        
	//Check that 1 value is insert in list and equal 0 index 
	list.insert(0,1);
	assert(list[0] == 1 );

	//Check that 1 index is remove in list and 3 value is equal 1 index
	list.remove_index(1);
	assert(list[1] == 3);

	List cp_list = list;
	cp_list.print();
	


	list.print();
	return 0;
}
