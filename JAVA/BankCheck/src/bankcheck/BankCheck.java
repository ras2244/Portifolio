/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bankcheck;

import static java.lang.System.exit;
import java.util.Scanner;

/**
 *
 * @author Ricardo
 */
public class BankCheck {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args){
        
        
        Scanner input=new Scanner(System.in);
        System.out.print("Number of banks:");
        int BankNumber=input.nextInt();
        System.out.print("Insert the limit:");
        double limit =input.nextDouble();

        System.out.print("\n");
        double[][] lenders=new double[BankNumber][BankNumber];
        double[] curBalance=new double[BankNumber];

        for(int i=0;i<curBalance.length;i++){
            int count=0;
            try{
            //read the current balance
            System.out.print("Bank ID#"+i+" Please,insert your inicial balance:");
            curBalance[i]=input.nextDouble();
            //read the number of borrowers
            System.out.print("Enter the number of bank(s) will borrow to Bank ID#" + i + ":");
            int numOflenders=input.nextInt();
            //setting up each bank balance, lenders and amount to borrow.
            do {
                System.out.print("Enter the ID of the Bank lander number " + (count+1) + ":");
                int lendersID=input.nextInt();
                System.out.print("Enter the bank lander number " + (count+1) + " Loan amount:");
                lenders[i][lendersID]=input.nextDouble();
                count++;
            }while(count<numOflenders);
            count=0;
            System.out.print("\n");
            }catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Array is out of Bounds"+e);
                exit(0);
            }
        }      
        
        //provisioning money on banks balances + borrow amount
        int index=0;
        for(int row=0;row<lenders.length;row++){
            double total=0.0;
            try{
                for(int col=0;col<lenders[row].length;col++){
                    total+=lenders[row][col];
                }
            }catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Array is out of Bounds"+e);
                exit(1);
            }
            total+=curBalance[row];
            if(total<limit){
                index=row;
            }
        }
        sweep(lenders,index);

        bankCheck(curBalance, lenders, limit);

        System.out.print("\n");
    }
    
    // Clearing lenders 
    private static void sweep(double[][] b, int index) {        
        try{
            for (double[] b1 : b) {
                b1[index] = 0;
            }
        }catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array is out of Bounds"+e);
            exit(2);
        }
    }
    
    // checking if each bank got above limit
    private static void bankCheck(double[] cB, double[][] b, double l) {
        // TODO Auto-generated method stub
        System.out.print("Unsafe banks are ");
        for(int i=0;i<cB.length;i++){
            try{
                double total=0;
                for(int j=0;j<b[i].length;j++){
                    total+=b[i][j];
                }
                total+=cB[i];
                if(total<l){
                    System.out.print("Bank ID#"+i+" ");
                }
            }catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Array is out of Bounds"+e);
                exit(3);
            }
        }
    } 
}
