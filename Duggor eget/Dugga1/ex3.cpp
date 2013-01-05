#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

/*******************************
 * 1. function declarations     *
 ********************************/

void padRight(char A[], int n);


/*******************************
 * 2. Main function             *
 *******************************/

int main()
{
    const int SIZE = 101;
    
    char text[SIZE];
    int n;
    
    cout << "Enter some text (max 100 chars): ";
    cin.getline(text, SIZE);
    cout << "N = ";
    cin >> n;
    
    if ( (n <= 0) || (n > SIZE - 1) ) {
        cout << "Invalid N!!"  << endl;
        return 0;
    }
    
    cout << endl << "Before pad to right: "
    << text << "#" << endl;
    
    padRight(text, n);
    
    cout << "After pad to right: "
    << text << "#" << endl;
    
    return 0;
}


/*******************************
 * 3. Functions implementation  *
 ********************************/

void padRight(char *A, int n)
{
    char *start = A;
    
    while(*start++);            // ökar pos to end of text;

    int endOfText = (start - A) - 1;  // nr of stored chars
    
    for (int i = endOfText;i < endOfText+n; i++){
        A[i] = ' ';
    }
}