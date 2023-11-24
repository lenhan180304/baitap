#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Question {
public:
    Question(const std::string& question, const std::string& answer1, const std::string& answer2,
             const std::string& answer3, const std::string& answer4, int correctAnswer);

    std::string getQuestion() const;
    std::string getAnswer1() const;
    std::string getAnswer2() const;
    std::string getAnswer3() const;
    std::string getAnswer4() const;
    int getCorrectAnswer() const;

private:
    std::string question;
    std::string answer1;
    std::string answer2;
    std::string answer3;
    std::string answer4;
    int correctAnswer;
};

Question::Question(const std::string& q, const std::string& a1, const std::string& a2,
                   const std::string& a3, const std::string& a4, int correct)
    : question(q), answer1(a1), answer2(a2), answer3(a3), answer4(a4), correctAnswer(correct) {}

std::string Question::getQuestion() const {
    return question;
}

std::string Question::getAnswer1() const {
    return answer1;
}

std::string Question::getAnswer2() const {
    return answer2;
}

std::string Question::getAnswer3() const {
    return answer3;
}

std::string Question::getAnswer4() const {
    return answer4;
}

int Question::getCorrectAnswer() const {
    return correctAnswer;
}

class TriviaGame {
public:
    TriviaGame();
    void playGame();

private:
    Question questions[10];
};

TriviaGame::TriviaGame() {
    // Initialize questions with your own trivia questions and answers
    // You can modify or add more questions as needed
    questions[0] = Question("What is the capital of France?", "Berlin", "Paris", "Madrid", "Rome", 2);
    questions[1] = Question("Which planet is known as the Red Planet?", "Venus", "Mars", "Jupiter", "Saturn", 2);
    questions[2] = Question("Who wrote 'Romeo and Juliet'?", "Charles Dickens", "William Shakespeare", "Jane Austen", "Mark Twain", 2);
    questions[3] = Question("What is the largest mammal?", "Elephant", "Giraffe", "Blue Whale", "Dolphin", 3);
    questions[4] = Question("Which element has the chemical symbol 'O'?", "Osmium", "Oxygen", "Gold", "Silver", 2);
    questions[5] = Question("What is the capital of Japan?", "Beijing", "Tokyo", "Seoul", "Bangkok", 2);
    questions[6] = Question("Who painted the Mona Lisa?", "Vincent van Gogh", "Leonardo da Vinci", "Pablo Picasso", "Claude Monet", 2);
    questions[7] = Question("What is the largest ocean on Earth?", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean", 4);
    questions[8] = Question("What is the powerhouse of the cell?", "Nucleus", "Mitochondria", "Endoplasmic Reticulum", "Ribosome", 2);
    questions[9] = Question("Which programming language is known for its simplicity and readability?", "Java", "C++", "Python", "Ruby", 3);
}

void TriviaGame::playGame() {
    int player1Score = 0;
    int player2Score = 0;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Question " << (i + 1) << ": " << questions[i].getQuestion() << std::endl;
        std::cout << "1. " << questions[i].getAnswer1() << std::endl;
        std::cout << "2. " << questions[i].getAnswer2() << std::endl;
        std::cout << "3. " << questions[i].getAnswer3() << std::endl;
        std::cout << "4. " << questions[i].getAnswer4() << std::endl;

        int player1Answer, player2Answer;
        std::cout << "Player 1, enter your answer (1-4): ";
        std::cin >> player1Answer;

        std::cout << "Player 2, enter your answer (1-4): ";
        std::cin >> player2Answer;

        if (player1Answer == questions[i].getCorrectAnswer()) {
            std::cout << "Player 1 is correct!\n";
            player1Score++;
        } else {
            std::cout << "Player 1 is incorrect. The correct answer is: " << questions[i].getCorrectAnswer() << "\n";
        }

        if (player2Answer == questions[i].getCorrectAnswer()) {
            std::cout << "Player 2 is correct!\n";
            player2Score++;
        } else {
            std::cout << "Player 2 is incorrect. The correct answer is: " << questions[i].getCorrectAnswer() << "\n";
        }

        std::cout << std::endl;
    }

    // Display final scores
    std::cout << "Player 1 score: " << player1Score << std::endl;
    std::cout << "Player 2 score: " << player2Score << std::endl;

    // Determine the winner
    if (player1Score > player2Score) {
        std::cout << "Player 1 wins!\n";
    } else if (player2Score > player1Score) {
        std::cout << "Player 2 wins!\n";
    } else {
        std::cout << "It's a tie!\n";
    }
}

int main() {
    TriviaGame game;
    game.playGame();

    return 0;
}
