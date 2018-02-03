/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package geometricobj;

import java.util.Date;
import java.util.Scanner;

/**
 *
 * @author Ricardo
 */
public abstract class GeometricObj {

    private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;

    /**Default construct*/
    protected GeometricObj() {
        dateCreated = new java.util.Date();
    }

    /**Construct a geometric object*/
    protected GeometricObj(String color, boolean filled) {
        this.dateCreated = new java.util.Date();
        this.color = color;
        this.filled = filled;
    }

    /**Getter method for color*/
    public String getColor() {
        return color;
    }

    /**Setter method for color*/
    public void setColor(String color) {
        this.color = color;
    }

    /**Getter method for filled. Since filled is boolean,
       so, the get method name is isFilled*/
    public boolean isFilled() {
        return filled;
    }

    /**Setter method for filled*/
    public void setFilled(boolean filled) {
        this.filled = filled;
    }
    
    public Date getDateCreated(){
        return this.dateCreated;
    }

    /**Abstract method findArea*/
    public abstract double getArea();

    /**Abstract method getPerimeter*/
    public abstract double getPerimeter();
    
    
    @Override
    public String toString() {
	return "\ncreated on " + dateCreated +
                "\nArea of: "+getArea()+
                "\nPerimeter of: "+ getPerimeter()+
                "\ncolor: " + color + 
                "\nfilled: " + filled + "\n";
    }

  
    public static void main(String[] args) throws IllegalTriangleException {
       Scanner input = new Scanner(System.in);

        // create triangle
        Triangle triangle = new Triangle();
        boolean check = false;
        double side1 = 1.0;
        double side2 = 1.0;
        double side3 = 1.0;

        System.out.println("Enter size of three sides: ");

        while (!check) {
            try {
                side1 = input.nextDouble();
                side2 = input.nextDouble();
                side3 = input.nextDouble();
                triangle = new Triangle(side1, side2, side3);
                check = true;
            }
            catch (IllegalTriangleException ex) {
                System.out.println(ex.getMessage());
                System.out.print("Enter three sides:  ");
                input.nextLine();
            }
        }
        
        System.out.println("Enter a color:  ");
        String color = input.next();
        triangle.setColor(color);

        System.out.println("Enter true or false for triangle filled: ");
        boolean filled = input.nextBoolean();
        triangle.setFilled(filled);
        
        System.out.print(triangle.toString());
        }
       
        
    
}
