#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "diver.h"

using namespace std;

bool compare(Diver a, Diver b){
	return a.getTotal() > b.getTotal();
}

void read_binary(vector<Diver> &vec){
	ifstream inFile("/Users/Charlsas/Documents/Skola/Programering/C++/Kod/Lab5/Lab5/diversMac_x86.bin", ios::binary);
	
	Diver diver;
	
	// Number of divers form bineryfile
	inFile.seekg(0, ios::end);
	int endPos = (int) inFile.tellg();
	inFile.seekg(0, ios::beg);
	int begPos = (int) inFile.tellg();
	int size = (endPos-begPos)/sizeof(Diver);
	
	for (int i = 0; i < size; i++) {
		inFile.read((char *) (&diver), sizeof(Diver)); //&diver referens till diver objekt.
		vec.push_back(diver);
	}
	inFile.close();
	
	sort(vec.begin(),vec.end(), compare);
}

bool get_diver(ifstream &file, int &id, double &res){
	double dif;
	double score[7];
	
// Read ID 
	string line;
	getline(file,line);
	
	if(file.eof()) return false;
	
	while (line[0] != 'D') {
		getline(file,line);
	}
	
	id = (atoi(line.substr(1, 4).c_str())-200);
	
// Read results	
	getline(file,line);
	istringstream streamRes(line);
	
	streamRes >> dif;
	double temp; 
	int i = 0;
	while (streamRes >> temp){
		score[i++] = temp;
	}
	streamRes >> ws;

// Calculate total
	double sum = 0;
	double max = score[0];
	double min = score[0];
	
	for (int i = 0; i < 7; i++)
	{		
		if (max < score[i])
		{
			max = score[i];
		}
		else if (min > score[i])
		{
			min = score[i];
		}
		sum += score[i];
	}
	res =  (double) 3/5 * (sum-(max+min)) * dif;
	return true;
}

bool update_round(string textFile, string binaryFile, int round){
	
	ifstream inFile(textFile.c_str());
	fstream bin(binaryFile.c_str(), ios::in|ios::out|ios::binary);
	int id;
	double res;
	bool end = true;
	
	if (!inFile.is_open()) return false;
	
		while(end){
			Diver D;
			end = get_diver(inFile, id, res); // returns id and res for one diver
			if(!end){
			break;	
			}
		
			bin.seekg((id-1)*sizeof(Diver));
			bin.read((char*) (&D), sizeof(Diver));
			D.update(round, res); 
		
			bin.seekp((id-1)*sizeof(Diver));
			bin.write((char *) (&D), sizeof(Diver)); //&diver referens till diver objekt.
			
		}
	bin.close();
	inFile.close();
}


void print_divers(vector<Diver> d){
	for (int i = 0; i < d.size(); i++) {
		cout << d[i];
	}
}

int main() {
	vector<Diver> allDivers;
	string binFile, round;
	bool okej = true;
	
	cout << "binärfilensnamn: " << endl;
	cin >> binFile;
	
	int i = 1;
	while (okej || i < 6) {
		cout << "mata filnamnet för rundan: " << endl;
		cin >> round;
		okej = update_round(round, binFile, i);
		read_binary(allDivers);
		print_divers(allDivers);
		allDivers.clear();
		i++;
	}
	
	/*
	cout << "mata filnamnet för runda 1: " << endl;
	cin >> round;
	update_round(round, binFile, 1);
	cout << "mata filnamnet för runda 1: " << endl;
	cin >> round;
	update_round(round, binFile, 2);
	cout << "mata filnamnet för runda 1: " << endl;
	cin >> round;
	update_round(round, binFile, 3);
	*/
	
	/*
	update_round("/Users/Charlsas/Documents/Skola/Programering/C++/Kod/Lab5/Lab5/round_1.txt", "/Users/Charlsas/Documents/Skola/Programering/C++/Kod/Lab5/Lab5/diversMac_x86.bin",1);
	update_round("/Users/Charlsas/Documents/Skola/Programering/C++/Kod/Lab5/Lab5/round_2.txt", "/Users/Charlsas/Documents/Skola/Programering/C++/Kod/Lab5/Lab5/diversMac_x86.bin",2);
	update_round("/Users/Charlsas/Documents/Skola/Programering/C++/Kod/Lab5/Lab5/round_3.txt", "/Users/Charlsas/Documents/Skola/Programering/C++/Kod/Lab5/Lab5/diversMac_x86.bin",3);
	*/

	return 0;
}