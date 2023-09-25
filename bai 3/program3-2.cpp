#include <iostream>
using namespace std;

int main ()
{
    int lenght, width, area;

    cout <<"This program calculates the area of a ";
    cout <<"rectangle.\n";
    cout <<"Enter the lenght and width of the rectangle ";
    cout <<"separated by a space.\n";
    cin >> lenght >> width; 
    area = lenght * width;
    cout <<"The area of the rectangle is " << area << endl;
    return 0;
}