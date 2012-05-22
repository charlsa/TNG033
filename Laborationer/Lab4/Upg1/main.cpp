#include <iostream>
#include <map>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>



using namespace std;
bool comp(pair<int,string> i, pair<int,string> j)//jämnför två par
{
    return (i.first>j.first);
}

void print(vector<pair<int,string> > &par_vec,map<string,int> &word, int counter)
{
    map<string,int>::iterator it;
    vector<pair<int,string> >::iterator it_vec;//iteratorer

    for(it = word.begin();it!=word.end();it++)//skriv ut map och skapa vectorn
    {
        cout<<it->first<<": "<<it->second<<endl;
        pair <int,string> p (it->second,it->first);
        par_vec.push_back(p);
    }
    cout<<endl;

    sort(par_vec.begin(),par_vec.end(), comp);//sortera vectorn
    for(it_vec=par_vec.begin();it_vec != par_vec.end();it_vec++)//skriv ut vectorn
    {
        cout<<it_vec->first<<it_vec->second<<endl;
    }
    cout<<endl<<endl<<"counter: "<<counter<<endl;
}

int read(map<string,int> &word)
{
    ifstream in("uppgift1.txt");
    map<string,int>::iterator it;
    string s,tmp;
    int counter=0;
    while(in>>s)
    {
        for(unsigned int j = 0;j<s.size();j++)//testar varge element i strängen
        {
            if((('a'<=s[j]) && (s[j]<= 'z')) || (s[j]=='\x27') || (s[j]=='\x60')) tmp+=s[j];
            if(('A'<=s[j]) && (s[j]<= 'Z')) tmp+=s[j]+('a'-'A');
        }
        it = word.find(tmp); //iteratorn letar efter tmp
        if(it != word.end())
        {
            word[tmp]=it->second++;
        }
        else
        {
            word[tmp]=1;
        }
        counter++;
        tmp="";
    }
    in.close();
    return counter;
}

int main()
{
    map<string,int> word;
    vector<pair<int,string> > par_vec;

    print(par_vec, word, read(word));
    return 0;
}


