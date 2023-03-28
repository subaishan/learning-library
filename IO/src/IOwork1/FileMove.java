package IOwork1;

import java.io.*;

public class FileMove {
    public static void main(String[] args) throws IOException {
        File input = new File("src\\FileTestWord");
        File output = new File("src\\Fileword");

        Move(input,output);
    }

    static boolean Move(File _in, File _output) throws IOException {
       //文件夹的创建
        _output.mkdir();
        //文件内容的获取
        File[] files = _in.listFiles();
        //文件内容的拷贝
        for(File file:files){
            if(file.isFile()){
                FileOutputStream _out = new FileOutputStream(new File(_output,file.getName()));
                FileInputStream in = new FileInputStream(file);
                byte[] by = new byte[1024];
                int len;
                while((len = in.read(by))!= -1){
                    _out.write(by,0,len);
                }
                in.close();
                _out.close();
            }else{
                Move(file,new File(_output,file.getName()));
            }
        }
        return true;
    }
}
