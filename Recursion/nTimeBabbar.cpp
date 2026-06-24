#include<iostream>
using namespace std;

void babbar(int n){
    if(n==0) return;
    babbar(n-1);
    cout<<"Babbar"<<endl;
}

int main(){
     babbar(5);
    return 0;
}

/*
recursive tree

   babbar(5) print
      |
       babbar(4) print
          |
           babbar(3) print
              |
                 babbar(2) print
                    |
                       babbar(1) print
                          | 
                             babbar(0) return;  
                 

*/