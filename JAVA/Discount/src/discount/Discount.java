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

import java.util.Date;

/**
 *
 * @author Ricardo
 */
public class Discount {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
                System.out.println("--> Setting up Customer CTOR <--");
                Customer customer1 = new Customer("Jonh Snow");
		System.out.println(customer1);
		
		System.out.println("\n--> First Visit - no Discount "
                        + "new Member <--");
		Visit visit_new = new Visit("Petyr Baelish", new Date());
		visit_new.setServiceExpense(100);
		visit_new.setProductExpense(100);
		System.out.println(visit_new);
		
		System.out.println("\n--> Second Visit - Member, but no "
                        + "member type setted <--");
		Visit visit2 = new Visit(customer1, new Date());
		visit2.setServiceExpense(100);
		visit2.setProductExpense(100);
		System.out.println(visit2);
		customer1.setMember(true);
		
		System.out.println("\n--> Third Visit - Discount member and "
                        + "silver member type<--");
		Visit visit3 = new Visit(customer1, new Date());
                customer1.setMemberType("Silver");
		visit3.setServiceExpense(100);
		visit3.setProductExpense(100);                
		System.out.println(visit3);
		
                
                System.out.println("\n--> Third Visit - Discount member and "
                        + "Gold member type<--");
		Visit visit4 = new Visit(customer1, new Date());
                customer1.setMemberType("Gold");
		visit4.setServiceExpense(100);
		visit4.setProductExpense(100);
		System.out.println(visit4);
		
                
                System.out.println("\n--> Third Visit - Discount member and "
                        + "Premium member type<--");
		Visit visit5 = new Visit(customer1, new Date());
                customer1.setMemberType("Premium");
		visit5.setServiceExpense(100);
		visit5.setProductExpense(100);
		System.out.println(visit5);                              
		
		System.out.println("\n--> Last Visit, same status different "
                        + "values<--");
		Visit visit6 = new Visit(customer1, new Date());
		visit6.setServiceExpense(1000);
		visit6.setProductExpense(1000);
		System.out.println(visit6);
                
                System.out.println("\n-----------------------------------\n");
                
                System.out.println("--> Setting up another Customer CTOR <--");
                Customer customer2 = new Customer("Aria");
		System.out.println(customer2);
                
                System.out.println("\n--> New Client - setting Discount member "
                        + "and Premium member type all together <--");
		Visit visit_new2 = new Visit(customer2, new Date());
                customer2.setMember(true);
                customer2.setMemberType("Premium");
		visit_new2.setServiceExpense(1000);
		visit_new2.setProductExpense(1000);
		System.out.println(visit_new2);
                System.out.println("\n");
  
    }
    
}
