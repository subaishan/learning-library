package Fileword2;

import java.io.FileInputStream;
import java.io.IOException;

public class test {
    public static void main(String[] args) throws IOException {
        //创建一个字符流输入对象
        FileInputStream ims = new FileInputStream("src\\file.txt");
        int b = 0;
        //循环读取
        while((b = ims.read()) != -1){
            System.out.println(b);
        }
        //释放资源
        ims.close();
    }
}
