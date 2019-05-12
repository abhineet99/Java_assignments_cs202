package algorithms;

import algorithms.arithmeticMean;
import algorithms.statsAlgorithms;

/*
 This file gives the access to the algorithms.
 Inclusion of any other algorithm later should be specified and added here for the user to access.
 The algorithm is chosen as per the demand of the user, i.e., as per the string input.

*/
//Note that the function below returns an object of type statsAlgorithms
public class fetchAlgorithms{
    public static statsAlgorithms fetchAlgo(String algo){
        if(algo==null)
        {
        //System.out.println("here2");
            return null;
        }    
        else if(algo.equals("arithmeticMean"))
        {
            //System.out.println("here");
            return new arithmeticMean();
        }
        else if(algo.equals("variance"))
        {
          //  System.out.println("here");
            return new variance();
        }
        else
        {
           // System.out.println(algo);
            
           // System.out.println("here1");
            return null; 
        }           
    }
}