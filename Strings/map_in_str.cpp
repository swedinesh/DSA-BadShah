#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, char> map;

    // map['p'] = 't';
    // map['a'] = 'i';
    // map['x'] = 't';
    // map['e'] = 'l';
    // map['r'] = 'e';

    const string s = "227cDhx";
    const string t = "6O42TOI";

    unordered_map<char, char> sTot;

    int s_size = s.length();
    int t_size = t.size();

    for (int i = 0; i < s_size; i++)
    {

        // char one = s[i];
        // char two = t[i];

        sTot[s[i]] = t[i];
    }
    unordered_map<char, char> tTos;

    for (int i = 0; i < t_size; i++)
    {

        // char one = t[i];
        // char two = s[i];

        tTos[t[i]] = s[i];
    }

    cout << "sTot size : " << sTot.size() << endl;
    cout << "tTos size : " << tTos.size() << endl;

    // for(auto it= sTot.begin(); it != sTot.end(); it++){
    //     cout<<it->first<<" : "<<it->second<<endl;
    // }

    // cout<<endl;

    //  for(auto it= tTos.begin(); it != tTos.end(); it++){
    //     cout<<it->first<<" : "<<it->second<<endl;
    // }

     for(auto it = sTot.begin(); it!=sTot.end(); it++)
        {
            char first_StoT = it->first;
            char second_StoT = it->second;
            cout<<"StoT : "<<first_StoT<<endl;
            char first_TtoS = tTos[second_StoT];
            cout<<"TtoS : "<<first_TtoS<<endl;
        }

    return 0;
}