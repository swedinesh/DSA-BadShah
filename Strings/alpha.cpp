#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "thequickbrownfoxjumpsoverthelazydog";
    unordered_map<char, int> map;

    size_t n = s.length();
        for(size_t i=0; i<n; i++)
        {
        char c = s[i];
           map[c]++;
        }
       auto it = map.begin();
        while(it !=  map.end())
        {
            pair<char, int> p = *it;
          cout<<p.first<<"->"<<p.second<<endl;
          it++;
        }
    
    return 0;
}