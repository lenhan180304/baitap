#include <iostream>
#include <map>
#include <string>
#include <cctype>

std::string charToMorse(char character) {
    // Define a map for Morse code representation
    static const std::map<char, std::string> morseCodeMap = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."},
        {'D', "-.."}, {'E', "."}, {'F', "..-."},
        {'G', "--."}, {'H', "...."}, {'I', ".."},
        {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"},
        {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"},
        {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."},
        {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."},
        {'0', "-----"}
    };

    // Convert character to uppercase
    character = std::toupper(character);

    // Check if the character is in the map
    auto it = morseCodeMap.find(character);
    if (it != morseCodeMap.end()) {
        return it->second;
    } else {
        // If the character is not in the map, return an empty string
        return "";
    }
}

std::string stringToMorse(const std::string& input) {
    std::string morseCode;
    for (char ch : input) {
        if (std::isalnum(ch) || std::isspace(ch)) {
            // Convert alphanumeric characters and spaces to Morse code
            morseCode += charToMorse(ch) + " ";
        }
    }
    return morseCode;
}

int main() {
    std::string userInput;

    // Get a string from the user
    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);

    // Convert the string to Morse code
    std::string morseCodeResult = stringToMorse(userInput);

    // Display the result
    std::cout << "Morse Code: " << morseCodeResult << std::endl;

    return 0;
}
