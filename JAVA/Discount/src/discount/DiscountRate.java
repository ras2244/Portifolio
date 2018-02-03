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

/**
 *
 * @author Ricardo
 */
public class DiscountRate {
    
    // Static doubles to setup premium,Gold and silver service rates.
    // This setup respect the rules for today service rates.
    private static double serviceDiscountPremium = 0.2;
    private static double serviceDiscountGold = 0.15;
    private static double serviceDiscountSilver= 0.1;
    
       
    // Static doubles to setup premium,Gold and silver product Rates.
    // This setup respect the rules for today product rates (it might change).
    private static double productDiscountPremium = 0.1;
    private static double productDiscountGold = 0.1;
    private static double productDiscountSilver= 0.1;
    
    /**
     * Verify the memberType to return an appropriated service discount 
     * @param type
     * @return double rate.
     * case null or any match return a value 0.0
     */
    public static double getServiceDiscountRate(String type) {
        if (type == null) 
            return 0.0;
        switch (type) {
        case "Premium":
                return serviceDiscountPremium;
        case "Gold":
                return serviceDiscountGold;
        case "Silver":
                return serviceDiscountSilver;
        default:
                return 0.0;
        }
    }
    
    /**
     * Verify the memberType to return an appropriated product discount 
     * @param type
     * @return double rate.
     * case null or any match return a value 0.0
     */
    public static double getProductDiscountRate(String type) {
        if (type == null) return 0.0;
        switch (type) {
        case "Premium":
                return productDiscountPremium;
        case "Gold":
                return productDiscountGold;
        case "Silver":
                return productDiscountSilver;
        default:
                return 0.0;
        }
    } 
       
}
