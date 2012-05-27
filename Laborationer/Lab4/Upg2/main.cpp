#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>


using namespace std;

void read(multimap<string, string> &anagram){
    ifstream in("uppgift2_kort.txt");
    string s,tmp;
    while(in>>s){
        tmp=s;
        sort(tmp.begin(),tmp.end());
        anagram.insert(make_pair(tmp,s));                 //lägger in sorterad string som nyckel till orginalet
    }
    in.close();
}

void print(multimap<string, string> anagram){
    multimap<string, string>::iterator it1,it2;
    it1=anagram.begin();
    it2=it1;
    while(it2!=anagram.end()){
        int count=0;
        it2=anagram.upper_bound(it1->first);//it2 pekar på nästkommande ord
        if(++it1==it2);                     //kollar om det endast finns ett ord av samma typ
        else{
            --it1;
            while(it1!=it2){                 //it1 stegar fram till it2
                cout << it1-> second << "  ";
                it1++;
                count++;
            }
            cout<<"antal: "<<count<<endl;
        }
    }
}

int main(){
    multimap<string, string> anagram;

    read(anagram);
    print(anagram);
    return 0;
}
