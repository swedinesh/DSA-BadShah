#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void sub(vector<string>& ans, int index, string output, string str){

if(index >= str.length()) {
// 2 kaam - rukna tab hai jab subSequence ready hota hai    
ans.push_back(output); 
return;
}

//append
char ch = str[index]; 
output.push_back(ch);

//include
sub(ans, index+1, output, str);
//backTrack
output.pop_back();

//exclude
sub(ans, index+1, output, str);

}

int main(){

string str = "ab";
vector<string> ans;
int index = 0;
string output = "";
sub(ans, index, output, str);
//sort(ans.begin(), ans.end());
cout<<endl;
for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
cout<<endl;
return 0;
}