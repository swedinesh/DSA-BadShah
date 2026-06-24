#include<iostream>
using namespace std;

void populate(int arr[],int n){
    int j=0;
    for(int i=0; i < n; i = i + 2){
        arr[n-j-1] = i+2;
        arr[j] = i+1;
        j++;
    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr)/sizeof(arr[0]); 
    populate(arr, n);

    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}