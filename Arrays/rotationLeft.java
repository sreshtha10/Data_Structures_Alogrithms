import java.util.*;

public class Main{
	public static void main(String args[]) {
		int[] arr = {1,2,3,4,5};
		arr = rotateLeft(arr);
		System.out.println(Arrays.toString(arr));
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
}
