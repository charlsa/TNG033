#include "set.h"
#include <NEW>

//Constructors
Set::Set()
{
								// Constructor for an empty set e.g Set R
	header = new Node(0,NULL);	// Node men värde 0 och referens NULL. 
}

Set::Set (const Set& b)
{// Copy constructor initialising R whit S
	header = new Node(0,NULL);	// Skapar en ny	
	
	Node* n = b.header->next;	// b.header är en pekare till
	while (n && (n->next != n)){ //ty != null true 
		insert(n->value);	// n pekar till nästa 
		n = n->next;
	}

}

Set::Set(int a[], int n){
	header = new Node(0,NULL);
	// Constructor creating a set R from n integer in the array a
	int i = 0;
	while (i < n) {
		insert(a[i]);	// insert function in Set
		i++;
	}
}

//Destructor
Set::~Set(){
// Destructor deallocating the nodes in the list, including the header node.
	for (Node* n = header; n; n = n->next) {
		header = header->next;
		delete n;
	}
	delete header;
}

bool Set::member(int x) const{
// If the element x is in the set R then true is returned, otherwise false,
	Node* n = header->next;
	while (n) {
		if (n->value == x) return true;
		n = n->next;
	}
	return false;
}

int Set::cardinality() const{
	// Returns the number of elements in the set R,
	if (empty()) {
		return 0;
	}
	Node* n = header->next;
	
	int i = 0;
	
	while (n) {
		i++;
		n = n->next;
	}
	return i;
}

bool Set::empty() const{ // Returns true if the set R is empty,
	if (!(header->next)) return true;
	return false;
}

void Set::insert(int x){
	//A private member function for inserting the element x in the set R.
	//x should be inserted in sorted order in the linked list. If x already belongs
	//to the list then it should not be inserted again.
	if(empty()){
		header->next = header->insert(x);
	}
	else {
		Node* temp = header;
		while (temp->next){ // tittar en framåt
			if(x > temp->next->value){ // mindre gå vidare
				temp = temp->next;
			}
			else if	(x < temp->next->value){ // lägger till
				temp->insert(x);			 // insert function fån node
				return;	
			}
			else if(x == temp->next->value){ // om det redan finns 
				return;
			}
		}
		temp = temp->insert(x);
	}
}

void Set::del(int x){
	Node* n = header;
	Node* temp = n;
	
	while (n) {						// sålänge != null
		if (n->next->value == x) {	
			temp = n->next;
			n->next = n->next->next;// länkar om!
			delete temp;
			return;
		}
		n = n->next;
	}
}
//Overloaded operators
//Definerar operatorerna för ett Set.
Set Set::operator+(const Set& b) const{	
	Set temp = *this;
	Node* right = b.header->next;
	
	while (right) {
		temp.insert(right->value);
		right = right->next;
	}
	return	temp; 
}

Set Set::operator*(const Set& b) const{
	Set n = *this;
	Set ny;
	//Node* n = header->next;
	Node* m = b.header->next;
	
	while (m) {
		if(n.member(m->value))
		{
			ny.insert(m->value);
		}
		m = m->next;
	}
	return ny;
}

Set Set::operator-(const Set& b) const{
	Set n = *this; // referensen pekar på första efter dummy 
	Set temp;
	Node* m = b.header->next;
	while (m) {
		temp = n - (m->value);
		n = temp;
		m = m->next;
	}
	return n; 
		
}

Set Set::operator+(int x) const{
	Node* n = header; // referensen pekar på första efter dummy 
	
	while (n->next){ // tittar en framåt
		if(x > n->next->value){
			n = n->next;
		}
		else if	(x < n->next->value){
			n->insert(x);
			return *this;	
		}
		else if(x == n->next->value){
			return *this;
		}
	}
}

Set Set::operator-(int x) const{
	Set n = *this; // referensen pekar på första efter dummy 
	if(n.member(x)){
		n.del(x);
	}
	return n; 
}

bool Set::operator<=(const Set& b) const{
	Set n = *this;
	
	for (Node* m = b.header->next; m; m = m->next) {
		if (n.member(m->value)) {
			return true;
		}
	}
	return false;
}

bool Set::operator==(const Set& b) const{
	return (*this <= b) && (this->cardinality() == b.cardinality());
}

bool Set::operator<(const Set& b) const{
	return (*this <= b) && (this->cardinality() < b.cardinality()) ;
}

const Set& Set::operator=(const Set& b){
	// Overloaded assignment operator
	// deleat
	Node* n = header; // referensen pekar på första efter dummy 
	while (n) {
		delete n; // tar bort minnet
		n = n->next;
	}
	
	header = new Node(0,NULL);
	
	Node* temp = b.header->next;
	while(temp){
		insert(temp->value);
		temp = temp->next;
	}
	return *this;
}

std::ostream& operator << (std::ostream &os, const Set &theSet){ // Printing
	Node* temp = theSet.header->next;
	if (theSet.empty()) {
		os << "Set is empty!";
		return os;
	}
	else {
		while(temp){
			os << temp->value << ", "; // ty pekare till Node anars "."
			temp = temp->next;
		}
		return os;
	}
}