<<<<<<< HEAD
package hw1;
import java.util.*;
import java.io.*;

public class hw1 {

	public static void main(String[] args) throws IOException {
		FileReader inputFile = new FileReader("input.txt");
		Scanner in = new Scanner(inputFile);
		Scanner input = new Scanner(System.in);
		
		double buffer;	
		
		int[] data = new int[3];
		
		for(int i=0; i<data.length; i++)
		{
			buffer = in.nextDouble();
			
			data[i] = (int)buffer;
			
			//System.out.println(data[i]);
		}
		in.close();
		
		int min = data[0];
		int max = data[1];
		int ans = data[2];
		int cin;
		
		System.out.println("Please guess an integer number between "+ min + " and " + max);
		cin = input.nextInt();
		
		while(cin != ans) 
		{
			if(cin < min || cin > max){
				System.out.println("The number you entered is not within the valid range.");
				System.out.println("Please try again!");
			}
			else if(cin < ans){
				min = cin;
			}
			else if(cin > ans){
				max = cin;
			}
			System.out.println("Please guess an integer number between "+ min + " and " + max);
			cin = input.nextInt();
		}
		System.out.println("Bingo! You hit the bomb.");
	}
}
=======
package hw1;
import java.util.*;
import java.io.*;

public class hw1 {

	public static void main(String[] args) throws IOException {
		FileReader inputFile = new FileReader("input.txt");
		Scanner in = new Scanner(inputFile);
		Scanner input = new Scanner(System.in);
		
		double buffer;	
		
		int[] data = new int[3];
		
		for(int i=0; i<data.length; i++)
		{
			buffer = in.nextDouble();
			
			data[i] = (int)buffer;
			
			//System.out.println(data[i]);
		}
		in.close();
		
		int min = data[0];
		int max = data[1];
		int ans = data[2];
		int cin;
		
		System.out.println("Please guess an integer number between "+ min + " and " + max);
		cin = input.nextInt();
		
		while(cin != ans) 
		{
			if(cin < min || cin > max){
				System.out.println("The number you entered is not within the valid range.");
				System.out.println("Please try again!");
			}
			else if(cin < ans){
				min = cin;
			}
			else if(cin > ans){
				max = cin;
			}
			System.out.println("Please guess an integer number between "+ min + " and " + max);
			cin = input.nextInt();
		}
		System.out.println("Bingo! You hit the bomb.");
	}
}
>>>>>>> 3af4f55 (commit2021/05/07)
