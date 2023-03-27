package Classwork1;
public class MyThred extends Thread{
    static int num = 1;
    static Object obj = new Object();
    public void run(){
        while(true){
            synchronized (obj){
                try {
                    Thread.sleep(3000);
                    Thread.yield();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                if(num > 1000000){
                 return;
            }else{
                System.out.println(getName()+"售卖第"+num+"票");
                num++;
            }
            }
        }
    }
}
