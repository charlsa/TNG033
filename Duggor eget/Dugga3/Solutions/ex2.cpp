#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


/********************************
* Class Clock definition        *
*********************************/


class Clock{
    public:

        //constructor
        Clock(int h=0, int m=0);

        int get_hours() const;
        int get_minutes() const;

        bool operator <(const Clock &k) const;

        friend ostream& operator<<(ostream& os, const Clock& k);

     private:
        int hh, mm; //represent time as hh:mm
};


/*****************************************************
* Class Clock member functions implementation        *
******************************************************/


Clock::Clock(int h, int m) : hh(h), mm(m)
{ }


int Clock::get_hours() const
{
    return hh;
}


int Clock::get_minutes() const
{
    return mm;
}

bool Clock::operator <(const Clock &k) const
{
    if (hh < k.hh)
        return true;

    if ( (hh == k.hh) && (mm < k.mm) )
        return true;

    return false;
}

/*************************************/
/* Other functions                   */
/*************************************/

//If you need other functions
//then you can add the code here

ostream& operator<<(ostream& os, const Clock& k)
{
    if (k.hh < 9)
        os << "0";

    os << k.hh << ":";

    if (k.mm < 9)
        os << "0";

    os << k.mm << endl;

    return os;
}



//Use STL tools to implement this function
//Aim of this exercise: to test your ability in using STL algorithms
void display_sort(ostream& os, vector<Clock> V)
{
    sort(V.begin(), V.end());

    ostream_iterator<Clock> out_it(os, "\n");

    copy(V.begin(), V.end(), out_it);
}



/**************************************
* Main function  -- test              *
* DO NOT CHANGE                       *
***************************************/


int main()
{
    Clock k1(10,0);
    Clock k2(10,30);
    Clock k3(9,15);
    Clock k4(9,0);
    Clock k5(11,0);
    Clock k6(7,0);

    vector<Clock> V;

    V.push_back(k1);
    V.push_back(k2);
    V.push_back(k3);
    V.push_back(k4);
    V.push_back(k5);
    V.push_back(k6);

    display_sort(cout, V);

    return 0;

}
