/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hotel_reservation;

import java.io.Serializable;
import java.util.Date;
import java.util.List;

/**
 *
 * @author Ricardo
 */
public class Reservation{
    private int Book_id;
    private Date Book_Date;
    private Date Check_in;
    private Date Check_out;
    private int numOfGuests;
    private int roomId;
    private String RoomType;
    public List<Guest> guest;
    private String guest2;
    
    
    //ctor
    
    public Reservation(){
        this.Book_id=0;
        this.Book_Date= new Date();
        this.Check_in= new Date();
        this.Check_out=new Date();
    }
    
    public Reservation(Date bd, Date ci,Date co,int num, String rt,List<Guest> g,int rid){
        //this.Book_id=0;
        this.Book_Date= bd;
        this.Check_in= ci;
        this.Check_out=co;
        this.numOfGuests=num;
        this.RoomType=rt;
        this.guest=g;
        this.roomId=rid;
    }
    
    public Reservation(Date bd, Date ci,Date co,int num, String rt,String g,int rid){
        //this.Book_id=0;
        this.Book_Date= bd;
        this.Check_in= ci;
        this.Check_out=co;
        this.numOfGuests=num;
        this.RoomType=rt;
        this.guest2=g;
        this.roomId=rid;
    }
    //getters
    
    public String getGuest(){
        return this.guest2;
    }
    public int getRoom_Id(){
        return this.roomId;
    }
    
    public int getBook_Id(){
        return this.Book_id;
    }
    
    public Date getBook_Date(){
        return this.Book_Date;
    }
    
    public Date getCheck_in(){
        return this.Check_in;
    }
    
    public Date getCheck_out(){
        return this.Check_out;
    }
    
    public int getNumOfGuests(){
        return this.numOfGuests;
    }
    
    public String getRoomtype(){
        return this.RoomType;
    }
    
    //Setters
    
    public void setBook_Id(int id){
        this.Book_id=id;
    }
    
    public void setRoom_id(int id){
        this.roomId=id;
    }
    
    public void setBook_Date(Date date){
        this.Book_Date=date;
    }
    
    public void setCheck_in(Date date){
        this.Check_in=date;
    }
    
    public void setCheck_out(Date date){
        this.Check_out=date;
    }
    
    public void setNumOfGuests(int num){
        this.numOfGuests=num;
    }
    
    public void setRoomType(String t){
        this.RoomType=t;
    }
    
    @Override
    public String toString(){
        return getBook_Id() + ","+getBook_Date()+
                ","+ getCheck_in()+","+ getCheck_out()+
                "," + guest.get(0).getFirst_Name()+ ","+this.numOfGuests+"," 
                + this.RoomType+","+this.roomId;
    }
    
}
