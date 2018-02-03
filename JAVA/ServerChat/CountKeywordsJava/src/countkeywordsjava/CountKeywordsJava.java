/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package countkeywordsjava;

import java.io.File;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author Ricardo
 */
public class CountKeywordsJava {
/** Method returns the keyword count
     * @param file
     * @return 
     * @throws java.lang.Exception */
    public static int countKeywords(File file) throws Exception {
        
        // Array of all Java Keywords + true, false and null
        String[] keywordString = {"abstract", "assert", "boolean",
            "break", "byte", "case", "catch", "char", "class", "const",
            "continue", "default", "do", "double", "else", "enum",
            "extends", "for", "final", "finally", "float", "goto",
            "if", "implements", "import", "instanceof", "int",
            "interface", "long", "native", "new", "package", "private",
            "protected", "public", "return", "short", "static",
            "strictfp", "super", "switch", "synchronized", "this",
            "throw", "throws", "transient", "try", "void", "volatile",
            "while", "true", "false", "null"};

        Set<String> keywordSet = 
            new HashSet<>(Arrays.asList(keywordString));
        int count = 0;
        
       

        Scanner input = new Scanner(file);

        while (input.hasNext()) {
            String word = input.next();
            if (word.contains("//")) { // Don't count comments
                input.nextLine(); 
            }
            else if (word.contains("\"")) { // Don't count string
                String nextWord;
                do {
                    nextWord = input.next();
                }while(!nextWord.contains("\""));
            }
            else if (word.contains("/*")) { // Don't count block comments
                String nextWord;
                do {
                    nextWord = input.next();
                }while(!nextWord.contains("*/"));
            }
            else if(keywordSet.contains(word))
                count++;
        }

        return count;
    }
   
    public static void main(String[] args) throws Exception {
        // Check command line length
        if (args.length != 1) {
            System.out.println("Usage: java sourceFile");
            System.exit(1);
        }

        // Check if file exists and display keyword count
        File file;
        File dir = new File("C:\\Users\\Ricardo\\Documents\\Java_course");
        file = new File(dir + "\\"+ args[0]);
        System.out.println(file);
        if (file.exists()) {
            
            System.out.println("The number of keywords in " + args[0] 
                + " is " + countKeywords(file));
        }
        else {
            System.out.println("File " + args[0] + " does not exist");
        }
    }
    
}
