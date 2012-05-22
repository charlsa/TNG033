/*
 *  printClient.cpp
 *  Lab3
 *
 *  Created by Kalle Westerberg on 2012-04-27.
 *  Copyright 2012 Liu. All rights reserved.
 *
 */
#include "printClient.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintClient::set_PrintStrategy (PrintStrategy *newPrintStrategy){
	//if (printStrategy) delete printStrategy; //deallocate memory for old strategy
	
	printStrategy = newPrintStrategy;
}

void PrintClient::print(double x){
	printStrategy->print(x, outStream);
}
	
void PrintClient::print(double *X, int n, string header){
	ofstream outStream;

	string fileName = "/Users/Charlsas/Documents/Skola/Programering/C++/Kod/Lab3/Lab3/out.txt";
	outStream.open(fileName.c_str());
	outStream << header << endl;
	
	for (int i = 0; i < n; i++) {
		printStrategy->print(X[i], outStream);
		//theFile << outStream << endl;
	}	
	outStream.close();
}