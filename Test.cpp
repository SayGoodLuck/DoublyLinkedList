#include "List.h"
#include<iostream>

using namespace std;


int main()
{
	List* lst = new List();

	lst->addNode(1);
	lst->addNode(2);
	lst->addNode(3);
	lst->addNode(4);
	lst->addNode(5);
	lst->addNode(6);


	lst->addNode(6);

	lst->removeNode(6);

	lst->showList();

}