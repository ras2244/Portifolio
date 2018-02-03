/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lottery2;


import static java.lang.System.exit;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Ricardo
 */
public class Lottery2 {

    /**
     * @param args the command line arguments
     */
    //static ArrayList<int> numbers = new ArrayList<>();
    //static ArrayList<String> wordList = new ArrayList<>();
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        List<Integer> lotteryList = new ArrayList<>();
        List<Integer> guessList = new ArrayList<>();
        
        lotteryList.add((int)(Math.random() * 10));
        lotteryList.add((int)(Math.random() * 10));
        lotteryList.add((int)(Math.random() * 10));
        
        System.out.print("The lottery number is ");
        for(int i=0; i<lotteryList.size(); i++){
            System.out.print(lotteryList.get(i));
        }
        System.out.print("\n");
        
        System.out.print("Enter a three-digit number: ");
        int guess = input.nextInt();
        
        try {
            if(guess>999){
                System.out.println("\nInvalid input please insert only 3 digits");
                exit(1);
            }
            }catch(InputMismatchException e){
                    e.printStackTrace();                    
            }        
        
        guessList.add(guess / 100);
        guessList.add((guess % 100) / 10);
        guessList.add((guess % 100) % 10);
        
        //Collections.sort(lotteryList);
        //Collections.sort(guessList);
        List<Integer> l1 = Arrays.asList(lotteryList.get(0), lotteryList.get(1));
        List<Integer> l2 = Arrays.asList(lotteryList.get(0), lotteryList.get(2));
        List<Integer> l3 = Arrays.asList(lotteryList.get(1), lotteryList.get(2));
        if (guessList.equals(lotteryList)) {
                System.out.println("Exact match: you won $10,000");
                System.out.print("The lottery number was ");
                for(int i=0; i<lotteryList.size(); i++){
                        System.out.print(lotteryList.get(i));
                    }
                System.out.println("\n");
        }
        else if (guessList.containsAll(l1) || guessList.containsAll(l2) || guessList.containsAll(l3)) {
                System.out.println("Two digits match: you won $2,000");
                System.out.print("The lottery number was ");
                for(int i=0; i<lotteryList.size(); i++){
                        System.out.print(lotteryList.get(i));
                    }
                System.out.println("\n");
        }
        else if (guessList.contains(lotteryList.get(0)) || guessList.contains(lotteryList.get(1))
                || guessList.contains(lotteryList.get(2)) ){
                System.out.println("Match one digit: you won $1,000");
                System.out.print("The lottery number was ");
                for(int i=0; i<lotteryList.size(); i++){
                        System.out.print(lotteryList.get(i));
                    }
                System.out.println("\n");
        }
        else {
                System.out.println("You did not have luck this time! keep trying");
                System.out.print("The lottery number was ");
                for(int i=0; i<lotteryList.size(); i++){
                        System.out.print(lotteryList.get(i));
                    }
                System.out.println("\n");
        }
       
    }
    
}
