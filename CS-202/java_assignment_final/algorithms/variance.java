package algorithms;
//import algorithms.*;
public class variance extends statsAlgorithms{

    public void print(){
        System.out.println("Returning the variance...");

    }

    // the main algorithm to find the arithmetic mean
    public void value(int[] inputArr){
        int array_length=inputArr.length;
        find_variance(inputArr,array_length);

    }
    private static void find_variance(int[] inputArr, int array_length){
        int sum=sum_array(inputArr, array_length);
        double arithmetic_mean= sum/array_length;
        double error=sq_error(inputArr,array_length,arithmetic_mean);
        double variance= error/array_length;
        System.out.println("The variance of the given input is: "+ variance);
        
    }
    private static double sq_error(int[] inputArr,int array_length, double arithmetic_mean){
        double error=0;
        int index =0;
        for(index=0;index<array_length;index++){
            error+=((inputArr[index]-arithmetic_mean)*(inputArr[index]-arithmetic_mean));
        }
        return error;
        
    }
    private static double find_mean(int[] inputArr, int array_length){
        int sum=sum_array(inputArr, array_length);
        double arithmetic_mean= sum/array_length;
        return arithmetic_mean;
        //System.out.println("The mean of the given sequence is: "+ arithmetic_mean);
        
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