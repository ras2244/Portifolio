/**********************************************
Course:<JAC444> - Semester Fall/2017
Last Name:<Leal>
First Name:<Ricardo>
ID:<student ID>
Section:<JAC444SCCL.>
This assignment represents my own work in accordance with
Seneca Academic Policy.
Signature Ricardo Leal
Date:<10/14/2017>
**********************************************/

package discount;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 *
 * @author Ricardo
 */
public class Visit{
    
    private Customer customer;
    private Date date;
    private Double serviceExpense;
    private Double productExpense;
    
    /**
     * Ctor for a new customer
     * 
     * @param n - customer name 
     * @param dt - Date
     */
    
    
    public Visit(String n, Date dt){
        
        customer = new Customer (n);
        this.date=dt;       
    }
    
    /**
     * Ctor For an existing customer
     * @param customer - customer name
     * @param dt - Date
     */
    public Visit(Customer customer, Date dt){
        
        this.customer = customer;
        this.date=dt;       
    }
    
    /**
     * Get for customer name
     * @return customer name
     */
    public String getName(){
        return customer.getName();
    }
    
    /**
     * Get for service Expense
     * @return double values for service Expanse
     */
    public Double getServiceExpense(){
        return serviceExpense;
    }
    
    /**
     * Get for product Expense
     * @return double values for product Expense
     */
    public Double getProductExpense(){
        return productExpense;
    }
    
    /**
     * Getter for total value
     * @return double value for total cost.
     */
    public Double getTotalExpense(){
        return serviceExpense + productExpense;        
    }
    
    /**
     * Make a calculation for serviceExpense based on Discount rate 
     * receiving a double with the value for a service.
     * @param sExpense 
     */
    public void setServiceExpense(double sExpense){
        this.serviceExpense = sExpense - (sExpense
            * DiscountRate.getServiceDiscountRate(customer.getMemberType()));
        
    }
    
    /**
     * Make a calculation for serviceProduct based on Discount rate 
     * receiving a double with the value for a product.
     * @param pExpense 
     */
    public void setProductExpense(double pExpense){
        this.productExpense = pExpense - (pExpense
            * DiscountRate.getProductDiscountRate(customer.getMemberType()));   
    }
    
    
    /**
     * Create a string msg to print a date, 
     * Product and service expenses,and the total cost
     * @return String with concatenated msg.
     */
    @Override
    public String toString() {
        return  new SimpleDateFormat("EEE, MMM d, yyyy").format(this.date) + 
                "\n" + customer + "\nProduct expense: " + 
                productExpense + "\nService expense: " + 
                serviceExpense + "\nTotal expense: " +
                getTotalExpense();
    }
}
