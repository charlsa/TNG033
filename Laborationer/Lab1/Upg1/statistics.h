#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <climits>

//Funktionen maxmin returnerar det st�rsta v�rdet bland n heltal i arrayen a.
//Det minsta v�rdet i arrayen a placeras i referensparametern min.
int maxmin (int a[], int n, int& min);


//Funktionen mean ber�knar medelv�rdet f�r n heltal i arrayen a.
//Medelv�rdet returneras fr�n funktionen.
double mean (int a[], int n);


//Funktionen median ber�knar medianv�rdet f�r n heltal i den sorterade
//arrayen a och returnerar detta v�rde. Medianv�rdet �r det mittersta v�rdet
//i den sorterade arrayen. Om n �r j�mnt blir det medelv�rdet av de tv� talen
//i mitten.
double median (int a[], int n);


//Returns the standard deviation of n integer numbers in array a
double standardDeviation(int a[], int n);


//Funktionen sort sorterar n heltal i arrayen a med en annan sorterings-
//algoritm �n bubblesort.
void sort (int a[], int n);


//swap byter v�rde p� de formella parametrarna a och b och anv�nds av sort
void swap(int& a, int& b);

#endif
