/* Bubble sort code */
     
    #include <stdio.h>       	// Header File in included in this line
     
    int main()					// The main function Begain here
    {
      int array[100], n, c, d, swap;      /*Defineing the variable used in the program*/
     
      printf("Enter number of elements\n");  // total number of integers in the sorting list that can be added into the array 
      scanf("%d", &n);
     
      printf("Enter %d integers\n", n);     //add different integers dont use ,(comma) hit enter after every new integer value
     
      for (c = 0; c < n; c++)
        scanf("%d", &array[c]);			// adding values into the array
     
      for (c = 0 ; c < n - 1; c++)		//checking for correct/sorted order by loopuing and comparing each values in array and then swapping them in correct position
      {
        for (d = 0 ; d < n - c - 1; d++)
        {
          if (array[d] > array[d+1]) /* For decreasing order use < */
          {
            swap       = array[d];           //method for swappin is define in line no 23-25
            array[d]   = array[d+1];
            array[d+1] = swap;
          }
        }
      }										// list is sorted till here now we will be printing the sorted list
     
      printf("Sorted list in ascending order:\n");
     
      for (c = 0; c < n; c++)
         printf("%d\n", array[c]);
     
      return 0;                          

      /*    Time  Complexity for Bubble Sort is O(n^2)*/
    }