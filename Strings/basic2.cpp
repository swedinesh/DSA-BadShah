#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = " DineshX ";
    string str2 = " Kushwaha";

    string str;

    string base = "The quick brown fox jumps over a lazy dog.";

    // Assign complete string
    str.assign(base);
    cout << str << '\n';

    // Assign 9 characters starting from index 10
    str.assign(base, 10, 9);
    cout << str << '\n';

    // Assign first 7 characters
    str.assign("pangrams are cool", 7);
    cout << str << '\n';

    // Assign complete C-string
    str.assign("c-string");
    cout << str << '\n';

    // Assign '*' 10 times
    str.assign(10, '*');
    cout << str << '\n';

    // Assign '-' 10 times
    str.assign(10, 0x2D);
    cout << str << '\n';

    // Assign using iterators
    str.assign(base.begin() + 16, base.end() - 12);
    cout << str << '\n';

    // Append 5 characters from str1 starting at index 3
    str.append(str1, 3, 5);
    cout << str << endl;

    // Access using index
    for (unsigned i = 0; i < str.length(); ++i)
    {
        cout << str[i] << " ";
    }

    cout << endl;

    // Change last character
    str2.back() = 'Z';

    // Access using iterator
    for (string::iterator it = str2.begin(); it != str2.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}