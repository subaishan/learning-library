package Fileword2;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Files {
    public static void main(String[] args) throws IOException {
        FileInputStream fis = new FileInputStream("src\\file.txt");
        FileOutputStream fos = new FileOutputStream("src\\file(1).txt");
        //文件拷贝
        int value = 0;
        while((value = fis.read()) != -1){
            fos.write(value);
        }
        //释放资源
        fis.close();
        fos.close();
    }
}
