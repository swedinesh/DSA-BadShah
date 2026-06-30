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

class LLMethods{
public:
Node* head = NULL;
Node* tail = NULL;

void insertAtHead(int data){
    if(isEmpty()){
        Node* newNode = new Node(data);
        head = tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(int data){
      if(isEmpty()){
        Node* newNode = new Node(data);
        head = tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        (*tail).next = newNode;
        tail = newNode;
    }
}

// length
int length(){
    Node* temp = head;
    int l=0;
    while(temp != NULL){
      l++;
      temp = temp->next;
    }
    return l;
}

//insert at position
void insertAtKthPos(int data, int pos){
    // length+1 for insert at tail
   if(pos<1 && pos>length()+1) return;

   Node *start = head;
   Node *newNode = new Node(data);

   if(pos == 1){
     newNode->next = head;
     head = newNode;
    cout<<"Congratulation - Insert "<<data<<" at Position "<<pos<<" --> Succesfull..."<<endl;
     return;
   }

   for(int i=1; i<pos-1; i++){
    start = start->next;
   }
   //because add hone ke baad length increase ho jayegi
   if(pos == length()+1)
   tail = newNode;

   newNode->next = start->next;
   start->next = newNode;
   cout<<"Congratulation - Insert "<<data<<" at Position "<<pos<<" --> Succesfull..."<<endl;

   
   
   cout<<"Now : Head -> "<<head->data<<" & Tail -> "<<tail->data<<endl;
   return;
}

void deleteAtHead(){
if(isEmpty()) 
{
cout<<"List is Empty!.."<<endl;    
    return;
}

cout<<head->data<<" (Head) is Deleting ..."<<endl;
Node * temp = head;
head = head->next;
temp = NULL;
delete temp;

return;
}

void deleteAtTail(){
if(isEmpty()) 
{
cout<<"List is Empty!.."<<endl;    
    return;
}

Node* pre = head;

for(int i=1; i<length()-1; i++){
    pre = pre->next;
}

cout<<tail->data<<" (Tail) is Deleting ..."<<endl;
Node* forward = tail;
tail = pre;
tail->next = NULL;

forward=NULL;
delete forward;

return;
}

//delete Kth
void deleteKthPos(int pos){
if(pos<1 && pos > length()){
    cout<<"Invalid Input!.."<<endl;
return;
}
 if(isEmpty()) 
{
cout<<"List is Empty!.."<<endl;    
    return;
}

    if(pos==1){
        deleteAtHead();
        return;
    }
    else if(pos==length()){
        deleteAtTail();
        return;
    }
    else{
        Node* pre = head;
        for(int i=1; i<pos-1; i++){
            pre = pre->next;
        }
       
        Node* current = pre->next;
        Node* forward = current->next;
        pre->next = forward;
         
        cout<<current->data<<" is Deleting ..."<<endl;

        current = NULL;
        delete current;
    
        return;
    }

    return;
}

int search(int target){
   if(isEmpty()){
    cout<<"List is Empty!.."<<endl;
   }
   
   Node *temp = head;
   for(int i=1; i<=length(); i++){
    if(temp->data==target)
    return i;
    temp = temp->next;
   }

   return -1;
}

int search(int len, Node* temp, int target, int idx){
     if(isEmpty()){
    cout<<"List is Empty!.."<<endl;
   }

    if(len==0) return -1;
    
    if(temp->data == target)
    return idx;

    return search(len-1, temp->next, target, idx+1);
   
}

bool isEmpty(){
    if(head==NULL && tail==NULL) return true;
    return false;
}

// void mini(){
//     Node *temp = head;
//     int min = temp->data;

//     for(int i=0; i<length(); i++){
        
//     }
// }

void display(){

    Node* temp = head;
    cout<<"=== Your List IS ==="<<endl;
    while(temp != NULL){
        cout<<temp->data;
        if(temp->next != NULL) cout<<"-->";
        temp = temp->next;
    }
    cout<<endl;
}

void display(int n){
    Node *temp = head;
    cout<<"=== Your List IS ==="<<endl;
    for(int i=1; i<=n; i++){
       cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<endl;
}

};

int main(){
    LLMethods *m = new LLMethods();
    // int n;
    // cout<<"Enter Number of Nodes : ";
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     cout<<"Element "<<(i+1)<<" : ";
    //     int x;
    //     cin>>x;
    //     //m->insertAtHead(x);
    //     m->insertAtTail(x);
    // }

    m->insertAtKthPos(10,1);
    cout<<endl;
    m->display();
    cout<<"Length : "<<m->length()<<endl;
    
    cout<<"Iterative Search Index : "<<m->search(9)<<endl;
    
    cout<<"Recursive Search Index : "<<m->search(m->length(), m->head, 1, 1)<<endl;

    if(m->isEmpty())
    cout<<"List is Empty!.."<<endl;
    else
    cout<<"List is NOT Empty!.."<<endl;



    // m->deleteAtHead();
    // m->display();
    // m->deleteAtTail();
    // m->display();
   
    // m->deleteKthPos(1);
    // m->display();
    // cout<<"Length : "<<m->length()<<endl;

    // m->deleteKthPos(2);
    // m->display();
    // cout<<"Length : "<<m->length()<<endl;

    // m->deleteKthPos(3);
    // m->display();
    // cout<<"Length : "<<m->length()<<endl;




    // m->insertAtKthPos(77,6);
    // m->display();
    // cout<<"Length : "<<m->length()<<endl;
    // m->display(m->length()-1);
    return 0;
}