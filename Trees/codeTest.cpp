#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Op
{
public:
    Node *root = nullptr;

    void buildTree(){
        root = buildTreeHelper();
    }

    Node* buildTreeHelper(){
        int x;
        cin>>x;
        if(x == -1) return nullptr;

        else{
            Node* newNode = new Node(x);
            newNode->left = buildTreeHelper();
            newNode->right = buildTreeHelper();
            return newNode;
        }
    }

    void inorderTraversal(){
        inorderTraversalHelper(root);
    }
    void inorderTraversalHelper(Node* temp){
        if(temp == nullptr) return;

        inorderTraversalHelper(temp->left);
        cout<<temp->data<<" ";
        inorderTraversalHelper(temp->right);

    }

   
};

int main()
{
    Op t1;
    
    t1.buildTree();

    cout << endl;
    t1.inorderTraversal();
    cout << endl;
    cout<<t1.root->data<<endl;

    return 0;
}