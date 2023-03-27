package Classwork4;

import java.util.Random;

public class MyThread extends Thread{
    static double monkey = 100;
    static int num = 3;
    static final double MIN = 0.1;
    static Object obj = new Object();
    @Override
    public void run() {
        synchronized (obj){
            if(num == 0){
                System.out.println(this.getName()+"该用户没有抢到红包");
            }else{
                double prize = 0;
                if(num == 1){
                    prize = monkey;
                    System.out.println(this.getName()+prize);
                }else {
                    Random ran = new Random();
                    double TruePrize = monkey - (num - 1) * MIN;
                    prize = ran.nextDouble(TruePrize);
                    if(prize < MIN){
                        prize = MIN;
                    }
                }
                monkey -= prize;
                num--;
                System.out.println(getName() + "抢到" + prize);
            }
        }
    }
}
