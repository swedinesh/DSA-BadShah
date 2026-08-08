#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    int sqrtN = sqrt(n);
    for(int i=2; i<=sqrtN; i++)
        if(n%i==0) return false;
    
    return true;
}

void countPrime(int n){
    int c = 0;

    for(int i=0; i<=n; i++){
        if(isPrime(i)) c++;
    }

    cout<<"Sqrt Approach Number Of Primes 0-n : "<<c<<endl;
    
}

int main(){
     countPrime(100);

    return 0;
}