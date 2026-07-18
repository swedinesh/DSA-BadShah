#include <iostream>
#include <queue>
#include<climits>
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
        left = NULL;
        right = NULL;
    }
};

class Trees
{
public:
    Node *createTree()
    {
        int val;
        cin >> val;

        if (val == -1)
        {
            return NULL;
        }
        else
        {
            Node *root = new Node(val);
            root->left = createTree();
            root->right = createTree();
            return root;
        }
    }

    void preOrderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";

        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }

    void levelOrderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            cout << front->data << " ";

            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
        }

        cout << endl;
    }

    void TruelevelOrderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            if (front == NULL)
            {
                cout << endl;

                 if(!q.empty())
                q.push(NULL);

            }

            else
            {
                cout << front->data << " ";

                if (front->left != NULL)
                    q.push(front->left);

                if (front->right != NULL)
                    q.push(front->right);
            }
        }

        cout << endl;
    }

    int maxDepth_height(Node* root){
        if(root==NULL) return 0;
        
        // left subtree + root
        int leftheight = maxDepth_height(root->left)+1;
       // cout<<"L : "<< leftheight<<endl;

        // right subtree + root 
        int rightheight = maxDepth_height(root->right)+1;
          //cout<<"R : "<< rightheight<<endl;

        // Dono mai jo max hai bhi height
        int maxi = max(leftheight, rightheight);
        //cout<<"Max : "<<maxi<<endl;
        return maxi;
    }

     int maxDepth(Node* root) {
        if(root==NULL) return 0;

        // root + left sabTree
        int l = maxDepth(root->left)+1;

        // root +  right subTree
        int r = maxDepth(root->right)+1;
        
        int maxi = max(l,r);

        return maxi;
    }

    int diameterOfBinaryTree(Node* root){
       
    if(root==NULL) return 0;

     int option1 = maxDepth(root->left) + maxDepth(root->right);
     int option2 = diameterOfBinaryTree(root->left);
     int option3 = diameterOfBinaryTree(root->right);

     int ans = max(option1, max(option2, option3));

     return ans;
    }

    int maxDepth1(Node* root){
        if(root==NULL) return 0;

        int leftHeight = maxDepth1(root->left);
        //cout<<"leftHeight : "<<leftHeight<<endl;

        int rightHeight = maxDepth1(root->right);
        //cout<<"rightHeight : "<<rightHeight<<endl;

        int ans = max(leftHeight, rightHeight)+1;
         //cout<<"Ans : "<<ans<<endl;

       return ans;
    }
};


//Find Optimal Way
class Solution {
public:
   
    int maxDepth(Node* root) {
        if(root==NULL) return 0;

        // root + left sabTree
        int l = maxDepth(root->left)+1;

        // root +  right subTree
        int r = maxDepth(root->right)+1;

        return max(l, r);
    }

    int diameterOfBinaryTree(Node* root) {
        
    if(root==NULL) return 0;

     int option1 = maxDepth(root->left) + maxDepth(root->right);
     int option2 = diameterOfBinaryTree(root->left);
     int option3 = diameterOfBinaryTree(root->right);

     int ans = max(option1, max(option2, option3));

     return ans;
    }
};


int main()
{

    Trees t;
    Node *root = NULL;

    root = t.createTree();

    cout<<endl;

    cout<<"m1 : "<< t.maxDepth1(root);

    cout<<endl;

    cout<<t.maxDepth(root);
    cout<<endl;

    // cout<<endl<<" === Pre Order Traversal === "<<endl;
    // t.preOrderTraversal(root);

    // cout<<endl<<" === In Order Traversal === "<<endl;
    // t.inOrderTraversal(root);

    // cout<<endl<<" === Post Order Traversal === "<<endl;
    // t.postOrderTraversal(root);
    
    // cout<<endl<<" === Level Order Traversal === "<<endl;
    // t.TruelevelOrderTraversal(root);

    // cout<<"Height : "<<t.maxDepth_height(root)<<endl;

    // cout<<"max diameter : "<<t.diameterOfBinaryTree(root)<<endl;
    
    return 0;
}

// 10 20 -1 -1 30 -1 40 10 -1 -1 -1