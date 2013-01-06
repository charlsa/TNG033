//Add your code for exercise 3 to this file

#include <iostream>
#include <utility>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

typedef pair<int,int> info;
typedef pair<string, int> pairInVector;
typedef map<string, info> mapOfWords;
typedef vector<pairInVector> wordVector;

void tableOfWords(mapOfWords& w, int &u);
void copyToVector(mapOfWords& w, wordVector& v);
bool func(pairInVector a, pairInVector b);


int main()
{
    mapOfWords words;
    wordVector V;
    wordVector copyV;
    
    int nrUinque;
    pair<string, int> pairOFwords;
    
    tableOfWords(words, nrUinque);
    
    copyToVector(words,V);
    sort(V.begin(),V.end(),func);
        
    /* Test print vector */
    for (wordVector::iterator i = V.begin(); i != V.end(); i++) {
    cout << (*i).first << "\t" << (*i).second << endl;
    }
     
    
    cout << nrUinque;

    return 0;
}

void tableOfWords(mapOfWords& w, int &u){
////// Read from file
    ifstream file("/Users/Charlsa/Desktop/Programmering TNG033 omtenta/Duggor/Dugga3_3/Dugga3_3/test_file.txt");
    // Declarations
    stringstream os;
    string line;
    string temp;
    int lineNR = 0;
    u = 0;
    // Loop file
    while (!file.eof()){
        getline(file,line);
        cout << line;
        lineNR++;
        os << line;
        // Loop stream
        while (!os.eof()) {
            os >> temp;
            
            mapOfWords::iterator it = w.find(temp);
            if (it != w.end()){
                w.erase(it);
                u--;
            }
            else{
                w[temp].first = lineNR;
                w[temp].second = 1;
                u++;
            }
            /*test printing map
            for (mapOfWords::iterator i = w.begin(); i != w.end(); i++) {
                cout << (*i).first << "\t" << w[(*i).first].second << "\t" <<w[(*i).first].first << endl;
            }
            */
        }
        os.flush();
        os.clear(); // clear flags...
    }
}

void copyToVector(mapOfWords& w, wordVector& v){
    for (mapOfWords::iterator i = w.begin(); i != w.end(); i++) {
    //    (*a).first = (*i).first; // copy word to first in pair
    //    (*a).second = w[(*i).first].second;
    //    v.push_back(make_pair((*i).first, w[(*i).first].first));
        v.push_back(make_pair(i->first, w[i->first].first));
    }
    /* Test print vector 
    for (wordVector::iterator i = v.begin(); i != v.end(); i++) {
        cout << (*i).first << "\t" << (*i).second << endl;
    } 
     */
    
}

bool func(pairInVector a, pairInVector b){
    return a.first < b.first; 
}


