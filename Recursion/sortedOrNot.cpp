#include<iostream>
#include<vector>
using namespace std;

bool checkArray(vector<int>& arr, int index){
if(index >= arr.size()-1){
 return true;
}

if(arr[index]>arr[index+1])
return false;
else
return checkArray(arr, index+1);
}

bool solveSort(vector<int>& arr,int index){
    if(index==0){
        return true;
    }
    if(arr[index]>=arr[index-1]){
        return solveSort(arr, index-1);
    }
    else{
        return false;
    }
}

int main(){
    vector<int> arr = {};
    bool flag = solveSort(arr, arr.size()-1);

    if(flag)
    cout<<"Array is Sorted"<<endl;
    else
    cout<<"Array is Not Sorted"<<endl;

    

    return 0;
}