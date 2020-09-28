// circular queue - array implementation
class CircularQueue{
    int size;
    int arr[];
    int front =-1,rear = -1;
    public CircularQueue(int size){
        this.size = size;
        this.arr = new int[size];
    }
    public boolean isEmpty(){
        if(front == -1 ){
            return true;
        }
        return false;
    }
    public boolean isFull(){
        if(front == rear +1 || front == 0 && rear = this.size -1){
            return true;
        }
        return false;
    }
    public int peek(){
        if(this.isEmpty()){
            System.out.println("Queue Underflow");
            System.exit(1);
        }
        return arr[front];
    }
    public void insert(int x){
        if(this.isFull()){
            System.out.println("Queue Overflow");
            return;
        }
        if(front == -1){
            front = 0;
            rear = 0;
        }
        else if(rear == this.size-1){
            rear = 0;
        }
        else{
            rear = rear+1;
        }
        arr[rear] = x;
        return;
    }
    public int delete(){
        if(this.isEmpty()){
            System.out.println("Queue Underflow");
            System.exit(1);
        }
        int x = arr[front];
        if(front == rear){
            front =-1;
            rear = -1;
        }
        else if(front == this.size-1){
            front =0;
        }
        else{
            front = front +1;
        }
        return x;
    }
    public void display(){
        
    }
}
public class Main{
    public static void main(String args[]){
        CircularQueue c = new CircularQueue(10);
        
    }
}
