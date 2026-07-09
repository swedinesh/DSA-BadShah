#include <iostream>
#include <stack>
#include <climits>

using namespace std;

void insertAtBottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }

    int x = s.top();
    s.pop();
    insertAtBottom(s, val);
    s.push(x);
}

void print(stack<int> s)
{

    for (; !s.empty();)
    {
        cout << "[    " << s.top() << "   ]" << endl;
        s.pop();
    }
    cout << endl;
}

void reverse(stack<int> &s)
{

    if (s.empty())
    {
        return;
    }

    int val = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, val);
}

int getLength(stack<int> s)
{
    int len = 0;

    while (!s.empty())
    {
        len++;
        s.pop();
    }
    return len;
}



int maximum(stack<int> &s, int maxi)

{
    if (s.empty()) return maxi;

    int temp = s.top();
    s.pop();

    maxi =  maximum(s, max(maxi, temp));
     //maximum push nhi karna hai 
    if(temp != maxi){
        s.push(temp);
    }

    return maxi;

}

void printMid(stack<int>& s, int mid, int i){

    if(i == mid){
     cout<<"Mid : "<<s.top()<<endl;
     return;
    }

    int temp = s.top();
    s.pop();

    printMid(s, mid, i+1);
    
    s.push(temp);
 
    return;

}

bool checkSorted(stack<int>& s, int min){
    if(s.empty()) return true;

    int temp = s.top();
    s.pop();
    
    if( min > temp){
        s.push(temp);
        return false;
    }
    
    min = temp;

   bool check = checkSorted(s, min);

   s.push(temp);

   return check;

}

void insertInSortedStack(stack<int>& s, int val){

    if(s.empty()){
      s.push(val);
      return;
    }

    int temp = s.top();
    s.pop();

    if(temp >= val){
        s.push(temp);
        s.push(val);
        return;
    }

    insertInSortedStack(s, val);

    s.push(temp);
    
}


void sort(stack<int> &s){
  if(s.empty()) return;
    
  int temp = s.top();
  s.pop();

  sort(s);
  insertInSortedStack(s,temp);
}


int main()
{

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    // int n = s.size();
    // cout << "Size : " << n << endl;
    // int mid = n/2;

    print(s);

    // insertAtBottom(s, 69);
    // cout<<"Size : "<<s.size()<<endl;
    // print(s);
    // printMid(s, mid, 0);

    // reverse(s);
    // print(s);

    // int max = INT_MIN;

    // cout<<"Maximum : "<<maximum(s,max)<<endl;

    // int min = INT_MIN;
    // cout<<checkSorted(s, min)<<endl;

    // insertInSortedStack(s,2);
    // insertInSortedStack(s,4);
    // insertInSortedStack(s,6);
    // insertInSortedStack(s,8);

    sort(s);

    print(s);

    return 0;
}
