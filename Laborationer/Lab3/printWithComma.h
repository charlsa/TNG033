/*
 *  printWithComma.h
 *  Lab3
 *
 *  Created by Kalle Westerberg on 2012-04-27.
 *  Copyright 2012 Liu. All rights reserved.
 *
 */

#ifndef PRINTWITHCOMMA_H_INCLUDED
#define PRINTWITHCOMMA_H_INCLUDED

#include "printStrategy.h"

class PrintWithComma : public PrintStrategy{
	
public:
	PrintWithComma(){}
	~PrintWithComma(){}
	void print(double x, std::ostream& out);
};
#endif