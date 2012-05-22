/*
 *  printWithScientific.cpp
 *  Lab3
 *
 *  Created by Kalle Westerberg on 2012-04-27.
 *  Copyright 2012 Liu. All rights reserved.
 *
 */

#include "printWithScientific.h"
#include <string>
#include <ostream>
#include <sstream>

using namespace std;

void PrintWithScientific::print(double x, std::ostream& out){
	ostringstream os;
	os << scientific << x;
	string temp = os.str();
	
	// decimal
	int ePos = (int) temp.find('e');
	int a = ePos-1;
	
	while (temp.at(a) == '0') {
		a--;
	}
	
	string tempString = temp.substr(0, a+1);
	
	if (temp.at(a) == '.') {
		tempString += '0';
	}
	
	out << tempString << "*10^";
	
	// exponent
	a = ePos+1;
	if (temp.at(a) == '+'){
		a++;
	}
	else {
		out << temp.at(a); // '-'
		a++;
	}

	while (temp.at(a) == '0') {
		a++;
		if ((temp.at(a) == '0') && a == (int)temp.length()-1) {
			out << '0' << endl;
			return;
		}
	}

	tempString = temp.substr(a, (int)temp.length()-1);
	
	out	<< tempString << endl;	
}