/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hotel_reservation;

import java.io.Console;
import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

/**
 *
 * @author Ricardo
 */
public class Server extends Thread{
private static ServerSocket ss;
private Socket s;
private final static int PORT = 3128;	
	
	public Server(){
            
        }
	public Server(Socket s) {
		this.s = s;
	}
        
    @Override
    public void run() {
        String User;
        String Pass;
        boolean check;
        System.out.println("HOTEL RESERVATION SYSTEM: LOGIN\n");
        Scanner scan = new Scanner(System.in);
        System.out.print("Please enter your user: ");
        User=scan.next();        
        System.out.print("Please enter your Password: ");
        Pass=scan.next();
        Login login =new Login(User,Pass);
        check=login.login();
        if(check){            
            Hotel_Reservation.mainMenu();
            
        }else{
            System.out.println("Invalid User or Password ");
        }
    }
    
   public static void main(String[] args) {
       
        
        
        try {
            ss = new ServerSocket(PORT);
	}catch (IOException e1) {
            e1.printStackTrace();
	}
        System.out.println("Server Socket rodando na porta = "
				+ ss.getLocalPort());    

         
        
    } 
   
}
