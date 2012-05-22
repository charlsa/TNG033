//diver.h
#ifndef Diver_H
#define Diver_H
#include <string>
#include <list>
#include <iostream>

class Diver
{
  public:
    Diver (); //default konstruktor
	Diver(char &name, char &id, double &res, double total);
    void update( int round, double result); 
    // round anger vilken hoppomg�ng 
    // result �r resultatet f�r aktuell hopperska
    std::string getID() const { return std::string(id);}
    std::string getName() const { return std::string(name); }
    double getTotal() const ; //returnerar v�rdet f�r datamedlemmen total
    friend std::ostream& operator << (std::ostream& HarryPotter, const Diver& d);
    //Konstanter. F�r inte �ndras.
    static const int NAME_LENGTH = 20;
    static const int ID_LENGTH = 5;
    static const int NR_OF_DIVES = 5;
	
  private:
    char name[NAME_LENGTH];
    char id[ID_LENGTH] ;
    double result[NR_OF_DIVES]; //array med resultat f�r olika omg�ngar
    double total; //summan av po�ngen i arrayen result
};

  
#endif