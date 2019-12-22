Sorting algorithms

1. Insertion Sort

Concept Summary
Insertion sort is a simple sorting algorithm that works the way we arrange cards in our hands.
There are N card lists.
First, insert the new card in the correct place between the existing aligned cards.
Second, repeat repetition N-1 times.
Then, the entire card will be aligned.

Insertion Sort Algorithm
insertionSort(int arr[], int n)  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  (The first key value starts with the second data)
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        (if arr[j] is greater than key, move it to one position ahead of the current positon)
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
} 

Example
12, 11, 13, 5, 6
11, 12, 13, 5, 6
11, 12, 13, 5, 6
5, 11, 12, 13, 6
5, 6, 11, 12, 13

2. Merge Sort

Concept Summary
Merge Sort is a Divide and Conquer algorithm.
It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.
Algorithm steps are largely divided into three phases.
First, Split: Divide the problem you want to solve into the same problems of small size
Second, Conquest: Solve each small problem
Third, Combination : A solution to the original problem is obtained by combining the solutions of the small problem

Merge Sort Algorithm
MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)



