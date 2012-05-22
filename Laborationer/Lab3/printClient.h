/*
 *  printClient.h
 *  Lab3
 *
 *  Created by Kalle Westerberg on 2012-04-27.
 *  Copyright 2012 Liu. All rights reserved.
 *
 */
#ifndef PRINTCLIENT_H_INCLUDED
#define PRINTCLIENT_H_INCLUDED

#include <iostream>
#include <string>

#include "printStrategy.h"

using namespace std;

class PrintClient {
public:
	
	//constructor that creates a print client that prints with
	//a print strategy given by newPrintStrategy
	//and prints to the output stream out
	PrintClient(ostream& out = cout, PrintStrategy *newPrintStrategy = NULL):
	outStream(out), printStrategy(newPrintStrategy){} // måste ha ett värde på outStream innan objectet skapas! gäller även konstanter och ref
	
	~PrintClient(){}
	
	//Sets the print strategy to the one given by newPrintStrategy
	void set_PrintStrategy (PrintStrategy *newPrintStrategy);			// PrintStrategy används för att sammla alla funktioner
	
	//Prints a double d with the strategy set for the print client
	//Prints to the output stream set for the client
	void print(double x);
	
	//Prints an array X of n doubles
	//with te strategy set for the print client
	//Prints to the output stream set for the client
	//A header is printed first
	void print(double *X, int n, string header = "");
	
	
private:
	//Add any needed data members here
	PrintStrategy *printStrategy;
	ostream& outStream;
	
};

#endif //PRINTCLIENT_H_INCLUDED