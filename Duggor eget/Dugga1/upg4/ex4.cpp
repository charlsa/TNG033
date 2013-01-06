//
//  main.cpp
//  Dugga1_4
//
//  Created by Karl Westerberg on 2013-01-04.
//  Copyright (c) 2013 Karl Westerberg. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>


using namespace std;

string conv_log(double d);

int main(){
    double x;
    string res;
    cout << "Type 'x' in the function log(x) \n x = ";
    cin >> x;
    
    res = conv_log(x);
    
    cout << res << endl;
    
    return 0;
}

string conv_log(double x){
    double res = log10(x);
    stringstream ss;
    ss << fixed << setprecision(3) << res;
    string result;
    ss >> result;
    
    return result;
}

