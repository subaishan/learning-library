package IOwork5;

import java.io.*;

public class test {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        student ste = new student(10,"张三");
        ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("src\\IOwork5\\a.txt"));
        out.writeObject(ste);
        out.close();

        ObjectInputStream in = new ObjectInputStream(new FileInputStream("src\\IOwork5\\a.txt"));
        Object o = in.readObject();
        System.out.println(o);
        in.close();
    }
}
