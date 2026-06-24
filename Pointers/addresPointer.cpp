#include<iostream>
using namespace std;

int main(){
    int arr[3];
    cout<<endl;
    for(int i=0; i<3; i++){
        cout<<"arr["<<i<<"] : "<<&arr[i]<<endl;
    }
    cout<<endl;

    cout<<endl;
    for(int i=0; i<3; i++){
        cout<<"arr["<<i<<"] : "<<arr+i<<endl;
    }
        cout<<endl;

        cout<<"&arr+1 : "<<&arr+1<<endl;
    return 0;
}

/*
arr[0] : 0x7ffd30909fbc
arr[1] : 0x7ffd30909fc0
arr[2] : 0x7ffd30909fc4


arr[0] : 0x7ffd30909fbc
arr[1] : 0x7ffd30909fc0
arr[2] : 0x7ffd30909fc4

&arr+1 : 0x7ffd30909fc8
*/