#include<iostream>
using namespace std;

int main(){
    int count = 1;
    for(int i=100240; i>1; i=i/2){
        cout<<i<<" ";
        count++;
    }
    cout<<endl<<count<<endl;
    return 0;
}