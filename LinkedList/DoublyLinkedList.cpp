#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *pre;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->pre = NULL;
        this->next = NULL;
    }
};

class Operation
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    // insert at head
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL && tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
    }

    // insert at tail
    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL && tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }

    void displayForward()
    {
        if(isEmpty()){
            cout<<"Display is Failed!.."<<endl;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
                cout << "-->";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward()
    {

        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->pre != NULL)
                cout << "<--";
            temp = temp->pre;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        if (head == NULL && tail == NULL)
            return true;

        return false;
    }

    int length()
    {

        int l = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }

    void push_front(int data)
    {

        insertAtHead(data);
        return;
    }

    void push_end(int data)
    {

        insertAtTail(data);
        return;
    }

    void insertKthPosForward(int data, int pos)
    {
        if (pos < 1 || pos > length() + 1)
        {
            cout << "Invalid Input...Failed!" << endl;
            return;
        }
        if (pos == 1)
        {
            cout << "New Element " << data << " Insert at Head" << endl;
            push_front(data);
            return;
        }
        if (pos == length() + 1)
        {
            cout << "New Element " << data << " Insert at Tail" << endl;
            push_end(data);
            return;
        }
        else
        {
            Node *newNode = new Node(data);
            Node *newPre = head;

            int i;
            for (i = 1; i < pos - 1; i++)
            {
                newPre = newPre->next;
            }

            cout << "New Element Inserting in " << (i + 1) << " index and data -> is " << newNode->data << " Succesfully!..." << endl;

            newNode->next = newPre->next;
            newNode->next->pre = newNode;
            newNode->pre = newPre;
            newPre->next = newNode;

            return;
        }
    }

    void pop_front()
    {

        if (isEmpty())
        {
            cout << "List is Empty" << endl;
            return;
        }

        // 10-20-30

        cout << "Head is Revomed from the list " << head->data << endl;

        Node *temp = head;
        head = head->next;

        if (head != NULL)
            head->pre = NULL;
        else
            tail = NULL;

        delete temp;

        // 20-30
    }

    void pop_end()
    {

        if (isEmpty())
        {
            cout << "List is Empty" << endl;
            return;
        }

        if (head == tail)
        {
            cout << "Tail is Revomed from the list " << tail->data << endl;
            delete head;
            head = tail = NULL;
            return;
        }

        // 10-20-30

        cout << "Tail is Revomed from the list " << tail->data << endl;

        Node *end = tail;
        tail = end->pre;
        ;
        tail->next = NULL;
        delete end;
    }

    void deleteKthPos(int pos)
    {
        if (pos < 1 || pos > length())
        {
            cout << "Invalid Position" << endl;
            return;
        }

        if (isEmpty())
        {
            cout << "List is Empty!.." << endl;
            return;
        }

        if (pos == 1)
        {
            pop_front();
            return;
        }

        else if (pos == length())
        {
            pop_end();
            return;
        }

        else
        {
            int i;
            Node *temp = head;
            for (i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            i++;

            Node *current = temp->next;
            Node *forward = current->next;

            cout << current->data << " is Revomed at index " << i << " from the list " << endl;

            forward->pre = temp;
            temp->next = forward;

            delete current;
        }
    }

    ~Operation()
    {
        while (head)
            pop_front();
    }
};

int main()
{
    Operation *m = new Operation();
    int n;
    cout << "Enter Number of Nodes : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << (i + 1) << " : ";
        int x;
        cin >> x;
        m->insertAtTail(x);
        // m->insertAtHead(x);
    }

    m->displayForward();
    // m->displayBackward();

    m->insertKthPosForward(19, 1);
    m->displayForward();
    m->insertKthPosForward(39, 7);
    m->displayForward();
    m->insertKthPosForward(108, 4);
    m->displayForward();

    m->pop_front();
    m->displayForward();
    m->pop_end();
    m->displayForward();
    m->deleteKthPos(3);
    m->displayForward();

    m->pop_end();
    m->displayForward();

    m->pop_end();
    m->displayForward();

    m->pop_end();
    m->displayForward();

    m->pop_end();
    m->displayForward();

    m->pop_end();
    m->displayForward();

    m->pop_end();
    m->displayForward();

    return 0;
}

/*
if (head == tail)
{
delete head;
head = tail = NULL;
return;
}

Node* temp = head;

while (temp->next != tail)
{
temp = temp->next;
}

Node* end = tail;

tail = temp;
tail->next = NULL;

delete end;
*/