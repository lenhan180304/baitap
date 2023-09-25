#include <iostream>
using namespace std;

int main()
{
    int numberOfGallons = 20;
    double averageMilesPerGallonCity = 23.5;
    double averageMilesPerGallonHighway = 28.9;

    double distanceCity = numberOfGallons * averageMilesPerGallonCity;
    double distanceHighway = numberOfGallons * averageMilesPerGallonHighway;

    cout << "The car can travel " << distanceCity << " miles on one tank of gas in the city." << endl;
    cout << "The car can travel " << distanceHighway << " miles on one tank of gas on the highway." << endl;

    return 0;
}

