package Classwork1;

public class test {
    public static void main(String[] args) {
        MyThred t1 = new MyThred();
        MyThred t2 = new MyThred();
        t1.setName("线程一");
        t2.setName("线程二");
        t1.start();
        t2.start();
    }
}
