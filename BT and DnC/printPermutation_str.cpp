#include <bits/stdc++.h>
using namespace std;

void printPermutationOfString(string &s, int i)
{
    if (i >= s.length())
    {
        cout << s << endl;
        return;
    }

    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        printPermutationOfString(s, i + 1);
        // BackTrack
        swap(s[i], s[j]);
    }
}
int main()
{
    string s = "abc";
    cout << "===============" << endl;
    printPermutationOfString(s, 0);
    cout << "===============" << endl;
    return 0;
}