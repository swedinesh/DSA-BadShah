#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *buildTree(int data, Node *root)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }
    else
    {
        if (data <= root->data)
        {
            root->left = buildTree(data, root->left);
        }
        else
        {
            root->right = buildTree(data, root->right);
        }
    }
    return root;
}

Node* crBST(Node* root)
{
    int val;
    cout<<"Initial Data : ";
    cin>>val;

    while(val!=0)
    {
      root = buildTree(val, root);
      cout<<"Data : ";
      cin>>val;
    }

    return root; 
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cout << "Data : ";
        cin >> d;
        root = buildTree(d, root);
    }

    cout << endl;
    inorder(root);
    cout << endl;

    return 0;
}