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
    
    
    
}


public class Main{
    public static void main(String args[]){
        PriorityQueue pq = new PriorityQueue();
    }
}
