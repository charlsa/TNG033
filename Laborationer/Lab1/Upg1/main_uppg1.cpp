#include <iostream>
#include <fstream>
#include "statistics.h"

using namespace std;
/******************************/
/* 1. Functions declarations  */
/******************************/
//read_int l�ser heltal med cin >> till filslut, end of file, och l�gger
//in talen i arrayen a. D� man n�tt filslut ska str�mmen �terst�llas med
//clear. Funktionen returnerar antalet inl�sta heltal.
int read_int(int a[]);

//print skriver ut n heltal i arrayen a med cout. 10 tal per rad ska skrivas.
void print(int a[], int n);

//copy kopierar n heltal fr�n arrayen from till arrayen to.
//See F� 3
void copy(int *to, int *from, int n);

/******************************/
/* 2. Main function           */
/******************************/
const int NR_OF_INTEGERS = 1000;

int main ()
{
	int theNumbers[NR_OF_INTEGERS], theCopy[NR_OF_INTEGERS];

	int count = read_int (theNumbers);

	copy (theCopy, theNumbers, count);
	sort (theCopy, count);

	cout << "De inl�sta talen osorterade" << endl;
	print(theNumbers, count);

	cout << "\nDe inl�sta talen sorterade" << endl;
	print(theCopy, count);

	int max = 0, min = 0;
	max = maxmin(theNumbers, count, min);
	cout << "\nMax-vardet = " << max << " och min-v�rdet = " << min << endl;

	double theMean = mean(theNumbers, count);
	cout << "Medelvardet = " << theMean << "." << endl;

	double theMedian = median(theCopy, count);
	cout << "Medianvardet = " << theMedian << "." << endl;

	double theStandardDev = standardDeviation(theNumbers, count);
	cout << "Standard deviation = " << theStandardDev << "." << endl;

	return 0;
}
/******************************/
/* 3. Functions definitions   */
/******************************/
int read_int(int a[])
{
	int i = 0;
	while (cin >> a[i]) 
	{
		i++;
	}	
	return i;
}

void print(int a[], int n)
{
	int i = 0;
	while(i < n)
	{
		if (!(i%10))
		{
			cout << endl;
		}
		cout << a[i] << " ";
		i++;
	}
}

void copy(int *to, int *from, int n)
{
	int i = 0;
    while (i < n)
	{
		to[i] = from[i];
		i++;
	}
}