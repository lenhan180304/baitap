#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double score1, score2, score3, score4, score5;
    double average;

    // Ask the user to enter five test scores
    cout << "Enter the first test score: ";
    cin >> score1;
    cout << "Enter the second test score: ";
    cin >> score2;
    cout << "Enter the third test score: ";
    cin >> score3;
    cout << "Enter the fourth test score: ";
    cin >> score4;
    cout << "Enter the fifth test score: ";
    cin >> score5;

    // Calculate the average test score
    average = (score1 + score2 + score3 + score4 + score5) / 5.0;

    // Display the average test score
    cout << fixed << setprecision(1);
    cout << "The average test score is: " << average << endl;

    return 0;
}
