/* Implement the Peak finding algorithm for 2-D array 
	extended divide and conquer.
	Time complexity - n(log(n))*/

import java.util.Scanner;
public class Main{
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the size of the array");
		int size = scanner.nextInt();
		int arr[][] = new int[size][size];
		System.out.println("Enter the array");
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++) {
				arr[i][j] = scanner.nextInt();
			}
		}
		System.out.println(peakFinder(arr,size,0,size));
		scanner.close();

	}
	public static int peakFinder(int arr[][],int rowLen,int low,int high) {
		int midCol = (low+high)/2;
		int maxRow = max(arr, rowLen, midCol);
		if(midCol < high-1 && arr[maxRow][midCol] < arr[maxRow][midCol+1]) {
			return peakFinder(arr, rowLen, midCol+1,high);
		}
		else if(midCol > low && arr[maxRow][midCol] < arr[maxRow][midCol-1] ) {
			return peakFinder(arr, rowLen, low, midCol-1);
		}
		else {
			return arr[maxRow][midCol];
		}
		
	}
	
	// To find the maximum element in a column
	public static int max(int[][] arr,int row,int mid) {
		int max = 0;
		for(int i =0;i<row;i++) {
			if(arr[i][mid] > arr[max][mid]) {
				max = i;
			}
		}
		return max;
	}
}
