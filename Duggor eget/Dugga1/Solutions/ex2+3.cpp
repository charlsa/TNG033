#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

/*******************************
* 1. function declarations     *
********************************/

void padRight(char A[], int n);

void padRight_ex3(char *A, int n);



/*******************************
* 2. Main function             *
*******************************/

int main()
{
    int SIZE = 101;

    char text[SIZE];
    int n;

    cout << "Enter some text (max 100 chars): ";
    cin.getline(text, SIZE);
    cout << "N = ";
    cin >> n;

    if ( (n <= 0) || (n > SIZE -1) )  {
      cout << "Invalid N!!"  << endl;
      return 0;
    }

    cout << endl << "Before pad to right: "
         << text << "#" << endl;

    //padRight(text, n);
    padRight_ex3(text, n);

    cout << "After pad to right: "
         << text << "#" << endl;

    return 0;
}


/*******************************
* 3. Functions implementation  *
********************************/

void padRight(char A[], int n)
{
    int L = strlen(A);

    //cout << strlen(A) << endl;

    if (n <= L) return;

    for(int i = L; i < n; i++)
        A[i] = ' ';

    A[n] = '\0';

    //cout << strlen(A);
}

void padRight_ex3(char *A, int n)
{
    int L = strlen(A);

    cout << strlen(A) << endl;

    if (n <= L) return;

    char *pt_end = A+n;


    for(char *pt = A+L; pt < pt_end; pt++)
        *pt = ' ';

    *pt_end = '\0';

    cout << strlen(A);
}

