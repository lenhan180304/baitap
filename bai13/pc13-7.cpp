#include <iostream>

class TestScores {
private:
    double score1;
    double score2;
    double score3;

public:
    // Constructor
    TestScores(double s1, double s2, double s3);

    // Accessor functions
    double getScore1() const;
    double getScore2() const;
    double getScore3() const;

    // Mutator functions
    void setScore1(double s1);
    void setScore2(double s2);
    void setScore3(double s3);

    // Member function to calculate the average
    double calculateAverage() const;
};

// Constructor
TestScores::TestScores(double s1, double s2, double s3) : score1(s1), score2(s2), score3(s3) {}

// Accessor functions
double TestScores::getScore1() const {
    return score1;
}

double TestScores::getScore2() const {
    return score2;
}

double TestScores::getScore3() const {
    return score3;
}

// Mutator functions
void TestScores::setScore1(double s1) {
    score1 = s1;
}

void TestScores::setScore2(double s2) {
    score2 = s2;
}

void TestScores::setScore3(double s3) {
    score3 = s3;
}

// Member function to calculate the average
double TestScores::calculateAverage() const {
    return (score1 + score2 + score3) / 3.0;
}

int main() {
    // Demonstrate the TestScores class
    double testScore1, testScore2, testScore3;

    // Get test scores from the user
    std::cout << "Enter three test scores:\n";
    std::cout << "Test Score 1: ";
    std::cin >> testScore1;
    std::cout << "Test Score 2: ";
    std::cin >> testScore2;
    std::cout << "Test Score 3: ";
    std::cin >> testScore3;

    // Create an instance of the TestScores class
    TestScores testScoresObj(testScore1, testScore2, testScore3);

    // Display the average of the test scores
    std::cout << "Average Test Score: " << testScoresObj.calculateAverage() << std::endl;

    return 0;
}
