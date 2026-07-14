#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

void nextSmaller(vector<int>& arr, vector<int>& ans, stack<int>& s){
int n = arr.size()-1;

for(int i=n; i>=0; i--){
   int temp = arr[i];

    while(s.top() >= temp){
        s.pop();
    }
    
    int val = s.top();
    ans.push_back(val);
    s.push(temp);
    
}


}

int main(){
    vector<int> arr;
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);

    stack<int> s;
    s.push(-1);

    vector<int> ans;
     
  

    nextSmaller(arr, ans, s);

    reverse(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    return 0;
}