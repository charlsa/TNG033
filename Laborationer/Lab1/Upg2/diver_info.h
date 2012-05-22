#ifndef DIVER_INFO_H
#define DIVER_INFO_H

#include <iostream>

using namespace std;

const int NR_OF_REF = 7;  //NR_OF_REF = antal domare
const int NAME_LENGTH = 25;
const int ERROR = -1;  //indicates error in the data of a diver


//Denna post, struct, beskriver en diver, simhoppare
struct Diver_info
{
	char name[NAME_LENGTH];
	double points[NR_OF_REF];
	double difficulty;
	double final_score;
};

//Implementera följande funktioner i en ny fil diver_info.cpp


//Funktionen läser data för diver, hopparen, j från strömmen in och
//returnerar strömmen in.
//If errors were encountered while reading the data of diver j
//then j.difficulty is set to ERROR
istream& read (istream& in, Diver_info& j);


//Beräknar totalpoäng för hoppet för diver j enligt reglerna, se instruktionen.
void calculate_final(Diver_info& j);


//prints skriver ut data till standard output (cout) för diver j.
void print(const Diver_info& j);


#endif


