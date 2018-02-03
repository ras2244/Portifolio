/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercises6_8;

import static java.lang.Math.random;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Ricardo
 */
public class Exercises6_8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        
        
        System.out.println("-----remove Duplicate Integers-----\n");
        System.out.print("Enter 10 integers: ");
        Scanner input = new Scanner(System.in);
        ArrayList<Integer> sample_list = new ArrayList<>();
        
        
        
        for (int i = 0; i < 10; i++){
            sample_list.add(input.nextInt());
        }
        System.out.println("The first 10 integers are:");
        System.out.println(sample_list);
        System.out.println("List without Duplicated numbers is:");
        removeDuplicate(sample_list);
        System.out.println(sample_list);
        
        System.out.println("-----Shuffle Array number-----\n");
        
        ArrayList<Number> number_sample = new ArrayList<>();
        
        for(int i =0;i<10;i++){
            number_sample.add(i);
        }
        System.out.println("The list with 10 integers is:");
        System.out.println(number_sample);
        System.out.println("The list shuffed is:");
        shuffle(number_sample);
        System.out.println(number_sample);
        
        System.out.println("-----Shuffle Array <E>-----\n");
        
        ArrayList<Number> number_sample2 = new ArrayList<>();
        
        for(int i =0;i<10;i++){
            number_sample2.add(i);
        }
        System.out.println("The list with 10 integers is:");
        System.out.println(number_sample2);
        System.out.println("The list shuffed is:");
        shuffle_tmp(number_sample2);
        System.out.println(number_sample2);
        
    }
    
    public static void removeDuplicate(ArrayList<Integer> list)
    {
        ArrayList<Integer> sample = new ArrayList<>();
        
        for(int i=0; i<list.size();i++){
            if(!sample.contains(list.get(i))){
                sample.add(list.get(i));
            }
        }
        
        list.clear();
        list.addAll(sample);
    }
    
    
    public static void shuffle(ArrayList<Number> list){
        
        for(int i=0; i<list.size();i++){
            int seed = (int) (Math.random())*(list.size());            
            int shuffed= (int)list.get(seed);
            list.set(seed,list.get(i));
            list.set(i,shuffed);
        
        }
    }
    
    public static <E> void shuffle_tmp(ArrayList<E> list){
        
        for(int i=0; i<list.size();i++){
            int seed = (int) random()*(list.size());
            E shuffed= list.get(seed);
            list.set(seed,list.get(i));
            list.set(i,shuffed);
         }
    }
}
