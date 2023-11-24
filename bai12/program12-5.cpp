#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
bool openFileIn(fstream &, const string &);
void showContents(fstream &);

int main()
{
    fstream dataFile;

    if (openFileIn(dataFile, "demofile.txt"))
    {
        cout << "File opened successfully.\n";
        cout << "Now reading data from the file.\n\n";
        showContents(dataFile);
        dataFile.close();
        cout << "\nDone.\n";
    }
    else
    {
        cout << "File open error!" << endl;
    }

    return 0;
}

// Definition of function openFileIn.
bool openFileIn(fstream &file, const string &name)
{
    file.open(name, ios::in);
    return file.is_open(); // Return true if the file is open, false otherwise
}

// Definition of function showContents.
void showContents(fstream &file)
{
    string line;

    while (getline(file, line))
    {
        cout << line << endl;
    }
}
