#include <iostream>
#include <string>
#include <vector>

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
ostream& operator<<(ostream &os, Clock &V){
    os << V.get_hours() << ":" << V.get_minutes();
    return os;
}
/*************************************/
/* Other functions                   */
/*************************************/

//If you need other functions
//then you can add the code here
bool func (Clock A,Clock B) {
    return (B<A);
}

//Use STL tools to implement this function
//Aim of this exercise: to test your ability in using STL algorithms
void display_sort(ostream& os, vector<Clock> V)
{
    sort(V.begin(), V.end(),func);
    
    // print
    vector<Clock>::iterator it = V.begin();
    
    while (it != V.end()){
        cout << *it << endl;
        it++;
    }
        
    //Add code here
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
