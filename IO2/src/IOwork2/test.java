package IOwork2;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class test {
    public static void main(String[] args) throws IOException {
        //文件加密
        File inFile = new File("src\\IOwork2\\infile");
        File outFile = new File("src\\IOwork2\\outfile");

        password(inFile,outFile);
        getFile(outFile);

    }

    static public void password(File inFile, File outFile) throws IOException {
        //建立一个文件夹
        outFile.mkdir();
        //获取文件夹
        File[] files = inFile.listFiles();
        for(File file:files)
        {
            if(file.isFile())
            {
                FileInputStream _in = new FileInputStream(file);
                FileOutputStream _out = new FileOutputStream(new File(outFile,file.getName()));
                byte[] by = new byte[1024];
                int len;
                while((len = _in.read(by)) != -1)
                {
                    //进行加密
                    for(int i = 0; i < len; i++)
                    {
                        by[i] = (byte) (by[i] ^ 2);
                    }
                    _out.write(by,0,len);
                }
                _in.close();
                _out.close();
            }
            else{
                password(file,new File(outFile,file.getName()));
            }
        }
    }

    static public void getFile(File file) throws IOException {
        File[] files = file.listFiles();
        for(File _file:files){
            if(_file.isFile()){
                FileInputStream _in = new FileInputStream(_file);
                FileOutputStream _out = new FileOutputStream(new File(_file.getParent(),"123.png"));
                byte[] by = new byte[1024];
                int len;
                while((len = _in.read(by))!=-1){
                    for(int i = 0; i < len; i++){
                        by[i] = (byte) (by[i] ^ 2);
                    }
                    _out.write(by,0,len);
                }
                _in.close();
                _out.close();
            }else{
                getFile(_file);
            }
        }
    }
}
