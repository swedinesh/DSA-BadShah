import java.util.Scanner;

class Node{
    int data;
    Node next;
    Node(int data){
        this.data = data;
        this.next = null;
    }
}

class Obj{
    Node head = null;
    Node tail = null;

    void insertAtHead(int data){
        Node newNode = new Node(data);

        if(head==null){
            head = tail = newNode;
        }
        else{
            newNode.next = head;
            head = newNode;
        }
    }

    void display(){
        Node temp = head;
         
        while(temp!=null){
            System.out.print(temp.data);
            if(temp != tail) System.out.print(" --> ");
            temp = temp.next;
        }
        System.out.println();
    }

    void displayRecursive(Node temp){
        if(temp == null){
            return;
        }
       displayRecursive(temp.next);

       System.out.print(temp.data+ "-->");
    }
}

public class SinglyList {
    public static void main(String[] args) {
        Obj ll = new Obj();

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for(int i=0; i<n; i++){
            System.out.print("Element "+(i+1)+" : ");
            ll.insertAtHead(sc.nextInt());
        }
       
        ll.display();
        System.out.println();
        ll.displayRecursive(ll.head);
        System.out.println();
        
    }
}
