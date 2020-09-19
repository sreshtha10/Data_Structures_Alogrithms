class CircularLinkedList{
    class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    Node last = null;
    public void print(){
        Node p;
        if(last == null){
            System.out.println("List is empty");
            return;
        }
        p = last.next;
        do{
            System.out.println(p.data);
        }while(p != last.next);
        return;
    }
    public void insert(int data){
        Node p;
        Node tmp = new Node(data);
        if(last == null){
            last = tmp;
            last.next = tmp;
            return;
        }
        
    }
}

public class Main{
    public static void main(String args[]){
        CircularLinkedList c = new CircularLinkedList();
        c.insert(1);
        c.print();
        
    }
}
