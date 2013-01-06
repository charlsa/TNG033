#include <iostream>
#include <iomanip>

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

        void display( ) const;

        Clock& delay(int min); //add to the clock min minutes

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


void Clock::display( ) const
{
    cout << hh << ":" << mm << endl;
}


Clock& Clock::delay(int min)
{
    int h = (mm + min) / 60;

    hh = (hh + h) % 24;
    mm = (mm + min) % 60;

    return *this;
}

/**************************************
* Main function  -- test              *
***************************************/

int main()
{
    Clock K1(2,30);

    K1.display();

    cout << "Delaying the clock ..." << endl;
    K1.delay(30).delay(30).display();

    return 0;

}




