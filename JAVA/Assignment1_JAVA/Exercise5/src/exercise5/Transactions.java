package exercise5;


import java.util.Date;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Ricardo
 */
public class Transactions {
    private final Date date;
    private char type;
    private double amount;
    private double balance;
    private String description;
    
    /**
     *
     * @param tType
     * @param tAmount
     * @param tBalance
     * @param desc
     */
    public Transactions(char tType, double tAmount, double tBalance, String desc){
        
        this.type=tType;
        this.amount=tAmount;
        this.balance=tBalance;
        this.description=desc;
        this.date = new Date();
    }
    
    //getters
    
    public char getType(){
        return this.type;
    }
    
    public double getTransBalance(){
        return this.balance;
    }
    
    public double getAmount(){
        return this.amount;
    }
    
    public String getDescription(){
        return this.description;
    }
    
    public Date transDate(){
        return this.date;
    }
    
    //setters
    
    public void setType(char newType){
        this.type=newType;
    }
    
    public void setBalance(double newBalance){
        this.balance=newBalance;
    }
    
    public void setAmount(double newAmount){
        this.amount=newAmount;
    }
    
    public void setDesc(String newDesc){
        this.description=newDesc;
    }
}
