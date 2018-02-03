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
public class Triangle extends GeometricObj {
    
    private double side1;
    private double side2;
    private double side3;
    
    public Triangle() {
        side1 = 1.0;
        side2 = 1.0;
        side3 = 1.0;
    }
    
    public Triangle(double s1, double s2, double s3) throws IllegalTriangleException {
        if (s1 >= s2 + s3){
            throw new IllegalTriangleException(s1);}
        else if (s2 >= s1 + s3){
            throw new IllegalTriangleException(s2);}
        else if (s3 >= s2 + s1){
            throw new IllegalTriangleException(s3);}
        else {
            this.side1 = s1;
            this.side2 = s2;
            this.side3 = s3;
        }
    }
    
    public double getSideOne() {
        return this.side1;
    }
    
    public double getSideTwo() {
        return this.side2;
    }
    
    public double getSideThree() {
        return this.side3;
    }

    @Override
    public double getArea() {
        double perimeter = this.side1 + this.side2 + this.side3;
        return 
            Math.sqrt(perimeter * (
                                    (perimeter - this.side1) * 
                                    (perimeter - this.side2) * 
                                    (perimeter - this.side3)));
    }

    @Override
    public double getPerimeter() {
        return (this.side1 + this.side2 + this.side3);
    }
    
    @Override
    public String toString() {
        return "Triangle: side1 = " + this.side1 + " side2 = " + this.side2 +
               " side3 = " + this.side3 + super.toString();
    }
}
