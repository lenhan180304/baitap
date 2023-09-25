#include <iostream>
#include <ctime>
#include <cstdlib>

int math_tutor() {
    int num1 = rand() % 1000 + 1;
    int num2 = rand() % 1000 + 1;

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    int answer;
    std::cout << "Enter the answer: ";
    std::cin >> answer;

    if (answer == num1 + num2) {
        std::cout << "Congratulations! Your answer is correct." << std::endl;
    } else {
        int correct_answer = num1 + num2;
        std::cout << "Sorry, the correct answer is " << correct_answer << std::endl;
    }

    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Call math_tutor function
    math_tutor();

    return 0;
}
