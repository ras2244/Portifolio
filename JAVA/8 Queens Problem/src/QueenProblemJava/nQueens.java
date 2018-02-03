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


public class nQueens {
    
    /**
     * Make the queen movement into the board checking the row, column and  
     * diagonals positions covering all possible movements of a .
     * @param x
     * @param y
     * @param position
     * @param size
     * @return 
     */
    public static boolean movement (int x, int y, int position[][], int size) {
	
	//checking in the particular row and column
	for (int i = 0; i < size; i++) {
            //row check
            if ((position[x][i] == 1) && (i != y)) {
		return true;
            }

            //column check
            if ((position[i][y] == 1) && (i != x)) {
                return true;
            }
	}

	//diagonals check
	for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
		if ( ((i + j) == (x + y)) || ((i - j) == (x - y)) ) {
                    if (((i != x) || (j != y)) && (position[i][j] == 1)) {
			return true;
                    }
		}
            }
	}

	return false;
    }
    
    
    /**
     * Based on row, position(2d array) and board size
     * this program will run the queen positions
     * @param position
     * @param row
     * @param size
     * @return 
     */
    public static boolean nQueens (int position[][], int row, int size) {
	// returns true when the row and size is the same.
        // otherwise return false
        if (row == size) {
            return true;
	}
        
        // runs the program setting the queens positions.
	for (int j = 0; j < size; j++) {
            // check queens positions for a row colum and diags.
            //if returns true still looking.
            if (movement(row, j, position, size)) {
		continue;
            }
            //if false set the queen position on the board 
            position[row][j] = 1;
            
            //if true go to the next row and check all over again 
            // returning true 
            if(nQueens(position, row+1, size)) {
		return true;
            }
            //if false set 0 to represent no queen 
            //at that position on the board 
            position[row][j] = 0;
	}

	return false;
    }
    
    /**
     * Run rows and columns printing the board 
     * placing 1 for queen and 0 for no Queens
     * @param board
     * @param size 
     */
    public static void displayBoard (int[][] board, int size) {
	System.out.println("\n");
            for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
                    System.out.print("|" + board[i][j] + "|");
		}
		System.out.println();
            }
        System.out.println("\n");
    }
}
