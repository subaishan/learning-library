package Network1;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class test {
    public static void main(String[] args) throws IOException {
        DatagramSocket ds = new DatagramSocket(10086);
        byte[] by = new byte[1024];
        DatagramPacket dp = new DatagramPacket(by,by.length);
        while(true){
            ds.receive(dp);

            //解析数据包
            byte[] data = dp.getData();
            int len = dp.getLength();
            String name = dp.getAddress().getHostName();
            String ip = dp.getAddress().getHostAddress();

            System.out.println("ip地址为"+ip+"主机名字为"+name+"发送了数据:"+new String(data,0,len));
        }
    }
}
