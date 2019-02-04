import java.util.Scanner;
class arrayMax{
	public static void main(String args[]){
		int[] myArray;
		myArray= new int[10];
		System.out.println("Enter 10 integers!\n");
		int x=0;
		while(x!=10)
		{
			Scanner input=new Scanner(System.in);
			myArray[x]=input.nextInt();
			x++;
		}
		x=0;
		int max=-2147483644;
		while(x!=10)
		{
			if (myArray[x]>max)
			max=myArray[x];
			x++;
		}
		System.out.println("The maximum integer is:\n");
		System.out.println(max);

	}
}