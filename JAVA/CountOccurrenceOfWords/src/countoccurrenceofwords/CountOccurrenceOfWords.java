/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package countoccurrenceofwords;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.TreeMap;

/**
 *
 * @author Ricardo
 */
public class CountOccurrenceOfWords {

    private static class WordOccurrence implements Comparable<WordOccurrence> {

        int count;
        String word;

        public WordOccurrence(String word, int count) {
            this.word = word;
            this.count = count;
        }

        @Override
        public int compareTo(WordOccurrence o) {
            if (o.count > count)
                return -1;
            else if (o.count < count)
                return 1;
            else
                return 0;
        }
    }
    
    public static void main(String[] args) {
    
    // Set text in a string
        String text = "z Good morning. Have a good class. " +
                "Have a good visit. Have fun!";

        // Create a TreeMap to hold words as key and count as value
        Map<String, Integer> map = new TreeMap<>();

        String[] words = text.split("[ \\n\\t\\r.,;:!?(){}]");
        for (String word1 : words) {
            String key = word1.toLowerCase();

            if (key.length() > 0) {
                if (!map.containsKey(key)) {
                    map.put(key, 1);
                } else {
                    int value = map.get(key);
                    value++;
                    map.put(key, value);
                }
            }
        }

        ArrayList<WordOccurrence> list = new ArrayList<>();
        
        // Display key and value for each entry
        map.forEach((k, v) -> list.add(new WordOccurrence(k, v)));
        Collections.sort(list);
        list.forEach((word) -> System.out.println(word.word + "\t" + word.count));


    }
    
}
