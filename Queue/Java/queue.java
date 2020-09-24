// Queue FIFO - First In First Out 
class Queue{
    class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    Node front = null;
    Node rear = null;
    public void display(){
        Node p = front;
        if(front == null){
            System.out.println("Queue Underflow");
            return;
        }
        while(p!=null){
            System.out.println(p.data);
            p = p.next;
        }
        return;
    }
    public void insert(int data){
        Node tmp = new Node(data);
        if(front == null){
            front = tmp;
        }
        tmp.next = null;
        if(rear != null){
            rear.next= tmp;
        }
        rear = tmp;
        return;
    }
    
}

public class Main{
    public static void main(String args[]){
        Queue q = new Queue();
        q.insert(1);
        q.insert(2);
        q.insert(3);
        q.display();
    }
}
