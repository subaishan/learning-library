package IOwork4;

import java.io.*;

public class outstrem {
    public static void main(String[] args) throws IOException {
        //输出不同的编码格式
        OutputStreamWriter osw = new OutputStreamWriter
                (new FileOutputStream("a.txt",true),"UTF-8");
        BufferedWriter bw = new BufferedWriter(osw);
//        String s1 = "\n时间总会说出抱歉";
//        osw.write(s1);
//        osw.close();

        String s2 = "时间总会说出抱歉";
        bw.newLine();
        bw.write(s2);
        bw.close();
    }
}
