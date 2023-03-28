package IOwork1;

import java.io.UnsupportedEncodingException;
import java.lang.reflect.Array;
import java.util.Arrays;

public class test {
    public static void main(String[] args) throws UnsupportedEncodingException {
        //编码
        String s1 = "ai你又";
        byte[] b1 = s1.getBytes();
        System.out.println(Arrays.toString(b1));
        byte[] b2 = s1.getBytes("GBK");
        System.out.println(Arrays.toString(b2));

        //解码
        String s2 = new String(b1);
        System.out.println(s2);
        String s3 = new String(b1,"GBK");
        System.out.println(s3);
    }
}
