package IOwork3;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Serializable;

public class writerFile {
    public static void main(String[] args) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("src\\a.txt",true));
        writer.write("你的眼睛很美，但是没我的美，为什么");
        writer.newLine();
        writer.write("因为我的眼里有你");
        writer.close();
    }
}
