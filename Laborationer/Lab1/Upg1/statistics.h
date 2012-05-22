#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <climits>

//Funktionen maxmin returnerar det största värdet bland n heltal i arrayen a.
//Det minsta värdet i arrayen a placeras i referensparametern min.
int maxmin (int a[], int n, int& min);


//Funktionen mean beräknar medelvärdet för n heltal i arrayen a.
//Medelvärdet returneras från funktionen.
double mean (int a[], int n);


//Funktionen median beräknar medianvärdet för n heltal i den sorterade
//arrayen a och returnerar detta värde. Medianvärdet är det mittersta värdet
//i den sorterade arrayen. Om n är jämnt blir det medelvärdet av de två talen
//i mitten.
double median (int a[], int n);


//Returns the standard deviation of n integer numbers in array a
double standardDeviation(int a[], int n);


//Funktionen sort sorterar n heltal i arrayen a med en annan sorterings-
//algoritm än bubblesort.
void sort (int a[], int n);


//swap byter värde på de formella parametrarna a och b och används av sort
void swap(int& a, int& b);

#endif
