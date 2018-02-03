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
public class SavingsAccount extends Exercise4{
    
    private boolean triger;
    public SavingsAccount(){
        super();
    }
    
    public SavingsAccount(int id, double balance){
        super(id,balance);
    }
    
    public void withdraw(double newValue){
        if(getBalance()>=newValue){
            setBalance(getBalance() - newValue);
            triger=true;
            this.toString();
            
        }
        else{
            
            //System.out.println("Error, Amount exceeds the limit for this Saving Account.");
            triger=false;
            this.toString();
        }
    }
    
    @Override
    public String toString() {
        String result;
        if(triger==true){
            result = "\nChecking Account Balance: $"+ this.getBalance()
            + super.toString() + "\nThis Account does not have "
            + "Overdraft limit";
	}
        else{
            result = "\nError, Amount Requested exceeds "
                    + "Saving Account limit, which is now: $" 
                    +this.getBalance();
            
        }
        
        return result;
		
	}
}
