#include <iostream>
using namespace std;

int main()
{
    int number = 12345;
    int ringhtMost = number % 10;
    
    cout << "The rightmost digit in "
         << number << " is "
         << ringhtMost << endl;

   return 0;          
}