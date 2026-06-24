#include<iostream>
using namespace std;

int binarySearch(int* arr, int s, int e, int target){
    if(s>e)
    return -1;
    
    int mid = s + ( e - s)/2;

    if(arr[mid]==target)
    return mid;
    else if(arr[mid]<target){
       return binarySearch(arr, mid+1, e, target);
    } 
    else{
        return binarySearch(arr, s, mid-1, target);
    }
}
void printDigit(int n){
    if(n==0) return;
    printDigit(n/10);
    cout<<n%10<<" ";
    return;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    cout<<"Binary Search : "<<binarySearch(arr, 0, 6, 70)<<endl;
    printDigit(423);
    cout<<endl;
    return 0;
}