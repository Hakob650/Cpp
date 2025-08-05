#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include <stdexcept>
#include "DoublyLinkedList.hpp"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
	: head(nullptr), tail(nullptr), count(0) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> init)
	: DoublyLinkedList()
	{
		for(const T& val : init)
		{
			push_back(val);
		}
	}

template <typename T>
void DoublyLinkedList<T>::copyFrom(const DoublyLinkedList<T>& other)
{
	for(Node* curr = other.head; curr != nullptr; curr = curr->next)
	{
		push_back(curr->data);
	}
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
	: DoublyLinkedList() 
	{
		copyFrom(other);
	}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept
	: head(other.head), tail(other.tail), count(other.count)
	{
		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
	}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
	if(this != &other)
	{
		clear();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& other) noexcept
{
	if(this != &other)
	{
		clear();
		head = other.head;
		tail = other.tail;
		count = other.count;

		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
	}

	return *this;
} 

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value)
{
    Node* node = new Node(value, nullptr, head);
    if(head) {
        head->prev = node;
    }
    else
    {
        tail = node;
    }
    head = node;
    ++count;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value)
{
    Node* node = new Node(value, tail, nullptr);
    if(tail)
    {
        tail->next = node;
    }
    else
    {
        head = node;
    }
    tail = node;
    ++count;
}

template <typename T>
void DoublyLinkedList<T>::pop_front()
{
	if(!head)
	{
		return;
	}
	Node* temp = head;
	head = head->next;
	if(head)
	{
		head->prev = nullptr;
	}
	else
	{
		tail = nullptr;
	}
	delete temp;
	--count;
}

template <typename T>
void DoublyLinkedList<T>::pop_back()
{
	if(!tail)
	{
		return;
	}
	Node* temp = tail;
	tail = tail->prev;
	if(tail)
	{
		tail->next = nullptr;
	}
	else
	{
		head = nullptr;
	}
	delete temp;
	count--;
}

template <typename T>
void DoublyLinkedList<T>::erase(Node* node)
{
	if(!node)
	{
		return;
	}
	if(node == head)
	{
		pop_front();;
	}
	else if(node == tail)
	{
		pop_back();
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
		--count;
	}
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
	Node* curr = head;
	while(curr)
	{
		Node* temp = curr;
		curr = curr->next;
		delete temp;
	}
	head = nullptr;
	tail = nullptr;
	count = 0;
}

template <typename T>
T& DoublyLinkedList<T>::front() const
{
	if(!head)
	{
		throw std::out_of_range("List is empty~");
	}
	return head->data;
}

template <typename T>
T& DoublyLinkedList<T>::back() const
{
	if(!tail)
	{
		throw std::out_of_range("List is empty!");
	}
	return tail->data;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::find(const T& value) const
{
	Node* curr = head;
	while(curr)
	{
		if(curr->data == value)
		{
			return curr;
		}
		curr = curr->next;
	}
	return nullptr;
}

template <typename T>
void DoublyLinkedList<T>::merge(DoublyLinkedList<T>& other)
{
	if(other.head == nullptr)
	{
		return;
	}
	if(tail)
	{
		tail->next = other.head;
		other.head->prev = tail;
		tail = other.tail;
	}
	else
	{
		head = other.head;
		tail = other.tail;
	}

	count += other.count;

	other.head = nullptr;
	other.tail = nullptr;
	other.count = 0;
}

template <typename T>
typename DoublyLinkedList<T>::size_type DoublyLinkedList<T>::size() const
{
	return count;
}

#endif