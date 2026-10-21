#include<bits/stdc++.h>
using namespace std;
 int unique(vector<int>& arr)
    {
       unordered_map<int, int> m;
       for(int i=0; i<arr.size(); i++)
       {
        m[arr[i]];
       }
       int s = m.size();
       return s;
    }
int main()
{
    vector<int> nums = {1,2,1};
    vector<int> temp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            temp.clear();
            for(int j=i; j<n; j++)
            {
            for(int k=i; k<=j; k++){
                temp.push_back(nums[k]);
            }
            cout<<unique(temp)<<" ";
            }
            
        }
        cout<<endl;
    return 0;
}