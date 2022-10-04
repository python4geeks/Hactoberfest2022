public class queue {
    private int[] queueArr;
    private int front;
    private int rear;

    public queue(int numberOfElements){
        this.front=-1;
        this.rear=-1;
        queueArr=new int[numberOfElements];
    }
    public boolean isFull(){
        if(rear==queueArr.length-1){
            return true;
        }
        return false;
    }
    public boolean isEmpty(){
        if(front == -1){
            return  true;
        }
        return false;
    }
    public void display(){
        System.out.println("----");
        for(int i=0;i<=rear;i++){
            System.out.println(queueArr[i]);
        }
        System.out.println("----");
    }
    public void enqueue(int data) {
        if (isFull())    System.out.println("Queue is full");
        else {
            if (front == -1) front++;
            rear++;
            queueArr[rear]=data;
        }
    }
    public int dequeue(){
        if(isEmpty()) System.out.println("Queue is empty");
        else{
            int  data = queueArr[rear];
            for (int i = 0; i < rear; i++) {
                queueArr[i]=queueArr[i+1];
            }
            queueArr[rear]=0;
            rear--;
            if(rear==-1){
                front=-1;
            }
            return data;
        }
        return 0;
    }
    public static void main(String[] args) {
        queue queueobj=new queue(5);
        queueobj.enqueue(5);
        queueobj.enqueue(4);
        queueobj.enqueue(6);
        queueobj.display();
        int dequeue = queueobj.dequeue();
        queueobj.display();
    }
}