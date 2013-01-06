#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;



/**************************/
/* Employee class         */
/**************************/

class Employee {
  public:

    //constructor
    Employee(string s = "") : name(s) {    };

    virtual ~Employee() {};

    void change_name(const string s) { name = s; };

    virtual void display(ostream& os) const
    {
        os << "Name: " << name << endl;
    } ;

    friend ostream& operator<<(ostream& os, const Employee &E);

	protected:
        string name;

};


ostream& operator<<(ostream& os, const Employee &E)
{
    E.display(os);

    return os;
}


/**************************/
/* Teacher class          */
/**************************/


class Teacher : public Employee {
  public:

    //constructor
    Teacher(string s = "", string *c = NULL, int n = 0);

    //copy constructor
    Teacher(const Teacher &T);

    ~Teacher() //base class destructor is first called
    {
        delete [] courses;
    };

    bool gives_course(string code) const;


    void display(ostream& os) const;

	protected:
        string *courses;  //array of courses  codes given by the teacher
        int n_courses; //number of courses given by the teacher
};


/////////////////////////////////////////
//Teacher's member functions definitions
/////////////////////////////////////////


//constructor
Teacher::Teacher(string s, string *c, int n)
  : Employee(s) //call constructor of base class
{
    n_courses = n;

    courses = new string[n_courses]; //allocate memory for the course codes
    for(int i = 0; i < n_courses; i++)
        courses[i] = c[i];
};


//copy constructor
Teacher::Teacher(const Teacher &T)
//default copy constructor of Employee is called first
{
    n_courses = T.n_courses;

    courses = new string[n_courses]; //allocate memory for the course codes

    for(int i = 0; i < n_courses; i++)
        courses[i] = T.courses[i];
};


bool Teacher::gives_course(string code) const
{
    for(int i = 0; i < n_courses; i++)
        if (code == courses[i])
            return true;

    return false;
}


void Teacher::display(ostream& os) const
{
    os << "Teacher: " << name << endl;

    os << "Courses: ";
    for(int i = 0; i < n_courses-1; i++)
            os << courses[i] << ", ";

    os << courses[n_courses-1] << endl;
}



/**************************/
/* Programmer class       */
/**************************/

class Programmer : public Teacher {
  public:

    //constructor
    Programmer(string s = "", string *c = NULL, int n = 0, string f = "C++");


    void display(ostream& os) const;

	private:
        string fav_lang;  //favourite programming language
};


/////////////////////////////////////////////
//Programmer's member functions definitions
/////////////////////////////////////////////


Programmer::Programmer(string s, string *c, int n, string f)
  : Teacher(s, c, n) //call constructor of Teacher class
{
    fav_lang = f;
};


void Programmer::display(ostream& os) const
{
    os << "Programmer: " << name << endl;
    os << "Favourite prog. language: " << fav_lang << endl;

    os << "Courses: ";
    for(int i = 0; i < n_courses-1; i++)
        os << courses[i] << ", ";

    os << courses[n_courses-1] << endl;
} ;


/**************************/
/* Researcher class       */
/**************************/

class Researcher : public Employee {
  public:

    //constructor
    Researcher(string s = "", string a = "");

    void display(ostream& os) const;

	private:
        string area;  //area of research
};


/////////////////////////////////////////////
//Researcher's member functions definitions
/////////////////////////////////////////////

//constructor
Researcher::Researcher(string s, string a)
 : Employee(s) //call constructor of base class
{
    area = a;
};


void Researcher::display(ostream& os) const
{
    os << "Researcher: " << name << endl;
    os << "Area of research: " << area << endl;
} ;



/***********************************************************/
/* main()  -- testing purposes                             */
/* DO NOT CHANGE                                           */
/***********************************************************/


int main()
{
    const int MAX = 100;

    string C1[] = {"TND012", "TNG033", "TNK031"};
    string C2[] = {"TNCG018", "TND004"};

    Teacher T("Anna", C2, 2);
    Programmer P("Aida", C1, 3, "Smalltalk");
    Researcher R("Monika", "Swearing theory");

    Employee* DB[MAX];
    int howMany = 3;

    DB[0] = &T;
    DB[1] = &P;
    DB[2] = &R;

    for(int i = 0; i < howMany; i++) {
        cout << *DB[i]; //NEW PART
        //DB[i]->display(cout);
        cout << endl;
    }

   return 0;
}


