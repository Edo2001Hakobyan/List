#include <iostream>
#include <cassert>
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

int& List::operator[](int index)
{
	if(index < 0 || index >= m_size)
	{
		std::cout<<"Index out of range:"<<std::endl;
	}
	Node* current = m_first;
	for(int i = 0;i < index; i++)
	{
		current = current->m_next;
	}
	return current->m_data;
}


void List::pop_back()
{
	if(is_empty())
	{
		return;
	}

	if(m_size == 1)
	{
		delete m_first;
		m_first = nullptr;
		m_last = nullptr;
		m_size = 0;
		return;
	}

	Node* current = m_first;
	while(current->m_next != m_last)
	{
            current = current->m_next;
	}

	delete m_last;
	m_last = current;
	m_last->m_next = nullptr;
	m_size--;
}

void List::insert(int index,int value)
{
	if(index < 0 || index > m_size)
	{
		std::cout<<"Index out of range"<<std::endl;
	}

	Node* new_node = new Node(value);

	if(is_empty())
	{
		m_first = new_node;
		m_last = new_node;
	}

	else if(index == 0)
	{
		new_node->m_next = m_first;
		m_first = new_node;
	}

	else
	{
		Node* current = m_first;
		for(int i = 0; i < index; i++)
		{
			current = current->m_next;
		}
		new_node->m_next = current->m_next;
	        current->m_next = new_node;	
	}
	m_size++;
}

void List::remove_value(int value)
{
	if(is_empty())
	{
		return;
	}

	if(m_first->m_data == value)
	{
		Node* old_node = m_first;
		m_first = m_first->m_next;
		delete old_node;
		return;
	}

	Node* current = m_first;
	while(current->m_next != nullptr && current->m_next->m_data != value)
	{
		current = current->m_next;
	}

	if(current->m_next != nullptr)
	{
		Node* old_node = current->m_next;
		current->m_next = current->m_next->m_next;
		delete old_node;
	}
}

void List::remove_index(int index)
{
	assert(index >= 0 &&  index < get_size());

	if (index == 0)
	{
		Node* old_node = m_first;
		m_first = m_first->m_next;
		delete old_node;
		return;
	}

	Node* current = m_first;
	for(int i = 0; i < index-1; i++)
	{
		current = current->m_next;
	}

	Node* old_node = current->m_next;
	current->m_next = current->m_next->m_next;
	delete old_node;

	if(index == get_size() - 1)
	{
		m_last = current;
	}
}
