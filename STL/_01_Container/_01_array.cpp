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
for(it = a1.begin(); it!=a1.end(); it++)
cout<<*it<<" ";




}

int main()
{
   f1();
   cout<<endl;
   return 0; 
}