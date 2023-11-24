#include <iostream>
#include <string>

using namespace std;

// Structure to store movie data
struct MovieData {
    string title;
    string director;
    int yearReleased;
    int runningTime;
    double productionCost;
    double firstYearRevenue;
};

// Function to display movie data including profit or loss
void displayMovieData(const MovieData& movie) {
    cout << "Title: " << movie.title << endl;
    cout << "Director: " << movie.director << endl;
    cout << "Year Released: " << movie.yearReleased << endl;
    cout << "Running Time: " << movie.runningTime << " minutes" << endl;
    cout << "Production Cost: $" << movie.productionCost << endl;
    cout << "First Year Revenue: $" << movie.firstYearRevenue << endl;

    // Calculate profit or loss
    double profitLoss = movie.firstYearRevenue - movie.productionCost;
    cout << "First Year Profit/Loss: $" << profitLoss << endl;
    cout << endl;
}

int main() {
    // Create two MovieData variables and initialize their members
    MovieData movie1 = {"The Shawshank Redemption", "Frank Darabont", 1994, 142, 25000000.0, 58900000.0};
    MovieData movie2 = {"Inception", "Christopher Nolan", 2010, 148, 160000000.0, 829895144.0};

    // Display movie data for each movie
    cout << "Movie 1 Data:\n";
    displayMovieData(movie1);

    cout << "Movie 2 Data:\n";
    displayMovieData(movie2);

    return 0;
}
