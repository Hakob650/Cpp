#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <initializer_list>
#include <cstddef>
#include <iostream>

template <typename T>
class DoublyLinkedList
{
public:
		struct Node
		{
			T data;
			Node* prev;
			Node* next;

			Node(const T& val, Node* p = nullptr, Node* n = nullptr)
				: data(val), prev(p), next(n) {}
		};

		using size_type = std::size_t;

		DoublyLinkedList();

		DoublyLinkedList(std::initializer_list<T> init);

		DoublyLinkedList(const DoublyLinkedList& other);

		DoublyLinkedList& operator=(const DoublyLinkedList& other);

		DoublyLinkedList(DoublyLinkedList&& other) noexcept;

		DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

		~DoublyLinkedList();

		void push_front(const T& value);
		void push_back(const T& value);

		void pop_front();
		void pop_back();
		void erase(Node* node);
		void clear();

		T& front() const;
		T& back() const;
		Node* find(const T& value) const;

		void merge(DoublyLinkedList<T>& other);

		size_type size() const;

		Node* begin() { 
			if(!head)
			{
				return nullptr;
			}	
			return head; 
		}

		Node* end() {
			if(!tail)
			{
				return nullptr;
			}
			return tail; 
		}

		const Node* begin() const 
		{
			if(!head)
			{
				return nullptr;
			} 
			return head; 
		}
		
		const Node* end() const 
		{ 
			if(!tail)
			{
				return nullptr;
			}
			return tail; 
		}

		friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
			os << "[";
			const typename DoublyLinkedList<T>::Node* current = list.begin();
			bool first = true;
			while (current) {
				if (!first) {
					os << "<->";
				}
				os << current->data;
				current = current->next;
				first = false;
			}
			os << "]";
			return os;
		}
private:
		Node* head;
		Node* tail;
		size_type count;

		void copyFrom(const DoublyLinkedList<T>& other);
};
#include "DoublyLinkedList.cpp"

#endif