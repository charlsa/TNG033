#ifndef NODE_H
#define NODE_H

#include <iostream>

class Set;

class Node
{
public:
   //constructor
   Node (int, Node*);

   //insert a new node before the current one
   Node* insert (int value);

private:
   int value;
   Node* next;

   friend class Set;
   friend std::ostream& operator << (std::ostream &os, const Set &theSet);
};

#endif


