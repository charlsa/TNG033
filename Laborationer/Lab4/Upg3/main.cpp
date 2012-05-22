#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>


using namespace std;

void read(multimap<string, string> &anagram)
{
    ifstream in("uppgift3.txt");
    string s,tmp;
    while(in>>s)
    {
        tmp=s;
        sort(tmp.begin(),tmp.end());
        anagram.insert(make_pair(tmp,s));                 //lägger in sorterad string som nyckel till orginalet
    }
    in.close();
}

void sort(multimap<string, string> &anagram, multimap<int, multimap<string, string>::iterator> &ref) //ref innehåller en multimap av int och en pekare på en multimap anagram
{
    multimap<string, string>::iterator it1,it2,it3;
    it1=anagram.begin();
    it2=it1;
    while(it2!=anagram.end())
    {
        int count=0;
        it2=anagram.upper_bound(it1->first);//it2 pekar på ordet efter it1->first
        if(++it1==it2);
        else
        {
            --it1;
            it3=it1;
            while(it1!=it2)
            {
                it1++;
                count++;
            }
            ref.insert(make_pair(count,it3));
        }
    }
}


void print(multimap<string, string> anagram, multimap<int, multimap<string, string>::iterator> &ref)
{
    ofstream out("out.txt");
    multimap<string, string>::iterator it1,it2;
    multimap<int,multimap<string, string>::iterator>::reverse_iterator itpow2; //omvänd iterator för att stega bakåt
    itpow2=ref.rbegin();

    while(itpow2 != ref.rend())
    {
        it1=anagram.lower_bound(itpow2->second->first);//itpow2 pekar på ref som pekar på nyckeln i anagram
        it2=anagram.upper_bound(it1->first);
        while(it1!=it2)
        {
            out << it1->second << "  ";
            it1++;
        }
        out<<"number:  "<<itpow2->first<<endl;
        itpow2++;
    }
    out.close();
}


int main()
{
    multimap<string, string> anagram;
    multimap<int, multimap<string, string>::iterator> ref;

    read(anagram);
    sort(anagram,ref);
    print(anagram,ref);
    return 0;
}

