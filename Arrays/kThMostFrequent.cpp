#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// int binarySearch(vector<int>& arr, int k){
//    int n = arr.size();
//    int s = 0;
//    int e = n-1;

//    while(s<=e){
//     int mid = s + (e - s)/2;
//     if(arr[mid]==k)
//     return mid;
//     else if(k > arr[mid])
//     s = mid + 1;
//     else{
//         e = mid - 1;
//     }
//  }
//  return -1;
// }

void frequency(vector<int>& arr, int k){
    unordered_map<int, int> mapping;
    int c=0;

    for(int i=0; i<arr.size(); i++){
        if(i>0 && arr[i]!=arr[i-1])
        c = 0;
        mapping[arr[i]] = ++c;
    }

    // for(int i=0; i<mapping.size(); i++){
    //     cout<<mapping[i]<<" ";
    // }
     vector<int> ans;
    for(auto it : mapping){
        ans.push_back(it.second);
    }
    cout<<endl;
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    //return c;
    
}

int main(){
    vector<int> arr = {1, 1, 1, 2, 2, 3, 4};
    sort(arr.begin(), arr.end());
    int k = 6;
    
    frequency(arr, k);

   // cout<<"serach : "<<binarySearch(arr, k)<<endl;
    
    return 0;
}