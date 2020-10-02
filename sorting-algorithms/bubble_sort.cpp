void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(int[] a)
/*
Bubble sort, sometimes referred to as sinking sort, is a simple sorting
algorithm that repeatedly steps through the list, compares adjacent elements,
and swaps them if they are in the wrong order. The pass through the list is
repeated until the list is sorted.
*/
{
   	int n = a.length;
    for (int j = 0; j < n - 1; ++j){111
        for (int i = 0; i < n - j - 1; ++i)
            if (a[i] > a[i+1])
                swap(a, i, i+1);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


int main()
{
    // a main function that can be used to test our code

    int arr[] = {1, 5, 6, 3, 2};

    bubbleSort(arr);

    std::cout << "Sorted array:" << std::endl;
    printArray(arr, n);
    return 0;
}
