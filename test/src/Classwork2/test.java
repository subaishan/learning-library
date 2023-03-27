package Classwork2;

public class test {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();
        t1.setName("线程一");
        t2.setName("线程二");

        t1.start();
        t2.start();
    }
}
