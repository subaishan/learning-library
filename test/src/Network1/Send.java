package Network1;

import java.io.IOException;
import java.net.*;
import java.util.Scanner;

public class Send extends Thread{
    public static void main(String[] args) throws IOException {
        DatagramSocket net = new DatagramSocket();
        Scanner scn = new Scanner(System.in);
        while(true){
            String s1 = scn.next();
            if("886".equals(s1)){
                break;
            }
            byte[] by = s1.getBytes();
            InetAddress address = InetAddress.getByName("127.0.0.1");

            int port = 10086;
            DatagramPacket dp = new DatagramPacket(by,by.length,address,port);
            net.send(dp);
        }
        net.close();
    }
}
