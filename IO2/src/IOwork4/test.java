package IOwork4;

import java.io.*;

public class test {
    public static void main(String[] args) throws IOException {
        //转换流可以时IO流以不同的编码格式进行读取写入。
        InputStreamReader isr = new InputStreamReader
                (new FileInputStream("src\\b.txt"),"UTF-8");
        BufferedReader br = new BufferedReader(isr);
//        char[] data = new char[1024];
//        int len;
//        while((len = isr.read(data))!=-1){
//            System.out.println((new String(data,0,len)));
//        }
//        isr.close();
        //用转换流使字节流可以调用字符流的方法。
        String da;
        while((da = br.readLine())!=null){
            System.out.println(da);
        }
        br.close();
    }
}
