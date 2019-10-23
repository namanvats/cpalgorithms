#include <iostream>
using namespace std;

void insertion(int[],int);
void showData(int[],int);

main(){
	int size = 40,counter = 0;
	int array[size]; //Size can be changed, just to prove it works
	cout << "************FILLING ARRAY************" << endl;
	for(int i=size;i>0;i--){ //Worst case, as it is ordered backwards
		array[counter]= i;
		cout << "Array, position " << counter << ": " << array[counter] << endl;
		counter++;
	}
	cout << "************FINISHED FILLING, STARTING SORTING************" << endl;
	insertion(array,size);
}

void insertion(int data[], int size){
	int aux=0,j=0;
        for(int i=1;i<=size;i++){
            j=i;
            aux=data[i];
            while(j>0 && aux<data[j-1]){
                data[j] = data[j-1];
                j--;
            }
            data[j] = aux;
        }
        showData(data,size);
}

void showData(int array[],int size){
	for(int i=0;i<size;i++){
		cout << "Element " << (i+1) << ": " << array[i] << endl;
	}
}



