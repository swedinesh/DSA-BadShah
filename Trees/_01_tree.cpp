#include <bits/stdc++.h>
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

Node *buildTree()
{
    int data;
    cout << "DATA : ";
    cin >> data;

    if (data == -1)
        return nullptr;
    else
    {
        Node *root = new Node(data);
        root->left = buildTree();
        root->right = buildTree();
        return root;
    }
}

void leveOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    // every level end insert null
    q.push(nullptr);
    cout << "\n";

    cout << "===== Level Order TraverSal =====" << endl;

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << "\n";
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
    }

    cout << "\n";

    // while( !q.empty() )
    // {
    //     Node* temp = q.front();
    //     cout<<temp->data<<" ";

    //     q.pop();

    //     if(temp->left != nullptr)
    //     {
    //         q.push(temp->left);
    //     }
    //     if(temp->right != nullptr)
    //     {
    //         q.push(temp->right);
    //     }
    // }
    // cout<<"\n";
}

int height(Node* root)
{
    if(root == nullptr) return 0;

    return 1 + max( height(root->left), height(root->right));
}

void pre(Node *root)
{
    if (root == nullptr)
        return;

    // nlr
    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}

int main()
{
    Node *root;
    root = buildTree();

    cout << "\n";

    pre(root);

    cout << "\n";

    leveOrderTraversal(root);

    cout<<" height : "<<height(root)<<"\n";

    return 0;
}