#include <iostream>
#include <array>
using namespace std;

void f1()
{
    array<int, 5> x = {1, 2, 3, 4, 5};
    array<string, 4> y = {"Delhi", "Lucknow", "Kanpur", "Hamirpur"};
    array<int, 5> z = x;

    //[]
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";

    cout << endl;

    // at()
    for (int i = 0; i < x.size(); i++)
        cout << x.at(i) << " ";

    cout << endl;

    // implicit
    for(auto ele : x)
    cout<<ele<<" ";
     cout<<endl;

    // explicitly 
    array<int,5>::iterator it;
    for(it = x.begin(); it != x.end(); it++)
    cout<<*it<<" ";

    cout<<endl;
}
int main()
{
    f1();
    return 0;
}