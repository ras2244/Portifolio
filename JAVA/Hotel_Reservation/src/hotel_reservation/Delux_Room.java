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
public class Delux_Room extends Room{
    private boolean isVacant;
    
    public Delux_Room(){        
    }
    
    public Delux_Room(int id, double rate,String type,boolean check){
        this.room_id=id;
        this.rate=rate;
        this.isVacant=check;
        this.room_type=type;
    }
    
    @Override
    public int getRoom_Id() {
        return this.room_id;
    }

    @Override
    public double getRate() {
        return this.rate;
    }

    @Override
    public void setRoom_id(int id) {
        this.room_id=id;
    }

    @Override
    public void setRate(double rate) {
       this.rate=rate;
    }
    
    public boolean getIsVacant(){
        return this.isVacant;
    }
    
    public void setIsVacant(boolean check){
        this.isVacant=check;
    }

//    @Override
//    public double calculate_rate() {
//        returns
//    }
    
    public String toString(){
        return getRoom_Id() + ","+getRate()+
                ","+ getRoom_Type()+","+ getIsVacant();
    }
}
