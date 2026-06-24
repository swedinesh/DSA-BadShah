#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int mode(vector<int>& arr){
    unordered_map<int, int> mapping;
    int c = 0;
    for(int i=0; i<arr.size(); i++){
        if(i>0 && arr[i] != arr[i-1]) 
        c = 0;
        mapping[arr[i]] = ++c;
    }
    int max = -1;
    for(int i=0; i<arr.size(); i++){
        if(max < mapping[arr[i]]){
            max = mapping[arr[i]];
        }
    }
    return max;
}
int main(){
    vector<int> arr = {5, 6, 5, 7};
    sort(arr.begin(), arr.end());
    int count = mode(arr);
    cout<<endl<<"Count : "<<count<<endl;
    return 0;
}