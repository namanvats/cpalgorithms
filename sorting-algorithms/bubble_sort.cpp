#include <iostream>
using namespace std;

/*
 * BubbleSort:
 * sorting algorithm that works by repeatedly swapping the adjacent elements
 * if they are in wrong order
 *
 * Average/Worst Case Time Complexity: O(n*n)
 * Best Case Time Complexity: O(n)
 */

// change location of two arrays
void swap(int &a, int &b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

// sort array in ascending order
void BubbleSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i-1; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

int main(){
	int size;
	int* array;
	cout << "Size: "; 
	cin >> size;
	array = new int[size];
	for(int i=0;i<size;i++){
		cout << "Array[" << (i+1) << "]: ";
		cin >> array[i];
	}
	BubbleSort(array, size);
	for(int j=0;j<size;j++){
		cout << array[j] << " ";
	}
	return 0;
}


