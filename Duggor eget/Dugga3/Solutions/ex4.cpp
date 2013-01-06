#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;


/********************************
* Class Clock definition        *
*********************************/


class Clock{
    public:

        //constructor
        Clock(int h=0, int m=0);

        Clock(ifstream& in, int i); //NEW constructor

        int get_hours() const;
        int get_minutes() const;

        void display(ostream& os);

        void write(ofstream& out) const; //NEW function

     private:
        int hh, mm; //represent time as hh:mm
};


/*****************************************************
* Class Clock member functions implementation        *
******************************************************/


Clock::Clock(int h, int m) : hh(h), mm(m)
{ }


Clock::Clock(ifstream& in, int i)
{
    streampos pos = (i-1) * sizeof(Clock);

    in.seekg(pos, ios::beg);

    Clock temp;

    in.read((char *) &temp, sizeof(Clock));

    hh = temp.hh;
    mm = temp.mm;
}


int Clock::get_hours() const
{
    return hh;
}


int Clock::get_minutes() const
{
    return mm;
}


void Clock::write(ofstream& out) const
{
    out.seekp(0, ios::end);

    out.write((char *) this, sizeof(Clock));
}


void Clock::display(ostream &os)
{
    if (hh < 9)
        os << "0";

    os << hh << ":";

    if (mm < 9)
        os << "0";

    os << mm << endl;

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
    const Clock k5(11,0);

    //Write to binary file

   ofstream outF("clocks.bin", ios::binary);

   if (!outF)
   {
       cout << "File clocks.bin could not be open!!" << endl;
       return 0;
   }

   k1.write(outF);
   k2.write(outF);
   k3.write(outF);
   k4.write(outF);
   k5.write(outF);

   outF.close();

   //Read from binary file

   ifstream inF("clocks.bin", ios::binary);

   if (!inF)
   {
       cout << "File clocks.bin could not be open!!" << endl;
       return 0;
   }

   Clock Ka(inF, 3); //read the 3rd clock from file InF
   Ka.display(cout);

   Clock Kb(inF, 5); //read the 5th clock from file InF
   Kb.display(cout);

   Clock Kc(inF, 1); //read the 1st clock from file InF
   Kc.display(cout);

   inF.close();

    return 0;

}
