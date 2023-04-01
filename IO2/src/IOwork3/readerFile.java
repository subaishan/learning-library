package IOwork3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class readerFile {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("src\\a.txt"));
        String line;
        line = reader.readLine();
        System.out.println(line);
        reader.close();
    }
}
