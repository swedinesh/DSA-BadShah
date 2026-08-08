#include<iostream>
#include<vector>
using namespace std;

vector<bool> Sieve(int n){
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;

    // hame i ko uske root tak hi le jaana hai
    for(int i=2; i*i<=n; i++){
        if(sieve[i]){
            // uska next multiple ko store karo
            // int j = 2*i;

            // first unmarked number i*i, as other have been marked
            //by 2 to (i-1)
            int j = i*i; // : optimization 1
            
            // uske saare multiple khojo
            while(j<=n){
                // uske multiple ko false karo(not prime karo)
                if(sieve[j])
                sieve[j] = false;
                // j ko next multiple ke liye update karo
                j+=i;  
            }

        }
    }
    // sieve return karo (array)
    return sieve;
}

int main(){
    vector<bool> sieve = Sieve(25);
    for(int i=0; i<=25; i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}