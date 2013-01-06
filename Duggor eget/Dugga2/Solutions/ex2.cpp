#include <iostream>
#include <string>
#include <cmath>


using namespace std;


/*******************************************
* Class Euclidean_vector definition        *
********************************************/


class Euclidean_vector {
    public:

    Euclidean_vector(int a = 0, int b = 0, int c = 0)
      : x(a), y(b), z(c)
    { };

    int get_X() const { return x; };
    int get_Y() const { return y; };
    int get_Z() const { return z; };

    double length() const { return sqrt(x*x + y*y + z*z); };


    //scalar multiplication
    const Euclidean_vector operator*(double a) const
    {
        Euclidean_vector temp(*this);

        temp.x *= a;
        temp.y *= a;
        temp.z *= a;

        return temp;
    };

    //addition of vectors
    const Euclidean_vector operator+(const Euclidean_vector& v) const
    {
        Euclidean_vector temp;

        temp.x = x + v.x;
        temp.y = y + v.y;
        temp.z = z + v.z;

        return temp;
    };

    friend ostream& operator<<(ostream& os, const Euclidean_vector &v);

    private:
       double x, y, z;
};


ostream& operator<<(ostream& os, const Euclidean_vector &v)
{
    os << "X = " << v.x << " , "
       << "Y = " << v.y << " , "
       << "Z = " << v.z << endl;

    return os;
};



/****************************************************************
* Class Euclidean_vector member functions implementation        *
*****************************************************************/

//Add member functions implementation here




/**************************************
* Main function  -- test              *
* DO NOT CHANGE                       *
***************************************/

int main()
{
    const Euclidean_vector V1(1,1,1);
    Euclidean_vector V2(2,2,2);
    Euclidean_vector V3(3,3,3);


    cout << "Length(V1) = " << V1.length() << endl;
    cout << "V1's X coordinate: " << V1.get_X() << endl;
    cout << "V1's Y coordinate: " << V1.get_Y() << endl;
    cout << "V1's Z coordinate: " << V1.get_Z() << endl <<endl;

    cout << "Length(V1+V2) = " << (V1+V2).length() << endl;

    cout << "Length(V2*3 + V1) = " << (V2*3 + V1).length() << endl;
    cout << "Coordinates of (V2*3 + V1 + V3): " << (V2*3 + V1 + V3) << endl;


    return 0;

}
