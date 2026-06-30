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

class Op{
public:

Node* head=NULL;
Node* tail=NULL;

void insertAtHead(int data){
    // Head Null hai means abhi list empty hai hame new node 
    //insert karne ke liye node create karna padega

     if(head==NULL){
        Node* newNode = new Node(data);
        // head and tail ko node par point kara diya
        head = tail = newNode;
     }
     // if Other node insert karne hai pehle node create karenge
     else{
        Node* newNode = new Node(data);
        //link karna hai hamne head head ko new node se link kar diya
        newNode->next = head;
        //head ko new node par point kra dia
        head = newNode;
     }
}

void insertAtTail(int data){
  
     if(head==NULL){
        Node* newNode = new Node(data);
   
        head = tail = newNode;
     }
 
     else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
     }
}

// hame display karana hai

void display(){
    Node* temp = head;

    while( temp != NULL){
        cout<<temp->data;
        if(temp != tail) cout<<" --> ";
        temp = temp->next;
    }
cout<<endl;
}

void recusiveDisplay(Node* temp){
  if(temp == NULL) return;
  recusiveDisplay(temp->next);
  cout<<temp->data;
  if(temp != head) cout<<" --> ";
 }

 int length(){
    Node* temp = head;
    int length = 0;

    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
 }
 
 void convertIntoCircular(){
    if(head==NULL);
    else
    tail->next = head;
 }

 void displayCircular(){
    Node* temp = head;

    // while(temp != tail){
    //     cout<<temp->data<<"-->";
    //     temp = temp->next;
    // }
    // cout<<tail->data<<"-->"<<tail->next->data;

    while(1){
        if(temp->next == head){
            break;
        }
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<endl;
 }

 void inserAtKthPosition(int data, int pos){

    if(pos < 1 || pos > length() + 1)
        return;

    Node* newNode = new Node(data);

    if(pos == 1){
        newNode->next = head;
        head = newNode;

        if(tail == NULL)
            tail = newNode;

        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1; i++){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if(newNode->next == NULL)
        tail = newNode;

 return;
}

void deleteAtKthElement(int pos){
    if(pos<1 || pos > length()){
       return;
    }
    if(head==NULL && tail==NULL) return;

    if(pos==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;

         if(head == NULL)
        tail = NULL;

        cout<<"Deleting " <<temp->data<<" at "<<pos<<"th position"<<endl;
        delete temp;
        return;
    }

    Node* pre = head;
    
    for(int i=1; i<pos-1; i++){
        pre =  pre->next;
    } 
    
    Node* current = pre->next;
    Node* forward = current->next;

    current->next = NULL;
    pre->next = forward;

    cout<<"Deleting " <<current->data<<" at "<<pos<<"th position"<<endl;
    delete current;

    if(forward==NULL){
        tail = pre;
    }
  
    return;
}


};

int main(){
Op *ll = new Op();

int n;
cout<<"Enter Number Of Nodes : ";
cin>>n;
cout<<endl;

for(int i=0; i<n; i++){
    cout<<"Element "<<(i+1)<<" : ";
    int temp;
    cin>>temp;
   // ll->insertAtHead(temp);
   ll->insertAtTail(temp);
}

ll->display();
cout<<endl;
ll->recusiveDisplay(ll->head);
cout<<endl;
cout<<"length : "<<ll->length();
cout<<endl;
// ll->convertIntoCircular();
// ll->displayCircular();
cout<<endl;

// ll->inserAtKthPosition(69,6);
// ll->display();
// cout<<endl;
ll->deleteAtKthElement(1);
ll->display();
ll->deleteAtKthElement(1);
ll->display();
ll->deleteAtKthElement(1);
ll->display();
cout<<endl;

    return 0;
}




//  void inserAtKthPosition(int data, int pos){
//   if(pos < 1 || pos > length() + 1)
//     return;
//     Node* temp = head;
//     Node* newNode = new Node(data);

//     if(pos==1){
//      newNode->next = temp;  
//      head = newNode;
//      return; 
//     }
//     else{
//        int i=1;
//        while(1){
//         if(i == pos-1){
//           newNode->next = temp->next;
//           temp->next = newNode;
//           if(newNode->next==NULL){
//             tail = newNode;
//           }
//           return;
//         }
//         else{
//             i++;
//             temp = temp->next;
//         }
        
//        }
//     }
//     return;
//  }