#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getTestScores(double[], int);
double getTotal(const double[], int);
double getLowest(const double[], int);

int main()
{
    const int SIZE = 4; // Array size
    double testScores[SIZE], // Array of test scores
        total, // Total of the scores
        lowestScore, // Lowest test score
        average; // Average test score

    // Set up numeric output formatting.
    cout << fixed << showpoint << setprecision(1);

    // Get the test scores from the user.
    getTestScores(testScores, SIZE);

    // Get the total of the test scores.
    total = getTotal(testScores, SIZE);

    // Get the lowest test score.
    lowestScore = getLowest(testScores, SIZE);

    // Subtract the lowest score from the total.
    total -= lowestScore;

    // Calculate the average. Divide by (SIZE - 1) because
    // the lowest test score was dropped.
    average = total / (SIZE - 1);

    // Display the average.
    cout << "The average with the lowest score "
         << "dropped is " << average << ".\n";

    return 0;
}

// Function to get test scores from the user
void getTestScores(double scores[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter test score #" << (i + 1) << ": ";
        cin >> scores[i];
    }
}

// Function to calculate the total of the scores
double getTotal(const double scores[], int size)
{
    double total = 0.0;
    for (int i = 0; i < size; i++)
    {
        total += scores[i];
    }
    return total;
}

// Function to find the lowest test score
double getLowest(const double scores[], int size)
{
    double lowest = scores[0];
    for (int i = 1; i < size; i++)
    {
        if (scores[i] < lowest)
        {
            lowest = scores[i];
        }
    }
    return lowest;
}
