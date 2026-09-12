#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;

Node(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

};

class BTree{
public:
Node* root = nullptr;

Node* creatTree(){
  int n;
  cin>>n;
  if(n==-1) return nullptr;
  else{
    Node *root = new Node(n);
    root->left = creatTree();
    root->right = creatTree();
    return root;
  } 
}

void inorder(Node *root){
    if(root ==nullptr) return;

     inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

};

int main(){
    BTree t;
    Node * root;
    root = t.creatTree();
    t.inorder(root);
    cout<<endl;
    return 0;
}