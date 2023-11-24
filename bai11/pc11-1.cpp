#include <iostream>
#include <string>

using namespace std;

// Define the MovieData structure
struct MovieData {
    string title;
    string director;
    int yearReleased;
    int runningTime;
};

// Function to display movie information
void displayMovieInfo(const MovieData& movie) {
    cout << "Title: " << movie.title << endl;
    cout << "Director: " << movie.director << endl;
    cout << "Year Released: " << movie.yearReleased << endl;
    cout << "Running Time: " << movie.runningTime << " minutes" << endl;
    cout << "------------------------------------------" << endl;
}

int main() {
    // Create two MovieData variables and initialize their values
    MovieData movie1 = {"The Shawshank Redemption", "Frank Darabont", 1994, 142};
    MovieData movie2 = {"The Godfather", "Francis Ford Coppola", 1972, 175};

    // Display information about each movie using the function
    cout << "Movie Information:" << endl;
    displayMovieInfo(movie1);

    cout << "Movie Information:" << endl;
    displayMovieInfo(movie2);

    return 0;
}
