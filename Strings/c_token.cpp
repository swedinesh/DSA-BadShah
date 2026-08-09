#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    string str("Split this sentence in c Tokens");
    char *cstr = new char[str.length()+1];
    strcpy(cstr, str.c_str());
    
    char *p = strtok(cstr," ");

    while(p!=0){
        cout<<p<<'\n';
        p = strtok(NULL," ");
    }

    delete []cstr;

    return 0;
}