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

package QueenProblemJava;

/**
 *
 * @author Ricardo
 */
public class QueenProblemJava {

    /**
     * @param args the command line arguments
     * For this application will be given one possible solution
     */
    public static void main (String args[]) {
                
                int size = 8;
                
                System.out.println("Welcome to 8 Queen Solution!");

		int board[][] = new int[size][size];
                
                // calls nQueens passing size 8, board 8x8 and
                // starts at position 0
                // it will display a solution with the queens positions
                // if it fids one solution or a msg if irt not.
		if (nQueens.nQueens(board, 0, size)) {
			
                            nQueens.displayBoard(board, size);
                            
                            System.out.println("Congratulations Solution is founded!\n");
		}
		else {
			System.out.println("No solution.");
		}
	}
    
}
