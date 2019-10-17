#ifndef SelectionSort_H
#define SelectionSort_H

using namespace std;

// Function Prototypes
void swap(double *x, double *y); 
void selectionSort(double dataset[], int size);

/*
    Big O Summary for Selection Sort:
    
    Because it contains a loop nested within another loop, this algorithm operates in O(n^2) time in
    every case. The inner loop must iterate over the entire array upon each iteration of the outer
    loop. O(n^2), otherwise called quadratic time, is rather inefficient and will be slow for large
    datasets.
*/
void selectionSort(double data[], int size) {
    int minimumIndex;
    for (int i = 0; i < size - 1; i++) {
        minimumIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[minimumIndex]) {
                minimumIndex = j; 
            }
        }
        swap(&data[i], &data[minimumIndex]); 
    }
}

void swap(double *x, double *y) {
    double temp = *x; 
    *x = *y;
    *y = temp; 
}

#endif