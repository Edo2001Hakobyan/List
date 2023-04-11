#include <iostream>
#include "list.hpp"

Node::Node(int data)
{
	this->m_data = data;
	this->m_next = nullptr;
}

List::List()
{
	m_first = nullptr;
	m_last = nullptr;
        m_size = 0;
}

int List::get_size()
{
	return m_size;
}

bool List::is_empty()
{
	return m_size == 0;
}

void List::push_back(int data)
{
	Node* new_node = new Node(data);
	if(is_empty())
	{
		m_first = new_node;
	}
	else
	{
		m_last->m_next = new_node;
	}
	m_last = new_node;
	m_size++;
}

void List::print()
{
	Node* current = m_first;
	while(current != nullptr)
	{
		std::cout<<current->m_data<<" ";
		current = current->m_next;
	}
	std::cout<<std::endl;
}
