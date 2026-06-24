#include<iostream>
using namespace std;

int fastExponential(int a, int b){
    if(b==0) return 1;
    int ans =1;

    while(b>0){
        if(b & 1){
            //odd
            ans*=a;
        }
        //even
        a *= a;
        b>>=1;
    }
    return ans;
}

int slowExponent(int a, int b){
    //a ki power b
    if(b==0) return 1;
    int ans = 1;
    for(int i=1; i<=b; i++){
        ans *= a;
    }
    return ans;
}

int main(){
    int a, b;
   cin>>a>>b;
//    cout<<"Fast_Exponet "<<a<<" of "<<b<<" : "<<fastExponential(a,b)<<endl;
//    cout<<"Slow_Exponet "<<a<<" of "<<b<<" : "<<slowExponent(a,b)<<endl;

   cout<<"Fast_Exponet "<<a<<" of "<<b<<" : "<<fastExponential(a,b)<<endl;
   cout<<"Slow_Exponet "<<a<<" of "<<b<<" : "<<slowExponent(a,b)<<endl;

    return 0;

}