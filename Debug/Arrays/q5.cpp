#include<iostream>
using namespace std;


int pairSumToX(int input[], int size, int x){
	int pairs = 0;
	for(int i=0; i<size-1; i++){
        if(i>0 && input[i] ==  input[i-1])
            continue;
		for(int j=i+1; j<size; j++){
			if(input[i] + input[j] == x) pairs++;
		}
	}

	return pairs;
}

int main(){

     int arr[] = {1, 1, 2, 3, 3, 4, 5};
     int n = sizeof(arr)/sizeof(arr[0]);
     int x = 6;

     cout<<"Pairs : "<<pairSumToX(arr, n, x)<<endl;

    return 0;
}