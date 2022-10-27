// :- Note 1 : Creation of Thread by extending "Thread class " also known as "Inheritance Method to create thread"
//:- Note 1 : But the best method to create a Thread is "Association method" which by implementing "Runnable Interface"
class A implements Runnable {

    //override the run method
    //here you can any logic whatever you want
    public void run(){
        //here printing table of 2
        int a =2;
        for(int i=1;i<=10;i++){
            System.out.println("2 x"+" "+i+" ="+a*i);
        }
    }
}
// creating another class for the Multithreading
class B implements Runnable{
   
    //override the run method
    //here you can any logic whatever you want
    public void run(){
        //here printing table of 3
        int a= 3;
        for(int i=1;i<=10;i++){
            System.out.println("3 x"+" "+i+" ="+a*i);
        }
    } 
}


public class CreationOfThreadByRunnabaleInterface {
   //:- Note : Threads have no sequences any thread can run any time, it is decided by Thread schedular 

   public static void main(String[] args) {
    //here first create objects of your classes
    A a = new A();
    B b = new B();

    //now as we Here we also need to make object of "Thread class " to run the Thread
    Thread t1 = new Thread(a);
    Thread t2 = new Thread(b);
    //now call start() method to both Thread class Objects
    t1.start();
    t2.start();
   }
    
}
