//Mark E. Lehr
//Nov 27th, 2013
//List Implementation
//Minimalist List

#include "Llist.h"

//Initialize the List with NULLS, etc..
Llist::Llist(){
    first=NULL;
	last=NULL;
	count=0;
}

//Destroy all the Nodes in the list
//This is done from the front to the last
Llist::~Llist(){
	Node *temp;
	while(first != NULL){
		temp=first;
		first=first->link;
		delete temp;
	}
	last=NULL;
	count=0;
}

//How many Nodes are in the list
int Llist::getLength(){
	return count;
}

//From the front go find the ith item in
//the list
Object * Llist::fromFront(int i){
	assert(i<=count&&count>0);
	Node *temp;
	int n=0;
	temp=first;
	while(i>++n){
		temp=temp->link;
	}
	return temp->info;
}

//Insert the object in the list
void Llist::insert(Object &x){
	//Create a new node
	Node *newNode;
	newNode=new Node;
	assert(newNode!=NULL);

	//Point it to the Object
	newNode->info=&x;
	newNode->link=first;
	first=newNode;
	count++;
	if(last==NULL)last=newNode;
}
void Llist::addto(Object &y){
	//create a new node
	Node *newNode;
	newNode = new Node;
	assert(newNode != NULL);

	//Point the new node to the object
	newNode ->info=&y;
	//link last to the new node to shove it into the list
	last ->link=newNode;
	count++;
}