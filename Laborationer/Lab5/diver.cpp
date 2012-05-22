/*
 *  diver.cpp
 *  Lab5
 *
 *  Created by Kalle Westerberg on 2012-05-18.
 *  Copyright 2012 Liu. All rights reserved.
 */
#include "diver.h"
#include <iomanip>
#include "iostream" 

Diver::Diver(){}

Diver::Diver(char &name, char &id, double &res, double tot){
	*this->name = name;		// *this blir objektet ???
	*this->id = id;
	*this->result = res;
	this->total = tot;     
}

void Diver::update(int round, double points){
	result[round-1] = points;
	total = getTotal();
}

double Diver::getTotal() const{
	double total = 0;
	
	for (int i = 0; i < NR_OF_DIVES; i++) {
		if (result[i] == -1) {
			return total;
		}
		else {
			total += result[i];
		}
	}
	return total;
}

std::ostream& operator << (std::ostream& HarryPotter, const Diver& d){
	
	HarryPotter << d.getID() << "  " << std::setw(20) << std::left << d.getName();
	
	for (int i = 0; i < d.NR_OF_DIVES; i++) {
		if (d.result[i] != -1) {
			HarryPotter <<  std::setw(8) << d.result[i] << "  ";
		}
	}
	HarryPotter << d.total << std::endl;
	return HarryPotter;
}