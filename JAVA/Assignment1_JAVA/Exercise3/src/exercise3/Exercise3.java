/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise3;

import java.util.Date;
import java.util.Scanner;

/**
 *
 * @author Ricardo
 */
public class Exercise3 {

    private int id=0;
    private double balance=0.0;
    private double annualInterestRate;
    private Date dateCreated;
   
    
    
    //ctors
    
    public Exercise3(){
        this.id = 0;
        this.balance = 0.0;
        this.annualInterestRate = 0.0;
        this.dateCreated = new Date();
        
    }
    
    public Exercise3(int newId, double newBalance){
        this.id = newId;
        this.balance = newBalance;
    }    
    
    
    //getters
    
    public int getId(){
        return this.id;
    }
    
    public double getBalance(){
        return this.balance;
       
    }
    
    public double getAnnuaIntRates(){
        return this.annualInterestRate;
    }
    
    public String getDate(){
        return this.dateCreated.toString();
    }
    
    
    //setters
    
    public void setID(int newID){
        this.id=newID;
    }
    
    public void setBalance(double newBalance){
        this.balance=newBalance;        
    }
    
    public void setAnnualIntRates(double newRates){
        this.annualInterestRate=newRates;
    }
    
    // Methods
    
    public double getMonthlyInterestRate(){
        double monthlyIntRates=0.0;
        monthlyIntRates=this.annualInterestRate/12;
        return monthlyIntRates;        
    }
    
    public double getMonthlyInterest(){
        return getMonthlyInterestRate() * this.balance;
    }
    
     public void withdraw(int userId, double value){
       if(getId()!=userId){
            System.out.println("ERROR wrong Account ID");
       }
       else{
            this.balance -= value;
            
       }
    }
    
    public void deposit(int userId, double value){
        if(getId()!=userId){
            System.out.println("ERROR wrong Account ID");
       }
        else{
            this.balance += value;           
        }
    }
    
    public void menu(Exercise3 t ){
        int option=0;
        int amount;
        
       do{
            
            System.out.println("Main Manu");
            System.out.println("1: check balance");
            System.out.println("2: withdraw");
            System.out.println("3: deposit");
            System.out.println("4: exit");
            Scanner read = new Scanner(System.in);        
            option = read.nextInt();
            switch(option){
                case 1:                
                    System.out.println("The balance now is $"+t.getBalance());
                    break;
                case 2:                
                    System.out.print("Enter an amount to withdraw: ");
                    Scanner read2 = new Scanner(System.in);
                    amount = read2.nextInt();
                    t.withdraw(t.getId(), amount);
                    System.out.println("The balance now is $"+t.getBalance());
                    break;
                case 3:
                    System.out.print("Enter an amount to deposit: ");
                    Scanner read3 = new Scanner(System.in);
                    amount = read3.nextInt();
                    t.deposit(t.getId(), amount);
                    System.out.println("The balance now is $"+t.getBalance());
                    break;
                case 4:
                    break;               

            }
        } while(option!=4);
    }
    
    public static void main(String[] args) {
        
        int idArray[] = {0,1,2,3,4,5,6,7,8,9};
        int i=0;
        int userId;
        boolean check=false;        
        
        do{
            Scanner input=new Scanner(System.in);
            System.out.print("Enter an ID: ");
            userId= input.nextInt();
            for(i=0; i<idArray.length;i++){
                if (userId==idArray[i]){
                    check=true;
                    break;
                }
            }
            if(check==false){
                System.out.println("ID do not exist, please try again");
            }
        }while(check==false);     

        do{
             if (userId==idArray[i]){
                Exercise3 user = new Exercise3(i,100); 
                user.menu(user);
                i=10;
            }
             else{
                 i++;                 
             }             
        }while(i<idArray.length);
    }
    
}
