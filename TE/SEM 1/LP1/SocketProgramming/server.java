package SocketProgramming;

import java.io.*;
import java.net.*;

public class server {
    public static void main(String args[]) throws Exception {
        ServerSocket ser = new ServerSocket(3000);
        System.out.println("Server Ready.....");
        Socket soc = ser.accept();
        OutputStream ostream = soc.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);
        InputStream istream = soc.getInputStream();
        BufferedReader recieve = new BufferedReader(new InputStreamReader(istream));
        String fun;
        int a, b, c;
        while (true) {
            fun = recieve.readLine();
            if (fun.compareTo("exit") == 0) {
                System.out.println("Server Exit");
                soc.close();
                ser.close();
                break;
            } else if (fun != null) {
                System.out.println("Opreation is : " + fun);
            }
            a = Integer.parseInt(recieve.readLine());
            System.out.println("Parameter 1 : " + a);
            b = Integer.parseInt(recieve.readLine());
            System.out.println("Parameter 2 : " + a);
            if (fun.compareTo("add") == 0) {
                c = a + b;
                System.out.println("Addition is : " + c);
                pwrite.println("Addition is : " + c);
            }
            if (fun.compareTo("sub") == 0) {
                c = a - b;
                System.out.println("Subtraction is : " + c);
                pwrite.println("Subtraction is : " + c);
            }
            if (fun.compareTo("mul") == 0) {
                c = a * b;
                System.out.println("Multiplication is : " + c);
                pwrite.println("Multiplication is : " + c);
            }
            if (fun.compareTo("div") == 0) {
                c = a / b;
                System.out.println("Division is : " + c);
                pwrite.println("Division is : " + c);
            }
            System.out.flush();
        }
    }
}