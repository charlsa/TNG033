#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


/**************************/
/* Employee class         */
/**************************/

class Employee {
  public:

    //constructor
    Employee(string s = ""): name(s) { };

    virtual ~Employee() {};

    void change_name(const string s) { name = s; };

    virtual void display(ostream &os) const
    {
        os << "Name: " << name << endl;
    } ;


	protected:
        string name;
};



/**************************/
/* Teacher class          */
/**************************/


class Teacher : public Employee {
  public:

    //constructor
    Teacher(string s = "", string *c = NULL, int n = 0);

    //copy constructor
    Teacher(const Teacher &T);

    ~Teacher()
    {
        delete [] courses;
    }

    bool gives_course(string code) const;


    void display(ostream &os) const;

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
}


//copy constructor
Teacher::Teacher(const Teacher &T)
//default copy constructor of Employee is called first
{
    n_courses = T.n_courses;

    courses = new string[n_courses]; //allocate memory for the course codes

    for(int i = 0; i < n_courses; i++)
        courses[i] = T.courses[i];
}


bool Teacher::gives_course(string code) const
{
    for(int i = 0; i < n_courses; i++)
        if (code == courses[i])
            return true;

    return false;
}


void Teacher::display(ostream &os) const
{
    os << "Teacher: " << name << endl;

    os << "Courses: ";
    for(int i = 0; i < n_courses-1; i++)
            cout << courses[i] << ", ";

    os << courses[n_courses-1] << endl;
    os << "========================================" << endl;
}



/**************************/
/* Programmer class       */
/**************************/


class Programmer : public Teacher {
  public:

    //constructor
    Programmer(string s = "", string *c = NULL, int n = 0, string f = "C++");

    void display(ostream &os) const;

	private:
        string fav_lang;  //favourite programming language
};


//////////////////////////////////////////////
//Programmers's member functions definitions
//////////////////////////////////////////////

//constructor
Programmer::Programmer(string s, string *c, int n, string f)
 : Teacher(s, c, n) //call constructor of Teacher class
{
    fav_lang = f;
}


void Programmer::display(ostream &os) const
{
    os << "Programmer: " << name << endl;
    os << "Favourite prog. language: " << fav_lang << endl;

    os << "Courses: ";
    for(int i = 0; i < n_courses-1; i++)
        os << courses[i] << ", ";

    os << courses[n_courses-1] << endl;
    os << "========================================" << endl;
}


/**************************/
/* Researcher class       */
/**************************/

class Researcher : public Employee {
  public:

    //constructor
    Researcher(string s = "", string a = "");

    void display(ostream &os) const;

	protected:
        string area;  //area of research
};


//////////////////////////////////////////////
//Researcher's member functions definitions
//////////////////////////////////////////////

//constructor
Researcher::Researcher(string s, string a)
 : Employee(s) //call constructor of base class
{
    area = a;
}


void Researcher::display(ostream &os) const
{
    os << "Researcher: " << name << endl;
    os << "Area of research: " << area << endl;
    os << "========================================" << endl;
}


/*********************************/
/* Senior_Researcher class       */
/*********************************/
class Senior_Researcher : public Researcher{
    public:
        Senior_Researcher(string name, string area, Employee** slaves, int nr_of_slaves);
        void display(ostream &os);
    
    private:
        Employee** slaves;
        int nr_of_salves;
};

// Senior_Researcher Sr("Nuts Eriksson", "Theory of Bad Stuff", PhD_students, 3);
Senior_Researcher::Senior_Researcher(string x, string a, Employee** s, int n):Researcher(x, a){
    
    slaves = new Employee*[n];
    nr_of_salves = n;
    for(int i = 0; i < n; i++){
        slaves[i] = s[i];
    }
}

void Senior_Researcher::display(ostream &os){
    
    os << "Senior Researcher: " << name << endl;
    os << "Area of re: " << area << endl;
    
    for(int i = 0; i < nr_of_salves; i++){
        slaves[i]->display(os);
    }
}

/* Nuts Eriksson
Area of research: Theory of Bad Stuff
Supervisor of:
Teacher: Anna
Courses: TNCG018, TND004*/
////////////////////////////////////////////////////
//Senior_Researcher's member functions definitions
////////////////////////////////////////////////////





/***********************************************************/
/* main()  -- testing purposes                             */
/* DO NOT CHANGE                                           */
/***********************************************************/


int main()
{
    const int MAX = 100;

    string C1[] = {"TND012", "TNG033", "TNK031"};
    string C2[] = {"TNCG018", "TND004"};

    Teacher T1("Anna", C2, 2);
    Programmer P("Aida", C1, 3, "Smalltalk");
    Researcher R("Monika", "Swearing theory");

    Employee* PhD_students[MAX];

    PhD_students[0] = &T1;
    PhD_students[1] = &P;
    PhD_students[2] = &R;

    Senior_Researcher Sr("Nuts Eriksson", "Theory of Bad Stuff", PhD_students, 3);
    //Anna, Aida, and Monika are supervised by Nuts Eriksson

    Sr.display(cout);

   return 0;
}


