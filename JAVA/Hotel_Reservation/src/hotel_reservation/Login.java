/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hotel_reservation;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Ricardo
 */
public class Login {
    String user;
    String Password;
    
    public Login(){
        
    }
    
    public Login(String user, String pass){
        this.user=user;
        this.Password=pass;
    }
    
     public boolean login(){
           boolean result=false;
           try {

                File file;
                file = new File("C:\\Users\\Ricardo\\Documents\\login.txt");

                boolean fvar = file.createNewFile();
                if (fvar){
                      System.out.println("File has been created successfully");
                }

                Scanner scan=new Scanner(file);
                while(scan.hasNextLine()){
                    String line = scan.nextLine();
                    String[] details = line.split(",");
                    String first=details[0];
                        if(!"".equals(first)){                                        
                            String a,b;
                            a=details[0];
                            b=details[1];

                            if(a.contains(user)){
                                if(b.contains(Password)){
                                    System.out.println("Welcome! You are logged in as "+a);
                                    result=true;
                                    break;
                                }
                                else{
                                    System.out.println("Login or Password are not correct!");
                                    //System.out.println("Login or Password are not correct!");
                                    result=false;
                                    break;
                                }
                            }


                        }
                }


            } catch (IOException e) {
                    e.printStackTrace();
            }
       return result;
    }
     
     
}
