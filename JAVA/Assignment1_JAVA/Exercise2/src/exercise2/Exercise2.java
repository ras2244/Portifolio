/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise2;

import java.util.Date;

/**
 *
 * @author Ricardo
 */
public class Exercise2 {
    
    private int id=0;
    private double balance=0.0;
    private double annualInterestRate;
    private Date dateCreated;
   
    
    
    //ctors
    
    public Exercise2(){
        this.id = 0;
        this.balance = 0.0;
        this.annualInterestRate = 0.0;
        this.dateCreated = new Date();
        
    }
    
    public Exercise2(int newId, double newBalance){
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
    
    public static void main(String[] args) {
        
        Exercise2 user01=new Exercise2(1124,20000);
        user01.annualInterestRate = 4.5;
        System.out.println("Balance now is: " +user01.balance + "\n");
        user01.withdraw(1124,2500);
        System.out.println("Balance now after withdraw $2500 is: $" +user01.balance + "\n");
        user01.deposit(1124,3000); 
        System.out.println("Balance now after deposit $3000 is: $" +user01.balance + "\n");
        System.out.println("The user ID number: " + user01.id + " has a balance now: $"+ user01.balance);        
        
        System.out.println("\n-----------end of Exercise 2---------------\n");
    }
    
}
