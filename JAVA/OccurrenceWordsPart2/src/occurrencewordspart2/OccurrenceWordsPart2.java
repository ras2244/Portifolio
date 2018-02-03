/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package occurrencewordspart2;

/**
 *
 * @author Ricardo
 */
import java.util.*;
import java.io.*;

public class OccurrenceWordsPart2 {

      
     /** Method persist occurrence of words */
    private static void persist(Map<String, Integer> map, String[] words) {
        for (String word : words) {
            String key = word.toLowerCase();
            if (key.length() > 0 && Character.isLetter(key.charAt(0))) {
                if (!map.containsKey(key)) {
                    map.put(key, 1);
                }
                else {
                    int value = map.get(key);
                    value++;
                    map.put(key, value);
                }
            }
        }
    }
        
    public static void main(String[] args) throws Exception {
        
        File br = new File("\\CountWords.txt");
                
        if (!br.exists()) {
            System.out.println("The file does not exists.");
            System.exit(1);
        }
        
        // Create a TreeMap to hold words as key and count as value
        Map<String, Integer> map = new TreeMap<>();
        
        // Create an input stream
        try (Scanner input = new Scanner(br);){
            while (input.hasNext()) {
                String[] words = input.nextLine().split("[ \n\t\r\"\'.,;:!?()]");
                persist(map, words);
            }
        }catch(FileNotFoundException ex) {
            ex.printStackTrace();
        }        	

        // Get all entries into a set
        Set<Map.Entry<String, Integer>> entrySet = map.entrySet();

        // Get key and value from each entry
        entrySet.forEach((entry) -> {
            System.out.println(entry.getValue() + "\t" + entry.getKey());
        });
    }
   
}
    
    

