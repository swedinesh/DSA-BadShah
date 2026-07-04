#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    string f(string &n1, string &n2, int i, int j, string &ans, int &carry) {

        if (i < 0) {
            return ans;
        }

        if (j >= 0) {
            int value = (n1[i] - '0') + (n2[j] - '0') + carry;
            carry = value / 10;
            value = value % 10;
            ans = to_string(value) + ans;
    
        } else {
            int value = (n1[i] - '0') + carry;
            carry = value / 10;
            value = value % 10;
            ans = to_string(value) + ans;
        }

        return f(n1, n2, i-1, j-1, ans, carry);
    }

    string addStrings(string num1, string num2) {
        // User will implement the logic here

        int i = num1.length();
        int j = num2.length();

        string ans;
        int carry = 0;

        if (i >= j) {
            ans = f(num1, num2, i - 1, j - 1, ans, carry);
             
        } else {
            ans = f(num2, num1, j - 1, i - 1, ans, carry);
            
        }

        if(carry){
                ans = to_string(carry) + ans;
            }

        return ans;
    }
};

int main()
{

    Solution s;

    string res = s.addStrings("123", "11");

    cout<<res<<endl;

    // string str1 = "123";
    // string str2 = "11";
    // string sum;

    // int i = 2;
    // int carry = 0;
    // int j = 1;
    // while (i >= 0)
    // {
    //     if (j >= 0)
    //     {
    //         int value = (str1[i] - '0') + (str2[j] - '0') + carry;
    //         carry = value / 10;
    //         value = value % 10;
    //         sum = to_string(value) + sum;
    //         i--;
    //         j--;
    //     }
    //     else
    //     {
    //         int value = (str1[i] - '0') + carry;
    //         carry = value / 10;
    //         value = value % 10;
    //         sum = to_string(value) + sum;
    //         i--;
    //     }
    // }
    // if (carry)
    //     sum = to_string(carry) + sum;

    // cout << sum << endl;

    //    int n = (str1[0]-'0') + (str2[0]-'0');
    //    string str3 = to_string(n);

    //    cout<<str3<<endl;
    return 0;
}