/* Priority Queue - Linked List Implementation.
    It can be done in two ways : 1. Deletion at constant time and insertion at O(n) 
                                2. Insertion at constant time and Deletion at O(n) 
            */
class PriorityQueue{
    class Node{
        int pr;
        int data;
        Node next;
        Node(int data,int pr){
            this.data = data;
            this.pr = pr;
            this.next = null;
        }
    }
    Node front = null;
    public void display(){
        if(front == null){
            System.out.println("Queue Underflow");
            return;
        }
        Node p = front;
        while(p!= null){
            System.out.println("Queue: "+p.data+" Priority: "+p.pr);
            p = p.next;
        }
        return;
    }
    
    public void insert(int data,int pr){
        Node tmp = new Node(data,pr);
        if(front == null || pr < front.pr){
            tmp.next = front;
            front = tmp;
            return;
        }
        else{
            Node p = front;
            while(p.next != null && p.next.pr < pr){
                p = p.next;
            }
            tmp.next = p.next;
            p.next = tmp;
            return;
        }
    }
    public int delete(){
        int x;
        if(front == null){
            System.out.println("Queue Underflow");
            System.exit(1);
        }
        x = front.data;
        front = front.next;
        System.gc();
        return x;
    }
    
}


public class Main{
    public static void main(String args[]){
        PriorityQueue pq = new PriorityQueue();
        pq.insert(1,1);
        pq.insert(2,0);
        pq.insert(3,2);
        pq.delete();
        pq.display();
    }
}
