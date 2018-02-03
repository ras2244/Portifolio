/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise4;

/**
 *
 * @author Ricardo
 */
public class CheckingAccount extends Exercise4 {
    
    private double limit;
    private boolean triger;
    
    public CheckingAccount(){
        super();
        this.limit = -100;
    }
    public CheckingAccount (int id, double balance, double limit){
        super(id,balance);
        this.limit = limit;        
    }
    
    public double getLimit(){
        return this.limit;
    }
    
    public void setLimit(double newValue){
        this.limit=newValue;
    }
    
    public void withdraw (double value){
        if(getBalance()>= value + this.limit){
            setBalance(getBalance() - value);
            triger=true;
            this.toString();
            
        }
        
        else{
            //System.out.println("Error, Amount exceeds the limit.");
            triger=false;
            this.toString();
        }
    }
    
    @Override
    public String toString() {
	String result;
        if(triger==true){
            result = "\nChecking Account Balance: $"+ this.getBalance()
            + super.toString() + "\nYour Overdraft limit is $" + 
            String.format("%.2f", -1*(limit));
	}
        else{
            result = "\nError, Amount Requested exceeds "
                    + "Checking Account limit, which is now: $" 
                    +((this.getBalance())+(-1*(limit)));
            
        }
        
        return result;
    }
}
