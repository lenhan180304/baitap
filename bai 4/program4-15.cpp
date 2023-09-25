#include <iostream>
using namespace std;

int main() {
    char employed, recentGrad;

    // Prompt the user to answer questions
    cout << "Answer the following questions\n";
    cout << "with either Y for Yes or N for No.\n";

    // Ask if the user is employed
    cout << "Are you employed? ";
    cin >> employed;

    // Ask if the user has graduated from college in the past two years
    cout << "Have you graduated from college "
         << "in the past two years? ";
    cin >> recentGrad;

    // Check if the user qualifies for special interest rate
    if (employed == 'Y' && recentGrad == 'Y') {
        cout << "You qualify for the special "
              << "interest rate.\n";
    }
    else {
        cout << "You must be employed and have\n"
             << "graduated from college in the\n"
             << "past two years to qualify.\n";
    }
    
    return 0;
}
