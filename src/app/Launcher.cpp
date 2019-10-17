#include <iostream>
#include "../libs/algorithms/sorting/SelectionSort.h"
#include "DatasetOperations.h"
using namespace std;

// Global Variables
const int SIZE_OF_DATASET = 30;
double dataset[SIZE_OF_DATASET];

// Function Prototypes
void selectAlgorithm(); 

// Entry point
int main( int argc, const char* argv[] ) {
    selectAlgorithm();
}

void selectAlgorithm() {
    printf("Hello!  This program will run algorithms written in C++.\n");

    printf("Now, please select an algorithm to run from the list below:\n");
    printf("Enter \"1\" for selection sort.\n");

    // Recieve user input
    int userSelection;
    cin >> userSelection;

    switch (userSelection) {
        case 1: {
            randomizeDataset(dataset, SIZE_OF_DATASET);
            printf("The following are the contents of the dataset prior to the sort.\n\n");
            printDataset(dataset, SIZE_OF_DATASET);

            printf("The following are the contents of the dataset after the sort.\n\n");
            selectionSort(dataset, SIZE_OF_DATASET);
            printDataset(dataset, SIZE_OF_DATASET);
        }
        break;

        default: {
            cout << "The selection you have entered has not yet been implemented.\n";
            exit(0);
        }
    }
}

