#ifndef SET_H
#define SET_H

#include <iostream>

#include "node.h"

using namespace std;

class Set {
public:
	//constructors
   Set ();
   Set (int a[], int n);
   Set (const Set& b); //copy constructor

   //destructor
   ~Set ();

   bool empty () const;
   int cardinality() const;
   bool member (int x) const;

    //overloaded operators
   Set operator+ (const Set& b) const;
   Set operator* (const Set& b) const;
   Set operator- (const Set& b) const;
   Set operator+ (int x) const;
   Set operator- (int x) const;

   bool operator<= (const Set& b) const;
   bool operator== (const Set& b) const;
   bool operator< (const Set& b) const;

	//assignment operator
   const Set& operator=(const Set& b); 

private:
   Node *header;

   void insert (int value);
   void del (int value);

   friend ostream& operator << (ostream& os, const Set& b);
};


#endif
