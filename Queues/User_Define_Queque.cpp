#include<iostream>
using namespace std;


//Normal Queues Like - Row

class MyQueue{

private:

int *arr;
int front;
int rear;
int size;

public:

MyQueue(int capacity){

    this->size = capacity;
    arr = new int[size];

    front = -1;
    rear = -1;
}

bool isEmpty(){
    // if(rear == -1 && front == -1)
    // return true;
    // else 
    // return false;
    return front == -1;
}

void push(int data){
    if(rear == size-1){
        cout<<"Queue is Overflow"<<endl;
        return;
    }

   if(isEmpty()){
    // hmne dono 0 index par point kra diya
    front = rear = 0;
     //arr[rear] = data;
   }

   else{
    rear++;
    //arr[rear] = data;
   }

   // jab every case mai data push hona hai to to ham baar - baar kiu 
   // kare ek hi baar mai kar diya
    arr[rear] = data;

}

void pop(){

    if(isEmpty()){

        cout<<"Queue is Underflow"<<endl;
        return;
    }

    if( front == rear ){

        arr[front] = 0;
        front = rear = -1;
    }

    else{
     arr[front] = 0;
     front++;
    }

}

void display(){
    if(isEmpty()) {
        cout<<"Queue is Empty!.."<<endl;
        return;
    }
    
    cout<<endl<<"front --> ";
    for(int i=front; i<=rear; i++){
        cout<<arr[i]<<" ";
    }
    cout<<" <-- rear"<<endl<<endl;
}

// size
int len(){
    if(isEmpty()) return 0;
    return (rear - front + 1);
}

int front_data(){
    if(isEmpty())
    {
        cout<<" There is No Element"<<endl;
        return -1;
    }
    return arr[front];
}

int back_data(){
     if(isEmpty())
    {
        cout<<" There is No Element"<<endl;
        return -1;
    }
    return arr[rear];
}

~MyQueue(){
    delete []arr;
    arr = nullptr;
}


};

// Doubly Ended Queue

class MyDeque{
private:
int *arr;
int size;
int front;
int rear;

public:
MyDeque(int capacity){
    arr = new int[capacity];
    this->size = capacity;
    front = -1;
    rear = -1;
}

bool isEmpty(){
    return front == -1;
}

void push_back(int data){
  if(rear == size - 1){
     cout<<"DeQue is Overflow --> PUSH_BACK"<<endl;
     return;
  }    

  if(isEmpty()){
    front++;
    rear++;
  }
  else{
    rear++;
  }

  arr[rear] = data;
}

void pop_back(){

    if(isEmpty()){

        cout<<"Queue is Underflow --> POP_BACK"<<endl;
        return;
    }

    if( front == rear ){

        arr[front] = 0;
        front = rear = -1;
    }

    else{
     arr[rear] = 0;
     rear--;
    }

}

void push_front(int data){
  if(front == 0){
     cout<<"DeQue is Overflow --> PUSH_FRONT"<<endl;
     return;
  }    

  if(isEmpty()){
    front++;
    rear++;
  }
  else{
    front--;
  }
  arr[front] = data;
}

void pop_front(){

    if(isEmpty()){

        cout<<"Queue is Underflow --> POP_FRONT"<<endl;
        return;
    }

   else if( front == rear ){

        arr[front] = 0;
        front = rear = -1;
    }

    else{
     arr[front] = 0;
     front++;
    }

}

int getSize(){
    if(isEmpty()) return 0;
    else return rear - front - 1;
}

int getfront(){
    if(isEmpty()) return -1;
    return arr[front];
}

int getback(){
    if(isEmpty()) return -1;
    return arr[rear];
}

void display(){
    if(isEmpty()) {
        cout<<"Queue is Empty!.."<<endl;
        return;
    }
    
    cout<<endl<<"front --> ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<" <-- rear"<<endl<<endl;
}

~MyDeque(){
    delete []arr;
    arr = nullptr;
}

};

int main(){

    MyQueue q(5);

    MyDeque dq(5);

    dq.push_front(50);
    dq.push_back(100);
    dq.push_back(90);
    dq.push_back(200);
    dq.push_back(350);
    dq.push_back(450);

    dq.pop_front();
    dq.pop_front();
    dq.pop_back();
  
    dq.display();

     //q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);

   // q.push(70);
    
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
   // q.pop();

//    cout<<q.len()<<endl;

//    cout<<q.front_data()<<endl;
//    cout<<q.back_data()<<endl;

//     q.display();

    return 0;
}