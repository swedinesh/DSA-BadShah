#include<iostream>
using namespace std;

// important
void sort0sand1s(int input[], int size){
	int nextZero = 0;
	for(int i=0; i<size; i++){
		if(input[i] == 0){
			int temp = input[i];
			input[i] = input[nextZero];
			input[nextZero++] = temp;
		}
	}
}

int main(){
    int arr[] = {1, 0, 0, 1, 0, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort0sand1s(arr, n);

    cout<<endl;
    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}