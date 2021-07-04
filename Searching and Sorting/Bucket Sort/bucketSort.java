package project0;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class BucketSort {

	public static void main(String args[]) throws IOException {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the array");
		StringTokenizer st = new StringTokenizer(br.readLine());
		int arr[] = new int[st.countTokens()];
		int i=0;
		while(st.hasMoreTokens()) {
			arr[i] = Integer.parseInt(st.nextToken());
			i++;
		}
		
		bucketSort(arr);
		
		System.out.println(Arrays.toString(arr));
		
	}
	
	
	public static void bucketSort(int[] input) {
		List<Integer> buckets[] = new List[10];
		
		for(int i=0;i<buckets.length;i++) {
			buckets[i] = new ArrayList<Integer>();
		}
		
		for(int i=0;i<input.length;i++) {
			buckets[hash(input[i])].add(input[i]);
		}
		
		for(int i=0;i<buckets.length;i++) {
			Collections.sort(buckets[i]);
		}
		
		int j=0;
		for(int i=0;i<buckets.length;i++) {
			for(int item:buckets[i]) {
				input[j] = item;
				j++;
			}
		}
		 
	}
	
	private static int hash(int sortValue) {
		return sortValue/(int) 10 %10 ;
	}
	
	
	
	
	
}
