#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_MONKEYS = 3;
const int NUM_DAYS = 5;

void inputData(double foodEaten[NUM_MONKEYS][NUM_DAYS]) {
    for (int monkey = 0; monkey < NUM_MONKEYS; monkey++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            do {
                cout << "Enter the pounds of food eaten by Monkey " << (monkey + 1);
                cout << " on Day " << (day + 1) << ": ";
                cin >> foodEaten[monkey][day];
                if (foodEaten[monkey][day] < 0) {
                    cout << "Please enter a non-negative value for food eaten.\n";
                }
            } while (foodEaten[monkey][day] < 0);
        }
    }
}

double calculateAverageDailyFood(double foodEaten[NUM_MONKEYS][NUM_DAYS]) {
    double totalFood = 0;
    for (int monkey = 0; monkey < NUM_MONKEYS; monkey++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            totalFood += foodEaten[monkey][day];
        }
    }
    return totalFood / (NUM_MONKEYS * NUM_DAYS);
}

double findLeastFood(double foodEaten[NUM_MONKEYS][NUM_DAYS]) {
    double leastFood = foodEaten[0][0];
    for (int monkey = 0; monkey < NUM_MONKEYS; monkey++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            if (foodEaten[monkey][day] < leastFood) {
                leastFood = foodEaten[monkey][day];
            }
        }
    }
    return leastFood;
}

double findGreatestFood(double foodEaten[NUM_MONKEYS][NUM_DAYS]) {
    double greatestFood = foodEaten[0][0];
    for (int monkey = 0; monkey < NUM_MONKEYS; monkey++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            if (foodEaten[monkey][day] > greatestFood) {
                greatestFood = foodEaten[monkey][day];
            }
        }
    }
    return greatestFood;
}

int main() {
    double foodEaten[NUM_MONKEYS][NUM_DAYS];
    inputData(foodEaten);

    double averageDailyFood = calculateAverageDailyFood(foodEaten);
    double leastFood = findLeastFood(foodEaten);
    double greatestFood = findGreatestFood(foodEaten);

    cout << fixed << showpoint << setprecision(2);
    cout << "Average pounds of food eaten per day by all monkeys: " << averageDailyFood << endl;
    cout << "Least amount of food eaten during the week by any one monkey: " << leastFood << endl;
    cout << "Greatest amount of food eaten during the week by any one monkey: " << greatestFood << endl;

    return 0;
}
