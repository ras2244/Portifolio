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

import java.util.Objects;

/**
 *
 * @author Ricardo
 */
public class Customer {
   
    private String Name;
    private Boolean Member;
    private String MemberType;
 
/**
 * CTOR for customer receiving string name a setting 
 * Member and memberType 
 * @param name 
 */
    public Customer(String name){        
           
        this.Name=name;
        this.Member=false;
        this.MemberType="Not a Member";           

    }
    
    /**
     * Checks if name starts with numbers
     * to be used in future verifications
     * @param name
     * @return 
     */
    public boolean Validate(String name){
        final char c= name.charAt(0);
        boolean check=false;
        try{
            if(name.substring(0, 1).matches("[0-9]")== true){                    
                    throw(new Exception("error, name cannot start with number"));                    
                }
             else{
                check=true;
            }        
            
        }       
        catch(Exception e){
             e.printStackTrace();
            }
        return check;
    }
    
    /**
     * Getter for Name
     * @return String name
     */
    public String getName(){
        return this.Name;    
    }
    
    /**
     * check if a customer is a Member or not
     * @return Boolean 
     */
    public Boolean isMember(){
       return this.Member;
        
    }
    
    /**
     * Setter for Member receiving a boolean
     * @param member 
     */
    public void setMember(boolean member){
        this.Member = member;        
    }
    
    /**
     * Getter for MemberType receiving a boolean Member
     * @return string MemberType
     */
    public String getMemberType(){
        return MemberType;
    }
    
    /**
     * Set MemberType receiving a string
     * @param mType 
     */
    public void setMemberType(String mType){
        MemberType=mType;
    }
    
    /**
     * check member status to 
     * @return a string with appropriated msg.
     */
    public String validationMember(){
        if(this.Member==true && this.Member!= null ){
            return " has a ";
        }
        else{ 
            return " has not a ";
        }
    }
    
    
    /**
     * check memberType status to
     * @return a string with appropriated msg.
     */
    public String validationMemberType(){
        if(!Objects.equals(this.MemberType,"Not a member")||this.Member==false){
            return this.Name+"`s Membership Status now is " + this.MemberType ;
        }
        else{ 
            return "" + this.MemberType;
        }
    }
    /**
     * Create a string msg to print a customer name, 
     * member status and memberType at the moment
     * @return String with concatenated msg.
     */
    @Override
    public String toString() {
        return "This Customer "
				+ this.Name
				+ validationMember()
				+ "discounts advantages."
				+ validationMemberType();
    }
}