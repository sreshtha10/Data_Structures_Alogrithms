import java.util.*;
public class Main{
	public static void main(String args[]) {
		int[] arr1 = {1,2,3,4,5};
		int [] arr2 = {6,7,8,9,10};
		System.out.println("Left Rotation "+Arrays.toString(rotateLeft(arr1)));
		System.out.println("Right Rotation "+Arrays.toString(rotateRight(arr2)));
	}
	public static int[] rotateLeft(int[] arr) {
		int a,tmp = arr[arr.length-1];
		for(int i =arr.length-1;i>=0;i--) {
			if(i!=0) {
				a = tmp;
				tmp = arr[i-1];
				arr[i-1] = a;
			}
			else {
				arr[arr.length-1] = tmp;
			}
		}
		return arr;
	}
	public static int[] rotateRight(int[] arr) {
		int a,tmp = arr[0];
		for(int i=0;i<=arr.length-1;i++) {
			if(i != arr.length-1) {
				a = tmp;
				tmp = arr[i+1];
				arr[i+1] = a;
			}
			else {
				arr[0] = tmp;
			}
		}
		return arr;
	}
}
