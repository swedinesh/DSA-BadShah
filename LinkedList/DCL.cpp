#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *pre;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->pre = NULL;
    }
};

class LL{
    public:

    Node *head=NULL;
    Node *tail=NULL;

    void insertAtTail(int data){
        Node *newNode = new Node(data);

        if(head == NULL) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->pre = tail;
            tail =  newNode;
        }
        // circular
        head->pre = tail;
        tail->next = head;
    }

    void print(){
        if (head == NULL) return; // Guard clause for empty list

        Node *temp = head;
        // Use a do-while loop to print the full cycle completely
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl; 
    
    }

    void printBackward()
    {
        if (tail == NULL) return; // Guard clause for empty list
        Node* temp = tail;
        cout<<"(tail)"<<"->";
         do {
            cout << temp->data << "->";
            temp = temp->pre;
        } while (temp != tail);
        cout << endl;
    }

    ~LL(){
        if(head==NULL) return;

        // safety ke liye circular break kar diya because sara program 
        // exicute ho gya hai to koi kaam nhi
        tail->next = NULL;

       Node* temp = head;
       while(temp->next != NULL){
        Node *new_temp = temp->next;
        delete temp;
        temp = new_temp;
       }
    }

};

int main()
{
    int n;
    cout<<"Enter Number of nodes : ";
    cin>>n;

    cout<<endl;

    LL list;

    for(int i=0; i<n; i++){
      int d;
      cout<<"Element "<<(i+1)<<" : ";
      cin>>d;
      list.insertAtTail(d);
    }
    cout<<endl;

    list.print();
    list.printBackward();

    return 0;
}