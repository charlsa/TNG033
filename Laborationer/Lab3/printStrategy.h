/*
 *  printStrategy.h
 *  Lab3
 *
 *  Created by Kalle Westerberg on 2012-04-26.
 *  Copyright 2012 Liu. All rights reserved.
 *
 */

#ifndef PRINTSTRATEGY_H_INCLUDED
#define PRINTSTRATEGY_H_INCLUDED

#include <iostream> 
 
class PrintStrategy{
	
public:
	PrintStrategy(){}
	virtual ~PrintStrategy(){}
	virtual void print(double x, std::ostream& out) = 0;
};
#endif