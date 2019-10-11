#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int a[n];
    // loop for inputing the array
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //code segement responsible for the sorting 
    // first to loop for each position
    for(int i=0;i<n;i++){
        // looping through the crossed over array to find if there is something greater the number currentlt at this postion
        for(int j=0;j<n-i-1;j++){
            //checking condition to make a swap
            if(a[j]<a[i]){
                //implementing the swap
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    // looping to output the array
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}
