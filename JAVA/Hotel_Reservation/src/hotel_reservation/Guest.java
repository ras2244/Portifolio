/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hotel_reservation;

import java.io.Serializable;

/**
 *
 * @author Ricardo
 */



public class Guest{
    
    private int guest_ID=0;
    private String title;
    private String first_Name;
    private String last_Name;
    private String address;
    private String email;
    private long phone;
    
    
    //Ctor
    
    public Guest(){
        this.guest_ID=0;
        this.title=" ";
        this.first_Name=" ";
        this.last_Name=" ";
        this.address=" ";
        this.phone=0;
        this.email=" ";
    }
    
    public Guest(String t,String fName,String lName,String adr,long phone,String email){        
        this.title=t;
        this.first_Name=fName;
        this.last_Name=lName;
        this.address=adr;
        this.phone=phone;
        this.email=email;
    }
    //getters
    
    public int getGuest_ID(){
        return this.guest_ID;
    }
    
    public String getTitle(){
        return this.title;
    }
    
    public String getFirst_Name(){
        return this.first_Name;
    }
    
     public String getLast_Name(){
        return this.last_Name;
    }
    
    public String getAddress(){
        return this.address;
    }
    
    public String getEmail(){
        return this.email;
    }
    
    public long getPhone(){
        return this.phone;
    }
    
    //Setters
    
    public void setGuest_ID(int id){
        this.guest_ID=id;
    }
    
    public void setTitle(String title){
        this.title=title;
    }
    
    public void setFirst_Name(String fname){
        this.first_Name=fname;
    }
    
    public void setLast_Name(String lname){
        this.last_Name=lname;
    }
    
    public void setAddress(String adr){
        this.address=title;
    }
    
    public void setEmail(String email){
        this.email=email;
    }
    
    public void setPhone(int phn){
        this.phone=phn;
    }
    
    @Override
    public String toString(){
        return getGuest_ID() + ","+getTitle()+
                ","+ getFirst_Name()+","+ getLast_Name()+
                "," + getAddress()+ ","+ getPhone()+"," 
                + getEmail();
    }
}
