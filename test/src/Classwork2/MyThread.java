package Classwork2;

public class MyThread extends Thread{
    static int num = 100;
    static Object obj = new Object();
    public void run(){
        while(true ){
            if(num < 10){
                System.out.println("礼物小于10份");
                return;
            }
            else{
                System.out.println(getName()+"送出第"+num+"份礼物");
                num--;
            }
        }
    }
}