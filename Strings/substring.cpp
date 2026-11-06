#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str = "abc";
    vector<string> ans;
    int n = str.length();
    // substring
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string temp = "";
            for (int k = i; k <= j; k++)
            {
                temp.push_back(str[k]);
            }
            ans.push_back(temp);
        }
    }
    for(auto ele : ans)
    cout<<ele<<" ";
    cout<<endl;
    return 0;
}