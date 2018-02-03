/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serverchat;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author Ricardo
 */
public class ServerChat {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)throws Exception {
        
       ServerSocket ss=new ServerSocket(3333);
       System.out.println("Server is listening for the connections... ");
       Socket s = ss.accept();
       DataInputStream dis= new DataInputStream(s.getInputStream());
       DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       String str="",str2="";  
       while(!str.equals("stop")){  
           System.out.println("Waiting message from clinet...:");
           str=dis.readUTF();  
           System.out.println("client says: "+str);  
           System.out.println("Write message back to client"
                   + "(stop to close connection): ");
           str2=br.readLine();  
           dout.writeUTF(str2);
           dout.flush();  
       }
    dis.close();  
    s.close();
    ss.close();        
    }    
}
