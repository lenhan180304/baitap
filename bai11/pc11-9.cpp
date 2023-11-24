#include <iostream>
#include <string>

using namespace std;

const int NUM_SPEAKERS = 10;

// Structure to store speaker data
struct Speaker {
    string name;
    string phoneNumber;
    string speakingTopic;
    double feeRequired;
};

// Function prototypes
void displayMenu();
void inputSpeakerData(Speaker&);
void displayAllData(const Speaker[]);
void modifySpeakerData(Speaker[]);

int main() {
    Speaker speakers[NUM_SPEAKERS];

    int choice;

    do {
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputSpeakerData(speakers[NUM_SPEAKERS]);
                break;
            case 2:
                modifySpeakerData(speakers);
                break;
            case 3:
                displayAllData(speakers);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "\nSpeakers' Bureau Menu:\n";
    cout << "1. Enter new speaker data\n";
    cout << "2. Modify speaker data\n";
    cout << "3. Display all speaker data\n";
    cout << "4. Exit\n";
}

void inputSpeakerData(Speaker& speaker) {
    cout << "Enter speaker name: ";
    cin.ignore();  // Ignore the newline character left in the buffer
    getline(cin, speaker.name);

    cout << "Enter speaker telephone number: ";
    getline(cin, speaker.phoneNumber);

    cout << "Enter speaking topic: ";
    getline(cin, speaker.speakingTopic);

    // Input fee required, validating for negative values
    do {
        cout << "Enter fee required: $";
        cin >> speaker.feeRequired;
    } while (speaker.feeRequired < 0);

    cout << "Speaker data entered successfully!\n";
}

void displayAllData(const Speaker speakers[]) {
    cout << "\nSpeakers' Bureau Data:\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "Name\t\tTelephone\t\tTopic\t\tFee Required\n";
    cout << "-----------------------------------------------------------------------\n";

    for (int i = 0; i < NUM_SPEAKERS; ++i) {
        cout << speakers[i].name << "\t" << speakers[i].phoneNumber << "\t\t" << speakers[i].speakingTopic << "\t\t$"
             << speakers[i].feeRequired << "\n";
    }

    cout << "-----------------------------------------------------------------------\n";
}

void modifySpeakerData(Speaker speakers[]) {
    int speakerNumber;

    cout << "Enter the speaker number you want to modify (1-" << NUM_SPEAKERS << "): ";
    cin >> speakerNumber;

    if (speakerNumber >= 1 && speakerNumber <= NUM_SPEAKERS) {
        cout << "Modifying speaker data for speaker number " << speakerNumber << ":\n";
        inputSpeakerData(speakers[speakerNumber - 1]);
    } else {
        cout << "Invalid speaker number. Please enter a valid speaker number.\n";
    }
}
