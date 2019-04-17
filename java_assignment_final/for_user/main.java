import java.io.*;
import algorithms.statsAlgorithms;
import algorithms.fetchAlgorithms;
import java.util.Scanner;
public class main{
    public static void main(String args[]) throws IOException{
        int number;
        System.out.println("Please enter the number of elements in the sequence");
        Scanner input=new Scanner(System.in);
        boolean flag=0;
        
        number= input.nextInt();
        int num_array[]=new int[number];
        System.out.println("Please enter the elements of the sequence");
        for(int i=0;i<number;i++)
        {
            input=new Scanner(System.in);
            num_array[i]=input.nextInt();

        }
        System.out.println("Please enter the value which you want to get with regard to the sequence");
        System.out.println("The available options are; arithmeticMean OR variance");
        BufferedReader brObject = new BufferedReader(new InputStreamReader(System.in));  
        String algo= brObject.readLine();
        
        statsAlgorithms algoObject=fetchAlgorithms.fetchAlgo(algo);
        if (algoObject!=null){
            algoObject.print();
            algoObject.value(num_array);


        }
        else{
            System.out.println("Invalid Input");
        }


    }
}