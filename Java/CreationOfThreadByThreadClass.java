// :- Note 1 : Creation of Thread by extending "Thread class " also known as "Inheritance Method to create thread"
//:- Note 1 : But the best method to create a Thread is "Association method" which by implementing "Runnable Interface"
class A extends Thread {

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
class B extends Thread{
   
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

public class CreationOfThreadByThreadClass{
    //:- Note : Threads have no sequences any thread can run any time, it is decided by Thread schedular
    public static void main(String[] args) {
        //here create objects of your classes
        A t1 = new A();
        B t2 = new B();
        //now call start() of Thread class to run thread
        t1.start();
        t2.start();

    
    }
}