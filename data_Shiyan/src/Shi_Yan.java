import java.time.Clock;
public class Shi_Yan {
    int value = 0;
    int sum = 0;
    long time = 0;
    long end = 0;

    Shi_Yan(int _value){
        this.value = _value;
    }
    void add1_time() {
        if (this.value > 10000000) {
            sum = 0;
            time = System.currentTimeMillis();
            for (int i = 2; i < this.value; i++) {
                if (value % i == 0) {
                    sum += 1;
                }
            }
            end = System.currentTimeMillis();
            time = end - time;
            if (sum == 0)  System.out.println("方法一:\n" + "该数是指数\n" + "消耗时间为:" + ((float)time)/1000 + "秒");
             else  System.out.println("方法一:\n" + "该数不是是指数\n"  +  "消耗时间为:" + ((float)time)/1000 + "秒");
        }
    }
    void add2_time(){
        if(this.value > 10000000){
            sum = 0;
            time = System.currentTimeMillis();
            for(int i = 2; i < (int)Math.sqrt((float)value); i++){
                if (value % i == 0) {
                    sum += 1;
                }
            }
            end = System.currentTimeMillis();
            time = end - time;
            if (sum == 0)  System.out.println("方法二:\n" + "该数是指数\n" + "消耗时间为:" + ((float)time)/1000 + "秒");
            else  System.out.println("方法二:\n" + "该数不是是指数\n" + "消耗时间为:" + ((float)time)/1000 + "秒");
        }
    }
}
