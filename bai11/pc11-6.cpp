#include <iostream>
#include <string>

using namespace std;

const int NUM_PLAYERS = 12;

// Structure to store soccer player data
struct SoccerPlayer {
    string playerName;
    int playerNumber;
    int pointsScored;
};

// Function to input soccer player data
void inputPlayerData(SoccerPlayer& player) {
    // Input player name
    cout << "Enter player's name: ";
    cin.ignore();  // Ignore the newline character left in the buffer
    getline(cin, player.playerName);

    // Input player number, validating for negative values
    do {
        cout << "Enter player's number: ";
        cin >> player.playerNumber;
    } while (player.playerNumber < 0);

    // Input points scored, validating for negative values
    do {
        cout << "Enter points scored by the player: ";
        cin >> player.pointsScored;
    } while (player.pointsScored < 0);
}

// Function to display soccer player data
void displayPlayerData(const SoccerPlayer& player) {
    cout << player.playerNumber << "\t\t" << player.playerName << "\t\t" << player.pointsScored << endl;
}

int main() {
    SoccerPlayer players[NUM_PLAYERS];

    // Input soccer player data
    cout << "Enter data for each soccer player:\n";
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        cout << "\nPlayer " << (i + 1) << ":\n";
        inputPlayerData(players[i]);
    }

    // Display table header
    cout << "\nPlayer Number\tPlayer Name\tPoints Scored\n";

    // Display soccer player data and calculate total points
    int totalPoints = 0;
    int maxPoints = -1;
    string playerNameWithMaxPoints;

    for (int i = 0; i < NUM_PLAYERS; ++i) {
        displayPlayerData(players[i]);
        totalPoints += players[i].pointsScored;

        // Check for the player with the most points
        if (players[i].pointsScored > maxPoints) {
            maxPoints = players[i].pointsScored;
            playerNameWithMaxPoints = players[i].playerName;
        }
    }

    // Display total points and player with the most points
    cout << "\nTotal Points Earned by the Team: " << totalPoints << endl;
    cout << "Player with the Most Points: " << playerNameWithMaxPoints << " (" << maxPoints << " points)\n";

    return 0;
}
