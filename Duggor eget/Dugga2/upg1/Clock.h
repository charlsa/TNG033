//
//  Clock.h
//  Dugga2_1
//
//  Created by Karl Westerberg on 2013-01-04.
//  Copyright (c) 2013 Karl Westerberg. All rights reserved.
//

#ifndef Dugga2_1_Clock_h
#define Dugga2_1_Clock_h

class Clock{
public:
    
    //constructor
    Clock(int h=0, int m=0);
    
    int get_hours() const;
    int get_minutes() const;
    
    void display() const;
    
    Clock delay(int min);
    
private:
    int hh, mm; //represent time as hh:mm
};

#endif
