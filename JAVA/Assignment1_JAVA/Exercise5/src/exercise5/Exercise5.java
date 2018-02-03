/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise5;

import java.util.ArrayList;
import java.util.Date;

/**
 *
 * @author Ricardo
 */
public class Exercise5 {

    private int id=0;
    private double balance=0.0;
    private double annualInterestRate;
    private Date dateCreated;
    private String name;
    private ArrayList<Transactions> transactions;
    
    
    //ctors
    
    public Exercise5(){
        this.id = 0;
        this.balance = 0.0;
        this.annualInterestRate = 0.0;
        this.dateCreated = new Date();
        transactions = new ArrayList<Transactions>();
    }
    
    public Exercise5(int newId, double newBalance){
        this.id = newId;
        this.balance = newBalance;
    }
    
    public Exercise5(int newId, double newBalance, String name){
        this.id = newId;
        this.balance = newBalance;
        this.name = name;
        transactions = new ArrayList<Transactions>();
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
    
    public String getName(){
        return this.name;
    }
    
    public ArrayList<Transactions> getTransactions(){
        return transactions;
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
            Transactions newtrans = new Transactions('W',value,this.balance,"Withdraw Transaction");
            transactions.add(newtrans);
       }
    }
    
    public void deposit(int userId, double value){
        if(getId()!=userId){
            System.out.println("ERROR wrong Account ID");
       }
        else{
            this.balance += value;
            Transactions t = new Transactions('D',value,this.balance,"Deposit Transaction");
            transactions.add(t);
        }
    }
    public static void main(String[] args) {
        
        Exercise5 ex6 = new Exercise5(1122,1000,"George");
        ex6.annualInterestRate = 1.5;
        
        ex6.deposit(1122,30);
        ex6.deposit(1122,40);
        ex6.deposit(1122,50);
        
        ex6.withdraw(1122,5);
        ex6.withdraw(1122,4);
        ex6.withdraw(1122,2);
        
        System.out.printf("%s Account #%d%nInterest rate: %.2f%n" +
                          "Balance: %.2f%n" +
                          "Transactions: %n", 
                          ex6.getName(),
                          ex6.getId(),
                          ex6.getAnnuaIntRates(),
                          ex6.getBalance());
                          
        ArrayList<Transactions> transactions = ex6.getTransactions();
        for (Transactions trans : transactions) {
            System.out.printf("%nTransaction date: %s%n" + 
                              "Transaction type: %s%n" +
                              "Transaction amount: %.2f%n" +
                              "Transaction description: %s%n" +
                              "Balance after transaction: %.2f%n", 
                              trans.transDate().toString(),
                              trans.getType(),
                              trans.getAmount(),
                              trans.getDescription(),
                              trans.getTransBalance());
    }
    }
    
}
