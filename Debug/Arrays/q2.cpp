#include<iostream>
using namespace std;

void linearSearch(int arr[], int n ,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            cout<<"index : "<<i<<endl;
            return;
        }
    }
    return;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int val = 4;
    int n = sizeof(arr)/sizeof(arr[0]);

    linearSearch(arr, n, val);

    return 0;
}