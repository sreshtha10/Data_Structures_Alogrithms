class Node{
    int data;
    Node prev;
    Node next;
    public Node(int data){
        this.data = data;
    }
}
class LinkedList{
    Node head;
    Node tail;
    public void insert(int data){
        Node tmp = new Node(data);
        Node p = head;
        if(head == null){
            head = tmp;
            tmp.next = null;
            tmp.prev = null;
            tail = tmp;
            return;
        }
        while(p.next != null){
            p = p.next;
        }
        tail = tmp;
        tmp.next = null;
        tmp.prev = p;
        p.next = tmp;
        return;
    }
    
    public void insertStart(int data){
        Node tmp = new Node(data);
        tmp.next = head;
        tmp.prev = null;
        head.prev = tmp;
        head = tmp;
        return;
    }
    public void print(){
        Node p = head;
        if(head == null){
            System.out.println("List is empty");
            return;
        }
        p = head;
        while(p!= null){
            System.out.println(p.data+" ");
            p = p.next;
        }
    }
    public void printReverse(){
        Node p = tail;
        while(p != null){
            System.out.println(p.data);
            p = p.prev;
        }
    }
    
}
public class Main{
    public static void main(String args[]){
        LinkedList l = new LinkedList();
        l.insert(1);
        l.insert(2);
        l.insert(3);
        l.insert(4);
    }
}
