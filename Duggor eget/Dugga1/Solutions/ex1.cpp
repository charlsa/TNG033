#include <iostream>
#include <string>

using namespace std;

/*******************************
* 1. function declarations     *
********************************/

const int N_TEACHERS = 4;
const int N_COURSES = 5;

const int NOT_FOUND = -1;


string teachers_table[] = {"Anna Lund", "Jan Erikson", "Sylvia Piel", "Mats Demon"};

string courseCodes_table[] = {"TND012", "TNG033", "TND004", "TNCG18", "TNM031"};


void courses_of_teacher(bool T[][N_COURSES], string S);

void teachers_of_course(bool T[][N_COURSES], string S);



/*******************************
* 2. Main function             *
*******************************/

int main()
{

    bool table[N_TEACHERS][N_COURSES] = { {true, true, true, false, false},
                                          {false, true, true, false, false},
                                          {false, false, false, true, true},
                                          {false, true, false, false, true}
                                         };
    string name = "";
    string code = "";
    int option;

    do{
        cout << "1. Courses of a teacher" << endl;
        cout << "2. Teachers of a course" << endl;

        cout << "Option? ";
        cin >> option;
        cin.ignore();
        cout << endl;

        if (option == 1){

         cout << "Teacher name: ";
         getline(cin, name);
         courses_of_teacher(table, name);
         cout << endl;

         }
         else if (option == 2){

         cout << "Course code: ";
         getline(cin, code);
         teachers_of_course(table, code);
         cout << endl;


         }

    } while (option == 1 || option == 2); //exit with any option different from 1 or 2


    return 0;
}


/*******************************
* 3. Functions implementation  *
********************************/

int get_index(string *T, string S, int n)
{
    int i;

    for(i = 0; (i < n) && (T[i] != S) ; i++);

    if (i == n) return NOT_FOUND;

    return i;
}




void courses_of_teacher(bool T[][N_COURSES], string S)
{
    int i = 0;

    if ((i = get_index(teachers_table, S, N_TEACHERS)) == NOT_FOUND) {
        cout << "Invalid teacher name!!" << endl;
        return;
        }

    cout << "Courses of " << S << endl;

    for(int c = 0; c <  N_COURSES; c++)
        if (T[i][c])
            cout << courseCodes_table[c] << endl;

   cout << endl;
}


void teachers_of_course(bool T[][N_COURSES], string S)
{
    int i = 0;

    if ((i = get_index(courseCodes_table, S, N_COURSES)) == NOT_FOUND) {
        cout << "Invalid course code!!" << endl;
        return;
        }

    cout << "Teachers of " << S << endl;

    for(int l = 0; l <  N_TEACHERS; l++)
        if (T[l][i])
            cout << teachers_table[l] << endl;

   cout << endl;
}

