class CircularLinkedList{
    class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    Node last = null;
    int length = 0;
    public void print(){
        Node p;
        if(last == null){
            System.out.println("List is empty");
            return;
        }
        p = last.next;
        do{
            System.out.println(p.data);
            p = p.next;
        }while(p != last.next);
        return;
    }
    public void insert(int data){
        Node p;
        Node tmp = new Node(data);
        if(last == null){
            last = tmp;
            last.next = tmp;
            length++;
            return;
        }
        tmp.next = last.next;
        last.next = tmp;
        last = tmp;
        length++;
        return;
    }
}

public class Main{
    public static void main(String args[]){
        CircularLinkedList c = new CircularLinkedList();
        c.insert(1);
        c.insert(3);
        c.print();
        
    }
}
