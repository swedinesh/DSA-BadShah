#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(int data, Node* &head, Node* &tail){
    Node* newNode = new Node(data);
    //empty
    //non-empty

    if(head==NULL && tail==NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    
}

void inserAtTail(int data, Node* &head, Node* &tail){
    Node* newNode = new Node(data);
    //empty
    //non-empty

    if(head==NULL && tail==NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void display(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
 cout<<endl;
}

int main(){
Node* head = NULL;
Node* tail = NULL;

insertAtHead(10,head,tail);
insertAtHead(20,head,tail);
insertAtHead(30,head,tail);
inserAtTail(40, head, tail);

display(head);

    return 0;
}

