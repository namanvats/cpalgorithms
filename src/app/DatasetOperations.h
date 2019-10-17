#ifndef DatasetOperations_H
#define DatasetOperations_H
#include <random>
#include <iostream>
using namespace std;  

// Function Prototypes
double generateRandomNumber();

// Function Definitions
void randomizeDataset(double dataset[], int size) {
    for (int i = 0; i < size; i++) {
        dataset[i] = generateRandomNumber();
    }
}

double generateRandomNumber() {
    // Credit to Stephan T. Lavavej (stl) from Microsoft for this secure randomization code
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.00, 10.00);

    return dist(mt); 
}

void printDataset(double dataset[], int size) {
    for (int i = 0; i < size; i++) {
        cout << dataset[i] << "  ";
        if (i % 10 == 0 && i > 1) {
            cout << "\n"; 
        }
    }
    cout << "\n\n";
}

#endif