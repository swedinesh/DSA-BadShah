#include<iostream>
#include<string>
using namespace std;

int main(){
  string s = "42";
  for(size_t i=0; i<s.length(); i++){
    char c = s[i]- '0';
    int a = c;
    cout<<a<<" ";
  }
  cout<<endl;
    return 0;
}