/*
 *  printWithLetters.cpp
 *  Lab3
 *
 *  Created by Kalle Westerberg on 2012-04-27.
 *  Copyright 2012 Liu. All rights reserved.
 *
 */

#include "printWithLetters.h"
#include <string>
#include <ostream>
#include <sstream>

using namespace std;

void PrintWithLetters::print(double x, std::ostream& out){
	string::iterator i;	
	
	
	ostringstream os;
	os << x;
	string temp = os.str();
	
	i = temp.begin();
	while (i < temp.end()) {
		switch (*i) {
			case '0':
				out << "Zero ";
				break;
			case '1':
				out << "One ";
				break;
			case '2':
				out << "Two ";
				break;
			case '3':
				out << "Three ";
				break;
			case '4':
				out << "Four ";
				break;
			case '5':
				out << "Five ";
				break;
			case '6':
				out << "Six ";
				break;
			case '7':
				out << "Seven ";
				break;
			case '8':
				out << "Eight ";
				break;
			case '9':
				out << "Nine ";
				break;
			case ',':
				out << "Comma ";
				break;
			case '.':
				out << "Comma ";
				break;

			default:
				break;
		}
		i++;
	}
	out << endl;
}