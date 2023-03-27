package Classwork4;

public class test {
    public static void main(String[] args) {
        MyThread s1 = new MyThread();
        MyThread s2 = new MyThread();
        MyThread s3 = new MyThread();
        MyThread s4 = new MyThread();
        MyThread s5 = new MyThread();

        s1.setName("a");
        s2.setName("b");
        s3.setName("c");
        s4.setName("d");
        s5.setName("e");

        s1.start();
        s2.start();
        s3.start();
        s4.start();
        s5.start();
    }

}
