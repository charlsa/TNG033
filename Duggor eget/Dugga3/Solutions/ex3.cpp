#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <sstream>
#include <iterator>
#include <cctype>
#include <algorithm>


using namespace std;

typedef pair<int, int> Word_info; //<counter, line_number>

typedef map<string, Word_info> Table;

typedef pair<string,int> vector_pair;


char to_lower(char c)
{
    return tolower(c);
}


int create_table(istream& in, Table& T);


void display_map(ostream &out, Table& T);


void copy_to_vector(Table &T, vector<vector_pair> &V);


bool compare(vector_pair p1, vector_pair p2);


void display_vector(ostream &out, vector<vector_pair> V);



/***********************************************************/
/* main()  -- testing purposes                             */
/***********************************************************/


int main()
{
    Table Res_table;
    vector <vector_pair> V;

    int unique = 0;

    unique = create_table(cin, Res_table);

    cout << "Number of unique words: " << unique << endl;

    display_map(cout, Res_table);

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    copy_to_vector(Res_table, V);

    sort(V.begin(), V.end(), compare);

    display_vector(cout, V);

   return 0;
}



int create_table(istream& in, Table& T)
{
    string line, word;
    int line_number = 0;
    int unique = 0; //counst number of unique words

    //loop through every line
    while ( getline(in, line) )  {
        ++line_number;

        istringstream stream(line);

        //loop through every word in the line
        while (stream >> word) {
            transform(word.begin(), word.end(), word.begin(), to_lower);
            Table::iterator it = T.find(word);

            if ( it != T.end() ) {//not unique word
             if ( (it->second).first == 1)
                unique--;
             (it->second).first++; //inc. the word counter
            }
            else{
                T[word].first = 1; //inserrt word with counter 1
                T[word].second = line_number;
                unique++;
            }

        }
    }
    return unique;
}


void display_map(ostream &out, Table& T)
{
    ostream_iterator<int> out_it(out, ", ");

    out << endl << endl;

    out << setw (20) << left << "Unique Word"
        << right << "Line Number" << endl << endl;

    for(Table::iterator it = T.begin(); it != T.end(); it++)
    {
        //Display word+line number, if unique word
        if (it->second.first == 1) {
            out <<  setw(20) << left << it->first << " ";
            out << it->second.second << endl;
        }
    }
}

void copy_to_vector(Table &T, vector<vector_pair> &V)
{
    for(Table::iterator it = T.begin(); it != T.end(); it++)
    {
        if (it->second.first == 1) //unique word
        {
            V.push_back(make_pair(it->first, it->second.second));
        }
    }

}

bool compare(vector_pair p1, vector_pair p2)
{
    if (p1.second < p2.second)
        return true;

    return false;
}


void display_vector(ostream &out, vector<vector_pair> V)
{
    cout << "Number of unique words: " << V.size() << endl <<endl;

    out << setw (20) << left << "Unique Word"
        << right << "Line Number" << endl << endl;

    for(vector<vector_pair>::iterator it = V.begin(); it!= V.end(); it++)
        //Display word+line number
        out <<  setw(20) << left << it->first << " "
            << it->second << endl;

}


