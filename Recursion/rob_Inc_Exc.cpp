#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums, int index){
  if(index >= nums.size())
  return 0;

  int include = nums[index] + rob(nums, index+2);

  int exclude = 0 + rob(nums, index+1);

  int finalAns = max(include, exclude);

  return finalAns;
}

int main(){
    vector<int> nums = {2, 7, 9, 5, 6, 6};
    int ans = rob(nums, 0);
    cout<<endl<<"Robery : "<<ans<<endl<<endl;
    return 0;
}