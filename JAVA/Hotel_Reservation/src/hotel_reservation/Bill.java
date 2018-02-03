/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hotel_reservation;

/**
 *
 * @author Ricardo
 */
public class Bill extends Reservation{
    int Bill_id;
    double Amount_toPay;
    String Guest;
    String roomNumber;
    String roomId;
    
    public Bill(){
        Amount_toPay=0;
    }
    
    public Bill(double value,String name,String roomid, String room ){
        this.Amount_toPay=value;
        this.Guest=name;
        this.roomNumber=room;
        this.roomId=roomid;
    }
    
    public double getAmount(){
        return this.Amount_toPay;
    }
    
    public void setAmount(double a){
        this.Amount_toPay=a;
    }
    
    public String toString(){
        return "The bill for Reservation ID " + roomId + " Guest " + Guest +
               " room "+ roomNumber + " Amount "+ Amount_toPay +"\n";
    }
}
