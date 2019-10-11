#include <iostream>


/*
 * Mergesort:
 * This sorting algorithm recursively splits the larger array into halves
 * and then reorders the smaller arrays.
 *
 * Best/Average/Worst case: n(log(n))
 */
void mergeArrays(int arr[], int left, int center, int right) {
    int leftEnd = center - 1;
    int tempCounter = left;

    int arr_size = right - left + 1;
    int temparr[arr_size];

    // compares the values in the two arrays and sorts by smallest to least
    while(left <= leftEnd && center <= right) {
        if(arr[left]<= arr[center])
            temparr[tempCounter++] = arr[left++];
        else
            temparr[tempCounter++] = arr[center++];
    }

    // copy whatever was left in the first half
    while(left <= leftEnd)
        temparr[tempCounter++] = arr[left++];

    // same as ^, except for second half
    while(center <= right)
        temparr[tempCounter++] = arr[center++];

    // add the values backwards (basically it's sorted from greatest to least
    for( int i = 0; i < arr_size; i++, right-- )
        arr[right] = temparr[right];
}

// arr = the array that is being sorted
// left = the leftmost index where the array begins being sorted
// right = rightmost index
void mergeSortRecurse(int arr[], int left, int right) {
    if (left < right) {
        int center = (left + right)/2;

        // recursively split the array into 2 smaller halves
        mergeSortRecurse(arr, left, center);
        mergeSortRecurse(arr, center + 1, right);

        mergeArrays(arr, left, center + 1, right);
    }
}

int main() {
    // a main function that can be used to test our code

    int arr[] = {1, 5, 6, 3, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // a direct call to the recursive function
    mergeSortRecurse(arr, 0, arr_size - 1);

    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
}