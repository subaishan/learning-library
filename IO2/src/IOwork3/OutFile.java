package IOwork3;

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class OutFile {
    public static void main(String[] args) throws IOException {
        BufferedOutputStream outFile = new BufferedOutputStream(new FileOutputStream("src\\a.txt"));
        String s1 = "时间是把杀猪刀";
        byte[] by;
        by = s1.getBytes();
        outFile.write(by);
        outFile.close();
    }
}
