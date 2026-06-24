#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution{
public:
  int pairCount(vector<int>& arr, int k){
    sort(arr.begin(), arr.end());
    // int count = 0;
    int i=0, j=1;
    int n = arr.size();
    set<pair<int, int>> ans;

    while(j<n){
        int dif = arr[j] - arr[i];
        if(dif == k){
            ans.insert({arr[i],arr[j]});
            i++;
            j++;
        }
        else if(dif < k){
            j++;
        }
        // else if(dif > k && i<j){
        //     i++;
        // }
        else{
            i++;
        }
        if(i==j) j++;
    }
    return ans.size();
  }

  int bs(vector<int>& arr,int s, int x){
     int e = arr.size()-1;
     while(s <= e){
         int mid = s + ( e - s)/2;
         if(arr[mid] == x){
            return mid;
         }
         else if( x > arr[mid]){
            s = mid +1;
         }
         else {
            e = mid -1;
         }
     }
     return -1;
  }

  int secondMethod(vector<int>& arr, int k){
      int n = arr.size();
     set<pair<int, int>> st;
      for(int i=0; i<n; i++){
        if(bs(arr, i+1, arr[i]+k) != -1){
            st.insert({arr[i], arr[i]+k});
        }
      }
      return st.size();
  }
};

int main(){

    Solution s;
    vector<int>  arr = {2, 2, 2, 2};
   // cout<<s.pairCount(arr, 1)<<endl;
   cout<<"Pairs : "<<s.secondMethod(arr, 0)<<endl;
   char ch[10] = {'X','\0','d'};
   cout<<"Char : "<<ch<<endl;
    return 0;
}