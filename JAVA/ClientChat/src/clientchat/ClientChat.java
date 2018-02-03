/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clientchat;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

/**
 *
 * @author Ricardo
 */
public class ClientChat {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)throws Exception {
       Socket s=new Socket("localhost",3333);             
       DataInputStream dis= new DataInputStream(s.getInputStream());
       DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       String str="",str2="";  
       while(!str.equals("stop")){ 
           System.out.print("Write your message to server: "); 
           str=br.readLine();  
           dout.writeUTF(str);  
           dout.flush();  
           System.out.println("Waiting message from server..."
                   + "(stop to close connection)"); 
           str2=dis.readUTF(); 
           System.out.println("Server says: "+str2);           
       }
    dout.close();  
    s.close();
    }    
}
