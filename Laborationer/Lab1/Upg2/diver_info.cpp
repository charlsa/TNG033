#include "diver_info.h"
#include <istream>
#include <sstream>
#include <iomanip>

bool read_line(istream& in, double d[], double &dif);

//Implementera följande funktioner


istream& read (istream& in, Diver_info& j)
{
//	in.getline(j.name, NAME_LENGTH);  // frŒn in till structen diver
	if (!(in.getline(j.name, NAME_LENGTH)))
	{
		j.difficulty=ERROR;
		return in;
	}
	if(read_line(in, j.points, j.difficulty)) return in;
    else
    {
        j.difficulty=ERROR;
        cout<< "ERROR: "<< j.name <<endl;
    }
	return in;	
}

bool read_line(istream& in, double d[], double &dif)
{
	string line;
	getline(in,line);
	istringstream streamed(line);
	
	streamed >> dif;
	
	double score; 
	int i = 0;
	while (streamed >> score && (i < NR_OF_REF)) 
	{
		d[i++] = score;
	}
	streamed >> ws;
	if(streamed.eof() && i == NR_OF_REF) // if last bite true
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Beräknar totalpoäng för hoppet för diver j enligt reglerna, se instruktionen.
void calculate_final(Diver_info& j)
{
	double sum = 0;
	double max = j.points[0];
	double min = j.points[0];
	
	for (int i = 0; i < NR_OF_REF; i++)
	{
	//	if (max < j.points[i]) max = j.points[i];
	//	if (min > j.points[i]) min = j.points[i];
	//	j.final_score += j.points[i]*((3*j.difficulty)/5);
		
		if (max < j.points[i])
		{
			max = j.points[i];
		}
		else if (min > j.points[i])
		{
			min = j.points[i];
		}
		sum += j.points[i];
	}
//	j.final_score -= (max-min)*((3*j.difficulty)/5);
	j.final_score =  (double) 3/5 * (sum-(max+min)) * j.difficulty;
//	j.final_score=(((sum-max)-min)/5)*3*j.difficulty;
}

//prints skriver ut data till standard output (cout) för diver j.
void print(const Diver_info& j)
{
	if (j.difficulty != ERROR) 
	{
		cout << setw(25) << left << j.name;
		cout << fixed << setprecision(1) << j.final_score << endl;
	}
	else
	{
		cout << j.name << endl;
		cout << "Resultat: " << j.difficulty << endl;
	}
		
}