#include<iostream>
#include<vector>
using namespace std;

int coin(vector<int>& arr, int index, int amount){
    if(amount==0)
    return 1;
    
    if(amount < 0 || index >= arr.size()){
        return 0;
    }
    //include
    
    int inc = coin(arr, index, amount - arr[index]) ;
    
    // exclude
    int exc = coin(arr, index+1, amount);

    return inc + exc;
}

int main(){
     vector<int> arr = {1, 2, 5};
     int amount = 5;
    int ans = coin(arr,0, amount);
    cout<<endl<<"Coin change option : "<<ans<<endl;
    return 0;
}
/*
#include<iostream>
using namespace std;
int main(){
hello ji kaise ho aasa karta hu badiya hi hoge behan ke lode madharchod
betichod machchar ki jhanth paise karde kaise ho bsdk btao ydd hai tumko
! @ # $ % ^ & * () _ +- "" | {} 
hello mai aapka sebak betichodo kaise ho behan ke lodo kuchh to btao be
#include<>
*/