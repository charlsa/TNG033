//
//  Clock.cpp
//  Dugga2_1
//
//  Created by Karl Westerberg on 2013-01-04.
//  Copyright (c) 2013 Karl Westerberg. All rights reserved.
//

#include "Clock.h"
#include <iostream>
#include <iomanip>

using namespace std;

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

Clock Clock::delay(int min){
    int update;
    update = mm+min;
    
    if(update > 59){
        int hour, new_min;
        hour = update/60;
        new_min = update%60;
        mm = new_min;
        hh += hour;
    }
    else{
        mm = update;
    }
    return Clock(hh,mm);
}
