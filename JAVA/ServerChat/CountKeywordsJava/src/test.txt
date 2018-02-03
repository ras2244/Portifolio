/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Hangman {

    static ArrayList<String> wordList = new ArrayList<>();
    static boolean check;
    private static Scanner input, input2;
    
    // Methods
    
    //This Method randomly gets a word to be guessed.
    public static String getWord() {
        return wordList.get((int) (Math.random() * wordList.size()));
    }
    
    //This Method place asterics instead of words to hide the words
    public static String getHideWord(String w) {

        String hide = "";
        for (int i = 0; i < w.length(); i++) {
            hide += "*";
        }
        return hide;
    }
    
    /* This Method pass:
        String word to be guessed
        String HiddenWord that place asterics instead of words
        Char ch that is the word that the user have entered
        With those argumets this class will check if the word entered by user 
        is correct and if so replace in the string returnig a new string with 
        or not the word placed.
    */
    static public String checkGuess(String word, String hiddenWord, char ch) {

        check = false;
        StringBuilder s = new StringBuilder(hiddenWord);
        for (int i = 0; i < word.length(); i++) {

            if (ch == word.charAt(i) && s.charAt(i) == '*') {
                check = true;
                s = s.deleteCharAt(i);
                s = s.insert(i, ch);
            }
        }
        return s.toString();
    }
    
    /* This Method pass:        
        String HiddenWord that place asterics instead of words
        Char ch that is the word that the user have entered
        With those argumets this class will check if the word entered by user 
        have already be entered if so it returns true, otherwise false.
    */
    public static boolean isInTheWord(String hideWord, char ch) {

        for (int i = 0; i < hideWord.length(); i++) {

            if (ch == hideWord.charAt(i)) {
                return true;
            }
        }
        return false;
    }
    
    
    // Program (main)
    public static void main(String[] args) throws IOException {
        File br = new File("\\hangman.txt");
        String game = "y";
        
        if (!br.exists()) {            
            System.out.println(br + " File Not found!");
            System.exit(1);
        }
        try {
            input = new Scanner(br);
            while (input.hasNext()) {
                wordList.add(input.next());
            }
        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
        }        
        
 
        input2 = new Scanner(System.in);
                
        while (game.equals("y")) {
            String word = getWord();
            String hideWord = getHideWord(word);
            int count = 0;
            while (!word.equals(hideWord)) {

                System.out.print("(Guess) Enter a letter in word " + hideWord + " > ");
                char ch = input2.next().charAt(0);

                if (!isInTheWord(hideWord, ch)) {

                    hideWord = checkGuess(word, hideWord, ch);

                    if (!check) {
                        System.out.println(ch + " is not in the word.");
                        count++;
                    }

                } else {
                    System.out.println(ch + " is already in word.");
                }

            }
            System.out.println("Your hide word is "+word + " You have mistaken " + count + " time(s)");
            System.out.println("Do you want to try again? Enter y or n >");
            game = input2.next();
        }       

    }	
}