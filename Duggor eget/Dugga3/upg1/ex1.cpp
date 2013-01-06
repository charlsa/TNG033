#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;




//Add your code here
template <class T1, class T2>
void fuck(T1 *a, T2 *b, T2 (*func)(T1), int n){
   // T2 *temp = b;
    
    for (int i = 0; i < n; i++) {
        *b = func(*a);
        a++;
        b++;
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

    //trans(wordA, wordB, to_upper, 6);
    fuck(wordA, wordB, to_upper, 6);
    //display "abcde -- ABCDE"
    cout << wordA << " -- " << wordB << endl << endl;

    int arrayA[5] = {1, 2, 3, 4, 5};
    int arrayB[5];

    fuck(arrayA, arrayB, to_square, 5);

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




