#include<iostream>
#include <climits>
#include <utility>
using namespace std;

template<class u>
u add(u x, u y){
 return (x>y) ? x : y;
}

template<class u>
u said(u x, u y){
 return (x<y) ? x : y;
}

template<class V>
void sort(V *p, int s){
    
    // selection sort

   for(int i=0; i<s; i++){
       int min = i;
       for(int j = i; j<s; j++){
        if(p[min] > p[j]){
            min = j;
        }
       }
       if(min != i)
       swap(p[i], p[min]);
   } 

}

template<class V>
void print(V *p, int s, int i){
     if(i == s) return;
     cout<<p[i]<<" ";
     print(p,s,i+1);
 return;
}



int main(){
    // cout<<"Greater : "<<add(7, 6)<<endl; // 1.
    // cout<<"Less : "<<said(9,3)<<endl; // 2.

    int arr[] = { 4, 1, 3, 5, 2};
    char ch[]  = "Dinesh";

    sort(arr, 5);
    sort(ch,6);

    print(arr, 5, 0);
    cout<<endl;
    print(ch, 6, 0);

    // sort(V, 5);

    // for(int ele : V){
    //     cout<<ele<<" ";
    // }
  cout<<endl;

    return 0;
}