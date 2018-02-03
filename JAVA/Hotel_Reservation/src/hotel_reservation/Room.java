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
public abstract class Room {
    public int room_id;
    public String room_type;
    public double rate;
    
    public Room(){
        this.room_type = " ";
        this.room_id = 0;
        this.rate = 0.0;
    }
    
    public String getRoom_Type(){
        return this.room_type;
    }
    
    public void setRoom_type(String room){
        this.room_type=room;
    }
    
    public abstract int getRoom_Id();
    public abstract double getRate();
    public abstract void setRoom_id(int id);
    public abstract void setRate(double rate);
    //public abstract double calculate_rate();   
    
}

