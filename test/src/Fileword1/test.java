package Fileword1;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class test {
    public static void main(String[] args) throws IOException {
        //创建字符流
        FileOutputStream fops = new FileOutputStream("src/file.txt");
        //输入数据
        fops.write(53); //write(int) write(byte[]) write(byte[],int start,int end)
        //释放文件
        fops.close();

        //换行实现
        fops = new FileOutputStream("src/file.txt");
        String s1 = "你好";
        byte[] bytes = s1.getBytes();
        fops.write(bytes);
        //换行操作
        String s2 = "\r\n";
        bytes = s2.getBytes();
        fops.write(bytes);
        //实现完成
        String s3 = "世界";
        bytes = s3.getBytes();
        fops.write(bytes);
        fops.close();

        //续写实现
        fops = new FileOutputStream("src/file.txt",true);
        String t1 = "hello,world";
        bytes = t1.getBytes();
        fops.write(bytes);
    }
}
