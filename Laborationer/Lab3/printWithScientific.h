/*
 *  printWithScientific.h
 *  Lab3
 *
 *  Created by Kalle Westerberg on 2012-04-27.
 *  Copyright 2012 Liu. All rights reserved.
 *
 */
#ifndef PRINTWITHSCIENTIFIC_H_INCLUDED
#define PRINTWITHSCIENTIFIC_H_INCLUDED

#include "printStrategy.h"

class PrintWithScientific : public PrintStrategy{

public:
	PrintWithScientific(){}
	~PrintWithScientific(){}
	void print(double x, std::ostream& out);
};
#endif