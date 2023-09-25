#include <iostream>
using namespace std;

int main()
{
    const double WIDGET_WEIGHT = 12.5;
    
    // Ask the user for the weight of the pallet
    double palletWeight;
    cout << "Enter the weight of the pallet (in pounds): ";
    cin >> palletWeight;

    // Ask the user for the total weight of the pallet with widgets
    double totalWeight;
    cout << "Enter the total weight of the pallet with widgets (in pounds): ";
    cin >> totalWeight;

    // Calculate the number of widgets on the pallet based on the weight difference
    double widgetsWeight = totalWeight - palletWeight;
    int numWidgets = widgetsWeight / WIDGET_WEIGHT;

    // Display the number of widgets stacked on the pallet
    cout << "The number of widgets stacked on the pallet is: " << numWidgets << endl;

    return 0;
}
