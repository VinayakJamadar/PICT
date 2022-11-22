package SocketProgramming;

import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args) throws Exception {
        Socket soc = new Socket("localhost", 3000);
        BufferedReader readtype = new BufferedReader(new InputStreamReader(System.in));
        OutputStream ostream = soc.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);
        InputStream istream = soc.getInputStream();
        BufferedReader recieve = new BufferedReader(new InputStreamReader(istream));
        String sendmsg, recmsg;
        while (true) {
            System.out.println("Enter the Operation(add,sub,mul,div,exit)....");
            sendmsg = readtype.readLine();
            if (sendmsg.compareTo("exit") == 0) {
                pwrite.println("exit");
                soc.close();
                break;
            }
            pwrite.println(sendmsg);
            System.out.println("Enter the Parameter 1 : ");
            sendmsg = readtype.readLine();
            pwrite.println(sendmsg);
            System.out.println("Enter the Parameter 2 : ");
            sendmsg = readtype.readLine();
            pwrite.println(sendmsg);
            System.out.flush();
            if ((recmsg = recieve.readLine()) != null) {
                System.out.println(recmsg);
                if (recmsg.compareTo("exit") == 0) {
                    break;
                }
            }
        }
    }
}
