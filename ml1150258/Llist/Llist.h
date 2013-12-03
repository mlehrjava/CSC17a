//Mark E. Lehr
//Nov 27th, 2013
//List Specification
//Minimalist List


#ifndef LLIST_H
#define LLIST_H
#include "Node.h"
#include <cstddef>  //Null definition
#include <cassert>  //Assert function

class Llist{
    private:
	Node *first;  //Node Head
	Node *last;   //Node Tail
	int count;    //Number of Nodes
    public:
	Llist();
	~Llist();
	int getLength();         //Number of Nodes
	Object * fromFront(int); //Return nth Object from the front
	void insert(Object &);   //Insert an Object
};


#endif