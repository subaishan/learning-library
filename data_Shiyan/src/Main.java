import java.time.Clock;
import java.util.Scanner;
public class Main {
    public static void main(String args[]){
        System.out.println("请输入一个大于10000000的数");
        Scanner value1 = new Scanner(System.in);
        Shi_Yan shi = new Shi_Yan(value1.nextInt());
        shi.add1_time();
        shi.add2_time();
    }
}
