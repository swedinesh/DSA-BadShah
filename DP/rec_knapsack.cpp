#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp(5, vector<int>(8, -1));
int maxKnap(vector<int> &wt, vector<int> &val, int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    if(dp[n][w] != -1)
    return dp[n][w];

    if (wt[n - 1] <= w)
        return dp[n][w] = max(val[n - 1] + maxKnap(wt, val, w - wt[n - 1], n - 1),
                   maxKnap(wt, val, w, n - 1));

    else if (wt[n - 1] > w)
        return dp[n][w] = maxKnap(wt, val, w, n - 1);

    return 0;
}

int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int w = 7;
    cout<<"Max Profit : "<<maxKnap(wt, val, w, val.size())<<endl;
    return 0;
}