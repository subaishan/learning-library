package Fileword2;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Files2 {
    public static void main(String[] args) throws IOException {
        FileInputStream fis = new FileInputStream("src\\file.txt");
        FileOutputStream fos = new FileOutputStream("src\\file(2).txt");
        //文件拷贝
        byte[] value = new byte[5];
        int len = 0;
        while((len = fis.read(value)) != -1){
            fos.write(value);
        }
        //释放资源
        fis.close();
        fos.close();
    }
}
