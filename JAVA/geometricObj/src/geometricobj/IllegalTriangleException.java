/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package geometricobj;

/**
 *
 * @author Ricardo
 */
public class IllegalTriangleException extends Exception {    
    private double side;

    public IllegalTriangleException(double side) {
        super("The sum of two others side is greater than " + side
               + "\nPlease enter the sides again!");
    } 

    public double getSide1() {
        return side;
    }
}
