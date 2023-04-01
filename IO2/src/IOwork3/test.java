package IOwork3;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class test {
    public static void main(String[] args) throws IOException {
        //字节缓冲流的读取
        BufferedInputStream inFile = new BufferedInputStream
                (new FileInputStream("src\\DocumentFormat.OpenXml.dll"));
        byte[] by = new byte[1024];
        int len;
        while((len = inFile.read(by))!=-1){
            for(byte i:by){
                System.out.println(i);
            }
        }
        inFile.close();
    }
}
