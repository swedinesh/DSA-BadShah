#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void insetAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (tail == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node *ListNode(Node *l1, Node *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        Node *temp1 = l1;
        Node *temp2 = l2;
        Node *mHead = NULL;

        bool flag = true;

        if (temp1->data == temp2->data)
        {
            if (flag)
            {
                mHead = temp1;
                flag = false;
            }
            Node *tl1 = temp1;
            Node *tl2 = temp2;
            Node *store1 = NULL;
            while ((temp1->data <= temp2->data) && temp1 != NULL)
            {
                if (temp1->next == NULL)
                {
                    store1 = temp1;
                }
                temp1 = temp1->next;
            }

        }
    }
};

int main()
{
    int n;
    cout << "Enter Nodes : ";
    cin >> n;

    Solution s1, s2;

    for (int i = 1; i <= n; i++)
    {
        int d;
        cout << "Element " << i << " : ";
        cin >> d;
        s1.insetAtTail(d);
    }

    for (int i = 1; i <= n; i++)
    {
        int d;
        cout << "Element " << i << " : ";
        cin >> d;
        s2.insetAtTail(d);
    }

    cout << endl;
    s1.print();

    cout << endl;
    s2.print();

    return 0;
}