#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

/*
 * RadixSort:
 * Radix Sort is to do digit by digit sort starting 
 * from least significant digit to most significant digit
 *
 * Best Case Time Complexity: Ω(nk)
 * Average/Worst Case Time Complexity: O(nk)
 */

#define BUCKET 10 
#define DIGIT 4

void radix_sort(int arr[], int n) {
	int i, j,k=0;
	queue<int> q[10];
	int radix = 1;
	for (int d = 0; d < DIGIT; d++) {
		// sort arr according to the digit using queue
		for (i = 0; i < n; i++)						
			q[(arr[i] / radix) % 10].push(arr[i]);
		// build the output arr
		for (i=j=0; j < BUCKET; j++)			
			while (!q[j].empty()){
				arr[i++] = q[j].front();
				q[j].pop();
			}
		radix *= 10;
	}
}

int main() {
	srand(time(NULL));
	int array[10]={};
	//push randomly created number below 10000 into the array
	for (int i = 0; i < 10; i++) {
		array[i] = rand() % 10000;
		cout << array[i] << " ";
	}
	cout << endl;
	radix_sort(array, 10);
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
}




