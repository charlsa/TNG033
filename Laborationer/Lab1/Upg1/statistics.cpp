#include <iostream>
#include <climits>
#include <math.h>
#include "statistics.h"

//Fyll på med kod för de olika funktionerna

//Funktionen maxmin returnerar det största värdet bland n heltal i arrayen a.
//Det minsta värdet i arrayen a placeras i referensparametern min.
int maxmin (int a[], int n, int& min)
{
	int max = a[0];
	min = a[0];
	
	for (int i = 1; i < n; i++)
	{
		if (max < a[i]) 
		{
			max = a[i];
		}
		else if(min > a[i])
		{
			min = a[i];
		}
		else
		{
		}
	}
	return max;
}

//Funktionen mean beräknar medelvärdet för n heltal i arrayen a.
//Medelvärdet returneras från funktionen.
double mean (int a[], int n)
{
	double sum = 0;
	int i = 0;
    while (i < n)
	{
		sum += a[i];
		i++;
	}
	double mean = sum/n;
    return mean;
}

//Funktionen median beräknar medianvärdet för n heltal i den sorterade
//arrayen a och returnerar detta värde. Medianvärdet är det mittersta värdet
//i den sorterade arrayen. Om n är jämnt blir det medelvärdet av de två talen
//i mitten.
double median (int a[], int n)
{
	double median;
	int mid;
	if (n%2 == 0) 
	{
		mid = (n+1)/2;
		// medel vid jŠmnt
		median = (a[mid-1]+a[mid])/2;
	}
	else
	{
		mid = n/2;
		median = a[mid];
	}
    return median;
}

//Returns the standard deviation of n integer numbers in array a
double standardDeviation(int a[], int n)
{
    double S = 0;
	double sum;
	double meanValue = mean(a,n);
	
	int i = 0;
	
	do // sumering 
	{
		sum += pow(a[i]-meanValue,2);
		i++;
	}while (i < n);

	S = sqrt(sum/n);
    return S;
}

//Funktionen sort sorterar n heltal i arrayen a med en annan sorterings-
//algoritm än bubblesort.
void sort(int a[], int n)
{
	int key,i;
	for(int j=1;j<n;j++)  // insertion sort
	{
		key=a[j];
		i=j-1;
		while(a[i]>key && i>=0)
		{
			swap(a[i+1], a[i]);
			i--;
		}
		a[i+1]=key;
	}
}
   
//swap byter värde på de formella parametrarna a och b och används av sort
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
