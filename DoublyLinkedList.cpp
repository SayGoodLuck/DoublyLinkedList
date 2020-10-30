#include <iostream>
#include "List.h"

using namespace std;

void List::addNode(int value)
{
	Node* node = new Node(value);

	if (head == nullptr)
		head = node;
	else
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			if (current->value == value)
			{
				delete node;
				node = NULL;
				return;
			}

			current = current->next;
		}
		current->next = node;
		node->prev = current;
	}
}

void List::showList()
{
	Node* current = head;
	if (head != nullptr)
	{
		while (current != nullptr)
		{
			cout << current->value << endl;
			current = current->next;
		}
	}
	else
		cout << "This list is empty!" << endl;
}

void List::removeNode(int value)
{
	if (head == nullptr)
		return;

	if (head->value == value)
	{
		Node* secondNode = head->next;
		delete head;
		head = secondNode;
		return;
	}
	else
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->value == value)
			{
				if (current->next != nullptr)
				{
					Node* prev = current->prev;
					Node* next = current->next;

					prev->next = next;
					next->prev = prev;

					delete current;
					current = NULL;
					return;
				}
				else
				{
					Node* prev = current->prev;
					prev->next = nullptr;
					delete current;
					current = NULL;
					return;
				}

			}
			current = current->next;
		}
		return
			throw exception("didn't found");
	}
}

void List::reverseList(Node* head, Node*& headref)
{
	Node* first;
	Node* rest;

	if (head == nullptr)
		return;

	first = head;
	rest = first->next;

	if (rest == nullptr)
	{
		headref = first;
		return;
	}

	reverseList(rest, headref);

	rest->next = first;
	first->next = nullptr;
}
