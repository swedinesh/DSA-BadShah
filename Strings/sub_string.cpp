#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string data = "John 25 72.5";
    std::stringstream ss(data);

    std::string name;
    int age;
    double weight;

    // Stream automatically parses and converts data types by space
    ss >> name >> age >> weight;

    std::cout << name << " is " << age << " years old.\n";
}


// #include<bits/stdc++.h>
// using namespace std;


// int main(){

//     string s = "mississippi'";
//     string g = "issip";

//     size_t idx = s.find(g);

//     if(idx!=string::npos){
//         cout<<idx<<endl;
//     }
//    else{
//      cout<<-1<<endl;
//    }
//     return 0;
// }