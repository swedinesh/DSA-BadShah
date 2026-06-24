#include<iostream>
using namespace std;

int tripletSumToX(int input[], int size, int x){
	int triplets = 0;
     
	for(int i=0; i<size-2; i++){
        if(i>0 && input[i] == input[i-1])
        continue;
		for(int j=i+1; j<size-1; j++){
            if(j>i+1 && input[j] == input[j-1])
            continue;
			for(int k=j+1; k<size; k++){
                 if(k>j+1 && input[k] == input[k-1])
               continue;
				if(input[i] + input[j] + input[k] == x){ triplets++;
                cout<<endl<<input[i]<<", "<<input[j]<<", "<<input[k]<<endl;
                }
			}
		}
	}
	return triplets;
}

int main(){
    int arr[] = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 6;
    
    cout<<"triplets : "<<tripletSumToX(arr, n, x)<<endl;

    return 0;
}