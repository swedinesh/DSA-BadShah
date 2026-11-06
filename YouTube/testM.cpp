#include<bits/stdc++.h>
using namespace std;

int f1(int *val, int * wt, int w, int n)
{
    if(n==0||w==0) 
    return 0;

    if(wt[n-1]<=w)
    return max(val[n-1]+f1(val, wt, w-wt[n-1], n-1),
 f1(val, wt, w, n-1));

 else if(wt[n-1]>w)
 return f1(val, wt, w, n-1);
}

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