package algorithms;
//import algorithms.*;
public class arithmeticMean extends statsAlgorithms{

    public void print(){
        System.out.println("Returning the mean...");

    }

    // the main algorithm to find the arithmetic mean
    public void value(int[] inputArr){
        int array_length=inputArr.length;
        find_mean(inputArr,array_length);

    }

    private static void find_mean(int[] inputArr, int array_length){
        int sum=sum_array(inputArr, array_length);
        double arithmetic_mean= sum/array_length;
        System.out.println("The mean of the given sequence is: "+ arithmetic_mean);
        
    }
    private static int sum_array(int[] inputArr,int array_length){
        int sum=0;
        int index =0;
        for(index=0;index<array_length;index++){
            sum+=inputArr[index];
        }
        return sum;
    }

}