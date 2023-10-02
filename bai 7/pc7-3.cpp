#include <iostream>
#include <string>
using namespace std;

const int NUM_SALSA_TYPES = 5;

int main() {
    string salsaNames[NUM_SALSA_TYPES] = {
        "Mild", "Medium", "Sweet", "Hot", "Zesty"
    };
    int jarsSold[NUM_SALSA_TYPES] = {0};
    
    for (int i = 0; i < NUM_SALSA_TYPES; i++) {
        do {
            cout << "Enter the number of jars sold for " << salsaNames[i] << ": ";
            cin >> jarsSold[i];
        } while (jarsSold[i] < 0);
    }

    int totalSales = 0;
    int highestSales = jarsSold[0];
    int lowestSales = jarsSold[0];
    string highestSellingSalsa = salsaNames[0];
    string lowestSellingSalsa = salsaNames[0];

    for (int i = 0; i < NUM_SALSA_TYPES; i++) {
        totalSales += jarsSold[i];
        
        if (jarsSold[i] > highestSales) {
            highestSales = jarsSold[i];
            highestSellingSalsa = salsaNames[i];
        }
        
        if (jarsSold[i] < lowestSales) {
            lowestSales = jarsSold[i];
            lowestSellingSalsa = salsaNames[i];
        }
    }

    cout << "\nSales Report\n";
    cout << "-------------\n";
    for (int i = 0; i < NUM_SALSA_TYPES; i++) {
        cout << salsaNames[i] << " Salsa: " << jarsSold[i] << " jars\n";
    }
    cout << "Total Sales: " << totalSales << " jars\n";
    cout << "Highest Selling Salsa: " << highestSellingSalsa << " (" << highestSales << " jars)\n";
    cout << "Lowest Selling Salsa: " << lowestSellingSalsa << " (" << lowestSales << " jars)\n";

    return 0;
}
