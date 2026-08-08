#include<iostream>
using namespace std;

int main(){
    char str[] = "ABCD";
    
    for(int i=0; str[i]!='\0'; i++){
        cout<<str[i]<<" "<<*(str)+i<<" "<<*(str+i)<<" "<<i[str]<<endl;
    }
    return 0;
}