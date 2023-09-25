#include <iostream>
using namespace std;

int main() {
    const int A_SCORE = 90;
    const int B_SCORE = 80;
    const int C_SCORE = 70;
    const int D_SCORE = 60;
    const int MIN_SCORE = 0;
    const int MAX_SCORE = 100;

    int testScore;

    cout << "Enter your numeric test score and I will\n"
         << "tell you the letter grade you earned: ";
    cin >> testScore;

    if (testScore >= MIN_SCORE && testScore <= MAX_SCORE) {
        if (testScore >= A_SCORE)
            cout << "Your grade is A.\n";
        else if (testScore >= B_SCORE)
            cout << "Your grade is B.\n";
        else if (testScore >= C_SCORE)
            cout << "Your grade is C.\n";
        else if (testScore >= D_SCORE)
            cout << "Your grade is D.\n";
        else
            cout << "Your grade is F.\n";
    }
    else {
        cout << "That is an invalid score. Run the program\n"
             << "again and enter a value in the range of\n"
             << MIN_SCORE << " through " << MAX_SCORE << ".\n";
    }

    return 0;
}
