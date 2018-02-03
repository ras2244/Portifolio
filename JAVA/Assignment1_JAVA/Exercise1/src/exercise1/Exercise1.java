/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise1;

/**
 *
 * @author Ricardo
 */
public class Exercise1 {

    
    public static void main(String[] args) {
        
        double res = 0.0;
		for (double n = 1.0; n <= 97.0; n += 2) {
            res += n / (n + 2);
	}

	System.out.println(
            "the fraction Series sum of ->(1/3) + (3/5) + 5/7 + (7/9)"
                    + " + (9/11) + (11/13) + " + 
            " ... + (95/97)+ (97/99)");
	System.out.println("the result for the Sum of this series is: " + res);
    }
    
}
