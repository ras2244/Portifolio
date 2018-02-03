/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise4;


import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;

/**
 *
 * @author Ricardo
 */
public class Exercise4 {

    private int id=0;
    private double balance=0.0;
    private double annualInterestRate;
    private String dateCreated;
   
    
    
    //ctors
    
    public Exercise4(){
        this.id = 0;
        this.balance = 0.0;
        this.annualInterestRate = 0.0;
        //this.dateCreated.toString();        
    }
    
    public Exercise4(int newId, double newBalance){
        this.id = newId;
        this.balance = newBalance;
        //this.dateCreated.toString();
       
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
        LocalDateTime now = LocalDateTime.now();       

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");

        String formatDateTime = now.format(formatter);

        this.dateCreated =formatDateTime;
        
        return this.dateCreated;
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
     
    @Override
     public String toString(){
        return "\nAccount ID: " + this.id + 
                "\nDate created: " + getDate()
                + "\nmonthly interest: $" 
                + String.format("%.2f", getMonthlyInterest());
    }
     
    public static void main(String[] args) {
        
        Exercise4 account = new Exercise4(1122, 10000);
        SavingsAccount savings = new SavingsAccount(1001, 10000);
	CheckingAccount checking = new CheckingAccount(1004, 10000, -100);
	

        // Set annual interest rate 
	account.setAnnualIntRates(1.5);
	savings.setAnnualIntRates(4.5);
	checking.setAnnualIntRates(1.5);

	// Withdraw $2,500
	account.withdraw(1122,2500);
	savings.withdraw(2500);
	checking.withdraw(2500);

	// Deposit $5,000
	account.deposit(1122,3000);
	savings.deposit(1001,3000);
	checking.deposit(1004,3000);

	// Invoke toString methods
	System.out.println(account);
	System.out.println(savings);
	System.out.println(checking);
        
        //Testing limits
        
        System.out.println("\nTestting Acounts Limit\n");
        
        savings.withdraw(20000);
	checking.withdraw(20000);
	System.out.println(savings);
	System.out.println(checking);
	}
    
    }    
