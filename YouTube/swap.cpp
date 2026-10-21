#include<bits/stdc++.h>
using namespace std;

int sd(int x) {
        int sum = 0;
        while (x > 0) {
            int l = x % 10;
            sum += l;
            x /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
    
        multimap<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
           m.insert({nums[i], sd(nums[i])});
        }

        for (const auto& pair : m) {
            cout << pair.first << ": " << pair.second << "\n";

        }
        return nums[2];
    }
int main()
{
    vector<int> a = {18, 43, 34, 16};
    int x = minSwaps(a);
    return 0;
}