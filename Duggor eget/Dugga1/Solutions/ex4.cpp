#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;


string convert_log(double x)
{
    ostringstream os;

    os << "log("
       << fixed << setprecision(3) << x << ") = "
       << log10(x);

     string s = os.str(); //copy the contents of os buffer to string r

     return s;
}



int main()
{
  string w;
  double d;

  while (cin >> w){
      istringstream is(w);

      if (is >> d){ //a number

        if (d <= 0) continue; //zero or negative numbers should be ignore

        cout << convert_log(d) << endl;
     }
  }

  return 0;
}



//Another way to read the input and validate it
//int main()
//{
//
//  string trash;
//  double d;
//
//    while(!cin.eof())
//    {
//        if (cin >> d)
//        {
//            if ( d >= 0)
//                cout << convert_log(d)<< endl;
//        }
//        else
//        {
//            cin.clear();
//            cin >> trash;
//        }
//    }
//    return 0;
//}
