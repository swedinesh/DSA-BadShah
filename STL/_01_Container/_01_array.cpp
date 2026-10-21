// array dynamically grow nhi hota

#include<iostream>
#include<array>
using namespace std;

void f1()
{
// syntax : array<datatype, size(required)> name;
    array<int,5> a1 = {1,2,3,4,5};
    array<string,4> a2 = {"Bhopal","Gandhinagar", "Chennai", "Shilong"};
    array<int,5> a3 = a1;
// 4 type of access array elements

// [] - subscript operator || exception throw nhi karaya hai
for(int i=0; i<a1.size(); i++)
{
    cout<<a1[i]<<" ";
}
cout<<"\n";
// at() - methode 
// terminate called after throwing an instance of 'std::out_of_range'
try {
for(int i=0; i<=a1.size(); i++)
{
    cout<<a1.at(i)<<" ";
}
}
catch(out_of_range err)
{
    cout<<"\nError : Array Index Out of Bound..!";
}
cout<<"\n";

// implicit Operator
for(auto ele : a1)
cout<<ele<<" ";

// explicit Operator
/*
array method to get iterator object
        begin()    end()     | iterator
        rbegin()   rend()    | reverse_iterator
        cbegin()   cend()    | const_iterator
        crbegin()  crend()   | const_reverse_iterator

*/
cout<<"\n";

array<int,5>::iterator it;
it = a1.begin();
*it = 53;
*(it+2) = 99;
for(it = a1.begin(); it!=a1.end(); it++)
cout<<*it<<" ";
cout<<"\n";

array<int, 5>::reverse_iterator rit;
for(rit = a1.rbegin(); rit != a1.rend(); rit++)
cout<<*rit<<" ";
cout<<"\n";

array<int, 5>::const_iterator cit;
 cit = a1.cbegin();
//  *cit = 19; const not modifies
for(cit=a1.begin(); cit!=a1.end(); cit++)
cout<<*cit<<" ";
cout<<"\n";

cout<<a1.empty()<<"\n";
cout<<a1.front()<<endl;
cout<<a1.data()<<endl;
cout<<a1.back()<<endl;
}

int main()
{
   f1();
   cout<<endl;
   return 0; 
}