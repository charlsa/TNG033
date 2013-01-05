#include <iostream>
#include <math.h>


using namespace std;


/*******************************************
* Class Euclidean_vector definition        *
********************************************/


class Euclidean_vector {
    public:
        Euclidean_vector(int a,int b,int c);
        double length() const;
        int get_X() const;
        int get_Y() const;
        int get_Z() const;
        Euclidean_vector operator+ (const Euclidean_vector& V) const;
        Euclidean_vector operator* (int x) const;
    
    private:
        int X,Y,Z;
        friend ostream& operator<<(ostream& stream, const Euclidean_vector& V);
};



/****************************************************************
* Class Euclidean_vector member functions implementation        *
*****************************************************************/

Euclidean_vector::Euclidean_vector(int a, int b, int c){
    X = a; Y = b; Z = c;
}

double Euclidean_vector::length() const{
    double length;
    length = sqrt(X+Y+Z);
    return length;
}

int Euclidean_vector::get_X() const{
    return X;
}

int Euclidean_vector::get_Y() const{
    return Y;
}

int Euclidean_vector::get_Z() const{
    return Z;
}

Euclidean_vector Euclidean_vector::operator+ (const Euclidean_vector& V) const{
    int new_X = X+V.X;
    int new_Y = Y+V.Y;
    int new_Z = Z+V.Z;
    
    return Euclidean_vector(new_X,new_Y,new_Z);
}

Euclidean_vector Euclidean_vector::operator* (int n) const{
    int new_X = X*n;
    int new_Y = Y*n;
    int new_Z = Z*n;
    
    return Euclidean_vector(new_X,new_Y,new_Z);
}

std::ostream& operator << (std::ostream &os, const Euclidean_vector& V){
    os << "(" << V.X << "," << V.Y << "," << V.Z << ")";
    
    return os;
}

/**************************************
* Main function  -- test              *
* DO NOT CHANGE                       *
***************************************/

int main()
{
    const Euclidean_vector V1(1,1,1);
    Euclidean_vector V2(2,2,2);
    Euclidean_vector V3(3,3,3);
    cout << V1 << endl;
    cout << V2 << endl;
    cout << V3 << endl;

    cout << "Length(V1) = " << V1.length() << endl;
    cout << "V1's X coordinate: " << V1.get_X() << endl;
    cout << "V1's Y coordinate: " << V1.get_Y() << endl;
    cout << "V1's Z coordinate: " << V1.get_Z() << endl <<endl;

    cout << "Length(V1+V2) = " << (V1+V2).length() << endl;

    cout << "Length(V2*3 + V1) = " << (V2*3 + V1).length() << endl;
    cout << "Coordinates of (V2*3 + V1 + V3): " << (V2*3 + V1 + V3) << endl;

    return 0;

}
