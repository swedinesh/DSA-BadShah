#include<iostream>
using namespace std;


void swapAlternate(int arr[],int size){
    for(int i=0;i<size-1;i=i+2){
        int temp = arr[i];
        arr[i] = arr[i+1]; 
        arr[i+1] = temp;  
        
    //     arr[i] = arr[i]^arr[i+1];
    //     arr[i+1] = arr[i]^arr[i+1];
    //     arr[i] = arr[i]^arr[i+1];

    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr)/sizeof(arr[0]); 

    swapAlternate(arr, n);

    for(int ele : arr){
        cout<<ele<<" ";
    }

    cout<<endl;

    return 0;
}