#include "Clock.h"

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    Clock K1(2,30);

    K1.display();

    cout << "Delaying the clock ..." << endl;
    K1.delay(30).delay(30).delay(25).display();

    return 0;

}




