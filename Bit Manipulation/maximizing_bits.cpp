// C++ program to find maximum number by 
// swapping extreme bits. 
#include <bits/stdc++.h> 
using namespace std; 
  
#define ull unsigned long long int 
  
ull findMax(ull num) 
{ 
    ull num_copy = num; 
  
    /* Traverse bits from both extremes */
    int j = sizeof(unsigned long long int) * 8 - 1; 
    int i = 0; 
    while (i < j) { 
  
        // Obtaining i-th and j-th bits 
        int m = (num_copy >> i) & 1; 
        int n = (num_copy >> j) & 1; 
  
        /* Swapping the bits if lesser significant 
           is greater than higher significant 
           bit and accordingly modifying the number */
        if (m > n) { 
            int x = (1 << i | 1 << j); 
            num = num ^ x; 
        } 
  
        i++; 
        j--; 
    } 
    return num; 
} 
  
// Driver code to run program
int main() 
{ 
    ull num = 4; 
    cout << findMax(num); 
    return 0; 
} 
