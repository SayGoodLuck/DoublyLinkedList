#pragma once


class List
{
public:
	class Node
	{
	public:
		int value;
		Node* next;
		Node* prev;

		Node(int value, Node* next = nullptr, Node* prev = nullptr)
		{
			this->value = value;
			this->next = next;
			this->prev = prev;
		}
	};

	Node* head;
	List()
	{
		head = nullptr;
	}
	~List()
	{
		Node* tail;
		while (head != nullptr)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}


	void removeNode(int value);

	void addNode(int value);

	void showList();

	void reverseList(Node* head, Node*& headref);

	void reverse(Node*& headRef);

};