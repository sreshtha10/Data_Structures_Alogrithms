package project0;

import java.util.Arrays;

class Main{
	public static void main(String args[]) {
		// bubble sort
		int arr[] = {3,2,1,4,10,1,9,0};
		bubbleSort(arr);
		System.out.println(Arrays.toString(arr));
	}
	
	public static void bubbleSort(int arr[]) {
		for(int i=0;i<arr.length-1;i++) {
			for(int j =0;j<arr.length-i-1;j++) {
				if(arr[j] > arr[j+1]) {
					swap(arr,j,j+1);
				}	
			}
		}
	}
	
	public static void swap(int[] arr,int i,int j) {
		int tmp;
		if(i==j) {
			return;
		}
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}
