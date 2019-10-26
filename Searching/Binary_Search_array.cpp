//Searching algorithm for a key in an array
//Searching Algorithm: Binary Search
//Time Complexity: In searching O(log(n)) Sorting O(nlog(n)) Overall: O(nlog(n))
//Language Used: C++
//Author: goyaldhara
#include<bits/stdc++.h>
using namespace std;
int Binary_Search(int arr[],int start,int end,int key)
{
    // This function will return 1 if the key is found in the array, else it will return 0;
    while(start<=end)
    {
        int mid=(start)+(end-start)/2;
        if(arr[mid] == key)
            return 1;
        if(arr[mid] < key)
            start = mid+1;
        else
            end=mid-1;
    }
    return 0;
}
int main()
{
    int n,key;                          //size of array in which the key is to be searched
    cin>>n;
    int arr[n+10];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>key;
    sort(arr,arr+n);
    cout<<Binary_Search(arr,0,n-1,key)<<'\n';

return 0;
}