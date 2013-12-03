//Mark E. Lehr
//Nov 27th, 2013
//Create a node structure that has
//pointers to the information that
//might be an object not just primitive
//data

#ifndef NODE_H
#define NODE_H
#include "Object.h"

struct Node{
    Object *info;
    Node *link;
};

#endif