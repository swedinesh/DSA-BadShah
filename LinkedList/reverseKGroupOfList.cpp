#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Group
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void insertAtTail(int data)
    {

        if (head == NULL)
        {
            Node *newNode = new Node(data);

            head = tail = newNode;
        }

        else
        {
            Node *newNode = new Node(data);
            tail->next = newNode;
            tail = newNode;
        }
    }

    void recusiveDisplay(Node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->val << "-->";
        
        recusiveDisplay(temp->next);

    }

    Node *reverseKGroup(Node *head, int k)
    {
        int count = 0;

        Node *temp = head;

        while (temp != NULL && count < k)
        {
            temp = temp->next;
            count++;
        }

        if (count == k)
        {
            Node *forw = NULL;
            int i = 0;

            Node *pre = NULL;
            Node *curr = head;

            while (i < k)
            {
                forw = curr->next;
                curr->next = pre;
                pre = curr;
                curr = forw;
                i++;
            }

            Node* recursionKaHead = reverseKGroup(forw, k);

            head->next = recursionKaHead;

            return pre;
        }

        else{
            // group nhi mila
            return head;
        }
    }

};

int main()
{

    Group *ll = new Group();

    int n,k;
    cout << "Enter Number Of Nodes & Group Size (k) : ";
    cin >> n>>k;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << (i + 1) << " : ";
        int temp;
        cin >> temp;
        ll->insertAtTail(temp);
    }

    ll->recusiveDisplay(ll->head);
    cout<<endl;

    Node* groupHead = ll->reverseKGroup(ll->head, k);
      
    ll->recusiveDisplay(groupHead);

    return 0;
}