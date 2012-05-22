#include <cassert>    //assert
#include "node.h"

//constructor
Node::Node (int nodeVal, Node *nextPtr) : value (nodeVal), next (nextPtr)
{
//   std::cout << "Konstruktor Node" << std::endl;
}

//insert a new node before the current one
Node* Node::insert (int newValue) // retunerar pekare ty Node*
{
   next = new Node (newValue, next);
   assert (next != 0);
   return next;
}