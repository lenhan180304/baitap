#include <iostream>
#include <sstream>

std::string convertToPigLatin(const std::string& word) {
    if (word.empty()) {
        return "";
    }

    // Move the first letter to the end and append "ay"
    return word.substr(1) + word[0] + "AY";
}

std::string pigLatinSentence(const std::string& sentence) {
    std::stringstream ss(sentence);
    std::string word;
    std::string result;

    // Process each word in the sentence
    while (ss >> word) {
        result += convertToPigLatin(word) + " ";
    }

    return result;
}

int main() {
    std::string inputSentence;

    // Get a sentence from the user
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, inputSentence);

    // Convert the sentence to Pig Latin
    std::string pigLatinResult = pigLatinSentence(inputSentence);

    // Display the result
    std::cout << "Pig Latin: " << pigLatinResult << std::endl;

    return 0;
}

