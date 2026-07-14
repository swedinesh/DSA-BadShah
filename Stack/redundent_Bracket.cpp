#include <iostream>
#include <stack>
// #include<string>

using namespace std;

bool chechRedundency(string &s, stack<char> &st)
{
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            bool operatorFind = false;
            
            
            while (!st.empty() && st.top() != '(')
            {
                 char c = st.top();

                if (c == '+' || c == '-' || c == '/' || c == '*')
                {
                    operatorFind = true;
                }
                st.pop();
            }

            if (operatorFind == false)
            {
                return true;
            }
            else
            {
                st.pop();
            }
        }
    }
    return false;
}

int main()
{

    string s = "((a+b)";
    stack<char> st;

    if(chechRedundency(s, st)){
        cout<<"Yes Redendency"<<endl;
    }
    else{
          cout<<"No Redendency"<<endl;
    }

    return 0;
}