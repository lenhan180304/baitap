#include <iostream>
#include <string>
using namespace std;

// Function prototype
string replaceSubstring(const string& string1, const string& string2, const string& string3);

int main() {
    // Example values
    string originalString = "the dog jumped over the fence";
    string searchString = "the";
    string replacementString = "that";

    // Call the function and display the result
    string resultString = replaceSubstring(originalString, searchString, replacementString);
    cout << "Original String: " << originalString << endl;
    cout << "Search String: " << searchString << endl;
    cout << "Replacement String: " << replacementString << endl;
    cout << "Result String: " << resultString << endl;

    return 0;
}

// Function to replace occurrences of string2 with string3 in string1
string replaceSubstring(const string& string1, const string& string2, const string& string3) {
    string resultString = string1;
    size_t position = resultString.find(string2);

    // Replace all occurrences of string2 with string3
    while (position != string::npos) {
        resultString.replace(position, string2.length(), string3);
        position = resultString.find(string2, position + string3.length());
    }

    return resultString;
}
