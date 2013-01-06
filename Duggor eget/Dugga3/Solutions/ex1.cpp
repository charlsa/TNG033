#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

//Add your code here

template<class T1, class T2>
void transform(T1 *A, T2 *B, T2 (*F)(T1), int n)
{
    if (!n) //empty array A
        return;

    T2 *ptb = B;
    for(T1 *pta = A; pta != A+n; pta++, ptb++)
    {
        *ptb = F(*pta);
    }
}

char to_upper(char c)
{
    return toupper(c);
}

int to_square(int n)
{
    return n*n;
}



/**************************************
* Main function  -- test              *
* Do NOT change                       *
***************************************/

int main()
{
    char wordA[10] = "abcde";
    char wordB[10];

    transform(wordA, wordB, to_upper, 6);

    //display "abcde -- ABCDE"
    cout << wordA << " -- " << wordB << endl << endl;

    int arrayA[5] = {1, 2, 3, 4, 5};
    int arrayB[5];

    transform(arrayA, arrayB, to_square, 5);

    //display "1 2 3 4 5"
    for(int i = 0; i < 5; i++)
        cout << arrayA[i] << " ";

    cout << " -- ";

     //display "1 4 9 16 25"
    for(int i = 0; i < 5; i++)
        cout << arrayB[i] << " ";

    cout << endl;

    return 0;

}




