#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "printWithComma.h"
#include "printWithLetters.h"
#include "printWithScientific.h"
#include "printClient.h"


using namespace std;
/******************************/
/* 1. Functions declarations  */
/******************************/
//Display the menu
void display_menu();

//Load at most max numbers from file numbers.txt
//into array X
//Return the number of values stored in X
int load_file(double *X, int max);

//Add any other needed functions

/******************************/
/* 2. Main function           */
/******************************/
int main(){
    const int MAX = 100;

    //printing strategies (algorithms)
    PrintWithComma pwc; //comma format
	PrintWithLetters pwl;
	PrintWithScientific pws;

     //a print client
    PrintClient printcon; // innehåller en pekare till strategi

    int option;
    double d = 0;

    double seq[MAX];
    int howMany = 0;

    do{
        display_menu();
        cout << "Option ? ";
        cin >> option;
        cin.ignore();

        switch (option){
            case 1: cout << "The number: ";
                    cin >> d;
                    printcon.set_PrintStrategy(&pwc); // skickar ref till strategi
                    printcon.print(d);
					// Display with comma
                    break;
				
            case 2: cout << "The number: ";//Add code Display with scientific notation
					cin >> d;
					printcon.set_PrintStrategy(&pws);
					printcon.print(d);
                    break;
				
            case 3: cout << "The number: ";//Add code Display with letters
					cin >> d;
					printcon.set_PrintStrategy(&pwl);
					printcon.print(d);
					break;
				
            case 4: //Add code Generate comma format from file (numbers.txt)
					printcon.set_PrintStrategy(&pwc);
					howMany = load_file(seq, MAX);
					printcon.print(seq, howMany, "Comma");
                    break;
				
            case 5: //Add code Generate scientific format from file (numbers.txt)
					printcon.set_PrintStrategy(&pws);
					howMany = load_file(seq, MAX);
					printcon.print(seq, howMany, "Scientific");
                    break;
				
            case 6: //Add code Generate letters format from file (numbers.txt)
					printcon.set_PrintStrategy(&pwl);
					howMany = load_file(seq, MAX);
					printcon.print(seq, howMany, "Letters");
                    break;
				
            case 7: //  Quit
				
					break;
				
            default: cout << "Wrong option!!" << endl;
        }
   } while (option != 7);

   cout << endl << "GoodBye :)" << endl;

   return 0;
}

/******************************/
/* 3. Functions definitions   */
/******************************/

//Display the menu
void display_menu()
{
    cout << endl << setw(55) << setfill('*') << '*' << endl;
    cout << "1. Display with comma" << endl;
    cout << "2. Display with scientific notation" << endl;
    cout << "3. Display with letters" << endl;
    cout << "4. Generate comma format from file (numbers.txt)" <<endl;
    cout << "5. Generate scientific format from file (numbers.txt)" <<endl;
    cout << "6. Generate letters format from file (numbers.txt)" <<endl;
    cout << "7. Quit" << endl;
    cout << setw(55) << setfill('*') << '*' << endl;
    cout << setfill(' ');
}

//Load at most max numbers from file numbers.txt
//into array X
//Return the number of values stored in X
int load_file(double *X, int max)
{
	string line;
	string allLines = " ";
	ifstream inFile;
	inFile.open("/Users/Charlsas/Documents/Skola/Programering/C++/Kod/Lab3/Lab3/numbers.txt");
	
	while (!(inFile.eof())) {
		getline(inFile, line);
		allLines += " ";
		allLines += line;
	}
	string temp;
	int length = 0;
	double value;
	
	istringstream stream(allLines);
	
	while (!(stream.eof())) {
		if(stream >> value){
			X[length] = value;
			length++;
		}
		else{
			stream.clear();
			stream >> temp;
		}
	}
	inFile.close();

    return length;
}