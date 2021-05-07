<<<<<<< HEAD

import java.io.*;
import java.util.*;

class matrix
{
	private int ss = 0;
	private int[][] m;
	
	public matrix() {
		ss = 0;
		m = new int[ss][ss];
	}
	
	public matrix(int size) {
		ss = size;
		m = new int[ss][ss];
	}
	
	public matrix(matrix other) {
		ss = other.ss;
		m = new int[ss][ss];
		for(int i = 0; i < ss; i++) {
			for(int j = 0; j < ss; j++) {
				m[i][j] = other.m[i][j];
			}
		}
	}
	
	public void setElement(int i, int j, int input) {
		m[i][j] = input;
	}
	
	public int getElement(int i, int j) {
		return m[i][j];
	}
	
	public void printSelf() {
		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				System.out.print(m[i][j]);
				System.out.print(" ");
			}
			System.out.println();
		}
	}
}

public class M10815071_HW5 {
	public static void main(String[] args) {
		// obtain the matrix size from user
		int size;
		Scanner input = new Scanner(System.in);
		System.out.println("Please input the size of the square matrix.");
		size = input.nextInt();
		
		// create the matrix object
		matrix m = new matrix(size);
		
		// assign the values to the created matrix
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++)
			{
				if(i==j)
					m.setElement(i,j,10);	
				else
					m.setElement(i,j,1);	
			}
		
		// show the matrix on the screen
		System.out.println("m = ");
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
				System.out.print(m.getElement(i,j)+" ");

			System.out.println();
		}

		//testing standard constructors
		matrix[] mArr1 = new matrix[10];	//calling default constructor (10 times)
		matrix[] mArr2 = new matrix[5];							//calling default constructor (5 times)
		matrix m1;									//calling default constructor
		matrix m2 = new matrix(m);		//calling copy constructor
		matrix m3 = new matrix(m);				//calling copy constructor

		m1 = m;										//calling copy assignment operator
		
		//show the testing matrix objects
		System.out.println("m1 = ");
		m1.printSelf();
		System.out.println("m2 = ");
		m2.printSelf();
		System.out.println("m3 = ");
		m3.printSelf();
	}
}
=======

import java.io.*;
import java.util.*;

class matrix
{
	private int ss = 0;
	private int[][] m;
	
	public matrix() {
		ss = 0;
		m = new int[ss][ss];
	}
	
	public matrix(int size) {
		ss = size;
		m = new int[ss][ss];
	}
	
	public matrix(matrix other) {
		ss = other.ss;
		m = new int[ss][ss];
		for(int i = 0; i < ss; i++) {
			for(int j = 0; j < ss; j++) {
				m[i][j] = other.m[i][j];
			}
		}
	}
	
	public void setElement(int i, int j, int input) {
		m[i][j] = input;
	}
	
	public int getElement(int i, int j) {
		return m[i][j];
	}
	
	public void printSelf() {
		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				System.out.print(m[i][j]);
				System.out.print(" ");
			}
			System.out.println();
		}
	}
}

public class M10815071_HW5 {
	public static void main(String[] args) {
		// obtain the matrix size from user
		int size;
		Scanner input = new Scanner(System.in);
		System.out.println("Please input the size of the square matrix.");
		size = input.nextInt();
		
		// create the matrix object
		matrix m = new matrix(size);
		
		// assign the values to the created matrix
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++)
			{
				if(i==j)
					m.setElement(i,j,10);	
				else
					m.setElement(i,j,1);	
			}
		
		// show the matrix on the screen
		System.out.println("m = ");
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
				System.out.print(m.getElement(i,j)+" ");

			System.out.println();
		}

		//testing standard constructors
		matrix[] mArr1 = new matrix[10];	//calling default constructor (10 times)
		matrix[] mArr2 = new matrix[5];							//calling default constructor (5 times)
		matrix m1;									//calling default constructor
		matrix m2 = new matrix(m);		//calling copy constructor
		matrix m3 = new matrix(m);				//calling copy constructor

		m1 = m;										//calling copy assignment operator
		
		//show the testing matrix objects
		System.out.println("m1 = ");
		m1.printSelf();
		System.out.println("m2 = ");
		m2.printSelf();
		System.out.println("m3 = ");
		m3.printSelf();
	}
}
>>>>>>> 3af4f55 (commit2021/05/07)
