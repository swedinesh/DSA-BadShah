#include<iostream>
#include<vector>

using namespace std;

void mergeTwoSortedArray(vector<int>& a, vector<int>& b, vector<int>& ans){

   int i=0;
   int j=0;
   int as = a.size();
   int bs = b.size();
   ans.clear();
   ans.reserve(as+bs);

   while(i<as && j<bs){
    if(a[i]<=b[j])
        ans.push_back(a[i++]);
    else
         ans.push_back(b[j++]);
   }


    while(i<as){
       ans.push_back(a[i++]); 
    }
   
    while(j<bs){
       ans.push_back(b[j++]); 
    }


}

void mergeSort(vector<int> &arr){
    int n = arr.size();
    if(n<=1) return;

    vector<int> a;
    a.resize(n/2);
    vector<int> b;
    b.resize(n-(n/2));

      int idx = 0;

    for(int i=0; i<a.size(); i++) a[i] = arr[idx++];
    for(int i=0; i<b.size(); i++) b[i] = arr[idx++];

    mergeSort(a);
    mergeSort(b);

    mergeTwoSortedArray(a,b,arr);
}

int main(){

    // vector<int> a = {1, 3, 5, 7, 9};
    // vector<int> b = {2, 4, 6, 8, 10, 11};

    // vector<int> ans;

    // mergeTwoSortedArray(a,b,ans);

    vector<int> ans = {7,-5,2,1,10,9,8};

    mergeSort(ans);

    for(auto ele : ans){
        cout<<ele<<" ";
    }

    cout<<endl;

    return 0;
}